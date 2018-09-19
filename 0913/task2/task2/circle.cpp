/***********************

 * Author:	Yu Xiaoyuan
 * Date:	2018-9-17 23:10:24
 * Email:	yuxiaoyuan0406@hotmail.com

 ***********************/

#include "stdafx.h"
#define PI 3.1415926536

void getVal(const char msg[], float &arg)//�������л�ò���, msgΪ�����ʾ, radiusΪ�������
{
	printf("%s", msg);
	scanf_s("%f", &arg);
}

double calPerimeter(double radius)//��Բ�ܳ�, ����Ϊ�뾶, ����ֵΪ�ܳ�
{
	double perimeter = 2.0 * PI * radius;
	printf("Perimeter = %.3f\n", perimeter);
	return perimeter;
}

double calPerimeter()//��Բ�ܳ�, �޲�������, �������л�ð뾶, �����ܳ�
{
	float radius;
	getVal("Input radius:", radius);
	return calPerimeter(radius);
}

double calArea(float radius)//��Բ���, ����Ϊ�뾶, ����ֵΪ���
{
	double area = PI * radius * radius;
	printf("Area = %.3f\n", area);
	return area;
}

double calArea()//��Բ��� �޲�������, �������л�ð뾶, �������
{
	float radius;
	getVal("Input radius:", radius);
	return calArea(radius);
}

double calBallSurface(float radius)//��Բ������, ����Ϊ�뾶, ����ֵΪ���
{
	double surface = 4.0 * calArea(radius);
	printf("Surface of ball = %.3f\n", surface);
	return surface;
}

double calBallSurface()//��Բ������, �޲�������, �������л�ð뾶, �������
{
	float radius;
	getVal("Input radius:", radius);
	return calBallSurface(radius);
}

double calBallVolume(float radius)//��Բ�����, ����Ϊ�뾶, ����ֵΪ���
{
	double volume = 4.0 / 3.0 * PI * radius * radius * radius;
	printf("Volume of the ball = %.3f\n", volume);
	return volume;
}

double calBallVolume()//��Բ�����, �޲�������, �������л�ð뾶, �������
{
	float radius;
	getVal("Input radius:", radius);
	return calBallVolume(radius);
}

double calCylinderVolume()//��Բ�����, �޲�������, �������л�ð뾶�͸�,�������
{
	float height;
	double volume;
	double area = calArea();
	getVal("Input height:", height);
	volume = area * height;
	printf("Volume of the cylinder = %.3f\n", volume);
	return volume;
}
