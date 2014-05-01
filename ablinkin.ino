/*  Ablinkin -- Josh McSavaney
 *  Philbrick segment control hardware.
 *
 *  Architected such that a master probes for slave boards, probes for their
 *  column count ( max 127 columns ), and then commands the slave signs.
 */


#include <Wire.h>
#include "ablinkin_commands.h"
#include "sign_common.h"
#include "segment.h"
#include "master.h"

// Our segment data structure
Board * segment;

void setup()
{

    segment = NULL;
    count = 0;
    first = 0;
    last = 0;

    for( byte i = 2; i <= 9; i++ )
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

    Serial.println(address);
    delay(100);
}


