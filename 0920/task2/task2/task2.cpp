// task2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"

int main()
{
	orderSystem mySys(4, 8, 3);							//声明了一个订票系统
														//四班航班, 第一班八点, 间隔3小时
	return mySys.system_begin(std::cout, std::cin);		//启动系统
}

