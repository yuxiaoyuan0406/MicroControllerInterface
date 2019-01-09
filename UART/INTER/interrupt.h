#ifndef __INTERRUPT_H
#define __INTERRUPT_H

#include "system.h"

void InterruptInit();

static uint8_t buff = 0x01;
static bit buff_change = 0;

#endif	// !__INTERRUPT_H
