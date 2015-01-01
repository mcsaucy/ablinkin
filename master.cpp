// function implementations for the i2c master of Ablinking

#include "master.h"
#include "ablinkin_commands.h"
#include "segment.h"

// Scan all available i2c addresses looking for slaves
byte scanAndPopulate( Board * curr )
{
    byte ct = 0;
    for ( byte i = 1; i <= 127; i++ )
    {
        if ( poke(i) != 0 )
        {
            if ( first == 0 ) first = i;

            last = i;
            ct ++;
        }
    }

    byte ncol=0;
    for ( byte addr = first; addr <= last; addr++ )
    {
        if ( ( ncol = getCols(addr) ) == 0 )
            continue;

        curr = (Board *) malloc( sizeof(Board) );
        curr->address = addr;
        curr->ncols = ncol;
        curr->next = NULL;
        curr = curr->next;
    }

    return ct;
}

// Wait 'ms' milliseconds 'times' times for data on the wire
byte tapFoot( byte ms, byte times )
{
    for ( byte i = 0; i < times; i++ )
    {
        if ( Wire.available() )
            return times + 1; // multiples of 'ms' we had to wait, rounded up
        delay(ms);
    }

    return 0; // 0, in this case, signifies failure
}

// Request the number of columns from a slave board
byte getCols( byte addr )
{
    Wire.beginTransmission(addr);
    Wire.write( CTL | GET_COLS );
    if ( Wire.endTransmission() != 0 )
        return 0; // tranmission error

    Wire.requestFrom(addr, (byte) 1);
    if ( tapFoot(2,5) == 0 )
        return 0; // timed out
    return Wire.read();
}
