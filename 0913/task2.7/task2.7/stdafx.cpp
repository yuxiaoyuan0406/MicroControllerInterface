/***********************

 * Author:	Yu Xiaoyuan
 * Date:	2018-9-17 23:10:24
 * Email:	yuxiaoyuan0406@hotmail.com

 ***********************/
// stdafx.cpp : 只包括标准包含文件的源文件
// task2.7.pch 将作为预编译标头
// stdafx.obj 将包含预编译类型信息

#include "stdafx.h"

// TODO: 在 STDAFX.H 中引用任何所需的附加头文件，
//而不是在此文件中引用
using namespace std;

int findMax(const int argn, const int *val)
{
	int max = val[0];
	for (int i = 0; i < argn; i++)
	{
		if (val[i] > max)
		{
			max = val[i];
		}
	}
	return max;
}

int findMin(const int argn, const int *val)
{
	int min = val[0];
	for (int i = 0; i < argn; i++)
	{
		if (val[i] < min)
		{
			min = val[i];
		}
	}
	return min;
}

int reline
(
	const int argn,
	const int *val,
	int *lined
)
{
	int count = 0;
	int min;
	lined[0] = findMin(argn, val);
	while (lined[count] < findMax(argn, val))
	{
		min = findMax(argn, val);
		for (int i = 0; i < argn; i++)
		{
			if (val[i] > lined[count])
			{
				if (val[i] < min)
				{
					min = val[i];
				}
			}
		}
		count++;
		lined[count] = min;
	}
	for (int i = 0; i < count; i++)
	{
		cout << lined[i] << ", ";
	}
	cout << endl;
	return count;
}

void sort(const int argn, const int * val, const int * lined, int * code)
{
	for (int i = 0; i < argn; i++)
	{
		int j;
		for (j = 0; val[i] != lined[j]; j++);
		code[i] = j + 1;
	}
}
