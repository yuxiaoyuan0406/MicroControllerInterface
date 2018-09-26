#include "pch.h"
#include "CoordinateSystem.h"


CoordinateSystem::CoordinateSystem()
{
}


CoordinateSystem::~CoordinateSystem()
{
}

std::ostream & operator<<(std::ostream & out, const point & A)
{
	out << "(" << A.x << ", " << A.y << ")";
	return out;
}

std::istream & operator>>(std::istream & in, point & A)
{
	using namespace std;
	string buff;
	getline(in, buff);
	string _X = buff.substr(buff.find('(') + 1, buff.find(',') - buff.find('(') - 1);
	string _Y = buff.substr(buff.find(',') + 1, buff.find(')') - buff.find(',') - 1);
	A.x = atof(_X.c_str());
	A.y = atof(_Y.c_str());
	return in;
}

double delta_x(const point & A, const point & B)
{
	return B.x - A.x;
}

double delta_y(const point & A, const point & B)
{
	return B.y - A.y;
}

point operator-(const point & A, const point & B)
{
	return point({ -delta_x(A,B), -delta_y(A,B) });
}

point operator-(const point & A)
{
	return -1.0 * A;
}

point operator+(const point & A, const point & B)
{
	return point({ A.x + B.x, A.y + B.y });
}

double abs(const point & A)
{
	return sqrt(A.x*A.x + A.y*A.y);
}

double slope(const point & A, const point & B)
{
	if (delta_x(A, B) == 0)
	{
		return DBL_MAX;
		//横坐标差为0, 斜率无穷大
	}
	else
	{
		return delta_y(A, B) / delta_x(A, B);
	}
}

double operator*(const point & A, const point & B)
{
	return A.x * B.x + A.y * B.y;
}

bool operator==(const point & A, const point & B)
{
	if (abs(A.x - B.x) <= 5 * DBL_MIN && abs(A.y - B.y) <= 5 * DBL_MIN)
		return true;
	return false;
}

bool operator&&(const point & A, const point & B)
{
	double x = A * B,
		y = abs(A) * abs(B);
	if (A*B == abs(A)*abs(B))
		return true;
	return false;
}

bool operator||(const point & A, const point & B)
{
	if ((A && B) || ((-A) && B))
		return true;
	return false;
}

point operator*(const double & x, const point & A)
{
	return point({ x*A.x, x*A.y });
}

int DEBUG()
{
	using namespace std;
	point A, B;
	
	cout << "Input 2 points: ";
	cin >> A >> B;
	
	//A = { 1.234, 8.987 };
	//B = 1.67807 * (-A);
	cout << "Got point: \n";
	cout << "A" << A << endl;
	cout << "B" << B << endl;
	cout << "delta(x) = " << delta_x(A, B) << endl;
	cout << "delta(y) = " << delta_y(A, B) << endl;
	cout << "OA - OB = " << A - B << endl;
	cout << "OA + OB = " << A + B << endl;
	cout << "|OA| = " << abs(A) << endl;
	cout << "|OB| = " << abs(B) << endl;
	cout << "|AB| = " << abs(A - B) << endl;
	cout << "k(AB) = " << slope(A, B) << endl;
	cout << "OA * OB = " << A * B << endl;
	cout << "para " << (A || B) << endl;

	return 0;
}
