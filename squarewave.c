#include <reg52.H>
//#include <absacc.h>

#define TICKER_0_RESET_US(t)			\
	TH0 = (0xFFFF - t + 5) >> 8;		\
	TL0 = (0xFFFF - t + 5) & 0xFF

#define TICKER_0_RESET()	\
	TH0 = high_8;			\
	TL0 = low_8

typedef unsigned char	uint8_t;
typedef unsigned int	uint16_t;
typedef unsigned long	uint32_t;

// soft delay
void delay_ms(uint16_t nCount);

typedef union {
	uint16_t value;
	uint8_t T[2];
} ticker_union;

static uint16_t wave_period_us;

void setPeriod(uint16_t);

void SquareWaveInit();

volatile ticker_union ticker_0;

int main()
{
	uint16_t i;
	
	SquareWaveInit();
//	setPeriod(60);

	while(1)
	{
		for(i = 28; i < 20000; i = i + 2)
		{
			setPeriod(i);
			delay_ms(15);
		}
		
		for(i = 20000; i > 28; i = i - 2)
		{
			setPeriod(i);
			delay_ms(15);
		}
	}
}

void delay_ms(uint16_t nCount)
{
	uint16_t i;
	for(; nCount; nCount--)
		for(i = 0; i < 123; i++)
			;
}

/**	方波初始化
 */
void SquareWaveInit()
{
	TMOD = 0x01;
	TH0 = 0xFF;
	TL0 = 0xFF;
	EA = 1;
	ET0 = 1;
	TR0 = 1;
}

/** 设置方波周期
 *	单位: 微秒
 */
void setPeriod(uint16_t period)
{
//	EA = 0;
	wave_period_us = period;
	ticker_0.value = 0x10008 - (period >> 1);	// 经过计算在这种情况下设置单位为微秒

//	EA = 1;
}

/**	定时计数器0服务函数
 */
void timer0() interrupt 1
{
	TL0 = ticker_0.T[1];
	TH0 = ticker_0.T[0];
	P2 = ~P2;
}

