/***********************

 * Author:	Yu Xiaoyuan
 * Date:	2018-9-17 23:10:24
 * Email:	yuxiaoyuan0406@hotmail.com

 ***********************/
#include "month.h"
#ifndef YEAR_H

#define YEAR_H

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

#endif // !YEAR_H
