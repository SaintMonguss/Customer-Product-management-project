#ifndef __MANAGER_H__
#define __MANAGER_H__

#include <iostream>

class Manager
{
public:
	virtual void AddObj() = 0;
	virtual void DelObj(int) = 0;
	virtual void ModiObj(int) = 0;
	virtual void SerchObj(int) = 0;
	virtual void SerchObj(string) = 0;
	virtual void PrintObj() = 0;
	
};


#endif