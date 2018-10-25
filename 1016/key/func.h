#ifndef FUNC_H
#define FUNC_H

#include <reg52.h>

#define LED P2

typedef unsigned int uint16;
typedef unsigned char uint8;

/*
 * 延时函数
 */
void delay(uint16 i);

/*
 * 左移函数
 */
uint8 crol(uint8 target, uint8 i);

/*
 * 右移函数
 */
uint8 cror(uint8 target, uint8 i);

/*
 * 效果1
 */
void display_1();

void setup();

#endif
