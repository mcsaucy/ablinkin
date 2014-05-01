// function implementations for the i2c slave of Ablinkin

#include "slave.h"
#include "ablinkin_commands.h"
#include "segment.h"

void initSlave()
{
    pinMode(DAT_PIN, output); //data
    pinMode(CLK_PIN, output); //clock
    pinMode(LCH_PIN, output); //latch
    pinMode(ERS_PIN, output); //erase
    pinMode(DSP_PIN, output); //display

    erase(1); // start fresh

    columns = (byte *) malloc( NCOLS );
    column_index = 0;
    auto_latch = 1;

    output_enable = 1;
    digitalWrite(DSP_PIN, LOW); //display by default

    Wire.onReceive(handleRX);
    Wire.onRequest(handleTX);
}

byte shiftColumn( byte col )
{

    if ( col & SET_UPDATE_FLAG_INLINE )
        setUpdate( col & UPDATE_FLAG_INLINE );

    if ( auto_latch ) digitalWrite(LCH_PIN, LOW);

    shiftOut(DAT_PIN, CLK_PIN, MSBFIRST, col );

    if ( auto_latch ) digitalWrite(LCH_PIN, HIGH);

    return col & ~SET_UPDATE_FLAG_INLINE & ~UPDATE_FLAG_INLINE |
        ( 1 << SET_UPDATE_FLAG_INLINE_BIT );
}

byte erase( byte val )
{
    if ( ! val ) return !!val;

    digitalWrite(CLK_PIN, HIGH);
    digitalWrite(ERS_PIN, LOW);
    digitalWrite(CLK_PIN, LOW);
    digitalWrite(ERS_PIN, HIGH);

    return !!val;
}

byte setDisplay( byte val )
{
    digitalWrite( DSP_PIN, { HIGH, LOW }[!!val] );
    //!!val converts val into a 0 or 1 while preserving truthiness
    return (output_enable = !!val);
}

byte setUpdate( byte val )
{
    digitalWrite(LCH_PIN, LOW);
    return( auto_latch = !!val );
}


byte giveCols( byte addr )
{
    return NCOLS;
}

void handleTX()
{
    send(data);
    data = 0;
}

void handleRX( int numBytes )
{
    date = receive();
    if ( data & MSG == 0 )
    {
        data = shiftColumn( data );
        //shiftColumn handles inlined commands
        return;
    }

    if ( data & GET_COLS == 0 )
    {
        data &= 0xC0;
        data |= ( giveCols() & ~0xC0 );
        return;
    }

    if ( input & SET_UPDATE_FLAG )
    {
        auto_latch = !! ( data & UPDATE_FLAG );
    }

    if ( data & SET_MASTER_RESET_FLAG )
    {
        erase( data & MASTER_RESET_FLAG );
        data &= ~MASTER_RESET_FLAG;
        //spec dictates that MR should never be sent
        //back even if it was sent as MR does not persist
    }

    if ( input & SET_DISPLAY_FLAG )
    {
        output_enable = !! ( input & DISPLAY_FLAG );
    }

}

