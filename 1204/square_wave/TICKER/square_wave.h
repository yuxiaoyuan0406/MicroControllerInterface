#ifndef __SQUARE_WAVE
#define __SQUARE_WAVE

#include "system.h"

static uint16_t wave_period_us = 10;

static uint8_t high_8, low_8;

static uint8_t ticker_period;

//void setPeriod(uint16_t);

void SquareWaveInit();

#endif	//	!__SQUARE_WAVE
