#include "ProjectHeader.h"

#include <iostream>
#include <string>
#include <iomanip>
#include <stdio.h>
#include <windows.h>


ProductManager::ProductManager(map<int, Product*> PL) : productList(PL) {};

//鼻ヶ 薑爾 蹺陛
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
		std::cout << "詭賅葬 й渡 褒ぬ";
		return;
	}
	std::cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << std::endl;
	std::cout << "                                           褐敘 鼻ヶ 蛔煙                                   " << std::endl;
	std::cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << std::endl;
	std::cout << std::endl;;
	std::cout << "薯ヶ貲 : ";
	std::cin >> input;
	product->SetName(input);
	std::cout << "粽楠萄 : ";
	std::cin >> input;
	product->SetBrand(input);
	std::cout << "陛問 : ";
	std::cin >> num;
	product->SetPrice(num);
	std::cout << "營堅 : ";
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
		std::cout << "酈 ID 醞犒 嫦儅, 褐敘 鼻ヶ 蛔煙 褒ぬ" << std::endl;
		std::cout << std::endl;
		return;
	}
	std::cout << "褐敘 鼻ヶ 蛔煙 諫猿!";
	Sleep(1500); //�飛� 雖翱
	system("cls");
	return;
}

//鼻ヶ 薑爾 餉薯
void ProductManager::DelObj()
{
	int id;
	char check;
	Product* product;


	std::cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << std::endl;
	std::cout << "                                           鼻ヶ 薑爾 餉薯                                   " << std::endl;
	std::cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << std::endl;
	std::cout << std::endl;;
	PrintObj(); // 鼻ヶ 薑爾 轎溘 
	std::cout << std::endl;
	std::cout << "餉薯й 鼻ヶ曖 ID蒂 殮溘 п輿撮蹂 : ";
	std::cin >> id;

	try
	{
		productList.at(id);
	}
	catch (std::out_of_range e)
	{
		std::cout << "п渡ж朝 ID朝 襄營ж雖 彊蝗棲棻!!" << std::endl;
		return;
	}
	product = productList.find(id)->second; // 瓊嬴憮 贗塭檜樹お 偌羹蒂 й渡
	std::cout << product->GetName() << " 鼻ヶ 薑爾蒂 餉薯 ж衛啊蝗棲梱?" << std::endl;
	do
	{
		cin.ignore(999, '\n'); //幗ぷ 羶模
		std::cout << "[ Y / N ] : ";
		std::cin >> check;
		check = toupper(check); // 渠僥濠 瞪��
	} while ((check != 'Y') && (check != 'N'));
	if (check == 'N')
		return;
	productList.erase(id);
	std::cout << product->GetName() << " 鼻ヶ 薑爾蒂 餉薯ц蝗棲棻" << std::endl;
	Sleep(1500);
	system("cls");
}

//鼻ヶ 薑爾 熱薑
void ProductManager::ModiObj()
{
	int id;
	Product* product;
	string tmp;
	int num;

	std::cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << std::endl;
	std::cout << "                                           鼻ヶ 薑爾 熱薑                                   " << std::endl;
	std::cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << std::endl;
	std::cout << std::endl;
	std::cout << "熱薑й 鼻ヶ曖 ID蒂 殮溘 п輿撮蹂 : ";
	std::cin >> id;
	try
	{
		productList.at(id);
	}
	catch (std::out_of_range e)
	{
		std::cout << "п渡ж朝 ID朝 襄營ж雖 彊蝗棲棻!!" << std::endl;
		Sleep(1000);
		return;
	}
	product = productList.find(id)->second; // 瓊嬴憮 贗塭檜樹お 偌羹蒂 й渡
	std::cout << "⑷營 薯ヶ貲 : [ " << product->GetName() << " ]" << std::endl;
	std::cout << "熱薑й 薯ヶ貲 : ";
	std::cin >> tmp;
	product->SetName(tmp);
	std::cout << "⑷營 粽楠萄 : [ " << product->GetBrand() << " ]" << std::endl;
	std::cout << "熱薑й 粽楠萄 : ";
	std::cin >> tmp;
	product->SetBrand(tmp);
	std::cout << "⑷營 陛問 : [ " << product->GetPrice() << " ]" << std::endl;
	std::cout << "熱薑й 陛問 : ";
	std::cin >> num;
	product->SetPrice(num);
	std::cout << "⑷營 營堅 : [ " << product->GetStock() << " ]" << std::endl;
	std::cout << "熱薑й 營堅 : ";
	std::cin >> num;
	product->SetStock(num);
	std::cout << std::endl;
	std::cout << "鼻ヶ 薑爾 熱薑 諫猿";
	Sleep(1500);
	system("cls");
}

