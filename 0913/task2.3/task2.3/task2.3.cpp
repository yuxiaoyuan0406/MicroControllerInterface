/***********************

 * Author:	Yu Xiaoyuan
 * Date:	2018-9-17 23:10:24
 * Email:	yuxiaoyuan0406@hotmail.com

 ***********************/
 //

#include "stdafx.h"

int val[4][4];

void fun1()//对角线求和
{
	int sum = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (i == j || i + j == 3)//对角线判断条件: 下标相等或者相加为3
				sum += val[i][j];
		}
	}
	printf("fun1\nsum = %d\n", sum);
}

void fun2()//偶数下标求积
{
	int product = 1;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (i == j || i + j == 3)
				if (i % 2 == 0 && j % 2 == 0)
					product *= val[i][j];
		}
	}
	printf("fun2\nproduct = %d\n", product);
}

void fun3()//寻找对角线上最大值并输出位置
{
	int max = val[0][0];
	int max_1 = 0, 
		max_2 = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (i == j || i + j == 3)
				if (val[i][j] > max)
				{
					max = val[i][j];
					max_1 = i;
					max_2 = j;
				}
		}
	}
	printf("fun3\nmaxium at (%d,%d), value to %d\n", max_1, max_2, max);
}

int main()
{
	for (int i = 0; i < 4; i++)
	{
		printf("input %d roll\n", i + 1);
		scanf_s("%d %d %d %d", val[i], val[i] + 1, val[i] + 2, val[i] + 3);
	}
	fun1();
	fun2();
	fun3();
    return 0;
}

