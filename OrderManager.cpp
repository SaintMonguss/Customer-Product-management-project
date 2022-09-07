#include "ProjectHeader.h"

#include <iostream>
#include <string>
#include <iomanip>
#include <stdio.h>
#include <windows.h>

// »ý¼ºÀÚ ÆÄÀÏ ºÒ·¯¿À±â
OrderManager::OrderManager(Manager* CM, Manager* PM) : CM(CM), PM(PM) 
{
	//	std::vector<Client*> vecList;
	std::ifstream file;
	file.open("orderlist.txt");
	if (!file.fail()) {
		while (!file.eof()) {
			std::vector<string> row = parseCSV(file, ',');
			if (row.size()) {
				int id = atoi(row[0].c_str());
				Date date;
				date.SetYear(atoi(row[1].c_str()));
				date.SetMonth(atoi(row[2].c_str()));
				date.SetDay(atoi(row[3].c_str()));
				int productId = atoi(row[5].c_str());
				int clientId = atoi(row[6].c_str());
				int price = atoi(row[7].c_str());
				int stock = atoi(row[8].c_str());
				Order* c = new Order(id, date, row[4], productId, clientId, price, stock);
				orderList.insert({ id, c });
				//				vecList.push_back(c);
			}
		}
	}
	file.close();
};

//¼Ò¸êÀÚ ÆÄÀÏ ÀúÀå
OrderManager::~OrderManager()
{
	std::ofstream file;
	file.open("orderlist.txt");
	if (!file.fail()) {
		for (const auto& v : orderList) {
			Order* c = v.second;
			file << c->GetOrderId() << ", ";
			file << c->GetDate().GetYear() << ", ";
			file << c->GetDate().GetMonth() << ", ";
			file << c->GetDate().GetDay() << ", ";
			file << c->GetProductName() << ", ";
			file << c->GetProductId() << ", ";
			file << c->GetClientId() << ", ";
			file << c->GetOrderPrice() << ", ";
			file << c->GetOrderStock() << std::endl;
		}
	}
	file.close();
}



//ÁÖ¹® Á¤º¸ Ãß°¡
void OrderManager::AddObj()
{
	string input;
	Order* order;
	Product *product;
	Date date;
	int stockCheck;
	int num;
	int id;
	

	if (orderList.empty())
		id = 1;
	else
		id = (orderList.rbegin()->first) + 1;
	try
	{
		order = new Order(id);
	}
	catch (const std::bad_alloc& e)
	{
		std::cout << "¸Þ¸ð¸® ÇÒ´ç ½ÇÆÐ";
		return;
	}
	std::cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << std::endl;
	std::cout << "                                                            ½Å±Ô ÁÖ¹® µî·Ï" << std::endl;
	std::cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << std::endl;
	std::cout << std::endl;;
	std::cout << "µÚ·Î °¡°í ½Í´Ù¸é -1 ÀÔ·Â" << std::endl << std::endl;
	do
	{
		std::cout << "»óÇ° ID : ";
		num = InputFormat::IntCin();
		if (num == -1)
		{
			return;
		}
	} while (!(PM->TossObj(num))); // ¿¹¿Ü Ã¼Å©
	product = static_cast<Product*>(PM->TossObj(num)); //void* ¸¦ Product*·Î Ä³½ºÆÃÇÑµÚ ÀÌ¸§À» ¹Þ¾Æ¿Í¼­ input¿¡ ´ëÀÔ
	input = product -> GetName(); 
	stockCheck = product->GetStock(); // ÇöÀç ¼ö·® ÀúÀå
	order->SetProductId(num);
	order->SetProductName(input);
	do
	{
		std::cout << "ÁÖ¹® ³¯ÀÚ [³â] (yyyy) : ";
		num = InputFormat::IntCin();
	} while (!date.SetYear(num));
	do
	{
		std::cout << "ÁÖ¹® ³¯ÀÚ [¿ù] (mm): ";
		num = InputFormat::IntCin();
	} while (!date.SetMonth(num));
	do
	{
		std::cout << "ÁÖ¹® ³¯ÀÚ [ÀÏ] (dd): ";
		num = InputFormat::IntCin();
	} while (!date.SetDay(num));
	order->SetDate(date);

	std::cout << "±¸¸ÅÀÚ ID : ";
	num = InputFormat::IntCin();
	order->SetClientId(num);
	// ÁÖ¹® ¼ö·® ¼³Á¤
	std::cout << "±¸¸Å ¼ö·® : ";
	num = InputFormat::IntCin();

	order->SetOrderStock(num);
	if (stockCheck < num)
	{
		std::wcout << std::endl;
		std::cout << "°æ°í! ÇöÀç »óÇ° ¼ö·®º¸´Ù ÁÖ¹®·®ÀÌ ¸¹½À´Ï´Ù. È®ÀÎÀÌ ÇÊ¿äÇÕ´Ï´Ù. " << std::endl;
	}
	// ÁÖ¹® °¡°Ý ¼³Á¤
	order->SetOrderPrice(product->GetPrice());
	Sleep(1500); //È­¸é Áö¿¬
	
	try
	{
		auto tmp = (orderList.insert({ id, order }));
		if (tmp.second == false)
			throw;
	}
	catch (...)
	{
		std::cout << std::endl;
		std::cout << "Å° ID Áßº¹ ¹ß»ý, ÁÖ¹® ÀÌ·Â Ãß°¡ ½ÇÆÐ" << std::endl;
		std::cout << std::endl;
		return;
	}
	std::cout << std::endl;
	std::cout << "ÁÖ¹® ÀÌ·Â µî·Ï ¿Ï·á!";
	Sleep(1500); //È­¸é Áö¿¬
	system("cls");
	return;
}

