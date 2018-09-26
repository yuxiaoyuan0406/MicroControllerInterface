#pragma once
#include <iostream>
#include <cmath>

struct point
{
	double x;
	double y;
};

//using namespace std;
//输出一个点
std::ostream & operator<<(std::ostream & out, const point & A);

//返回横坐标差值, 后减去前
double delta_x(const point & A, const point & B);

//返回纵坐标差值, 后减去前
double delta_y(const point & A, const point & B);

//返回这两个向量的差向量
//向量和点的表示方式一样
point operator-(const point & A, const point & B);

//返回这两个向量的和向量
point operator+(const point & A, const point & B);

//返回向量的模
//可以用来计算两点之间距离
double abs(const point & A);

//返回两点斜率
double slope(const point & A, const point & B);

//返回向量内积
double operator*(const point & A, const point & B);

//判断向量相等
bool operator==(const point & A, const point & B);

//判断向量同向
bool operator&&(const point & A, const point B);

class CoordinateSystem
{
public:
	CoordinateSystem();
	~CoordinateSystem();
};

