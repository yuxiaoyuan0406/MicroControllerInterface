#ifndef __DIGITAL_H
#define __DIGITAL_H

#include "system.h"

// number to byte

static uint8_t data Digital_number[] = 
{
	0x3F,	// 0011 1111 b		0
	0x06,	// 0000 0110 b		1
	0x5B,	// 0101 1011 b		2
	0x4F,	// 0100 1111 b		3
	0x66,	// 0110 0110 b		4
	0x6D,	// 0110 1101 b		5
	0x7D,	// 0111 1101 b		6
	0x07,	// 0000 0111 b		7
	0x7F,	// 0111 1111 b		8
	0x6F,	// 0110 1111 b		9
	0x77,	// 0111 0111 b		A
	0x7C,	// 0111 1100 b		B
	0x39,	// 0011 1001 b		C
	0x5E,	// 0101 1110 b		D
	0x79,	// 0111 1001 b		E
	0x71,	// 0111 0001 b		F
};

// LED port
#define COMMON 		P2
#define DIGITAL		P0

// digital operators
#define Display_number(pos, num)	\
do{									\
	COMMON = (pos << 2);			\
	DIGITAL = Digital_number[num];	\
}while(0)

#define Display_empty(pos)			\
do{									\
	COMMON = ~(pos << 2);			\
	DIGITAL = 0;					\
}while(0)

// display function
void Display_str(char * str, uint8_t nArg);
//void Display_int(uint32_t num);

// initiate
void DigitalInit();

#endif	// !__DIGITAL_H
