#include "Product.h"
#include <iostream>


Product::Product(int id) 
	:m_id(id), m_name(""), m_brand(""), m_price(0), m_stock(0) {}


Product::Product(int id , string name, string brand, int price, int stock)
	:m_id(id), m_name(name), m_brand(brand), m_price(price), m_stock(stock) {}

string Product::GetName() const
{
	return m_name;
}

string Product::GetBrand() const
{
	return m_brand;
}

int Product::GetPrice() const
{
	return m_price;
}

int Product::GetStock() const
{
	return m_stock;
}

int Product::GetId() const
{
	return m_id;
}

void Product::SetName(string name)
{
	m_name = name;
}

void Product::SetBrand(string brand)
{
	m_brand = brand;
}

void Product::SetPrice(int price)
{
	m_price = price;
}

void Product::SetStock(int stock)
{
	m_stock = stock;
}