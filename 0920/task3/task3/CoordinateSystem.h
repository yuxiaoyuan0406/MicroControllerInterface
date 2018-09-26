#pragma once
#include <iostream>
#include <cmath>

struct point
{
	double x;
	double y;
};

//using namespace std;
//���һ����
std::ostream & operator<<(std::ostream & out, const point & A);

//���غ������ֵ, ���ȥǰ
double delta_x(const point & A, const point & B);

//�����������ֵ, ���ȥǰ
double delta_y(const point & A, const point & B);

//���������������Ĳ�����
//�����͵�ı�ʾ��ʽһ��
point operator-(const point & A, const point & B);

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
bool operator&&(const point & A, const point B);

class CoordinateSystem
{
public:
	CoordinateSystem();
	~CoordinateSystem();
};

