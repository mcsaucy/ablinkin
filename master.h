// header file for the master of the i2c bus for Ablinking

#ifndef __ABLINKIN_MASTER_H
#define __ABLINKIN_MASTER_H

#include "segment.h"
#include "sign_common.h"
#include <Wire.h>

// Scan all available i2c addresses looking for slaves
uint8_t scanAndPopulate ( Board * curr );
 
// Request the number of columns from a slave board
uint8_t getCols( uint8_t tgt );

// Wait 'ms' milliseconds 'times' times for data on the wire
uint8_t tapFoot( uint8_t ms, uint8_t times );

#endif
