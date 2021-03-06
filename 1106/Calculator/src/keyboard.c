#include "keyboard.h"

// key matrix scan function
uint8_t scan_col(uint8_t col)		// ��ɨ��
{
	switch(col)
	{
		case 0:
			KEY_MAT = ~0x8;		// ~0000 1000
			break;
		case 1:
			KEY_MAT = ~0x4;		// ~0000 0100
			break;
		case 2:
			KEY_MAT = ~0x2;		// ~0000 0010
			break;
		case 3:
			KEY_MAT = ~0x1;		// ~0000 0001
			break;
		default:
			return 0;
	}
	delay(0x03);
	if((~KEY_MAT) & 0x80)				// 1000 0000
	{
		while((~KEY_MAT) & 0x80)
			;
		return 1;
	}
	else if((~KEY_MAT) & 0x40)			// 0100 0000
	{
		while((~KEY_MAT) & 0x40)
			;
		return 2;
	}
	else if((~KEY_MAT) & 0x20)			// 0010 0000
	{
		while((~KEY_MAT) & 0x20)
			;
		return 3;
	}
	else if((~KEY_MAT) & 0x10)			// 0001 0000
	{
		while((~KEY_MAT) & 0x10)
			;
		return 4;
	}
	else
		return 0;
}

// keyboard initiate
void KeyboardInit()
{
	KEY_MAT = 0x00;
}
