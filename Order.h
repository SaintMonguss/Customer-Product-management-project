#ifndef __ORDER_H__
#define __ORDER_H__

#include <iostream>
#include "Date.h"

using std::cout;
using std::cin;
using std::string;


class Order
{
private:
	const int m_orderId; // 주문의 식별 번호
	Date m_date;
	string m_productName;
	int m_clientId; // 구매자 식별 번호
	int m_orderPrice;
	int m_orderStock;
	

public:
	Order(const int );
	Order(const int, Date, string, int, int, int);

	int GetOrderId() const;
	int GetClientId() const;
	int GetOrderPrice() const;
	int GetOrderStock() const;
	Date GetDate() const;
	string GetProductName() const;


	void SetClientId(int);
	void SetBrand(string);
	void SetOrderPrice(int);
	void SetOrderStock(int);
	void SetDate(Date);
	void SetProductName(string);
};

#endif
