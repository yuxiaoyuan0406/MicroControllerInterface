// task2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"

int main()
{
	using namespace std;
	orderSystem mySys(4, 8, 3);
	return mySys.system_begin(cout, cin);
}

