#include "system.h"
#include "square_wave.h"

extern ticker_union ticker_0;

int main()
{
	uint8_t i;
	
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
