#include "system.h"
#include "interrupt.h"

// 宏定义的定时计数器0复位
#define TICKER_RESET()	\
	TH0 = 0;			\
	TL0 = 0

static uint8_t measurement_flag;	// 这个变量记录了写入测量值在测量缓存数组中的位置

extern uint32_t measurement_buff[];	// 测量缓存数组, 在别处定义

uint8_t overflow_flag;		// 定时计数器溢出时的标记位
	// 考虑到定时计数器周期小于方波的周期
	// 那么在一个方波周期内定时计数器会触发中断
	// 使用溢出标记位的方式可以增加测量范围

// initiate
void InterruptInit()
{
	measurement_flag = 0;	// 初始化测量值的写入标记位
	overflow_flag = 0;		// 初始化定时计数器溢出标记位
	
	IT0 = 1;		//设置INT0下降沿触发
	EX0 = 1;		//使能
	P32 = 1;		//设置引脚默认上拉
	
	TMOD |= 0x01;			// 设置定时器工作模式
	TICKER_RESET();
	ET0 = 1;				// 开启定时器0工作
	TR0 = 1;				// 使用TCON寄存器
	
	EA 	= 1;		//中断总开关
}

void K3() interrupt 0	// 外部中断0, P32端口
{
	uint8_t * buff;		// 写入用的指针
	
	buff = (uint8_t *)(measurement_buff + measurement_flag);
	// measurement_buff是32位无符号数数组
	// 加measurement_flag后表示的是存放当前测量值在数组中的位置
	// 强制转化为8位指针, 可以把32位数当做一个长度为4字节的8位数数组来使用
	
	*buff = TL0;		
	// 直接寻址buff表示的是measurement_buff[measurement_flag]的0~7位
	*(buff+1) = TH0;
	// 寻址buff+1表示的是是measurement_buff[measurement_flag]的8~15位
	*(buff+2) = overflow_flag;
	// 寻址buff+2表示的是是measurement_buff[measurement_flag]的16~23位
	
	overflow_flag = 0;	// 定时计数器溢出标记位每次读取结束后要清零
	
	measurement_flag++;	// 写完数组一个单元后要自加一
	measurement_flag %= BUFF_LENGTH;	// 防止超过数组长度, 取模
	
	TICKER_RESET();		// 定时计数器清零, 这样少做步减法
}

void timer0() interrupt 1	// T0
{
	TICKER_RESET();			// 调用宏来初始化定时计数器
	overflow_flag++;		// 进入中断说明已经溢出, 溢出标记位需加一
}
