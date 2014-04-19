// function implementations for the i2c master of Ablinking

#include "master.h"
#include "ablinkin_commands.h"
#include "segment.h"

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
