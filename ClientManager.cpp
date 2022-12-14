#include "ProjectHeader.h"

#include <iostream>
#include <string>
#include <iomanip>
#include <stdio.h>
#include <windows.h>

//だ橾 碳楝螃晦
ClientManager::ClientManager()
{
	std::ifstream file;
	file.open("clientlist.txt");
		if (!file.fail()) {
		while (!file.eof()) {
			std::vector<string> row = parseCSV(file, ',');
			if (row.size()) {
				int id = atoi(row[0].c_str());
				Client* c = new Client(id, row[1], row[2], row[3], row[4]);
				clientList.insert({ id, c });
			}
		}
	}
	file.close();
}

//だ橾 盪濰
ClientManager::~ClientManager()
{
	std::ofstream file;
	file.open("clientlist.txt");
	if (!file.fail()) {
		for (const auto& v : clientList) {
			Client* c = v.second;
			file << c->GetId() << ", ";
			file << c->GetName() << ", ";
			file << c->GetPhoneNumber() << ", ";
			file << c->GetAddress() << ", ";
			file << c->GetEmail() << std::endl;
		}
	}
	file.close();
}


//堅偌 薑爾 蹺陛
void ClientManager::AddObj()
{
	string input;
	Client* client;
	int id;

	if (clientList.empty())
		id = 1;
	else
		id = (clientList.rbegin()->first) + 1;
	try
	{
		client = new Client(id);
	}
	catch (const std::bad_alloc& e)
	{
		std::cout << "詭賅葬 й渡 褒ぬ";
		return;
	}
	std::cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << std::endl;
	std::cout << "                                                           褐敘 堅偌 蛔煙" << std::endl;
	std::cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << std::endl;
	std::cout << std::endl;;
	std::cout << "菴煎 陛堅 談棻賊 -1 殮溘" << std::endl << std::endl;
	std::cout << "檜葷 : ";
	std::cin >> input;
	if (atoi(input.c_str()) == -1)
		return;
	client->SetName(input);
	std::cout << "翱塊籀( - 橈檜 殮溘) : ";
	std::cin >> input;
	client->SetPhoneNumber(input);
	std::cout << "輿模 : ";
	cin.ignore(999, '\n');						//幗ぷ 羶模
	std::getline(std::cin, input, '\n');		// и還 瞪羹蒂 嫡嬴撿 л戲煎 getline() 餌辨
	client->SetAddress(input);
	std::cout << "E-mail : ";
	std::cin >> input;
	client->SetEmail(input);
	try
	{
		auto tmp = (clientList.insert({ id, client }));
		if (tmp.second == false)
			throw;
	}
	catch (...)
	{
		std::cout << std::endl;
		std::cout << "酈 ID 醞犒 嫦儅, 堅偌 蹺陛 褒ぬ" << std::endl;
		std::cout << std::endl;
		return;
	}
	std::cout << "褐敘 堅偌 蛔煙 諫猿!";
	Sleep(1500);								//�飛� 雖翱
	system("cls");
	return;
}

// 堅偌 薑爾 餉薯
void ClientManager::DelObj()
{
	int id;
	char check;
	Client *client;

	system("cls");
	printClientForm(clientList);
	std::cout << std::endl;;
	std::cout << std::endl;;
	std::cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << std::endl;
	std::cout << "                                                         堅偌 薑爾 餉薯" << std::endl;
	std::cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << std::endl;
	std::cout << std::endl; 
	std::cout << "菴煎 陛堅 談棻賊 -1 殮溘" << std::endl << std::endl;
	std::cout << "餉薯й 堅偌曖 ID蒂 殮溘 п輿撮蹂 : ";
	id = InputFormat::IntCin();
	if (id == -1)
		return;
	try
	{
		clientList.at(id);
	}
	catch (std::out_of_range e)
	{
		std::cout << "п渡ж朝 ID朝 襄營ж雖 彊蝗棲棻!!" << std::endl;
		Sleep(1000);
		return;
	}
	client = clientList.find(id)->second;			// 瓊嬴憮 贗塭檜樹お 偌羹蒂 й渡
	std::cout << client->GetName() << " 堅偌 薑爾蒂 餉薯 ж衛啊蝗棲梱?"<<std::endl;
	do
	{
		cin.ignore(999, '\n');						//幗ぷ 羶模
		std::cout << "[ Y / N ] : ";
		std::cin >> check;
		check = toupper(check);						// 渠僥濠 瞪��
	} while ((check != 'Y') && (check != 'N'));
	if (check == 'N')
		return;
	clientList.erase(id);
	std::cout << "[" << client->GetName() << "]" << " 堅偌 薑爾蒂 餉薯ц蝗棲棻" << std::endl;
	Sleep(1500);
	system("cls");
}
// 堅偌 薑爾 熱薑
void ClientManager::ModiObj()
{
	int id;
	Client* client;
	string tmp;

	std::cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << std::endl;
	std::cout << "                                                            堅偌 薑爾 熱薑" << std::endl;
	std::cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << std::endl;
	std::cout << std::endl;
	std::cout << "菴煎 陛堅 談棻賊 -1 殮溘" << std::endl << std::endl;
	std::cout << "熱薑й 堅偌曖 ID蒂 殮溘 п輿撮蹂 : ";
	id = InputFormat::IntCin();
	if (id == -1)
		return;
	try
	{
		clientList.at(id);
	}
	catch (std::out_of_range e)
	{
		std::cout << "п渡ж朝 ID朝 襄營ж雖 彊蝗棲棻!!" << std::endl;
		Sleep(1000);
		return;
	}
	client = clientList.find(id)->second;			// 瓊嬴憮 贗塭檜樹お 偌羹蒂 й渡
	std::cout << "⑷營 檜葷 : [ " << client->GetName() << " ]" << std::endl;
	std::cout << "熱薑й 檜葷 : ";
	std::cin >> tmp;
	client->SetName(tmp);
	std::cout << "⑷營 廓�� : [ " << client->GetPhoneNumber() << " ]" << std::endl;
	std::cout << "熱薑й 廓�� : ";
	std::cin >> tmp;
	client->SetPhoneNumber(tmp);
	std::cout << "⑷營 輿模 : [ " << client->GetAddress() << " ]" << std::endl;
	std::cout << "熱薑й 輿模 : ";
	std::cin.clear();
	cin.ignore(999, '\n');							//幗ぷ 羶模 в蹂
	std::getline(std::cin, tmp, '\n');				// и還 瞪羹蒂 嫡嬴撿 л戲煎 getline() 餌辨
	client->SetAddress(tmp);
	std::cout << "⑷營 E-mail : [ " << client->GetEmail() << " ]" << std::endl;
	std::cout << "熱薑й E-mail : ";
	std::cin >> tmp;
	client->SetEmail(tmp);
	std::cout << std::endl;
	std::cout << "堅偌 薑爾 熱薑 諫猿";
	Sleep(1500);
	system("cls");
}

