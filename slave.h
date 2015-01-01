// header file for the slave of the i2c bus for Ablinking

#ifndef __ABLINKIN_SLAVE_H
#define __ABLINKIN_SLAVE_H

#include <Arduino.h>
#include <Wire.h>
#include "segment.h"
#include "sign_common.h"

// TODO: find a way to determine this dynamically on startup
#define NCOLS 48

static uint8_t * columns;
static uint8_t auto_latch; // storage latch off before update, on afterwards
static uint8_t output_enable;
static uint8_t column_index;
static volatile uint8_t data;

uint8_t giveCols(); // Give the number of LED columns available on this display

void initSlave(); // initialization routine for a slave
void handleRX( int numBytes ); // ISR for receiving data
void handleTX(); // ISR for being asked for data

uint8_t erase( uint8_t val ); // Wipe the slate clean
uint8_t setDisplay( uint8_t val ); // Set the display bit of the 595
uint8_t setUpdate( uint8_t val ); // Set the storage latch of the 595
uint8_t shiftColumn( uint8_t col ); // Shift out a column of output

#endif
