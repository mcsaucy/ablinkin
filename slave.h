// header file for the slave of the i2c bus for Ablinking

#ifndef __ABLINKIN_SLAVE_H
#define __ABLINKIN_SLAVE_H

#include "segment.h"
#include <Wire.h>

#define NCOLS 48

byte * columns;
byte auto_latch; // disengage storage latch before update, reengage afterwards
byte output_enable;
byte column_index;

byte giveCols();

void initSlave();
void handleRX( int numBytes );
void handleTX();

byte erase( byte val );
byte setDisplay( byte val );
byte shiftColumn( byte col );
byte setUpdate( byte val );
#endif
