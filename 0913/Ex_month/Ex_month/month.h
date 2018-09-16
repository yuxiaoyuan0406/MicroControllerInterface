#pragma once
#ifndef MONTH_H
#define MONTH_H

enum monthName//声明了一个枚举类型, 用于凸显月份的含义
{
	Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec
};

class month//声明了一个类
{
private:
	int yearNum;//年份
	monthName monthNum;//月份
	int days_of_month;//该月天数
	unsigned int count_days_of_month(int year, int month);//判断该月天数
public:
	month();//空的构造函数
	month(int year, monthName month);//输入年份和月份用于初始化
	~month();//空的析构函数
	void print();//输出这个月份的日的信息, 以月历的形式, 每周的开始为周日

};


#endif // !MONTH_H