// ÁÖ¹® Á¤º¸ »èÁ¦
void OrderManager::DelObj()
{
	int id;
	char check;
	Order *order;

	system("cls");
	printOrderForm(orderList);
	std::cout << std::endl;;
	std::cout << std::endl;;
	std::cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << std::endl;
	std::cout << "                                                          ÁÖ¹® ÀÌ·Â »èÁ¦" << std::endl;
	std::cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << std::endl;

	std::cout << std::endl; 
	std::cout << "µÚ·Î °¡°í ½Í´Ù¸é -1 ÀÔ·Â" << std::endl << std::endl;
	std::cout << "»èÁ¦ÇÒ ÁÖ¹®ÀÇ ID¸¦ ÀÔ·Â ÇØÁÖ¼¼¿ä : ";
	id = InputFormat::IntCin();
	if (id == -1)
		return;
	try
	{
		orderList.at(id);
	}
	catch (std::out_of_range e)
	{
		std::cout << "ÇØ´çÇÏ´Â ÁÖ¹® ID´Â Á¸ÀçÇÏÁö ¾Ê½À´Ï´Ù!!" << std::endl;
		Sleep(1000);
		return;
	}
	order = orderList.find(id)->second; // Ã£¾Æ¼­ Å¬¶óÀÌ¾ðÆ® °´Ã¼¸¦ ÇÒ´ç
	std::cout << "[" << order->GetOrderId() << "]" << " ¹ø ÁÖ¹® ÀÌ·ÂÀ» »èÁ¦ ÇÏ½Ã°Ú½À´Ï±î?" << std::endl;
	do
	{
		cin.ignore(999, '\n'); //¹öÆÛ Ã»¼Ò
		std::cout << "[ Y / N ] : ";
		std::cin >> check;
		check = toupper(check); // ´ë¹®ÀÚ ÀüÈ¯
	} while ((check != 'Y') && (check != 'N'));
	if (check == 'N')
		return;
	orderList.erase(id);
	std::cout << "[" << order->GetOrderId() << "]" << " ¹ø ÁÖ¹® ÀÌ·ÂÀ» »èÁ¦Çß½À´Ï´Ù" << std::endl;
	Sleep(1500);
	system("cls");
}
// ÁÖ¹® ÀÌ·Â ¼öÁ¤
void OrderManager::ModiObj()
{
	int id;
	int num;
	Date date;
	Order* order;
	string tmp;

	std::cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << std::endl;
	std::cout << "                                                       ÁÖ¹® ÀÌ·Â ¼öÁ¤" << std::endl;
	std::cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << std::endl;
	std::cout << std::endl;
	std::cout << "¼öÁ¤ÇÒ ¼ö ÀÖ´Â Ç×¸ñÀº ÁÖ¹® ¼ö·®°ú ³¯Â¥ÀÔ´Ï´Ù.";
	std::cout << std::endl;
	std::cout << "µÚ·Î °¡°í ½Í´Ù¸é -1 ÀÔ·Â" << std::endl << std::endl;
	std::cout << "¼öÁ¤ÇÒ ÁÖ¹®ÀÇ ID¸¦ ÀÔ·Â ÇØÁÖ¼¼¿ä : ";
	id = InputFormat::IntCin();
	if (id == -1)
		return;
	try
	{
		orderList.at(id);
	}
	catch (std::out_of_range e)
	{
		std::cout << "ÇØ´çÇÏ´Â ID´Â Á¸ÀçÇÏÁö ¾Ê½À´Ï´Ù!!" << std::endl;
		Sleep(1000);
		return;
	}
	order = orderList.find(id)->second; // Ã£¾Æ¼­ Å¬¶óÀÌ¾ðÆ® °´Ã¼¸¦ ÇÒ´ç
	std::cout << "ÇöÀç ¼ö·® : [ " << order->GetOrderStock() << " ]" << std::endl;
	std::cout << "¼öÁ¤ÇÒ ¼ö·® : ";
	num = InputFormat::IntCin();
	order->SetOrderStock(num);
	std::cout << "ÇöÀç ³¯Â¥ : [ " 
		<< order->GetDate().GetYear()<< "³â " 
		<< order->GetDate().GetMonth() << "¿ù "
		<< order->GetDate().GetDay() << "ÀÏ" 
		<< "]" << std::endl;
	do
	{
		std::cout << "¼öÁ¤ÇÒ ³¯ÀÚ [³â] (yyyy) : ";
		num = InputFormat::IntCin();
	} while (!date.SetYear(num));
	do
	{
		std::cout << "ÁÖ¹® ³¯ÀÚ [¿ù] (mm): ";
		num = InputFormat::IntCin();
	} while (!date.SetMonth(num));
	do
	{
		std::cout << "ÁÖ¹® ³¯ÀÚ [ÀÏ] (dd): ";
		num = InputFormat::IntCin();
	} while (!date.SetDay(num));
	order->SetDate(date);

	std::cout << "ÁÖ¹® Á¤º¸ ¼öÁ¤ ¿Ï·á";
	Sleep(1500);
	system("cls");
}

