// task2.6.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

using namespace std;

int main()
{
	unsigned int
		capital,
		lower,
		numbers,
		space,
		other;

	const char article[3][80]=
	{
		"This is a cpp program from Yu Xiaoyuan. ",
		"Time 2018-9-15 16:21:57. ",
		"This is the homework of Computer Interface. ",
	};
	count(article, capital, lower, numbers, space, other);
	
	for (int i = 0; i < 3; i++)
		cout << article[i] << endl;

	cout << "capital\t" << capital << endl
		<< "lower\t" << lower << endl
		<< "numbers\t" << numbers << endl
		<< "space\t" << space << endl
		<< "others\t" << other << endl;

    return 0;
}

