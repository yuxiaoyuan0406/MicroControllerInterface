#ifndef __SYSTEM_H
#define __SYSTEM_H

//#define PERIOD_MODE

#include <STC89C5xRC.H>

typedef unsigned char	uint8_t;
typedef unsigned int	uint16_t;
typedef unsigned long	uint32_t;

// soft delay
void delay_ms(uint16_t nCount);

#endif	// !__SYSTEM_H
