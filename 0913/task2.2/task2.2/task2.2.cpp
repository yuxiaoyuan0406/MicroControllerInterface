/***********************

 * Author:	Yu Xiaoyuan
 * Date:	2018-9-17 23:10:24
 * Email:	yuxiaoyuan0406@hotmail.com

 ***********************/
 //

#include "stdafx.h"


int main()
{
	int val;
	printf("Required a input:");
	scanf_s("%d", &val);
	for (int i = 0; val % 10 != 0 || val / 10 != 0; i++)//从个位开始逐个取出每一位上的数
	{
		printf("10^%d\t%d\n", i, val % 10);
		val /= 10;
	}
    return 0;
}

