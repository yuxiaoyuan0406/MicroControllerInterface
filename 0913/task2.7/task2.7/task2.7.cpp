// task2.7.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

int main()
{
	const int val[] =
	{
		3,8,13,15,98,14,76,25,12,15,
		25,12,98,13,46,72,12,1,2,28,
		96,74,38,94,25,12,23,13,4,9,
	};
	int rearenged[30],
		code[30];
	reline(30, val, rearenged);
	sort(30, val, rearenged, code);

	printf("val: \n");
	for (int i = 0; i < 30; i++)
		printf("%d\t",val[i]);
	printf("\n");

	printf("code: \n");
	for (int i = 0; i < 30; i++)
		printf("%d\t", code[i]);
	printf("\n");
	return 0;
}
