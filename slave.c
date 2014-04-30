// function implementations for the i2c slave of Ablinking

#include "slave.h"
#include "ablinkin_commands.h"
#include "segment.h"

void initSlave()
{
    pinMode(DAT_PIN, output); //data
    pinMode(CLK_PIN, output); //clock
    pinMode(LTC_PIN, output); //latch
    pinMode(ERS_PIN, output); //erase
    pinMode(DSP_PIN, output); //display

    erase(1); // start fresh

    columns = (byte *) malloc( NCOLS );
    column_index = 0;
    auto_latch = 1;
    output_enable = 1;
}

byte shiftColumn( byte col )
{
    
    if ( col & SET_UPDATE_FLAG_INLINE ) setUpdate( col & UPDATE_FLAG_INLINE );

    if ( auto_latch ) digitalWrite(latchPin, LOW);
   
    shiftOut(dataPin, clockPin, MSBFIRST, col );

    if ( auto_latch ) digitalWrite(latchPin, HIGH);
    
    return col;
}

byte erase( byte val )
{
    if ( ! val ) return !!val;

    digitalWrite(clockPin, HIGH);
    digitalWrite(erasePin, LOW);
    digitalWrite(clockPin, LOW);
    digitalWrite(erasePin, HIGH);
    
    return !!val;
}
    
byte setDisplay( byte val )
{
    digitalWrite( displayPin, { HIGH, LOW }[!!val] );
    //!!val converts val into a 0 or 1 while preserving truthiness
    return (output_enable = !!val);
}

byte setUpdate( byte val )
{
    digitalWrite(latchPin, LOW);
    return( auto_latch = !!val );
}


byte giveCols( byte addr )
{
    return NCOLS;
}
