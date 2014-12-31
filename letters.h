/*

Infosys Letter Section Lookup
Michael J Moffitt 2014

*/
#ifndef LETTERS_H
#define LETTERS_H

#define LETTER_WIDTH 4

extern char ch_lookup[1024];

// Pull in a given column from a given character
char get_char_section(char letter, int section);

#endif
