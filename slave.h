// header file for the slave of the i2c bus for Ablinking

#ifndef __ABLINKIN_SLAVE_H
#define __ABLINKIN_SLAVE_H

#include <Arduino.h>
#include <Wire.h>
#include "segment.h"
#include "sign_common.h"

#define NCOLS 48

static uint8_t * columns;
static uint8_t auto_latch; // disengage storage latch before update, reengage afterwards
static uint8_t output_enable;
static uint8_t column_index;
static volatile uint8_t data;

uint8_t giveCols();

void initSlave();
void handleRX( int numBytes );
void handleTX();

uint8_t erase( uint8_t val );
uint8_t setDisplay( uint8_t val );
uint8_t setUpdate( uint8_t val );
uint8_t shiftColumn( uint8_t col );

#endif
