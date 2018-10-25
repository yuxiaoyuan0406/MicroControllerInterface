#ifndef FUNC_H
#define FUNC_H

#include <reg52.h>

typedef unsigned int uint16;
typedef unsigned char uint8;

/*
 * ��ʱ����
 */
void delay(uint16 i);

/*
 * ���ƺ���
 */
uint8 crol(uint8 target, uint8 i);

/*
 * ���ƺ���
 */
uint8 cror(uint8 target, uint8 i);

#endif