// 堅偌 薑爾 匐儀
void ClientManager::SerchObj() 
{
	string name;
	map<int, Client*> serchList;

	system("cls");

	std::cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << std::endl;
	std::cout << "                                                        堅偌 薑爾 匐儀" << std::endl;
	std::cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << std::endl;
	std::cout << std::endl;

	std::cout << "匐儀й 渠鼻曖 檜葷擊 殮溘п 輿撮蹂 : ";
	std::cin >> name;

	for (auto itr = clientList.begin(); itr != clientList.end(); itr++)
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
	printClientForm(serchList);
	std::cout << std::endl;
	std::cout << "[" << name << "]" << " 匐儀 唸婁" << std::endl;
	std::cout << std::endl;
	std::cout << "檜瞪 �飛橉虞� 給嬴陛溥賊 enter蒂 殮溘п 輿撮蹂...";
	while (getchar() != '\n');
	getchar(); // 薯橫 �撣� 薑雖
	return;
	
}

//堅偌 薑爾 褻��
void ClientManager::PrintObj()
{
	system("cls");
	printClientForm(clientList);
	std::cout << std::endl;
	std::cout << "檜瞪 �飛橉虞� 給嬴陛溥賊 enter蒂 殮溘п 輿撮蹂...";
	while (getchar() != '\n');
	getchar(); // 薯橫 �撣� 薑雖
	return;
}

//堅偌 и貲曖 薑爾蒂 葬欐ж朝 л熱 / 奩�秣� any ⑽
void* ClientManager::TossObj(int id)
{
	Client* client =nullptr;
	try
	{
		client = clientList.at(id);
	}
	catch (std::out_of_range e)
	{
		std::cout << "п渡ж朝 ID朝 襄營ж雖 彊蝗棲棻!!" << std::endl;
		Sleep(1000);
	}
	
	return client;
}

// 堅偌 婦溼 轎溘 蠱Ы葩
void ClientManager::printClientForm(map<int, Client*> &clientList) const
{
	Client* client;
	std::cout << "忙式式式式式式式成式式式式式式式式式式式成式式式式式式式式式式式式式式成式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式成式式式式式式式式式式式式式式式式式式式式式式式式式忖" << std::endl;;
	std::cout << "弛   ID       檜葷          廓��                                      輿模                                       E-mail        弛" << std::endl;;
	for (auto itr = clientList.begin(); itr != clientList.end(); itr++)
	{
		client = itr->second;
		std::cout << "戍式式式式式式式托式式式式式式式式式式式托式式式式式式式式式式式式式式托式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式托式式式式式式式式式式式式式式式式式式式式式式式式式扣" << std::endl;;
		std::cout << "弛 ";
		///////////////////// ID 蘊 曄衝
		cout.fill('0');
		std::cout.width(C_ID_WIDTH);
		std::cout << itr->first;
		cout.fill(' ');								// 奢除 瓣遺擊 奢寥戲煎 棻衛 滲唳
		std::cout << " ";
		///////////////////// 檜葷 蘊 曄衝
		std::cout << "  ";
		std::cout.width(C_NAME_WIDTH);
		std::cout << client->GetName();
		std::cout << "  ";
		///////////////////// 廓�� 蘊 曄衝
		std::cout << "  ";
		std::cout.width(C_PHONNUMBER_WIDTH);
		std::cout << client->GetPhoneNumber();
		std::cout << "  ";
		///////////////////// 輿模 蘊 曄衝
		std::cout.width(C_ADRESS_WIDTH);
		std::cout << client->GetAddress();
		std::cout << "  ";
		///////////////////// 檜詭橾 蘊 曄衝
		std::cout.width(C_EMAIL_WIDTH);
		std::cout << client->GetEmail();
		std::cout << " 弛" << std::endl;
	}
	std::cout << "戌式式式式式式式扛式式式式式式式式式式式扛式式式式式式式式式式式式式式扛式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扛式式式式式式式式式式式式式式式式式式式式式式式式式戎" << std::endl;;
	return;
}

std::vector<string> ClientManager::parseCSV(std::istream& file, char delimiter)
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