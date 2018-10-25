/*******************************************
 * Author	:	YuXiaoyuan
 * Email	:	yuxiaoyuan0406@qq.com
 * Date		:	2018-10-25 18:05:40
*******************************************/

#include <reg52.h>

#define LED P2

sbit key_1 = P3 ^ 0;	//按键1
sbit key_2 = P3 ^ 1;	//按键2

unsigned char flag;		// 显示模式标记位
						// 0	->		无
						// 1	->		显示模式1
						// 2	->		显示模式2
						// 3	->		显示模式3	->		display_3
unsigned char en;		// 使能标记位
						// 1 为使能
unsigned char buff;		// 显示模式1和2的数据缓存

//左移函数
//空位用1补齐
unsigned char crol(unsigned char target, unsigned char i)
{
	return ~(~target << i);
}

//右移函数
//空位用1补齐
unsigned char cror(unsigned char target, unsigned char i)
{
	return ~(~target >> i);
}

//延时函数
void delay(unsigned int i)
{
	for(;i;i--)
		;
}

//显示模式3
//调用左移和右移函数
void display_3()
{
	unsigned char i;
	for(i = 0; i < 7; i++)		//左移到头
	{
		if (flag != 3 || !en)
			return;
		LED = crol(LED, 1);
		delay(5000);
	}
	for(i = 0; i < 7; i++)		//右移到头
	{
		if (flag != 3 || !en)
			return;
		LED = cror(LED, 1);
		delay(5000);
	}
}

//主函数
void main()
{
	IT0 = 1;		//设置INT0下降沿触发
	EX0 = 1;		//使能
	
	IT1 = 1;		//设置INT1下降沿触发
	EX1 = 1;		//使能
	
	EA 	= 1;		//中断总开关
	
	flag = 0;		/********************************/
	en = 0;			/*		初始化标记位和缓存		*/
	buff = 0;		/********************************/
	
	LED = 0xff;		//初始化P2所有LED状态
	
	while(1)		//总循环
	{
		if(en)		//判断是否使能
		{
			switch(flag)
			{
			case 1:	case 2:
				LED = ~buff;	//总是显示buff按位取反的结果
				break;
			case 3:
				LED = 0xfe;		//显示模式3要求LED初始化状态为0xFE
				delay(5000);
				display_3();	//调用显示模式3
				break;
			default:
				LED = 0xff;		//其他情况保持LED状态和buff状态
				buff = 0xff;
				break;
			}
			
			//读取按键1和按键2状态
			if(key_1 == 0)
			{
				delay(1500);	//延时去抖
				if(key_1 == 0)
				{
					flag = 1;
					buff--;
				}
			}
			else if(key_2 == 0)
			{
				delay(1500);	//延时去抖
				if(key_2 == 0)
				{
					flag = 2;
					buff++;
				}
			}
		}
		else
		{
			LED = 0xff;		//如果没有使能保持LED, buff, flag状态
			buff = 0;
			flag = 0;
		}
	}
}

/******************************
*********中断功能定义**********
******************************/

void display_INT0() interrupt 0		//INT0主管显示状态3
{
	EA = 0;						//关闭中断总开关
	delay(1500);				//延时去抖
	LED = 0xff;					//灭灯
	flag = flag == 3 ? 0 : 3;	//修改flag
	EA = 1;						//重新开启中断
}

void clear_INT1() interrupt 2		//INT1主管使能
{
	EA = 0;				//关闭中断总开关
	delay(1500);		//延时去抖
	LED = 0xff;			//灭灯
	en = !en;			//修改使能状态
	EA = 1;				//重新开启中断
}
