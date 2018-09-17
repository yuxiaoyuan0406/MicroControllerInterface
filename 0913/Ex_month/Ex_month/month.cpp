/***********************

 * Author:	Yu Xiaoyuan
 * Date:	2018-9-17 23:10:24
 * Email:	yuxiaoyuan0406@hotmail.com

 ***********************/

#include "stdafx.h"
#include <iostream>
#include "month.h"

unsigned int month::count_days_of_month(int year, int month)
{
	switch (month)
	{
	case Jan: case Mar: case May: case Jul: case Aug: case Oct: case Dec:
		return 31;
		break;
	case Feb:
		if (year % 400 == 0)
		{
			return 29;
			break;
		}
		else if (year % 4 == 0 && year % 100 != 0)
		{
			return 29;
			break;
		}
		else
		{
			return 28;
			break;
		}
	default:
		return 30;
		break;
	}
}

month::month()
	:yearNum(2013), monthNum(Jan), days_of_month(31)
{
}

month::month(int year, monthName month)
	: yearNum(year), monthNum(month)
{
	days_of_month = count_days_of_month(year, month);
}


month::~month()
{
}

void month::print()
{
	using namespace std;
	unsigned int differDays = 0;
	unsigned int weekDay = 0;
	if (yearNum < 2013)
	{
		for (int countMonth = monthNum; countMonth <= 12; countMonth++)
		{
			differDays += count_days_of_month(yearNum, countMonth);
		}
		for (int countYear = yearNum + 1; countYear < 2013; countYear++)
		{
			for (int countMonth = 1; countMonth <= 12; countMonth++)
			{
				differDays += count_days_of_month(countYear, countMonth);
			}
		}
		//differDays += 1;
		weekDay = (2 - differDays % 7 + 7) % 7;
	}
	else //if (yearNum >= 2013)
	{
		for (int countYear = 2013; countYear < yearNum; countYear++)
		{
			for (int countMonth = 1; countMonth <= 12; countMonth++)
			{
				differDays += count_days_of_month(countYear, countMonth);	//先算从2013年1月起到目标年份的天数
			}
		}
		for (int countMonth = 1; countMonth < monthNum; countMonth++)
		{
			differDays += count_days_of_month(yearNum, countMonth);			//再在目标年份内计算天数
		}
		//differDays += 1;													//最后再加1，目标月份的第一天
		weekDay = (2 + differDays % 7 + 7) % 7;
	}
	//cout << "differ days = " << differDays << endl;
	//cout << "week day = " << weekDay << endl;
	
	cout << "\t**" << monthNum << "**" << endl;
	cout << "Sun\tMon\tTue\tWed\tThu\tFri\tSat" << endl;
	for (unsigned int i = 0; i < weekDay; i++)
	{
		cout << "\t";
	}
	unsigned int countDay = 1;
	int countWeekDay = weekDay;
	while (countDay <= count_days_of_month(yearNum, monthNum))
	{
		cout << countDay;
		if (countWeekDay == 6)
		{
			cout << "\n";
			countWeekDay = 0;
		}
		else
		{
			cout << "\t";
			countWeekDay++;
		}
		countDay++;
	}
	cout << endl;
	cout << "_______________________________________" << endl;
}
