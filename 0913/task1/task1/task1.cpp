/***********************

 * Author:	Yu Xiaoyuan
 * Date:	2018-9-17 23:10:24
 * Email:	yuxiaoyuan0406@hotmail.com

 ***********************/

#include "stdafx.h"

double sumCal(int n)//调和数列求和
{
	double sum = 0;
	for (int i = 1; i <= n; i++)
	{
		sum += 1.0 / i;
	}
	return sum;
}

long unsigned int fact(unsigned int n)//求阶乘
{
//	long unsigned int val = 1;
	if (n == 1)
		return 1;
	else
		return n * fact(n - 1);
//	return val;
}

bool fun(int k)//判断素数，是素数返回true
{
	for (int i = 2; i < k-1; i++)
	{
		if (k % i == 0)
			return false;
	}
	return true;
}

int main()
{
	/*
	int n;
	printf("Input n:");
	scanf_s("%d", &n);
	printf("sum:\n%f\n", sumCal(n));
	printf("fact:\n%d\n", fact(n));
	getchar();
	*/
	int sum = 0,
		count = 0;
	double average = 0;
	for (int i = 2; i < 1000; i++)
	{
		if (fun(i))
		{
			sum += i;
			count++;
		}
	}
	average = double(sum) / double(count);
	printf("average = %f\n", average);
    return 0;
}

