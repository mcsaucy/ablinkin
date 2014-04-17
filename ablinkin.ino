/*  Ablinkin -- Josh McSavaney
 *  Philbrick segment control hardware.
 *
 *  Architected such that a master probes for slave boards, probes for their 
 *  column count ( max 127 columns ), and then commands the slave signs.
 */


#include <Wire.h>

#define PROBE 127

byte address;
byte error;
byte count;
byte first;
byte last;

typedef struct board_t{
    byte address; // address on i2c bus
    byte ncols; // number of columns
    struct board_t * next;
} Board;

// Our segment data structure
Board * segment;

// Probe for board information (column count)
byte probe ( byte addr )
{
    Wire.beginTransmission(addr);
    Wire.write(PROBE);
    byte ret = 0;
    
    // give the slave up to 10 ms to respond
    for ( int i = 0; i < 10 && ! Wire.available(); i++ )
    {
        delay(1);
    }

    if ( Wire.available() )
        ret = Wire.read();

    if ( Wire.endTransmission() != 0 ) // if an error occurred, return 0
        ret = 0;

    return ret;
}

// Check to see if an i2c address is in use
byte poke ( byte addr )
{
    Wire.beginTransmission(addr);
    return ( !! Wire.endTransmission() );
}

Board * insertLink ( Board * left, Board * center )
{
    if( left == NULL || center == NULL )
        return NULL;

    Board * right = left->next;
    left->next = center;
    center->next = right;
    return left;
}

// Rus as `free( removeLinkAfter( node ) );` to auto free the unlinked node
Board * removeLinkAfter( Board * left )
{
    if( left == NULL || left->next == NULL )
        return NULL;
    Board * ret = left->next;
    left->next = ret->next;
    return ret;
}

byte scanAndPopulate ()
{
    byte ncol;
    for ( byte i = 1; i <= 127; i++ )
    {
        if ( poke(i) != 0 )
        {
            if ( first == 0 ) first = i;
            last = i;
            count ++;
        }
    }

    Board * current = segment;

    for ( byte addr = first, addr <= last; addr++ )
    {
        if ( poke(addr) != 0 )
            continue;

        if ( ( ncol = probe(addr) ) == 0 )
            continue;
        
        current = (Board *) malloc( sizeof(Board) );
        current->address = addr;
        current->ncols = ncol;
        current->next = NULL;
        current = current->next;
    }

    return count;
}


void setup() {

    Serial.begin(9600);
    count = 0;
    first = 0;
    last = 0;

    for( byte i = 7; i <= 13; i++ )
    {
    pinMode(i, INPUT);
    }
  
    for ( byte i = 7; i <= 13; i++ )
    {
    address += digitalRead(i) << (i - 7);
    }
    if ( address == 0 )
    {
        segment = NULL;
        Wire.begin();
        do
        {
            delay(100); // allow slaves to come up/wait 100ms and try again
        }
        while ( scan() == 0 );

        
// TODO: add in slave code

    else
    Wire.begin(address);
}


void loop() {

    Serial.println(address);
    delay(100);
}




