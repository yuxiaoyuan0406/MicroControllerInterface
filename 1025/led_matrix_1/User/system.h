#ifndef __SYSTEM_H
#define __SYSTEM_H

#include <reg52.h>

// int define
#define uint8_t		unsigned char
#define uint16_t	unsigned int
#define uint32_t	unsigned long
//typedef unsigned char	uint8_t;
//typedef unsigned int	uint16_t;
//typedef unsigned long	uint32;

// soft delay
void delay(uint16_t nCount);

#define		SOFT_DELAY()		delay(0xFFFF)

#endif // !__SYSTEM_H
