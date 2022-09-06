#include "ProjectHeader.h"

#include <iostream>


Date::Date(int year, int month, int day) : year(year), month(month), day(day) {};

bool Date::SetYear(int yaer)
{
	if (year >= 1980)
	{
		this->year = year;
		return true;
	}
	else
	{
		std::cout << "잘못된 년도 값 입니다" << std::endl;
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
		std::cout << "잘못된 월 입니다." << std::endl;
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
		std::cout << "잘못된 날자 입니다." << std::endl;
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
