#ifndef __UART_H
#define __UART_H

#include "system.h"

static uint8_t receiveData;
static uint8_t sendBuff;

void UART_init();

void UART_send_byte(uint8_t dat);

#endif	//	! __UART_H
