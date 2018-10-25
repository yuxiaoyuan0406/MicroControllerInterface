#ifndef FUNC_H
#define FUNC_H

#include <reg52.h>

typedef unsigned int uint16;
typedef unsigned char uint8;

/*
 * ÑÓÊ±º¯Êı
 */
void delay(uint16 i);

/*
 * ×óÒÆº¯Êı
 */
uint8 crol(uint8 target, uint8 i);

/*
 * ÓÒÒÆº¯Êı
 */
uint8 cror(uint8 target, uint8 i);

#endif
