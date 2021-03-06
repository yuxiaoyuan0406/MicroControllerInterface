//Author:	Yu Xiaoyuan
//Date:		2018-9-25 23:27:42
//Email:	yuxiaoyuan0406@hotmail.com

#include "pch.h"

#define SPACE(a) for(int i = 0; i<a; i++) cout << ' '

int main()
{
	//DEBUG();
	using namespace std;
	unsigned int r, c;
	cout << "input rows and crolls: " << endl;;
	cin >> r >> c;
	c *= 2;

	point A, B;
	cout << "input A & B: ";
	cin >> A >> B;
	//cout << "inpyt B:" << endl;
	//cin >> B;
	cout << "A" << A << endl
		<< "B" << B << endl;

	if (
		(A.x < 0) || (A.x > c) ||
		(A.y < 0) || (A.y > r) ||
		(B.x < 0) || (B.x > c) ||
		(B.y < 0) || (B.y > r)
		)
	{
		cout << "input error" << endl;
		return -1;
	}

	point AB = B - A;
	
	cout << "+";
	SPACE(c);
	cout << "+" << endl;

	point C = { 0,r };
	for (int i = 0; i < r; i++)
	{
		cout << ' ';
		for (int j = 0; j < c; j++)
		{
			point AC = C - A;
			if ((AC && AB) && (abs(AC) <= abs(AB)))
				cout << '*';
			else
				cout << ' ';
			C.x += 0.5;
		}
		C.x = 0;
		C.y--;
		cout << endl;
	}

	cout << "+";
	SPACE(c);
	cout << "+" << endl;

	return 0;
}
