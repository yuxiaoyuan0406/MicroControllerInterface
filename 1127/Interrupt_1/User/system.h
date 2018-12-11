#ifndef __SYSTEM_H
#define __SYSTEM_H

#include <STC89C5xRC.H>

sbit led = P2 ^ 0;

typedef unsigned char	uint8_t;
typedef unsigned int	uint16_t;
typedef unsigned long	uint32_t;

// soft delay
void delay_ms(uint16_t nCount);

#endif	// !__SYSTEM_H
