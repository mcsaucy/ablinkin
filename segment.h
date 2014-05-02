// Ablinkin board definitions and common helper functions
#ifndef __SEGMENT_H
#define __SEGMENT_H

#include <Arduino.h>
#include <Wire.h>
#include "ablinkin_commands.h"

struct Board;

typedef struct Board{
    uint8_t address; // address on i2c bus
    uint8_t ncols; // number of columns
    struct Board * next;
} Board;


Board * insertLink ( Board * left, Board * center );

// Rus as `free( removeLinkAfter( node ) );` to auto free the unlinked node
Board * removeLinkAfter( Board * left );

// Check to see if an i2c address is in use
uint8_t poke ( uint8_t addr );

// Probe for board information (column count)
uint8_t probe ( uint8_t addr );

#endif
