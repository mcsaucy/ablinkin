/*  Ablinkin -- Josh McSavaney
 *  Philbrick segment control hardware.
 *
 *  Architected such that a master probes for slave boards, probes for their 
 *  column count ( max 127 columns ), and then commands the slave signs.
 */


#include <Wire.h>
#include "ablinkin_commands.h"
#include "segment .h"
#include "master.h"


#define PROBE 127

byte address;
byte error;
byte count;
byte first;
byte last;

byte output_enable;
byte master_erase;
byte auto_latch; // disengage storage latch before update, reengage afterwards

// Our segment data structure
Board * segment;

void setup()
{

    segment = NULL;
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
        Serial.begin(9600);
        Wire.begin();

        do
        {
            delay(100); // allow slaves to come up/wait 100ms and try again
        }
        while ( scanAndPopulate( segment ) == 0 ); // keep trying til it works
    }
    else
    {
        Wire.begin(address);



        
// TODO: add in slave code

}


void loop()
{

    Serial.println(address);
    delay(100);
}