//鼻ヶ 薑爾 褻��
void ProductManager::SerchObj()
{
	string name;
	map<int, Product*> serchList;

	system("cls");

	std::cout << "匐儀й 渠鼻曖 薯ヶ貲擊 殮溘п 輿撮蹂 : ";
	std::cin >> name;

	for (auto itr = productList.begin(); itr != productList.end(); itr++)
	{
		if (name == itr->second->GetName())
			serchList[itr->first] = itr->second;
	}
	if (serchList.empty())
	{
		std::cout << "[" << name << "]" << " 曖 匐儀 唸婁陛 橈蝗棲棻...";
		Sleep(1500);
		return;
	}
	printProductForm(serchList);
	std::cout << std::endl;
	std::cout << name << " 匐儀 唸婁" << std::endl;
	return;
}

void ProductManager::PrintObj()
{
	system("cls");
	printProductForm(productList);
	std::cout << std::endl;
	std::cout << "檜瞪 �飛橉虞� 給嬴陛溥賊 enter蒂 殮溘п 輿撮蹂...";
	while (getchar() != '\n');
	getchar(); // 薯橫 �撣� 薑雖
	return;
}

void ProductManager::printProductForm(map<int, Product*>& productList) const
{
	Product* product;
	std::cout <<	 "忙式式式式式式式成式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式成式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式成式式式式式式式式式式式式式式式式式式式成式式式式式式式式式式式式式式式式式忖" << std::endl;;
	std::cout <<	 "弛   ID                     薯ヶ貲                                   粽楠萄                       陛問                營堅     弛" << std::endl;;
	for (auto itr = productList.begin(); itr != productList.end(); itr++)
	{
		product = itr->second;
		std::cout << "戍式式式式式式式托式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式托式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式托式式式式式式式式式式式式式式式式式式式托式式式式式式式式式式式式式式式式式扣" << std::endl;;
		std::cout << "弛 ";
		///////////////////// ID 蘊 曄衝
		cout.fill('0');
		std::cout.width(6);
		std::cout << itr->first;
		cout.fill(' '); // 奢除 瓣遺擊 奢寥戲煎 棻衛 滲唳
		std::cout << " ";
		///////////////////// 薯ヶ貲 蘊 曄衝
		std::cout << "  ";
		std::cout.width(8);
		std::cout << product->GetName();
		std::cout << "  ";
		///////////////////// 粽楠萄 蘊 曄衝
		std::cout << "  ";
		std::cout.width(11);
		std::cout << product->GetBrand();
		std::cout << "  ";
		///////////////////// 陛問 蘊 曄衝
		std::cout.width(63);
		std::cout << product->GetPrice();
		std::cout << "  ";
		///////////////////// 營堅 蘊 曄衝
		std::cout.width(24);
		std::cout << product->GetStock();
		std::cout << " 弛" << std::endl;
	}
	std::cout << "戌式式式式式式式扛式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扛式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扛式式式式式式式式式式式式式式式式式式式扛式式式式式式式式式式式式式式式式式戎" << std::endl;;
	return;
}

