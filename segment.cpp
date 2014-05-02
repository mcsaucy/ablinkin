// Ablinkin board definitions and common helper functions
#include <Arduino.h>
#include <Wire.h>
#include "segment.h"
#include "ablinkin_commands.h"

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

// Check to see if an i2c address is in use
uint8_t poke ( uint8_t addr )
{
    Wire.beginTransmission(addr);
    return ( !! Wire.endTransmission() );
}

// Probe for board information (column count)
uint8_t probe ( uint8_t addr )
{
    Wire.beginTransmission(addr);
    Wire.write( CTL | GET_COLS );
    uint8_t ret = 0;

    // give the slave up to 10 ms to respond
    for ( int i = 0; i < 10 && ! Wire.available(); i++ )
    {
        delay(1);
    }

    if ( Wire.available() )
        ret = Wire.read();

    if ( Wire.endTransmission() != 0 ) // if an error occurred, return 0
        ret = 0;

    return ret; // caller will need to parse
}

