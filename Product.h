#ifndef __PRODUCT_H__
#define __PRODUCT_H__

#include <iostream>

using std::cout;
using std::cin;
using std::string;



class Product
{
private:
	const int m_id;
	string m_name;
	string m_brand;
	int m_price;
	int m_stock;

public:
	Product(const int id);
	Product(int, string, string, int, int);

	string GetName() const;
	string GetBrand() const;
	int GetPrice() const;
	int GetStock() const;
	int GetId() const;

	void SetName(string);
	void SetBrand(string);
	void SetPrice(int);
	void SetStock(int);
};

#endif
