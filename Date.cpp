#include "Date.h"
#include <iostream>


Date::Date(int year, int month, int day) : year(year), month(month), day(day) {};

void Date::SetYear(int yaer)
{
	this->year = year;
}

void Date::SetMonth(int month)
{
	this->month = month;
}
void Date::SetDay(int day)
{
	this->day = day;
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
