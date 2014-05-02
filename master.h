// header file for the master of the i2c bus for Ablinking

#ifndef __ABLINKIN_MASTER_H
#define __ABLINKIN_MASTER_H

#include "segment.h"
#include "sign_common.h"
#include <Wire.h>

uint8_t scanAndPopulate ( Board * curr );
uint8_t getCols( uint8_t tgt );
uint8_t tapFoot( uint8_t ms, uint8_t times );




#endif
