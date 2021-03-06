/***********************

 * Author:	Yu Xiaoyuan
 * Date:	2018-9-17 23:10:24
 * Email:	yuxiaoyuan0406@hotmail.com

 ***********************/
 //

#include "stdafx.h"
#include <cmath>

void daffodil_number(int val[])//寻找次大的水仙花数
{
	unsigned int flag = 0;
	for (int i = 100; i < 1000; i++)
	{
		int sum = pow(i / 100, 3) + pow((i / 10) % 10, 3) + pow(i % 10, 3);
		if (sum == i)
		{
			printf("daffodil number found: %d\n", i);
			val[flag] = i;
			flag++;
		}
	}
	printf("\nThe second big: %d\n", val[flag - 2]);//这里减去2就是为了寻找第二大的
}

int main()
{
	int val[1000];
	daffodil_number(val);
    return 0;
}

