#ifndef __PWM_H
#define __PWM_H

#include "system.h"

void PwmInit();

void Pwm_period_us(uint16_t T);

void Pwm_pulse_width_us(uint16_t w);

#endif	// ! __PWM_H
