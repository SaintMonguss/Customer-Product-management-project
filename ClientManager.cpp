#include "ProjectHeader.h"

#include <iostream>
#include <string>
#include <iomanip>
#include <stdio.h>
#include <windows.h>


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
		id = (clientList.rbegin()->first) + 1;
	try
	{
		client = new Client(id);
	}
	catch (const std::bad_alloc& e)
	{
		std::cout << "�޸� �Ҵ� ����";
		return;
	}
	std::cout << "����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������" << std::endl;
	std::cout << "                                           �ű� �� ���                                   " << std::endl;
	std::cout << "����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������" << std::endl;
	std::cout << std::endl;;
	std::cout << "�̸� : ";
	std::cin >> input;
	client->SetName(input);
	std::cout << "����ó( - ���� �Է�) : ";
	std::cin >> input;
	client->SetPhoneNumber(input);
	std::cout << "�ּ� : ";
	cin.ignore(10, '\n'); // ���ۿ� ���� ���� ����
	std::getline(std::cin, input, '\n'); //TODO: 32���� ���� ������ �ְ� ���� �ؾ���
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
		return;
	}
	std::cout << "�ű� �� ��� �Ϸ�!";
	Sleep(1500); //ȭ�� ����
	system("cls");
	return;
}

void ClientManager::DelObj()
{
	int id;
	char check;
	Client *client;


	std::cout << "����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������" << std::endl;
	std::cout << "                                           �� ���� ����                                   " << std::endl;
	std::cout << "����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������" << std::endl;
	std::cout << std::endl;;
	PrintObj(); // �� ���� ��� 
	std::cout << std::endl;
	std::cout << "������ ���� ID�� �Է� ���ּ��� : ";
	cin.ignore(10,'\n'); //���� û��
	std::cin >> id;

	try
	{
		clientList.at(id);
	}
	catch (std::out_of_range e)
	{
		std::cout << "�ش��ϴ� ID�� �������� �ʽ��ϴ�!!" << std::endl;
		return;
	}
	client = clientList.find(id)->second; // ã�Ƽ� Ŭ���̾�Ʈ ��ü�� �Ҵ�
	std::cout << client->GetName() << " �� ������ ���� �Ͻðڽ��ϱ�?"<<std::endl;
	do
	{
		cin.ignore(999, '\n'); //���� û��
		std::cout << "[ Y / N ] : ";
		std::cin >> check;
		check = toupper(check); // �빮�� ��ȯ
	} while ((check != 'Y') && (check != 'N'));
	if (check == 'N')
		return;
	clientList.erase(id);
	std::cout << client->GetName() << " �� ������ �����߽��ϴ�" << std::endl;
	Sleep(1500);
	system("cls");
}
void ClientManager::ModiObj()
{

}
void ClientManager::SerchObj()
{
	system("cls");
	
}

void ClientManager::PrintObj()
{
	system("cls");
	std::cout << "��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������" << std::endl;;
	std::cout << "��   ID       �̸�          ��ȣ                                      �ּ�                                       E-mail        ��" << std::endl;;
	
	
	for(auto itr = clientList.begin(); itr != clientList.end(); itr++)
	{
		Client* client = itr->second;
		std::cout << "��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������" << std::endl;;
		std::cout << "�� ";
		///////////////////// ID ĭ ���
		cout.fill('0');
		std::cout.width(6);
		std::cout << itr->first;
		cout.fill(' '); // ���� ä���� �������� �ٽ� ����
		std::cout << " ";
		///////////////////// �̸� ĭ ���
		std::cout << "  ";
		std::cout.width(8);
		std::cout << client->GetName();
		std::cout << "  ";
		///////////////////// ��ȣ ĭ ���
		std::cout << "  ";
		std::cout.width(11);
		std::cout << client->GetPhonNumber();
		std::cout << "  ";
		///////////////////// �ּ� ĭ ���
		std::cout.width(63);
		std::cout << client->GetAdress();
		std::cout << "  ";
		///////////////////// �̸��� ĭ ���
		std::cout.width(24);
		std::cout << client->GetEmail();
		std::cout << " ��" <<std::endl;
	}

	std::cout << "��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������" << std::endl;;
}
