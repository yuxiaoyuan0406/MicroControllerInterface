#include "matrix.h"

// HC595 function
void BufferSendData(uint8_t SendVal)
{
	uint8_t i;
	for(i = 0; i < 8; i++) 
	{
		if(SendVal & (0x80 >> i))
			Out=1;
		else
			Out=0;

		//产生数据移位信号
		S_CLK=0;
		BUFFER_DELAY();
		S_CLK=1;
	}
}

// display
void Display_figure(uint8_t * fig)
{
	uint8_t pos;
	for(pos = 0; pos < 8; pos++)
	{
		DISABLE_BUFFER();
		BufferSendData(fig[pos]);
		ENABLE_ROW(pos);
		ENABLE_BUFFER();
//		delay(0xf);
	}
}

// initiate
void MatrixInit()
{
	DISABLE_ROW();
	DISABLE_BUFFER();
}
