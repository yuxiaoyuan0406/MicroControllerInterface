/***********************

 * Author:	Yu Xiaoyuan
 * Date:	2018-9-17 23:10:24
 * Email:	yuxiaoyuan0406@hotmail.com

 ***********************/

#include "stdafx.h"

 //调和数列求和
double sumCal(int n)
{
	double sum = 0;
	for (int i = 1; i <= n; i++)
	{
		sum += 1.0 / i;
	}
	return sum;
}

//求阶乘
long unsigned int fact(unsigned int n)
{
//	long unsigned int val = 1;
	if (n == 1)
		return 1;
	else
		return n * fact(n - 1);
//	return val;
}

//判断素数，是素数返回true
bool fun(int k)
{
	for (int i = 2; i < k-1; i++)
	{
		if (k % i == 0)
			return false;
	}
	return true;
}

//第三题
void mission3()
{
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
}

//第四题
//输入参量val为储存输入数据的起始地址
//参数valn为输入参数的个数
//参数row为输出数据到屏幕时每行显示的个数
void mission4(int *val, const int valn, const int row)
{
	double average = 0;
	for (int i = 0; i < valn; i++)
	{
		printf("input number %d:\n", i + 1);
		scanf_s("%d", val + i);
		average += val[i];
	}
	average /= double(valn);
	printf("inputs:\n");
	for (int i = 0; i <valn; i += row)
	{
		for (int j = 0; j < row && i + j < valn; j++)
		{
			printf("%d\t", val[i + j]);
		}
		printf("\n");
	}
	printf("average = %f\n", average);
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

	/*
	mission3();
	*/
	const int valn = 10;
	int val[valn];
	mission4(val, valn, 7);

	return 0;
}

