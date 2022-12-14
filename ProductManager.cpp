#include "ProjectHeader.h"

#include <iostream>
#include <string>
#include <iomanip>
#include <stdio.h>
#include <windows.h>

ProductManager::ProductManager()
{
	std::ifstream file;
	file.open("productlist.txt");
	if (!file.fail()) {
		while (!file.eof()) {
			std::vector<string> row = parseCSV(file, ',');
			if (row.size()) {
				int id = atoi(row[0].c_str());
				int price = atoi(row[3].c_str());
				int stock = atoi(row[4].c_str());
				Product* c = new Product(id, row[1], row[2], price, stock);
				productList.insert({ id, c });

			}
		}
	}
	file.close();
}

ProductManager::~ProductManager()
{
	std::ofstream file;
	file.open("productlist.txt");
	if (!file.fail()) {
		for (const auto& v : productList) {
			Product* c = v.second;
			file << c->GetId() << ", ";
			file << c->GetName() << ", ";
			file << c->GetBrand() << ", ";
			file << c->GetPrice() << ", ";
			file << c->GetStock() << std::endl;
		}
	}
	file.close();
}


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
	std::cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << std::endl;
	std::cout << "                                                            褐敘 鼻ヶ 蛔煙" << std::endl;
	std::cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << std::endl;
	std::cout << std::endl;;
	std::cout << "菴煎 陛堅 談棻賊 -1 殮溘" << std::endl << std::endl;
	std::cout << "薯ヶ貲 : ";
	std::cin.clear();
	cin.ignore(999, '\n');								//幗ぷ 羶模 в蹂
	std::getline(std::cin, input, '\n');				// и還 瞪羹蒂 嫡嬴撿 л戲煎 getline() 餌辨
	if (static_cast<int>(atoi(input.c_str())) == -1)	// getline
		return;
	product->SetName(input);
	std::cout << "粽楠萄 : ";
	std::cin.clear();									// 嬪縑陛 getline 檜嘎煎 幗ぷ 羶模 碳в蹂
	std::getline(std::cin, input, '\n');				// и還 瞪羹蒂 嫡嬴撿 л戲煎 getline() 餌辨
	product->SetBrand(input);
	std::cout << "陛問 : ";
	num = InputFormat::IntCin();
	product->SetPrice(num);
	std::cout << "營堅 : ";
	num = InputFormat::IntCin();
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
	Sleep(1500);										//�飛� 雖翱
	system("cls");
	return;
}

//鼻ヶ 薑爾 餉薯
void ProductManager::DelObj()
{
	int id;
	char check;
	Product* product;

	system("cls");
	printProductForm(productList);
	std::cout << std::endl;;
	std::cout << std::endl;;
	std::cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << std::endl;
	std::cout << "                                                           鼻ヶ 薑爾 餉薯" << std::endl;
	std::cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << std::endl;
	std::cout << std::endl;
	std::cout << "菴煎 陛堅 談棻賊 -1 殮溘" << std::endl << std::endl;
	std::cout << "餉薯й 鼻ヶ曖 ID蒂 殮溘 п輿撮蹂 : ";
	id = InputFormat::IntCin();
	if (id == -1)
		return;
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
	product = productList.find(id)->second;				// 瓊嬴憮 贗塭檜樹お 偌羹蒂 й渡
	std::cout << product->GetName() << " 鼻ヶ 薑爾蒂 餉薯 ж衛啊蝗棲梱?" << std::endl;
	do
	{
		cin.ignore(999, '\n');							//幗ぷ 羶模
		std::cout << "[ Y / N ] : ";
		std::cin >> check;
		check = toupper(check);							// 渠僥濠 瞪��
	} while ((check != 'Y') && (check != 'N'));
	if (check == 'N')
		return;
	productList.erase(id);
	std::cout <<"[" << product->GetName() << "]" << " 鼻ヶ 薑爾蒂 餉薯ц蝗棲棻" << std::endl;
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

	std::cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << std::endl;
	std::cout << "                                                          鼻ヶ 薑爾 熱薑" << std::endl;
	std::cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << std::endl;
	std::cout << std::endl;
	std::cout << "菴煎 陛堅 談棻賊 -1 殮溘" << std::endl << std::endl;
	std::cout << "熱薑й 鼻ヶ曖 ID蒂 殮溘 п輿撮蹂 : ";
	id = InputFormat::IntCin();
	if (id == -1)
		return;
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
	product = productList.find(id)->second;				// 瓊嬴憮 贗塭檜樹お 偌羹蒂 й渡
	std::cout << "⑷營 薯ヶ貲 : [ " << product->GetName() << " ]" << std::endl;
	std::cout << "熱薑й 薯ヶ貲 : ";
	std::cin.clear();
	cin.ignore(999, '\n');								//幗ぷ 羶模 в蹂
	std::getline(std::cin, tmp, '\n');					// и還 瞪羹蒂 嫡嬴撿 л戲煎 getline() 餌辨
	product->SetName(tmp);
	std::cout << "⑷營 粽楠萄 : [ " << product->GetBrand() << " ]" << std::endl;
	std::cout << "熱薑й 粽楠萄 : ";
	std::cin.clear();
	std::getline(std::cin, tmp, '\n');					// и還 瞪羹蒂 嫡嬴撿 л戲煎 getline() 餌辨
	product->SetBrand(tmp);
	std::cout << "⑷營 陛問 : [ " << product->GetPrice() << " ]" << std::endl;
	std::cout << "熱薑й 陛問 : ";
	num = InputFormat::IntCin();
	product->SetPrice(num);
	std::cout << "⑷營 營堅 : [ " << product->GetStock() << " ]" << std::endl;
	std::cout << "熱薑й 營堅 : ";
	num = InputFormat::IntCin();
	product->SetStock(num);
	std::cout << std::endl;
	std::cout << "鼻ヶ 薑爾 熱薑 諫猿";
	Sleep(1500);
	system("cls");
}

