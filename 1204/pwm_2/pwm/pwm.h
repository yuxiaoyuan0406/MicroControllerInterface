#ifndef __PWM_H
#define __PWM_H

#include "system.h"

static uint16_t pwm_period_us;
static uint8_t ticker_period;

static uint8_t pwm_width;
static uint8_t ticker_counter;

void setPeriod(uint16_t);

void setWidth(uint8_t);

void PwmInit();

#endif	// ! __PWM_H
