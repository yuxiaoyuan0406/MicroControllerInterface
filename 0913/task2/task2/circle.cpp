/***********************

 * Author:	Yu Xiaoyuan
 * Date:	2018-9-17 23:10:24
 * Email:	yuxiaoyuan0406@hotmail.com

 ***********************/

#include "stdafx.h"
#define PI 3.1415926536

void getVal(const char msg[], float &arg)//从命令行获得参数, msg为输出提示, radius为传入参量
{
	printf("%s", msg);
	scanf_s("%f", &arg);
}

double calPerimeter(double radius)//求圆周长, 参数为半径, 返回值为周长
{
	double perimeter = 2.0 * PI * radius;
	printf("Perimeter = %.3f\n", perimeter);
	return perimeter;
}

double calPerimeter()//求圆周长, 无参量输入, 从命令行获得半径, 返回周长
{
	float radius;
	getVal("Input radius:", radius);
	return calPerimeter(radius);
}

double calArea(float radius)//求圆面积, 参数为半径, 返回值为面积
{
	double area = PI * radius * radius;
	printf("Area = %.3f\n", area);
	return area;
}

double calArea()//求圆面积 无参量输入, 从命令行获得半径, 返回面积
{
	float radius;
	getVal("Input radius:", radius);
	return calArea(radius);
}

double calBallSurface(float radius)//求圆球表面积, 参数为半径, 返回值为面积
{
	double surface = 4.0 * calArea(radius);
	printf("Surface of ball = %.3f\n", surface);
	return surface;
}

double calBallSurface()//求圆球表面积, 无参量输入, 从命令行获得半径, 返回面积
{
	float radius;
	getVal("Input radius:", radius);
	return calBallSurface(radius);
}

double calBallVolume(float radius)//求圆球体积, 参数为半径, 返回值为体积
{
	double volume = 4.0 / 3.0 * PI * radius * radius * radius;
	printf("Volume of the ball = %.3f\n", volume);
	return volume;
}

double calBallVolume()//求圆球体积, 无参量输入, 从命令行获得半径, 返回体积
{
	float radius;
	getVal("Input radius:", radius);
	return calBallVolume(radius);
}

double calCylinderVolume()//求圆柱体积, 无参量输入, 从命令行获得半径和高,返回体积
{
	float height;
	double volume;
	double area = calArea();
	getVal("Input height:", height);
	volume = area * height;
	printf("Volume of the cylinder = %.3f\n", volume);
	return volume;
}
