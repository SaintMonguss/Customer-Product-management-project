#ifndef __PRODUCTMANAGER_H__
#define __PRODUCTMANAGER_H__

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>

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
	ProductManager();
	~ProductManager();

	std::vector<string> parseCSV(std::istream& , char);

	virtual void AddObj() override;
	virtual void DelObj() override;
	virtual void ModiObj() override;
	virtual void SerchObj() override;
	virtual void PrintObj() override;
	virtual void* TossObj(int) override;
	void printProductForm(map<int, Product*> &) const;

};

#endif