// task2.2.cpp: 定义控制台应用程序的入口点。
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

