// task2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"

int main()
{
	using namespace std;
	/*flight _747(8);
	_747.rename(B);
	_747.orderSeat(1);
	_747.orderSeat(7);
	_747.printBoardingPass();
	cout << _747;
	*/
	
	orderSystem mySys(4, 8, 3);
	mySys.bookSeat(cout, cin);
	
	/*
	int i;
	cin >> i;
	cout << i << endl;
	*/
}

