/***********************

 * Author:	Yu Xiaoyuan
 * Date:	2018-9-19 17:28:03
 * Email:	yuxiaoyuan0406@hotmail.com

 ***********************/
 // task1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"

using namespace std;

int main()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cout << j + 1 << " * " << i + 1 << " = " << (j + 1)*(i + 1) << "\t";
		}
		cout << endl;
	}
}

