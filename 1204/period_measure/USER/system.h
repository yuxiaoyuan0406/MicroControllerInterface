#ifndef __SYSTEM_H
#define __SYSTEM_H

//#define PERIOD_MODE

#include <STC89C5xRC.H>
#include <absacc.h>

typedef unsigned char	uint8_t;
typedef unsigned int	uint16_t;
typedef unsigned long	uint32_t;

// soft delay
void delay_ms(uint16_t nCount);

//void delay(uint16_t nCount);

typedef union {
	uint16_t value;
	uint8_t T[2];
} ticker_union;

#endif	// !__SYSTEM_H
