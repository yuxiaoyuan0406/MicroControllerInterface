// stdafx.cpp : 只包括标准包含文件的源文件
// task2.6.pch 将作为预编译标头
// stdafx.obj 将包含预编译类型信息
/***********************

 * Author:	Yu Xiaoyuan
 * Date:	2018-9-17 23:10:24
 * Email:	yuxiaoyuan0406@hotmail.com

 ***********************/

#include "stdafx.h"

// TODO: 在 STDAFX.H 中引用任何所需的附加头文件，
//而不是在此文件中引用
void count
(
	const char words[3][80],
	unsigned int &capital,
	unsigned int &lower,
	unsigned int &numbers,
	unsigned int &space,
	unsigned int &other
)
{
	capital = lower = numbers = space = other = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 80; j++)
		{
			if (words[i][j] >= 'A' && words[i][j] <= 'Z')
				capital++;
			else if (words[i][j] >= 'a' && words[i][j] <= 'z')
				lower++;
			else if (words[i][j] >= '0' && words[i][j] <= '9')
				numbers++;
			else if (words[i][j] == ' ')
				space++;
			else if (words[i][j] != NULL)
				other++;
		}
	}
}

