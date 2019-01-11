#include "system.h"
#include "digital.h"
#include "interrupt.h"
#include <stdio.h>

uint8_t display_buff[9] = "\0";		// 显示用的缓存, 初始化为空字符串

uint32_t measurement_buff[BUFF_LENGTH] = {0};	// 存放测量值的缓存, 初始化全部为0

uint16_t average(const uint32_t *, uint8_t);	// 求平均值的函数, 传入数组和长度

int main()
{
	uint32_t ave;	// 声明储存平均值的变量
	
	DigitalInit();	// 初始化
	InterruptInit();
	
	while(1)		// 主功能函数
	{
		ave = average(
			measurement_buff, 
			BUFF_LENGTH);	// 求平均
		sprintf(display_buff, "%ld", ave);	
							// 平均值输出到显示缓存数组
		delay_ms(500);		// 延时500ms
	}
}

uint16_t average(const uint32_t *input, uint8_t length)
{
	uint32_t val = 0;	// 声明求平均用的变量
	uint8_t i;			// 声明循环求和用的变量
	for(i = 0; i < length; i++)
	{
		val += input[i];// 求和
	}
	return val/length;	// 返回平均值
}
