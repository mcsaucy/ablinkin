// header file for the master of the i2c bus for Ablinking

#ifndef __ABLINKIN_MASTER_H
#define __ABLINKIN_MASTER_H

#include "segment.h"
#include <Wire.h>

byte scanAndPopulate ( Board * curr );
byte getCols( byte tgt );
byte tapFoot( byte ms, byte times );




#endif
