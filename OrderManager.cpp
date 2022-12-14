#include "ProjectHeader.h"

#include <iostream>
#include <string>
#include <iomanip>
#include <stdio.h>
#include <windows.h>

// 儅撩濠 だ橾 碳楝螃晦
OrderManager::OrderManager(Manager* CM, Manager* PM) : CM(CM), PM(PM) 
{
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
			}
		}
	}
	file.close();
};

//模資濠 だ橾 盪濰
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



//輿僥 薑爾 蹺陛
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
		std::cout << "詭賅葬 й渡 褒ぬ";
		return;
	}
	std::cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << std::endl;
	std::cout << "                                                            褐敘 輿僥 蛔煙" << std::endl;
	std::cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << std::endl;
	std::cout << std::endl;;
	std::cout << "菴煎 陛堅 談棻賊 -1 殮溘" << std::endl << std::endl;
	do
	{
		std::cout << "鼻ヶ ID : ";
		num = InputFormat::IntCin();
		if (num == -1)
		{
			return;
		}
	} while (!(PM->TossObj(num)));							// 蕨諼 羹觼
	product = static_cast<Product*>(PM->TossObj(num));		//void* 蒂 Product*煎 議蝶たи菴 檜葷擊 嫡嬴諦憮 input縑 渠殮
	input = product -> GetName(); 
	stockCheck = product->GetStock();						// ⑷營 熱榆 盪濰
	order->SetProductId(num);
	order->SetProductName(input);
	do
	{
		std::cout << "輿僥 陳濠 [喇] (yyyy) : ";
		num = InputFormat::IntCin();
	} while (!date.SetYear(num));
	do
	{
		std::cout << "輿僥 陳濠 [錯] (mm): ";
		num = InputFormat::IntCin();
	} while (!date.SetMonth(num));
	do
	{
		std::cout << "輿僥 陳濠 [橾] (dd): ";
		num = InputFormat::IntCin();
	} while (!date.SetDay(num));
	order->SetDate(date);

	std::cout << "掘衙濠 ID : ";
	num = InputFormat::IntCin();
	order->SetClientId(num);
	// 輿僥 熱榆 撲薑
	std::cout << "掘衙 熱榆 : ";
	num = InputFormat::IntCin();

	order->SetOrderStock(num);
	if (stockCheck < num)
	{
		std::wcout << std::endl;
		std::cout << "唳堅! ⑷營 鼻ヶ 熱榆爾棻 輿僥榆檜 號蝗棲棻. �挫怹� в蹂м棲棻. " << std::endl;
	}
	// 輿僥 陛問 撲薑
	order->SetOrderPrice(product->GetPrice());
	Sleep(1500); //�飛� 雖翱
	
	try
	{
		auto tmp = (orderList.insert({ id, order }));
		if (tmp.second == false)
			throw;
	}
	catch (...)
	{
		std::cout << std::endl;
		std::cout << "酈 ID 醞犒 嫦儅, 輿僥 檜溘 蹺陛 褒ぬ" << std::endl;
		std::cout << std::endl;
		return;
	}
	std::cout << std::endl;
	std::cout << "輿僥 檜溘 蛔煙 諫猿!";
	Sleep(1500);											//�飛� 雖翱
	system("cls");
	return;
}

