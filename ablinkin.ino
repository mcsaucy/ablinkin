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

// Our segment data structure
Board * segment;

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




