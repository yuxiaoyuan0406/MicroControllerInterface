#pragma once

#include "month.h"

class Year//������һ����
{
private:
	int yearNum;//���
	month months_of_yesr[12];//��������һ���12����
public:
	Year();//�յĹ��캯��
	Year(int year);//������ݳ�ʼ��һ����Ķ���
	void print();//���һ�������Ϣ, ������ʽ, ��������Ϊ��һ��
	~Year();//�յ���������
};

