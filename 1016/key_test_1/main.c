/*******************************************
 * Author	:	YuXiaoyuan
 * Email	:	yuxiaoyuan0406@qq.com
 * Date		:	2018-10-25 18:05:40
*******************************************/

#include <reg52.h>

#define LED P2

sbit key_1 = P3 ^ 0;	//����1
sbit key_2 = P3 ^ 1;	//����2

unsigned char flag;		// ��ʾģʽ���λ
						// 0	->		��
						// 1	->		��ʾģʽ1
						// 2	->		��ʾģʽ2
						// 3	->		��ʾģʽ3	->		display_3
unsigned char en;		// ʹ�ܱ��λ
						// 1 Ϊʹ��
unsigned char buff;		// ��ʾģʽ1��2�����ݻ���

//���ƺ���
//��λ��1����
unsigned char crol(unsigned char target, unsigned char i)
{
	return ~(~target << i);
}

//���ƺ���
//��λ��1����
unsigned char cror(unsigned char target, unsigned char i)
{
	return ~(~target >> i);
}

//��ʱ����
void delay(unsigned int i)
{
	for(;i;i--)
		;
}

//��ʾģʽ3
//�������ƺ����ƺ���
void display_3()
{
	unsigned char i;
	for(i = 0; i < 7; i++)		//���Ƶ�ͷ
	{
		if (flag != 3 || !en)
			return;
		LED = crol(LED, 1);
		delay(5000);
	}
	for(i = 0; i < 7; i++)		//���Ƶ�ͷ
	{
		if (flag != 3 || !en)
			return;
		LED = cror(LED, 1);
		delay(5000);
	}
}

//������
void main()
{
	IT0 = 1;		//����INT0�½��ش���
	EX0 = 1;		//ʹ��
	
	IT1 = 1;		//����INT1�½��ش���
	EX1 = 1;		//ʹ��
	
	EA 	= 1;		//�ж��ܿ���
	
	flag = 0;		/********************************/
	en = 0;			/*		��ʼ�����λ�ͻ���		*/
	buff = 0;		/********************************/
	
	LED = 0xff;		//��ʼ��P2����LED״̬
	
	while(1)		//��ѭ��
	{
		if(en)		//�ж��Ƿ�ʹ��
		{
			switch(flag)
			{
			case 1:	case 2:
				LED = ~buff;	//������ʾbuff��λȡ���Ľ��
				break;
			case 3:
				LED = 0xfe;		//��ʾģʽ3Ҫ��LED��ʼ��״̬Ϊ0xFE
				delay(5000);
				display_3();	//������ʾģʽ3
				break;
			default:
				LED = 0xff;		//�����������LED״̬��buff״̬
				buff = 0xff;
				break;
			}
			
			//��ȡ����1�Ͱ���2״̬
			if(key_1 == 0)
			{
				delay(1500);	//��ʱȥ��
				if(key_1 == 0)
				{
					flag = 1;
					buff--;
				}
			}
			else if(key_2 == 0)
			{
				delay(1500);	//��ʱȥ��
				if(key_2 == 0)
				{
					flag = 2;
					buff++;
				}
			}
		}
		else
		{
			LED = 0xff;		//���û��ʹ�ܱ���LED, buff, flag״̬
			buff = 0;
			flag = 0;
		}
	}
}

/******************************
*********�жϹ��ܶ���**********
******************************/

void display_INT0() interrupt 0		//INT0������ʾ״̬3
{
	EA = 0;						//�ر��ж��ܿ���
	delay(1500);				//��ʱȥ��
	LED = 0xff;					//���
	flag = flag == 3 ? 0 : 3;	//�޸�flag
	EA = 1;						//���¿����ж�
}

void clear_INT1() interrupt 2		//INT1����ʹ��
{
	EA = 0;				//�ر��ж��ܿ���
	delay(1500);		//��ʱȥ��
	LED = 0xff;			//���
	en = !en;			//�޸�ʹ��״̬
	EA = 1;				//���¿����ж�
}