// 輿僥 薑爾 餉薯
void OrderManager::DelObj()
{
	int id;
	char check;
	Order *order;

	system("cls");
	printOrderForm(orderList);
	std::cout << std::endl;;
	std::cout << std::endl;;
	std::cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << std::endl;
	std::cout << "                                                          輿僥 檜溘 餉薯" << std::endl;
	std::cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << std::endl;

	std::cout << std::endl; 
	std::cout << "菴煎 陛堅 談棻賊 -1 殮溘" << std::endl << std::endl;
	std::cout << "餉薯й 輿僥曖 ID蒂 殮溘 п輿撮蹂 : ";
	id = InputFormat::IntCin();
	if (id == -1)
		return;
	try
	{
		orderList.at(id);
	}
	catch (std::out_of_range e)
	{
		std::cout << "п渡ж朝 輿僥 ID朝 襄營ж雖 彊蝗棲棻!!" << std::endl;
		Sleep(1000);
		return;
	}
	order = orderList.find(id)->second;					// 瓊嬴憮 贗塭檜樹お 偌羹蒂 й渡
	std::cout << "[" << order->GetOrderId() << "]" << " 廓 輿僥 檜溘擊 餉薯 ж衛啊蝗棲梱?" << std::endl;
	do
	{
		cin.ignore(999, '\n');							//幗ぷ 羶模
		std::cout << "[ Y / N ] : ";
		std::cin >> check;
		check = toupper(check);							// 渠僥濠 瞪��
	} while ((check != 'Y') && (check != 'N'));
	if (check == 'N')
		return;
	orderList.erase(id);
	std::cout << "[" << order->GetOrderId() << "]" << " 廓 輿僥 檜溘擊 餉薯ц蝗棲棻" << std::endl;
	Sleep(1500);
	system("cls");
}
// 輿僥 檜溘 熱薑
void OrderManager::ModiObj()
{
	int id;
	int num;
	Date date;
	Order* order;
	string tmp;

	std::cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << std::endl;
	std::cout << "                                                       輿僥 檜溘 熱薑" << std::endl;
	std::cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << std::endl;
	std::cout << std::endl;
	std::cout << "熱薑й 熱 氈朝 о跡擎 輿僥 熱榆婁 陳瞼殮棲棻.";
	std::cout << std::endl;
	std::cout << "菴煎 陛堅 談棻賊 -1 殮溘" << std::endl << std::endl;
	std::cout << "熱薑й 輿僥曖 ID蒂 殮溘 п輿撮蹂 : ";
	id = InputFormat::IntCin();
	if (id == -1)
		return;
	try
	{
		orderList.at(id);
	}
	catch (std::out_of_range e)
	{
		std::cout << "п渡ж朝 ID朝 襄營ж雖 彊蝗棲棻!!" << std::endl;
		Sleep(1000);
		return;
	}
	order = orderList.find(id)->second;					// 瓊嬴憮 贗塭檜樹お 偌羹蒂 й渡
	std::cout << "⑷營 熱榆 : [ " << order->GetOrderStock() << " ]" << std::endl;
	std::cout << "熱薑й 熱榆 : ";
	num = InputFormat::IntCin();
	order->SetOrderStock(num);
	std::cout << "⑷營 陳瞼 : [ " 
		<< order->GetDate().GetYear()<< "喇 " 
		<< order->GetDate().GetMonth() << "錯 "
		<< order->GetDate().GetDay() << "橾" 
		<< "]" << std::endl;
	do
	{
		std::cout << "熱薑й 陳濠 [喇] (yyyy) : ";
		num = InputFormat::IntCin();
	} while (!date.SetYear(num));
	do
	{
		std::cout << "輿僥 陳濠 [錯] (mm): ";
		num = InputFormat::IntCin();
	} while (!date.SetMonth(num));
	do
	{
		std::cout << "輿僥 陳濠 [橾] (dd): ";
		num = InputFormat::IntCin();
	} while (!date.SetDay(num));
	order->SetDate(date);

	std::cout << "輿僥 薑爾 熱薑 諫猿";
	Sleep(1500);
	system("cls");
}

// 輿僥 薑爾 匐儀
void OrderManager::SerchObj() 
{
	int id;
	map<int, Order*> serchList;

	system("cls");

	std::cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << std::endl;
	std::cout << "                                                          輿僥 檜溘 匐儀" << std::endl;
	std::cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << std::endl;
	std::cout << std::endl;
	std::cout << "菴煎 陛堅 談棻賊 -1 殮溘" << std::endl << std::endl;
	std::cout << "匐儀й 檜溘曖 掘衙濠 ID蒂 殮溘п 輿撮蹂 : ";
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
		std::cout << "[" << id << "]" << " 堅偌曖 輿僥 檜溘檜 橈蝗棲棻...";
		Sleep(1500);
		return;
	}
	system("cls");
	printOrderForm(serchList);
	std::cout << std::endl;
	std::cout << "[" << id << "]" << " 輿僥 檜溘 匐儀 唸婁" << std::endl;
	std::cout << std::endl;
	std::cout << "檜瞪 �飛橉虞� 給嬴陛溥賊 enter蒂 殮溘п 輿撮蹂...";
	while (getchar() != '\n');
	getchar();										// 薯橫 �撣� 薑雖
	return;
	
}

