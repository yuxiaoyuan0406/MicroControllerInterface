#ifndef __INTERRUPT_H
#define __INTERRUPT_H

#define TIMER_SET(trig)	\
do{						\
	ET0 = trig;			\
	TR0 = trig;			\
}while(0)

void InterruptInit();

static bit k3_flag = 0;
static bit k4_flag = 0;

#endif	// !__INTERRUPT_H
