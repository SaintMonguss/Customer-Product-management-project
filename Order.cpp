#include "ProjectHeader.h"

#include <iostream>

Order::Order(const int id) : m_orderId(id) {}
Order::Order(const int id, Date date, string productName, int clientId, int orderPrice, int orderStock) :
	m_orderId(id), m_date(date), m_productName(productName), m_clientId(clientId),
	m_orderPrice(orderPrice), m_orderStock(orderStock) {}


int Order::GetOrderId() const
{
	return m_orderId;
}
int Order::GetClientId() const
{
	return m_clientId;
}
int Order::GetOrderPrice() const
{
	return m_orderPrice;
}
int Order::GetOrderStock() const
{
	return m_orderStock;
}
Date Order::GetDate() const
{
	return m_date;
}
string Order::GetProductName() const
{
	return m_productName;
}


void Order::SetClientId(int clientId)
{
	m_clientId = clientId;
}
void Order::SetOrderPrice(int orderPrice)
{
	m_orderPrice = orderPrice;
}
void Order::SetOrderStock(int orderStock)
{
	m_orderStock = orderStock;
}
void Order::SetDate(Date date)
{
	m_date = date;
}
void Order::SetProductName(string productName)
{
	m_productName = productName;
}