//輿僥 薑爾 褻��
void OrderManager::PrintObj()
{
	system("cls");
	printOrderForm(orderList);
	std::cout << std::endl;
	std::cout << "檜瞪 �飛橉虞� 給嬴陛溥賊 enter蒂 殮溘п 輿撮蹂...";
	while (getchar() != '\n');
	getchar();										// 薯橫 �撣� 薑雖
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
		std::cout << "п渡ж朝 ID朝 襄營ж雖 彊蝗棲棻!!" << std::endl;
		Sleep(1000);
	}
	return order;
}


// 堅偌 婦溼 轎溘 蠱Ы葩
void OrderManager::printOrderForm(map<int, Order*> &orderList) const
{
	Order* order;
	std::cout << "忙式式式式式式式成式式式式式式式式式式式式式式式式式式式成式式式式式式式式式式成式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式成式式式式式式式式成式式式式式式式式式式式式式式式式式式成式式式式式式式式式式式式式式忖" << std::endl;;
	std::cout << "弛   ID          輿僥橾        掘衙濠 ID                      鼻ヶ 檜葷                鼻ヶ ID         陛問            熱榆     弛" << std::endl;;
	for (auto itr = orderList.begin(); itr != orderList.end(); itr++)
	{
		order = itr->second;
		std::cout << "戍式式式式式式式托式式式式式式式式式式式式式式式式式式式托式式式式式式式式式式托式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式托式式式式式式式式托式式式式式式式式式式式式式式式式式式托式式式式式式式式式式式式式式扣" << std::endl;;
		std::cout << "弛 ";
		///////////////////// ID 蘊 曄衝
		cout.fill('0');
		std::cout.width(O_ID_WIDTH);
		std::cout << itr->first;
		cout.fill(' ');								// 奢除 瓣遺擊 奢寥戲煎 棻衛 滲唳
		std::cout << " ";
		///////////////////// 陳瞼 曄衝
		std::cout << "   ";
		std::cout << order->GetDate().GetYear() << "喇 ";
		std::cout.width(2);
		std::cout << order->GetDate().GetMonth();
		std::cout << "錯 ";
		std::cout.width(2);
		std::cout << order->GetDate().GetDay();
		std::cout << "橾";
		std::cout << "  ";
		///////////////////// 掘衙濠 嬴檜蛤 曄衝
		std::cout << "  ";
		std::cout.width(O_CLIENTID_WIDTH);
		cout.fill('0');
		std::cout << order->GetClientId();
		cout.fill(' ');								// 奢除 瓣遺擊 奢寥戲煎 棻衛 滲唳
		std::cout << "  ";
		///////////////////// 薯ヶ 貲 曄衝
		std::cout << "  ";
		std::cout.width(O_PRODUCTNAME_WIDTH);
		std::cout << order->GetProductName();
		std::cout << " ";
		///////////////////// 薯ヶ ID 曄衝
		std::cout << "  ";
		cout.fill('0');
		std::cout.width(O_PRODUCTID_WIDTH);
		std::cout << order->GetProductId();
		cout.fill(' ');								// 奢除 瓣遺擊 奢寥戲煎 棻衛 滲唳
		std::cout << " ";
		///////////////////// 陛問 曄衝
		std::cout << "  ";
		std::cout.width(O_PRICE_WIDTH);
		std::cout << order->GetOrderPrice();
		std::cout << " ";
		///////////////////// 熱榆 曄衝
		std::cout.width(O_STOCK_WIDTH);
		std::cout << order->GetOrderStock();
		std::cout << " 弛" << std::endl;
	}
	std::cout << "戌式式式式式式式扛式式式式式式式式式式式式式式式式式式式扛式式式式式式式式式式扛式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扛式式式式式式式式扛式式式式式式式式式式式式式式式式式式扛式式式式式式式式式式式式式式戎" << std::endl;;
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