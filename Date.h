#ifndef __DATE_H__
#define __DATE_H__

#include <iostream>

class Date
{
private:
	int year;
	int month;
	int day;

public:
	Date() {};
	Date(int, int, int);

	bool SetYear(int );
	bool SetMonth(int );
	bool SetDay(int );

	const int GetYear();
	const int GetMonth();
	const int GetDay();
};

#endif