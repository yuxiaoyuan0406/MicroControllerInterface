#pragma once
#ifndef MONTH_H
#define MONTH_H

enum monthName//������һ��ö������, ����͹���·ݵĺ���
{
	Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec
};

class month//������һ����
{
private:
	int yearNum;//���
	monthName monthNum;//�·�
	int days_of_month;//��������
	unsigned int count_days_of_month(int year, int month);//�жϸ�������
public:
	month();//�յĹ��캯��
	month(int year, monthName month);//������ݺ��·����ڳ�ʼ��
	~month();//�յ���������
	void print();//�������·ݵ��յ���Ϣ, ����������ʽ, ÿ�ܵĿ�ʼΪ����

};


#endif // !MONTH_H
