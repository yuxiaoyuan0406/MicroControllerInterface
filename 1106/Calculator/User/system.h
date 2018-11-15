/*********
 * File name	:	system.h
 * Author		:	Yu Xiaoyuan
 * Version		:	1.0.0
 * Date			:	2018-11-13 10:10:18
 * Description	:	useful function and type name define
 * Function list:	delay, 
**/
#ifndef __SYSTEM_H
#define __SYSTEM_H

#include <reg52.H>

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
