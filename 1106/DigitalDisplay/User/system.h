#ifndef __SYSTEM_H
#define __SYSTEM_H

#include <reg52.h>

// int define
#define uint8_t		unsigned char
#define uint16_t	unsigned int
#define uint32_t	unsigned long

// soft delay
void delay(uint16_t nCount);

#define SOFT_DELAY		delay(0xFFFF)

#endif // !__SYSTEM_H