//鼻ヶ 薑爾 匐儀
void ProductManager::SerchObj()
{
	string name;
	map<int, Product*> serchList;

	system("cls");

	std::cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << std::endl;
	std::cout << "                                                          鼻ヶ 薑爾 匐儀" << std::endl;
	std::cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << std::endl;
	std::cout << std::endl;

	std::cout << "匐儀й 渠鼻曖 薯ヶ貲擊 殮溘п 輿撮蹂 : ";
	std::cin.clear();
	cin.ignore(999, '\n');								//幗ぷ 羶模 в蹂
	std::getline(std::cin, name, '\n');					// и還 瞪羹蒂 嫡嬴撿 л戲煎 getline() 餌辨

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
	system("cls");
	printProductForm(serchList);
	std::cout << std::endl;
	std::cout << name << " 匐儀 唸婁" << std::endl;
	std::cout << std::endl;
	std::cout << "檜瞪 �飛橉虞� 給嬴陛溥賊 enter蒂 殮溘п 輿撮蹂...";
	while (getchar() != '\n');
	return;
}

// 鼻ヶ 薑爾 褻��
void ProductManager::PrintObj()
{
	system("cls");
	printProductForm(productList);
	std::cout << std::endl;
	std::cout << "檜瞪 �飛橉虞� 給嬴陛溥賊 enter蒂 殮溘п 輿撮蹂...";
	while (getchar() != '\n');
	getchar();											// 薯橫 �撣� 薑雖
	return;
}


void* ProductManager::TossObj(int id)
{
	Product* product = nullptr;
	try
	{
		product = productList.at(id);
	}
	catch (std::out_of_range e)
	{
		std::cout << "п渡ж朝 ID朝 襄營ж雖 彊蝗棲棻!!" << std::endl;
		Sleep(1000);
	}
	return product;
}

//轎溘 曄衝
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
		std::cout.width(P_ID_WIDTH);
		std::cout << itr->first;
		cout.fill(' ');						// 奢除 瓣遺擊 奢寥戲煎 棻衛 滲唳
		std::cout << " ";
		///////////////////// 薯ヶ貲 蘊 曄衝
		std::cout << "  ";
		std::cout.width(P_NAME_WIDTH);
		std::cout << product->GetName();
		std::cout << "  ";
		///////////////////// 粽楠萄 蘊 曄衝
		std::cout << "  ";
		std::cout.width(P_BRAND_WIDTH);
		std::cout << product->GetBrand();

		std::cout << "  ";
		///////////////////// 陛問 蘊 曄衝
		std::cout.width(P_PRICE_WIDTH);
		std::cout << product->GetPrice();
		std::cout << "  ";
		///////////////////// 營堅 蘊 曄衝
		std::cout.width(P_STOCK_WIDTH);
		std::cout << product->GetStock();
		std::cout << " 弛" << std::endl;
	}
	std::cout << "戌式式式式式式式扛式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扛式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扛式式式式式式式式式式式式式式式式式式式扛式式式式式式式式式式式式式式式式式戎" << std::endl;;
	return;
}

std::vector<string> ProductManager::parseCSV(std::istream& file, char delimiter)
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