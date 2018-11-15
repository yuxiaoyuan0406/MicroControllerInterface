/*********
 * File name	:	keyboard.h
 * Author		:	Yu Xiaoyuan
 * Version		:	2.0.0
 * Date			:	2018-11-13 10:19:02
 * Description	:	key matrix driver library
 * Function list:	KeyboardInit, scan_row
**/
#ifndef __KEYBOARD_H
#define __KEYBOARD_H

#include "system.h"

// keyboard port
#define		KEY_MAT		P1

// keyboard initiate
void KeyboardInit();

/**
	key matrix scan function
 * 
_____________________________________________ 
|											|
|			col-0	col-1	col-2	col-3	|
|											|
|	row-1	S1		S2		S3		S4		|
|											|
|	row-2	S5		S6		S7		S8		|
|											|
|	row-3	S9		S10		S11		S12		|
|											|
|	row-4	S13		S14		S15		S16		|
|___________________________________________|

 * @param	unsigned char row		:	row number, 0 ~ 3
 * @return	unsigned char			:	col number, 1 ~ 4
 **/
uint8_t scan_col(uint8_t col);

#endif	// !__KEYBOARD_H
