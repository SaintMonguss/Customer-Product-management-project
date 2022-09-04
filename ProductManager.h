#ifndef __PRODUCTMANAGER_H__
#define __PRODUCTMANAGER_H__

#include <iostream>
#include <map>

#include "Manager.h"
#include "Product.h"


using std::cout;
using std::cin;
using std::string;
using std::map;

class ProductManager : public Manager
{
private:
	map<int, Product*> productList;

public:
	ProductManager() {};
	ProductManager(map<int, Product*>);

	virtual void AddObj() override;
	virtual void DelObj() override;
	virtual void ModiObj() override;
	virtual void SerchObj() override;
	virtual void PrintObj() override;
	void printProductForm(map<int, Product*>&) const;
};

#endif