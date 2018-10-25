#include <reg52.h>

#define row P0	//ÐÐ
#define col P2	//ÁÐ

unsigned char graph1[] = 
{
	0xfe,
	0xfd,
	0xfb,
	0xf7,
	0xef,
	0xdf,
	0xbf,
	0x7f,
};

void delay(unsigned int i)
{
	for(; i; i--)
		;
}

void main()
{
	unsigned char i;
	row = 0x0;
	//col = 0xfe;
	while(1)
	{
		for(i = 0; i < 8; i++)
		{
			row = (row<<1);
			col = graph1[i];
			delay(5000);
		}
		row = 0xfe;
	}
}
