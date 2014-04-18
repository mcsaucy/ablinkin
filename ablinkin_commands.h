#ifndef __ABLINKIN_COMMANDS_H
#define __ABLINKIN_COMMANDS_H

// Bit locations in message packets
// << shift to get your desired bit
#define MESSAGE_BIT 7
#define MSG_BIT MESSAGE_BIT

#define TEXT_BIT MESSAGE_BIT
#define TXT_BIT TEXT_BIT

#define CONTROL_BIT MESSAGE_BIT
#define CTL_BIT CONTROL_BIT

#define SET_UPDATE_FLAG_INLINE_BIT 6
#define GET_COL_BIT 6
#define CHANGE_FLAGS_BIT 6

#define SET_UPDATE_FLAG_BIT 5
#define UPDATE_FLAG_INLINE_BIT 5

#define UPDATE_FLAG_BIT 4

#define SET_MASTER_RESET_FLAG_BIT 3

#define MASTER_RESET_FLAG_BIT 2

#define SET_DISPLAY_FLAG_BIT 1

#define DISPLAY_FLAG_BIT 0

// Return values
#define GET_INLINE_DISPLAY_FLAG_BIT 1
#define GET_OVERFLOW_STATUS_BIT 2 // overflow isn't a bad thing, in this case


// Bit values for handy-dandy bitwise OR-ing
#define MESSAGE (0<<MSG_BIT)
#define MSG MESSAGE

#define CONTROL (1<<MSG_BIT)
#define CTL CONTROL

#define GET_COLS (0<<GET_COL_BIT)
#define CHANGE_FLAGS (1<<CHANGE_FLAGS_BIT)

#define SET_UPDATE_FLAG_INLINE (1<<SET_UPDATE_FLAG_INLINE_BIT)
#define UPDATE_FLAG_INLINE (1<<UPDATE_FLAG_INLINE_BIT)

#define SET_UPDATE_FLAG (1<<SET_UPDATE_FLAG_BIT)
#define UPDATE_FLAG (1<<UPDATE_FLAG_BIT)

#define SET_MASTER_RESET_FLAG (1<<SET_MASTER_RESET_FLAG_BIT)
#define MASTER_RESET_FLAG (1<<MASTER_RESET_FLAG_BIT)

#define SET_DISPLAY_FLAG (1<<SET_DISPLAY_FLAG_BIT)
#define DISPLAY_FLAG (1<<DISPLAY_FLAG_BIT)

// Bit masks for the extraction of data from return packets
#define GET_INLINE_DISPLAY_FLAG (1<<GET_INLINE_DISPLAY_FLAG_BIT)
#define GET_OVERFLOW_STATUS (1<<GET_OVERFLOW_STATUS_BIT)
// did anything "fall off" the sign?

#define OVERFLOW_MASK 0x1F //5 bits where we have our overflow content

#define GET_UPDATE_FLAG UPDATE_FLAG
#define GET_MASTER_RESET_FLAG MASTER_RESET_FLAG
#define GET_DISPLAY_FLAG DISPLAY_FLAG

#endif
