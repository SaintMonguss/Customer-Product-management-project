#include "ProjectHeader.h"

#include <iostream>
#include <string>


ClientManager::ClientManager(map<int, Client*> CL) : clientList(CL) {};

//�� ���� �߰�
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
		std::cout << "�޸� �Ҵ� ����";
		return;
	}
	std::cout << "�̸� : ";
	std::cin >> input;
	client->SetName(input);
	std::cout << "����ó( - ���� �Է�) : ";
	std::cin >> input;
	client->SetPhoneNumber(input);
	std::cout << "�ּ� : ";
	cin.ignore(10, '\n'); // ���ۿ� ���� ���� ����
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
		std::cout << "Ű ID �ߺ� �߻�, �� �߰� ����" << std::endl;
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
	std::cout << "������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������" << std::endl;;
	std::cout << "��   ID       �̸�             ��ȣ                 �ּ�                   E-mail            ��" << std::endl;;
	std::cout << "������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������" << std::endl;;
	
	/*for(auto itr = clientList.begin(); itr != clientList.end(); itr++)
	{
			itr->second
	}*/

}