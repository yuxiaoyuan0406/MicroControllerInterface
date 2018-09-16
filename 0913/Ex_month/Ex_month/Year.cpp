#include "stdafx.h"
#include "Year.h"


Year::Year()
{
}

Year::Year(int year)
	:yearNum(year)
{
	for (int i = 0; i < 12; i++)
	{
		(months_of_yesr + i)->month::month(yearNum, monthName(i + 1));
	}
}

void Year::print()
{
	printf("\t--------%d--------\n", yearNum);
	for (int i = 0; i < 12; i++)
	{
		(months_of_yesr + i)->print();
	}
}


Year::~Year()
{
}
