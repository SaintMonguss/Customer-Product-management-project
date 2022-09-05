#include "ProjectHeader.h"

#include <iostream>
#include <string>
#include <iomanip>
#include <stdio.h>
#include <windows.h>


ProductManager::ProductManager(map<int, Product*> PL) : productList(PL) {};

//»óÇ° Á¤º¸ Ãß°¡
void ProductManager::AddObj()
{
	string input;
	Product* product;
	int id;
	int num;
	if (productList.empty())
		id = 1;
	else
		id = (productList.rbegin()->first) + 1;
	try
	{
		product = new Product(id);
	}
	catch (const std::bad_alloc& e)
	{
		std::cout << "¸Þ¸ð¸® ÇÒ´ç ½ÇÆÐ";
		return;
	}
	std::cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << std::endl;
	std::cout << "                                           ½Å±Ô »óÇ° µî·Ï                                   " << std::endl;
	std::cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << std::endl;
	std::cout << std::endl;;
	std::cout << "Á¦Ç°¸í : ";
	std::cin >> input;
	product->SetName(input);
	std::cout << "ºê·£µå : ";
	std::cin >> input;
	product->SetBrand(input);
	std::cout << "°¡°Ý : ";
	std::cin >> num;
	product->SetPrice(num);
	std::cout << "Àç°í : ";
	std::cin >> num;
	product->SetStock(num);
	try
	{
		auto tmp = (productList.insert({ id, product }));
		if (tmp.second == false)
			throw;
	}
	catch (...)
	{
		std::cout << std::endl;
		std::cout << "Å° ID Áßº¹ ¹ß»ý, ½Å±Ô »óÇ° µî·Ï ½ÇÆÐ" << std::endl;
		std::cout << std::endl;
		return;
	}
	std::cout << "½Å±Ô »óÇ° µî·Ï ¿Ï·á!";
	Sleep(1500); //È­¸é Áö¿¬
	system("cls");
	return;
}

//»óÇ° Á¤º¸ »èÁ¦
void ProductManager::DelObj()
{
	int id;
	char check;
	Product* product;


	std::cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << std::endl;
	std::cout << "                                           »óÇ° Á¤º¸ »èÁ¦                                   " << std::endl;
	std::cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << std::endl;
	std::cout << std::endl;;
	PrintObj(); // »óÇ° Á¤º¸ Ãâ·Â 
	std::cout << std::endl;
	std::cout << "»èÁ¦ÇÒ »óÇ°ÀÇ ID¸¦ ÀÔ·Â ÇØÁÖ¼¼¿ä : ";
	std::cin >> id;

	try
	{
		productList.at(id);
	}
	catch (std::out_of_range e)
	{
		std::cout << "ÇØ´çÇÏ´Â ID´Â Á¸ÀçÇÏÁö ¾Ê½À´Ï´Ù!!" << std::endl;
		return;
	}
	product = productList.find(id)->second; // Ã£¾Æ¼­ Å¬¶óÀÌ¾ðÆ® °´Ã¼¸¦ ÇÒ´ç
	std::cout << product->GetName() << " »óÇ° Á¤º¸¸¦ »èÁ¦ ÇÏ½Ã°Ú½À´Ï±î?" << std::endl;
	do
	{
		cin.ignore(999, '\n'); //¹öÆÛ Ã»¼Ò
		std::cout << "[ Y / N ] : ";
		std::cin >> check;
		check = toupper(check); // ´ë¹®ÀÚ ÀüÈ¯
	} while ((check != 'Y') && (check != 'N'));
	if (check == 'N')
		return;
	productList.erase(id);
	std::cout << product->GetName() << " »óÇ° Á¤º¸¸¦ »èÁ¦Çß½À´Ï´Ù" << std::endl;
	Sleep(1500);
	system("cls");
}

