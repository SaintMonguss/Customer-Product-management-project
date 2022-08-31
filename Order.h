#ifndef __ORDER_H__
#define __ORDER_H__

#include <iostream>
#include "Date.h"

using std::cout;
using std::cin;
using std::string;

enum OrderState
{
	orederd, // 주문됨
	returned, // 반려됨
	processed, // 처리 완료됨
};

class Order
{
private:
	const int m_orderId; // 주문의 식별 번호
	Date m_date;
	string m_productName;
	int m_clientId; // 구매자 식별 번호
	int m_orderPrice;
	int m_orderStock;
	OrderState state;
	

public:
	Order(const int id);
	Order(int, Date, string, int, int, int, OrderState);

	int GetOrederId() const;
	int GetClientId() const;
	int GetOrederPrice() const;
	int GetOrederStock() const;
	Date GetDate() const;
	string GetProductName() const;
	OrderState GetState() const;

	void SetClientId(int);
	void SetBrand(string);
	void SetOrederPrice(int);
	void SetOrederStock(int);
	void SetDate(Date);
	void SetProductName(string);
	void SetState(OrderState);
};

#endif
