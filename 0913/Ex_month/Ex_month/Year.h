#pragma once

#include "month.h"

class Year//定义了一个类
{
private:
	int yearNum;//年份
	month months_of_yesr[12];//定义了这一年的12个月
public:
	Year();//空的构造函数
	Year(int year);//输入年份初始化一个年的对象
	void print();//输出一整年的信息, 年历格式, 周以周日为第一天
	~Year();//空的析构函数
};

