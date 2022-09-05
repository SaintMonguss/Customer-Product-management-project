#include "ProjectHeader.h"

#include <iostream>
#include <string>
#include <iomanip>
#include <stdio.h>
#include <windows.h>


ClientManager::ClientManager(map<int, Client*> CL) : clientList(CL) {};

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
	std::cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << std::endl;
	std::cout << "                                           褐敘 堅偌 蛔煙                                   " << std::endl;
	std::cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << std::endl;
	std::cout << std::endl;;
	std::cout << "檜葷 : ";
	std::cin >> input;
	client->SetName(input);
	std::cout << "翱塊籀( - 橈檜 殮溘) : ";
	std::cin >> input;
	client->SetPhoneNumber(input);
	std::cout << "輿模 : ";
	cin.ignore(999, '\n'); //幗ぷ 羶模
	std::getline(std::cin, input, '\n'); //TODO: 32旋濠 梱雖 嫡擊熱 氈啪 薯и п撿л
	client->SetAdress(input);
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
	Sleep(1500); //�飛� 雖翱
	system("cls");
	return;
}

void ClientManager::DelObj()
{
	int id;
	char check;
	Client *client;


	std::cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << std::endl;
	std::cout << "                                           堅偌 薑爾 餉薯                                   " << std::endl;
	std::cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << std::endl;
	std::cout << std::endl;;
	PrintObj(); // 堅偌 薑爾 轎溘 
	std::cout << std::endl;
	std::cout << "餉薯й 堅偌曖 ID蒂 殮溘 п輿撮蹂 : ";
	std::cin >> id;

	try
	{
		clientList.at(id);
	}
	catch (std::out_of_range e)
	{
		std::cout << "п渡ж朝 ID朝 襄營ж雖 彊蝗棲棻!!" << std::endl;
		return;
	}
	client = clientList.find(id)->second; // 瓊嬴憮 贗塭檜樹お 偌羹蒂 й渡
	std::cout << client->GetName() << " 堅偌 薑爾蒂 餉薯 ж衛啊蝗棲梱?"<<std::endl;
	do
	{
		cin.ignore(999, '\n'); //幗ぷ 羶模
		std::cout << "[ Y / N ] : ";
		std::cin >> check;
		check = toupper(check); // 渠僥濠 瞪��
	} while ((check != 'Y') && (check != 'N'));
	if (check == 'N')
		return;
	clientList.erase(id);
	std::cout << client->GetName() << " 堅偌 薑爾蒂 餉薯ц蝗棲棻" << std::endl;
	Sleep(1500);
	system("cls");
}

void ClientManager::ModiObj()
{
	int id;
	Client* client;
	string tmp;

	std::cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << std::endl;
	std::cout << "                                           堅偌 薑爾 熱薑                                   " << std::endl;
	std::cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << std::endl;
	std::cout << std::endl;
	std::cout << "熱薑й 堅偌曖 ID蒂 殮溘 п輿撮蹂 : ";
	std::cin >> id;
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
	client = clientList.find(id)->second; // 瓊嬴憮 贗塭檜樹お 偌羹蒂 й渡
	std::cout << "⑷營 檜葷 : [ " << client->GetName() << " ]" << std::endl;
	std::cout << "熱薑й 檜葷 : ";
	std::cin >> tmp;
	client->SetName(tmp);
	std::cout << "⑷營 廓�� : [ " << client->GetPhoneNumber() << " ]" << std::endl;
	std::cout << "熱薑й 廓�� : ";
	std::cin >> tmp;
	client->SetPhoneNumber(tmp);
	std::cout << "⑷營 輿模 : [ " << client->GetAdress() << " ]" << std::endl;
	std::cout << "熱薑й 輿模 : ";
	std::cin >> tmp;
	client->SetAdress(tmp);
	std::cout << "⑷營 E-mail : [ " << client->GetEmail() << " ]" << std::endl;
	std::cout << "熱薑й E-mail : ";
	std::cin >> tmp;
	client->SetEmail(tmp);
	std::cout << std::endl;
	std::cout << "堅偌 薑爾 熱薑 諫猿";
	Sleep(1500);
	system("cls");
}

void ClientManager::SerchObj()
{
	string name;
	map<int, Client*> serchList;

	system("cls");

	std::cout << "匐儀й 渠鼻曖 檜葷擊 殮溘п 輿撮蹂 : ";
	cin.ignore(999, '\n'); //幗ぷ 羶模
	std::cin >> name;

	for (auto itr = clientList.begin(); itr != clientList.end(); itr++)
	{
		if (name == itr->second->GetName())
			serchList[itr->first] = itr->second;
	}
	printClientForm(serchList);
	std::cout << std::endl;
	std::cout << name << " 匐儀 唸婁" << std::endl;
	return;
	
}

void ClientManager::PrintObj()
{
	system("cls");
	printClientForm(clientList);
	return;
}

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
		std::cout.width(6);
		std::cout << itr->first;
		cout.fill(' '); // 奢除 瓣遺擊 奢寥戲煎 棻衛 滲唳
		std::cout << " ";
		///////////////////// 檜葷 蘊 曄衝
		std::cout << "  ";
		std::cout.width(8);
		std::cout << client->GetName();
		std::cout << "  ";
		///////////////////// 廓�� 蘊 曄衝
		std::cout << "  ";
		std::cout.width(11);
		std::cout << client->GetPhoneNumber();
		std::cout << "  ";
		///////////////////// 輿模 蘊 曄衝
		std::cout.width(63);
		std::cout << client->GetAdress();
		std::cout << "  ";
		///////////////////// 檜詭橾 蘊 曄衝
		std::cout.width(24);
		std::cout << client->GetEmail();
		std::cout << " 弛" << std::endl;
	}
	std::cout << "戌式式式式式式式扛式式式式式式式式式式式扛式式式式式式式式式式式式式式扛式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扛式式式式式式式式式式式式式式式式式式式式式式式式式戎" << std::endl;;
	return;
}

