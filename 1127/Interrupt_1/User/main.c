#include "system.h"
#include "interrupt.h"

int main()
{
	InterruptInit();	// 时钟中断初始化
	while(1)
	{
		;
	}
}
