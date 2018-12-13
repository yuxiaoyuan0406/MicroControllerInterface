#include "digital.h"

volatile ticker_union ticker_1;

extern uint8_t display_buff[];

#define TICKER_1_SET_US(t)	ticker_1.value = 0x10008 - (t >> 1)

#define CLEAR()			\
	COMMON = 0x7 << 2;	\
	DIGITAL = 0x00
	
// initiate
void DigitalInit()
{
	CLEAR();
	
	TMOD |= 0x10;
	TH1 = 0xff;
	TL1 = 0xff;
	EA = 1;
	ET1 = 1;
	TR1 = 1;
	
	TICKER_1_SET_US(1250);
}

void timer1() interrupt 3
{
	static uint8_t pos = 0;
	TL1 = ticker_1.T[1];
	TH1 = ticker_1.T[0];
	CLEAR();
	if(display_buff[pos] != '\0')
	{
		Display_number(7 - pos, display_buff[pos] - '0');
	}
	else
	{
		pos = 0;
		return;
	}
	pos = (++pos) % 8;
}
