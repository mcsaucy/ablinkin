// Ablinkin board definitions and common helper functions
#ifdef __SEGMENT_H
#define __SEGMENT_H
#include "ablinkin_commands.h"
#include <Wire.h>


typedef struct board_t{
    byte address; // address on i2c bus
    byte ncols; // number of columns
    struct board_t * next;
} Board;


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
byte poke ( byte addr )
{
    Wire.beginTransmission(addr);
    return ( !! Wire.endTransmission() );
}

// Probe for board information (column count)
byte probe ( byte addr )
{
    Wire.beginTransmission(addr);
    Wire.write( CTL | GET_COLS );
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

    return ret; // caller will need to parse
}

#endif
