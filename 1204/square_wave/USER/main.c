#include "system.h"
#include "square_wave.h"

int main()
{
	SquareWaveInit();
//	setPeriod(60);
	high_8 = 0xff;
	low_8 = 0x0f;
	while(1);
}
