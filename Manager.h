#ifndef __MANAGER_H__
#define __MANAGER_H__

#include <iostream>

class Manager
{
public:
	virtual void AddObj() = 0;
	virtual void DelObj() = 0;
	virtual void ModiObj() = 0;
	virtual void SerchObj() = 0;
	virtual void PrintObj() = 0;
	
};


#endif