// ÁÖ¹® Á¤º¸ °Ë»ö
void OrderManager::SerchObj() 
{
	int id;
	map<int, Order*> serchList;

	system("cls");

	std::cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << std::endl;
	std::cout << "                                                          ÁÖ¹® ÀÌ·Â °Ë»ö" << std::endl;
	std::cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << std::endl;
	std::cout << std::endl;
	std::cout << "µÚ·Î °¡°í ½Í´Ù¸é -1 ÀÔ·Â" << std::endl << std::endl;
	std::cout << "°Ë»öÇÒ ÀÌ·ÂÀÇ ±¸¸ÅÀÚ ID¸¦ ÀÔ·ÂÇØ ÁÖ¼¼¿ä : ";
	id = InputFormat::IntCin();
	if (id == -1)
		return;
	for (auto itr = orderList.begin(); itr != orderList.end(); itr++)
	{
		if (id == itr->second->GetClientId())
			serchList[itr->first] = itr->second;
	}
	if (serchList.empty())
	{
		std::cout << "[" << id << "]" << " °í°´ÀÇ ÁÖ¹® ÀÌ·ÂÀÌ ¾ø½À´Ï´Ù...";
		Sleep(1500);
		return;
	}
	system("cls");
	printOrderForm(serchList);
	std::cout << std::endl;
	std::cout << "[" << id << "]" << " ÁÖ¹® ÀÌ·Â °Ë»ö °á°ú" << std::endl;
	std::cout << std::endl;
	std::cout << "ÀÌÀü È­¸éÀ¸·Î µ¹¾Æ°¡·Á¸é enter¸¦ ÀÔ·ÂÇØ ÁÖ¼¼¿ä...";
	while (getchar() != '\n');
	getchar(); // Á¦¾î Èå¸§ Á¤Áö
	return;
	
}

//ÁÖ¹® Á¤º¸ Á¶È¸
void OrderManager::PrintObj()
{
	system("cls");
	printOrderForm(orderList);
	std::cout << std::endl;
	std::cout << "ÀÌÀü È­¸éÀ¸·Î µ¹¾Æ°¡·Á¸é enter¸¦ ÀÔ·ÂÇØ ÁÖ¼¼¿ä...";
	while (getchar() != '\n');
	getchar(); // Á¦¾î Èå¸§ Á¤Áö
	return;
}

