#include "system.h"
#include "uart.h"
#include "interrupt.h"

#define led P2

void main()
{
	led = ~0x01;
	
	UART_init();  //	´®¿Ú³õÊ¼»¯
	InterruptInit();
	while(1)
	{
		P0 = 0xff;
		delay_ms(250);
		P0 = 0x00;
		delay_ms(250);
	}
}