//»óÇ° Á¤º¸ ¼öÁ¤
void ProductManager::ModiObj()
{
	int id;
	Product* product;
	string tmp;
	int num;

	std::cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << std::endl;
	std::cout << "                                           »óÇ° Á¤º¸ ¼öÁ¤                                   " << std::endl;
	std::cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << std::endl;
	std::cout << std::endl;
	std::cout << "¼öÁ¤ÇÒ »óÇ°ÀÇ ID¸¦ ÀÔ·Â ÇØÁÖ¼¼¿ä : ";
	std::cin >> id;
	try
	{
		productList.at(id);
	}
	catch (std::out_of_range e)
	{
		std::cout << "ÇØ´çÇÏ´Â ID´Â Á¸ÀçÇÏÁö ¾Ê½À´Ï´Ù!!" << std::endl;
		Sleep(1000);
		return;
	}
	product = productList.find(id)->second; // Ã£¾Æ¼­ Å¬¶óÀÌ¾ðÆ® °´Ã¼¸¦ ÇÒ´ç
	std::cout << "ÇöÀç Á¦Ç°¸í : [ " << product->GetName() << " ]" << std::endl;
	std::cout << "¼öÁ¤ÇÒ Á¦Ç°¸í : ";
	std::cin >> tmp;
	product->SetName(tmp);
	std::cout << "ÇöÀç ºê·£µå : [ " << product->GetBrand() << " ]" << std::endl;
	std::cout << "¼öÁ¤ÇÒ ºê·£µå : ";
	std::cin >> tmp;
	product->SetBrand(tmp);
	std::cout << "ÇöÀç °¡°Ý : [ " << product->GetPrice() << " ]" << std::endl;
	std::cout << "¼öÁ¤ÇÒ °¡°Ý : ";
	std::cin >> num;
	product->SetPrice(num);
	std::cout << "ÇöÀç Àç°í : [ " << product->GetStock() << " ]" << std::endl;
	std::cout << "¼öÁ¤ÇÒ Àç°í : ";
	std::cin >> num;
	product->SetStock(num);
	std::cout << std::endl;
	std::cout << "»óÇ° Á¤º¸ ¼öÁ¤ ¿Ï·á";
	Sleep(1500);
	system("cls");
}

//»óÇ° Á¤º¸ Á¶È¸
void ProductManager::SerchObj()
{
	string name;
	map<int, Product*> serchList;

	system("cls");

	std::cout << "°Ë»öÇÒ ´ë»óÀÇ Á¦Ç°¸íÀ» ÀÔ·ÂÇØ ÁÖ¼¼¿ä : ";
	std::cin >> name;

	for (auto itr = productList.begin(); itr != productList.end(); itr++)
	{
		if (name == itr->second->GetName())
			serchList[itr->first] = itr->second;
	}
	if (serchList.empty())
	{
		std::cout << "[" << name << "]" << " ÀÇ °Ë»ö °á°ú°¡ ¾ø½À´Ï´Ù...";
		Sleep(1500);
		return;
	}
	printProductForm(serchList);
	std::cout << std::endl;
	std::cout << name << " °Ë»ö °á°ú" << std::endl;
	return;
}

void ProductManager::PrintObj()
{
	system("cls");
	printProductForm(productList);
	std::cout << std::endl;
	std::cout << "ÀÌÀü È­¸éÀ¸·Î µ¹¾Æ°¡·Á¸é enter¸¦ ÀÔ·ÂÇØ ÁÖ¼¼¿ä...";
	while (getchar() != '\n');
	getchar(); // Á¦¾î Èå¸§ Á¤Áö
	return;
}

void ProductManager::printProductForm(map<int, Product*>& productList) const
{
	Product* product;
	std::cout <<	 "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¨¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¨¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¨¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¨¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤" << std::endl;;
	std::cout <<	 "¦¢   ID                     Á¦Ç°¸í                                   ºê·£µå                       °¡°Ý                Àç°í     ¦¢" << std::endl;;
	for (auto itr = productList.begin(); itr != productList.end(); itr++)
	{
		product = itr->second;
		std::cout << "¦§¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦«¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦«¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦«¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦«¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦©" << std::endl;;
		std::cout << "¦¢ ";
		///////////////////// ID Ä­ ¾ç½Ä
		cout.fill('0');
		std::cout.width(6);
		std::cout << itr->first;
		cout.fill(' '); // °ø°£ Ã¤¿òÀ» °ø¹éÀ¸·Î ´Ù½Ã º¯°æ
		std::cout << " ";
		///////////////////// Á¦Ç°¸í Ä­ ¾ç½Ä
		std::cout << "  ";
		std::cout.width(8);
		std::cout << product->GetName();
		std::cout << "  ";
		///////////////////// ºê·£µå Ä­ ¾ç½Ä
		std::cout << "  ";
		std::cout.width(11);
		std::cout << product->GetBrand();
		std::cout << "  ";
		///////////////////// °¡°Ý Ä­ ¾ç½Ä
		std::cout.width(63);
		std::cout << product->GetPrice();
		std::cout << "  ";
		///////////////////// Àç°í Ä­ ¾ç½Ä
		std::cout.width(24);
		std::cout << product->GetStock();
		std::cout << " ¦¢" << std::endl;
	}
	std::cout << "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦ª¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦ª¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦ª¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦ª¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥" << std::endl;;
	return;
}