void* OrderManager::TossObj(int id)
{
	Order* order = nullptr;
	try
	{
		order = orderList.at(id);
	}
	catch (std::out_of_range e)
	{
		std::cout << "ÇØ´çÇÏ´Â ID´Â Á¸ÀçÇÏÁö ¾Ê½À´Ï´Ù!!" << std::endl;
		Sleep(1000);
	}
	return order;
}


// °í°´ °ü·Ã Ãâ·Â ÅÛÇÃ¸´
void OrderManager::printOrderForm(map<int, Order*> &orderList) const
{
	Order* order;
	std::cout << "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¨¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¨¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¨¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¨¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¨¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¨¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤" << std::endl;;
	std::cout << "¦¢   ID          ÁÖ¹®ÀÏ        ±¸¸ÅÀÚ ID                      »óÇ° ÀÌ¸§                »óÇ° ID         °¡°Ý            ¼ö·®     ¦¢" << std::endl;;
	for (auto itr = orderList.begin(); itr != orderList.end(); itr++)
	{
		order = itr->second;
		std::cout << "¦§¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦«¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦«¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦«¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦«¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦«¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦«¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦©" << std::endl;;
		std::cout << "¦¢ ";
		///////////////////// ID Ä­ ¾ç½Ä
		cout.fill('0');
		std::cout.width(O_ID_WIDTH);
		std::cout << itr->first;
		cout.fill(' '); // °ø°£ Ã¤¿òÀ» °ø¹éÀ¸·Î ´Ù½Ã º¯°æ
		std::cout << " ";
		///////////////////// ³¯Â¥ ¾ç½Ä
		std::cout << "   ";
		std::cout << order->GetDate().GetYear() << "³â ";
		std::cout.width(2);
		std::cout << order->GetDate().GetMonth();
		std::cout << "¿ù ";
		std::cout.width(2);
		std::cout << order->GetDate().GetDay();
		std::cout << "ÀÏ";
		std::cout << "  ";
		///////////////////// ±¸¸ÅÀÚ ¾ÆÀÌµð ¾ç½Ä
		std::cout << "  ";
		std::cout.width(O_CLIENTID_WIDTH);
		cout.fill('0');
		std::cout << order->GetClientId();
		cout.fill(' '); // °ø°£ Ã¤¿òÀ» °ø¹éÀ¸·Î ´Ù½Ã º¯°æ
		std::cout << "  ";
		///////////////////// Á¦Ç° ¸í ¾ç½Ä
		std::cout << "  ";
		std::cout.width(O_PRODUCTNAME_WIDTH);
		std::cout << order->GetProductName();
		std::cout << " ";
		///////////////////// Á¦Ç° ID ¾ç½Ä
		std::cout << "  ";
		cout.fill('0');
		std::cout.width(O_PRODUCTID_WIDTH);
		std::cout << order->GetProductId();
		cout.fill(' '); // °ø°£ Ã¤¿òÀ» °ø¹éÀ¸·Î ´Ù½Ã º¯°æ
		std::cout << " ";
		///////////////////// °¡°Ý ¾ç½Ä
		std::cout << "  ";
		std::cout.width(O_PRICE_WIDTH);
		std::cout << order->GetOrderPrice();
		std::cout << " ";
		///////////////////// ¼ö·® ¾ç½Ä
		std::cout.width(O_STOCK_WIDTH);
		std::cout << order->GetOrderStock();
		std::cout << " ¦¢" << std::endl;
	}
	std::cout << "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦ª¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦ª¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦ª¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦ª¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦ª¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦ª¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥" << std::endl;;
	return;
}

std::vector<string> OrderManager::parseCSV(std::istream& file, char delimiter)
{
	std::stringstream ss;
	std::vector<string> row;
	string t = " \n\r\t";

	while (!file.eof()) {
		char c = file.get();
		if (c == delimiter || c == '\r' || c == '\n') {
			if (file.peek() == '\n') file.get();
			string s = ss.str();
			s.erase(0, s.find_first_not_of(t));
			s.erase(s.find_last_not_of(t) + 1);
			row.push_back(s);
			ss.str("");
			if (c != delimiter) break;
		}
		else {
			ss << c;
		}
	}
	return row;
}