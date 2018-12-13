#ifndef __SQUARE_WAVE
#define __SQUARE_WAVE

#include "system.h"

typedef union {
	uint16_t value;
	uint8_t T[2];
} ticker_union;

static uint16_t wave_period_us;

void setPeriod(uint16_t);

void SquareWaveInit();

#endif	//	!__SQUARE_WAVE
