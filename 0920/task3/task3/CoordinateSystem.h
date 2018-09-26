#pragma once
#include <iostream>
#include <cmath>
#include <string>

struct point
{
	double x;
	double y;
};

//define a origin
point O = { 0,0 };

//���һ����
std::ostream & operator<<(std::ostream & out, const point & A);

//����һ����
std::istream & operator>>(std::istream & in, point & A);

//���غ������ֵ, ���ȥǰ
double delta_x(const point & A, const point & B);

//�����������ֵ, ���ȥǰ
double delta_y(const point & A, const point & B);

//���������������Ĳ�����
//�����͵�ı�ʾ��ʽһ��
point operator-(const point & A, const point & B);

//�����෴����
point operator-(const point & A);

//���������������ĺ�����
point operator+(const point & A, const point & B);

//����������ģ
//����������������֮�����
double abs(const point & A);

//��������б��
double slope(const point & A, const point & B);

//���������ڻ�
double operator*(const point & A, const point & B);

//�ж��������
bool operator==(const point & A, const point & B);

//�ж�����ͬ��
bool operator&&(const point & A, const point & B);

//�ж���������
bool operator||(const point & A, const point & B);

//��������
point operator*(const double & x, const point & A);

class CoordinateSystem
{
public:
	CoordinateSystem();
	~CoordinateSystem();
};

int DEBUG();
