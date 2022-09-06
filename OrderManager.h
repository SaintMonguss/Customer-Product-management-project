#ifndef __ORDERMANAGER_H__
#define __ORDERTMANAGER_H__

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>

#include "Manager.h"
#include "Order.h"


using std::cout;
using std::cin;
using std::string;
using std::map;

class OrderManager : public Manager
{
private:
	map<int, Order*> orderList;
	Manager* CM;
	Manager* PM;

public:
	OrderManager() {};
	OrderManager(Manager*, Manager*);

	virtual void AddObj() override;
	virtual void DelObj() override;
	virtual void ModiObj() override;
	virtual void SerchObj() override;
	virtual void PrintObj() override;
	virtual void* TossObj(int) override;
	void printOrderForm(map<int, Order*> &) const;
};

#endif