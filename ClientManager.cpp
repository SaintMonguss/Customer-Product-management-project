#include "ProjectHeader.h"

#include <iostream>
#include <string>


ClientManager::ClientManager(map<int, Client*> CL) : clientList(CL) {};

//고객 정보 추가
void ClientManager::AddObj()
{
	string input;
	Client* client;
	int id;
	if (clientList.empty())
		id = 1;
	else
		id = (clientList.end()->first) + 1;
	try
	{
		client = new Client(id);
	}
	catch (const std::bad_alloc& e)
	{
		std::cout << "메모리 할당 실패";
		return;
	}
	std::cout << "이름 : ";
	std::cin >> input;
	client->SetName(input);
	std::cout << "연락처( - 없이 입력) : ";
	std::cin >> input;
	client->SetPhoneNumber(input);
	std::cout << "주소 : ";
	cin.ignore(10, '\n'); // 버퍼에 남은 개행 삭제
	std::getline(std::cin, input, '\n');
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
		std::cout << "키 ID 중복 발생, 고객 추가 실패" << std::endl;
		std::cout << std::endl;
	}
}

void ClientManager::DelObj(int id)
{
	
}
void ClientManager::ModiObj(int id)
{

}
void ClientManager::SerchObj(int id)
{

}
void ClientManager::SerchObj(string name)
{

}
void ClientManager::PrintObj()
{
	system("cls");
	std::cout << "┌───────┬───────────┬───────────────────────────────────────────────────────────────────────┐" << std::endl;;
	std::cout << "│   ID       이름             번호                 주소                   E-mail            │" << std::endl;;
	std::cout << "├───────┴───────────┴───────────────────────────────────────────────────────────────────────┤" << std::endl;;
	
	/*for(auto itr = clientList.begin(); itr != clientList.end(); itr++)
	{
			itr->second
	}*/

}