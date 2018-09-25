#include "pch.h"
#include "CoordinateSystem.h"


CoordinateSystem::CoordinateSystem()
{
}


CoordinateSystem::~CoordinateSystem()
{
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

point operator+(const point & A, const point & B)
{
	return point({ A.x + B.x, A.y + B.y });
}

double abs(const point & A)
{
	return A.x*A.x + A.y*A.y;
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

bool operator==(const point & A, const point & B)
{
	if (A.x == B.x && A.y == B.y)
		return true;
	return false;
}

bool operator&&(const point & A, const point B)
{
	if (A == point({ 0,0 }) || B == point({ 0,0 }))
		return true;
	return false;
}
