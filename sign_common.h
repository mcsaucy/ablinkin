// Ablinkin board definitions and common helper functions
#ifndef __SIGN_COMMON_H
#define __SIGN_COMMON_H

#include "ablinkin_commands.h"
#include <Wire.h>

#define PROBE 127

// Data pin
#define DAT_PIN A0

// Display pin (active low)
#define DSP_PIN 13

// Storage latch pin
#define LCH_PIN 12

// Clock pin
#define CLK_PIN 11

// Erase pin
#define ERS_PIN 10


static uint8_t address;
static uint8_t error;
static uint8_t count;
static uint8_t first;
static uint8_t last;

#endif
