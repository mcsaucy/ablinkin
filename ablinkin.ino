/*  Ablinkin -- Josh McSavaney
 *  Philbrick segment control hardware.
 *
 *  Architected such that a master probes for slave boards, probes for their
 *  column count ( max 127 columns ), and then commands the slave signs.
 */


#include <Arduino.h>
#include <Wire.h>
#include "ablinkin_commands.h"
#include "sign_common.h"
#include "segment.h"
#include "master.h"
#include "slave.h"
#include "letters.h"

// Our segment data structure
Board * segment;
byte strlength;
char * string;

void setup()
{
    string = "/\\";
    strlength = strlen(string);
    segment = NULL;
    count = 0;
    first = 0;
    last = 0;

    for( uint8_t i = 2; i < 9; i++ )
    {
        pinMode(i, INPUT);
        address |= digitalRead(i) << (i - 2);
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
        initSlave();
    }
}

void loop()
{
    if ( address == 0 )
    {   
        for ( int i = 0; i < strlength; i++ )
        {
            for ( int j = 0; j < 4; j++ )
            {
                Board * curboard = segment;
                while ( curboard != NULL )
                {
                    Wire.beginTransmission( curboard->address );
                    Wire.write( get_char_section( string[i], j ) );
                    Wire.endTransmission();
                    Wire.requestFrom( curboard->address, (byte) 1 );
                    if ( Wire.available() )
                        Wire.read();
                    curboard = curboard->next;
                }
            }
            delay(100);
        }
    }
    delay(10);
}
