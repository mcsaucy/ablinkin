/*

Infosys Letter Section Lookup
Michael J Moffitt 2014

*/
#include "letters.h"

char ch_lookup[] = // Every 4 indeces corresponds to the ascii lookup
{
// 0x00
	0x00, 0x00, 0x00, 0x00, // Null
	0x00, 0x00, 0x00, 0x00, // Null
	0x00, 0x00, 0x00, 0x00, // Null
	0x00, 0x00, 0x00, 0x00, // Null
	0x00, 0x00, 0x00, 0x00, // Null
	0x00, 0x00, 0x00, 0x00, // Null
	0x00, 0x00, 0x00, 0x00, // Null
	0x00, 0x00, 0x00, 0x00, // Null
	0x00, 0x00, 0x00, 0x00, // Null
	0x00, 0x00, 0x00, 0x00, // Null
	0x00, 0x00, 0x00, 0x00, // Null
	0x00, 0x00, 0x00, 0x00, // Null
	0x00, 0x00, 0x00, 0x00, // Null
	0x00, 0x00, 0x00, 0x00, // Null
	0x00, 0x00, 0x00, 0x00, // Null
	0x00, 0x00, 0x00, 0x00, // Null
	0x00, 0x00, 0x00, 0x00, // Null
	0x00, 0x00, 0x00, 0x00, // Null
	0x00, 0x00, 0x00, 0x00, // Null
	0x00, 0x00, 0x00, 0x00, // Null
	0x00, 0x00, 0x00, 0x00, // Null
	0x00, 0x00, 0x00, 0x00, // Null
	0x00, 0x00, 0x00, 0x00, // Null
	0x00, 0x00, 0x00, 0x00, // Null
	0x00, 0x00, 0x00, 0x00, // Null
	0x00, 0x00, 0x00, 0x00, // Null
	0x00, 0x00, 0x00, 0x00, // Null
	0x00, 0x00, 0x00, 0x00, // Null
	0x00, 0x00, 0x00, 0x00, // Null
	0x00, 0x00, 0x00, 0x00, // Null
	0x00, 0x00, 0x00, 0x00, // Null
	0x00, 0x00, 0x00, 0x00, // Null
// 0x20
	0x00, 0x00, 0x00, 0x00, // Null
	0x00, 0x17, 0x00, 0x00, // !
	0x03, 0x00, 0x03, 0x00, // "
	0x1F, 0x0A, 0x1F, 0x0A, // #
	0x12, 0x1F, 0x09, 0x00, // $
	0x19, 0x04, 0x13, 0x00, // %
	0x1F, 0x1F, 0x1F, 0x1F, // Don't use ampersand.
	0x00, 0x03, 0x00, 0x00, // '
	0x0E, 0x11, 0x00, 0x00, // (
	0x00, 0x11, 0x0E, 0x00, // )
	0x05, 0x02, 0x05, 0x00, // *
	0x04, 0x0E, 0x04, 0x00, // + 
	0x00, 0x10, 0x08, 0x00, // ,
	0x04, 0x04, 0x04, 0x00, // - 
	0x00, 0x10, 0x00, 0x00, // .
	0x18, 0x04, 0x03, 0x00, // /
	0x0E, 0x11, 0x0E, 0x00, // 0
	0x12, 0x1F, 0x10, 0x00, // 1
	0x11, 0x15, 0x12, 0x00, // 2
	0x15, 0x15, 0x0A, 0x00, // 3
	0x07, 0x04, 0x1F, 0x00, // 4
	0x17, 0x05, 0x1D, 0x00, // 5
	0x1F, 0x15, 0x17, 0x00, // 6
	0x01, 0x01, 0x1F, 0x00, // 7
	0x1F, 0x15, 0x1F, 0x00, // 8
	0x17, 0x15, 0x1F, 0x00, // 9 
	0x00, 0x0A, 0x00, 0x00, // :
	0x10, 0x0A, 0x00, 0x00, // ;
	0x04, 0x0A, 0x11, 0x00, // <
	0x0A, 0x0A, 0x0A, 0x00, // = 
	0x11, 0x0A, 0x04, 0x00, // > 
	0x01, 0x15, 0x02, 0x00, // ?
	
// 0x40
	0x0E, 0x17, 0x0E, 0x0A, // @ Don't use the at.
	0x1E, 0x05, 0x1E, 0x00, // A
	0x1F, 0x15, 0x0A, 0x00, // B
	0x0E, 0x11, 0x11, 0x00, // C
	0x1F, 0x11, 0x0E, 0x00, // D
	0x1F, 0x15, 0x15, 0x00, // E
	0x1F, 0x05, 0x05, 0x00, // F
	0x1F, 0x11, 0x1D, 0x00, // G
	0x1F, 0x04, 0x1F, 0x00, // H
	0x11, 0x1F, 0x11, 0x00, // I
	0x09, 0x11, 0x0F, 0x00, // J
	0x1F, 0x04, 0x1B, 0x00, // K
	0x1F, 0x10, 0x10, 0x00, // L
	0x1F, 0x06, 0x1F, 0x00, // M
	0x1F, 0x01, 0x1F, 0x00, // N
	0x0E, 0x11, 0x0E, 0x00, // O
	0x1F, 0x05, 0x02, 0x00, // P
	0x0E, 0x19, 0x1E, 0x00, // Q
	0x1F, 0x05, 0x1A, 0x00, // R
	0x12, 0x15, 0x09, 0x00, // S
	0x01, 0x1F, 0x01, 0x00, // T
	0x1F, 0x10, 0x1F, 0x00, // U
	0x0F, 0x10, 0x0F, 0x00, // V
	0x1F, 0x1C, 0x1F, 0x00, // W
	0x1B, 0x04, 0x1B, 0x00, // X
	0x03, 0x1C, 0x03, 0x00, // Y
	0x19, 0x15, 0x13, 0x00, // Z
	0x1F, 0x11, 0x11, 0x00, // [
	0x03, 0x04, 0x18, 0x00, // backslash
	0x11, 0x11, 0x1F, 0x00, // ]
	0x02, 0x01, 0x02, 0x00, // ^
	0x10, 0x10, 0x10, 0x00, // _
	
// 0x60
	0x00, 0x01, 0x02, 0x00, // `
	0x1E, 0x05, 0x1E, 0x00, // A (lowercase start)
	0x1F, 0x15, 0x0A, 0x00, // B
	0x0E, 0x11, 0x11, 0x00, // C
	0x1F, 0x11, 0x0E, 0x00, // D
	0x1F, 0x15, 0x15, 0x00, // E
	0x1F, 0x05, 0x05, 0x00, // F
	0x1F, 0x11, 0x1D, 0x00, // G
	0x1F, 0x04, 0x1F, 0x00, // H
	0x11, 0x1F, 0x11, 0x00, // I
	0x09, 0x11, 0x0F, 0x00, // J
	0x1F, 0x04, 0x1B, 0x00, // K
	0x1F, 0x10, 0x10, 0x00, // L
	0x1F, 0x06, 0x1F, 0x00, // M
	0x1F, 0x01, 0x1F, 0x00, // N
	0x0E, 0x11, 0x0E, 0x00, // O
	0x1F, 0x05, 0x02, 0x00, // P
	0x0E, 0x19, 0x1E, 0x00, // Q
	0x1F, 0x05, 0x1A, 0x00, // R
	0x12, 0x15, 0x09, 0x00, // S
	0x01, 0x1F, 0x01, 0x00, // T
	0x1F, 0x10, 0x1F, 0x00, // U
	0x0F, 0x10, 0x0F, 0x00, // V
	0x1F, 0x1C, 0x1F, 0x00, // W
	0x1B, 0x04, 0x1B, 0x00, // X
	0x03, 0x1C, 0x03, 0x00, // Y
	0x19, 0x15, 0x13, 0x00, // Z (lowercase end)
	0x0A, 0x15, 0x11, 0x00, // {
	0x00, 0x1B, 0x00, 0x00, // |
	0x11, 0x15, 0x0A, 0x00, // }
	0x02, 0x01, 0x02, 0x01, // ~
	0x00, 0x00, 0x00, 0x00
};

char get_char_section(char ltr, int section)
{
	if (ltr > 0x20)
	{
		return (ch_lookup[(4*ltr) + section]);
	}
	else
	{
		return 0x00;
	}
}

