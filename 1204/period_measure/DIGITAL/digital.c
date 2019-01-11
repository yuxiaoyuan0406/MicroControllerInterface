#include "digital.h"

// 定义联合体, 易便的
volatile ticker_union ticker_1;

// 显示用的缓存, 字符串, 在别处定义
extern uint8_t display_buff[];

// 设置定时计数器1的时间
// 这里的参量都是经验值
#define TICKER_1_SET_US(t)	ticker_1.value = 0x10008 - (t >> 1)

// 清屏
#define CLEAR()			\
	COMMON = 0x7 << 2;	\
	DIGITAL = 0x00
	
// initiate
void DigitalInit()
{
	CLEAR();		// 先清屏
	
	TMOD |= 0x10;	// 设置定时计数器1工作方式
	TH1 = 0xff;		// 设置定时计数器1数值
	TL1 = 0xff;
	EA = 1;			// 开启中断
	ET1 = 1;		// 接收定时计数器1中断信号
	TR1 = 1;		// 定时计数器开始工作
	
	TICKER_1_SET_US(1250);		// 设置周期为1250us
}

// 定时计数器中断服务函数
void timer1() interrupt 3
{
	static uint8_t pos = 0;		// 用于储存显示哪一位
	TL1 = ticker_1.T[1];		// 定时计数器复位
	TH1 = ticker_1.T[0];
	CLEAR();					// 清屏
	if(display_buff[pos] != '\0')	// 只要需要显示的这一位不是'\0'
	{								// 那么显示这一位的数, 左对齐
		Display_number(7 - pos, display_buff[pos] - '0');
	}
	else			// 如果发现要显示的位是'\0'
	{				// 说明字符串走到头了
		pos = 0;	// 重头再来
		return;		// 结束函数, pos不变
	}
	pos = (++pos) % 8;	// 为了显示下一位和不溢出, 自加一并用8整除
}
