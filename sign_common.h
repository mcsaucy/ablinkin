// Ablinkin board definitions and common helper functions
#ifndef __SIGN_COMMON_H
#define __SIGN_COMMON_H

#include "ablinkin_commands.h"
#include <Wire.h>

#define PROBE 127

#define DAT_PIN A0
#define DSP_PIN 13
#define LCH_PIN 12
#define CLK_PIN 11
#define ERS_PIN 10


static uint8_t address;
static uint8_t error;
static uint8_t count;
static uint8_t first;
static uint8_t last;

#endif
