#include "ProjectHeader.h"

#include <iostream>


Date::Date(int year, int month, int day) : year(year), month(month), day(day) {};

bool Date::SetYear(int year)
{
	if (year >= 1980)
	{
		this->year = year;
		return true;
	}
	else
	{
		std::cout << "�߸��� �⵵ �� �Դϴ�" << std::endl;
		return false;
	}

}

bool Date::SetMonth(int month)
{
	if (month >= 1 && month <= 12)
	{
		this->month = month;
		return true;
	}
	else
	{
		std::cout << "�߸��� �� �Դϴ�." << std::endl;
		return false;
	}
	
}
bool Date::SetDay(int day)
{
	if (day >= 1 && day <= 31)
	{
		this->day = day;
		return true;
	}
	else
	{
		std::cout << "�߸��� ���� �Դϴ�." << std::endl;
		return false;
	}
}

int const Date::GetYear()
{
	return year;
}

int const Date::GetMonth()
{
	return month;
}

int const Date::GetDay()
{
	return day;
}
