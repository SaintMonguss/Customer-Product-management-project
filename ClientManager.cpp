#include "ProjectHeader.h"

#include <iostream>
#include <string>
#include <iomanip>
#include <stdio.h>
#include <windows.h>

ClientManager::ClientManager()
{
//	std::vector<Client*> vecList;
	std::ifstream file;
	file.open("clientlist.txt");
		if (!file.fail()) {
		while (!file.eof()) {
			std::vector<string> row = parseCSV(file, ',');
			if (row.size()) {
				int id = atoi(row[0].c_str());
				Client* c = new Client(id, row[1], row[2], row[3], row[4]);
				clientList.insert({ id, c });
//				vecList.push_back(c);
			}
		}
	}
	file.close();
}

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
	cin.ignore(999, '\n'); //���� û��
	std::getline(std::cin, input, '\n'); //TODO: 32���� ���� ������ �ְ� ���� �ؾ���
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
		std::cout << "Ű ID �ߺ� �߻�, �� �߰� ����" << std::endl;
		std::cout << std::endl;
		return;
	}
	std::cout << "�ű� �� ��� �Ϸ�!";
	Sleep(1500); //ȭ�� ����
	system("cls");
	return;
}

// �� ���� ����
void ClientManager::DelObj()
{
	int id;
	char check;
	Client *client;

	system("cls");
	printClientForm(clientList);
	std::cout << std::endl;;
	std::cout << std::endl;;
	std::cout << "����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������" << std::endl;
	std::cout << "                                           �� ���� ����" << std::endl;
	std::cout << "����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������" << std::endl;
	std::cout << std::endl; 
	std::cout << "������ ���� ID�� �Է� ���ּ��� : ";
	id = InputFormat::IntCin();

	try
	{
		clientList.at(id);
	}
	catch (std::out_of_range e)
	{
		std::cout << "�ش��ϴ� ID�� �������� �ʽ��ϴ�!!" << std::endl;
		Sleep(1000);
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
	std::cout << "[" << client->GetName() << "]" << " �� ������ �����߽��ϴ�" << std::endl;
	Sleep(1500);
	system("cls");
}
// �� ���� ����
void ClientManager::ModiObj()
{
	int id;
	Client* client;
	string tmp;

	std::cout << "����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������" << std::endl;
	std::cout << "                                           �� ���� ����" << std::endl;
	std::cout << "����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������" << std::endl;
	std::cout << std::endl;
	std::cout << "������ ���� ID�� �Է� ���ּ��� : ";
	id = InputFormat::IntCin();
	try
	{
		clientList.at(id);
	}
	catch (std::out_of_range e)
	{
		std::cout << "�ش��ϴ� ID�� �������� �ʽ��ϴ�!!" << std::endl;
		Sleep(1000);
		return;
	}
	client = clientList.find(id)->second; // ã�Ƽ� Ŭ���̾�Ʈ ��ü�� �Ҵ�
	std::cout << "���� �̸� : [ " << client->GetName() << " ]" << std::endl;
	std::cout << "������ �̸� : ";
	std::cin >> tmp;
	client->SetName(tmp);
	std::cout << "���� ��ȣ : [ " << client->GetPhoneNumber() << " ]" << std::endl;
	std::cout << "������ ��ȣ : ";
	std::cin >> tmp;
	client->SetPhoneNumber(tmp);
	std::cout << "���� �ּ� : [ " << client->GetAddress() << " ]" << std::endl;
	std::cout << "������ �ּ� : ";
	std::cin >> tmp;
	client->SetAddress(tmp);
	std::cout << "���� E-mail : [ " << client->GetEmail() << " ]" << std::endl;
	std::cout << "������ E-mail : ";
	std::cin >> tmp;
	client->SetEmail(tmp);
	std::cout << std::endl;
	std::cout << "�� ���� ���� �Ϸ�";
	Sleep(1500);
	system("cls");
}

// �� ���� �˻�
void ClientManager::SerchObj() 
{
	string name;
	map<int, Client*> serchList;

	system("cls");

	std::cout << "����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������" << std::endl;
	std::cout << "                                           �� ���� �˻�" << std::endl;
	std::cout << "����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������" << std::endl;
	std::cout << std::endl;

	std::cout << "�˻��� ����� �̸��� �Է��� �ּ��� : ";
	std::cin >> name;

	for (auto itr = clientList.begin(); itr != clientList.end(); itr++)
	{
		if (name == itr->second->GetName())
			serchList[itr->first] = itr->second;
	}
	if (serchList.empty())
	{
		std::cout << "[" << name << "]" << " �� �˻� ����� �����ϴ�...";
		Sleep(1500);
		return;
	}
	system("cls");
	printClientForm(serchList);
	std::cout << std::endl;
	std::cout << "[" << name << "]" << " �˻� ���" << std::endl;
	std::cout << std::endl;
	std::cout << "���� ȭ������ ���ư����� enter�� �Է��� �ּ���...";
	while (getchar() != '\n');
	getchar(); // ���� �帧 ����
	return;
	
}

//�� ���� ��ȸ
void ClientManager::PrintObj()
{
	system("cls");
	printClientForm(clientList);
	std::cout << std::endl;
	std::cout << "���� ȭ������ ���ư����� enter�� �Է��� �ּ���...";
	while (getchar() != '\n');
	getchar(); // ���� �帧 ����
	return;
}

//�� �Ѹ��� ������ �����ϴ� �Լ� / ��ȯ�� any ��
void* ClientManager::TossObj(int id)
{
	Client* client =nullptr;
	try
	{
		client = clientList.at(id);
	}
	catch (std::out_of_range e)
	{
		std::cout << "�ش��ϴ� ID�� �������� �ʽ��ϴ�!!" << std::endl;
		Sleep(1000);
	}
	
	return client;
}

// �� ���� ��� ���ø�
void ClientManager::printClientForm(map<int, Client*> &clientList) const
{
	Client* client;
	std::cout << "��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������" << std::endl;;
	std::cout << "��   ID       �̸�          ��ȣ                                      �ּ�                                       E-mail        ��" << std::endl;;
	for (auto itr = clientList.begin(); itr != clientList.end(); itr++)
	{
		client = itr->second;
		std::cout << "��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������" << std::endl;;
		std::cout << "�� ";
		///////////////////// ID ĭ ���
		cout.fill('0');
		std::cout.width(C_ID_WIDTH);
		std::cout << itr->first;
		cout.fill(' '); // ���� ä���� �������� �ٽ� ����
		std::cout << " ";
		///////////////////// �̸� ĭ ���
		std::cout << "  ";
		std::cout.width(C_NAME_WIDTH);
		std::cout << client->GetName();
		std::cout << "  ";
		///////////////////// ��ȣ ĭ ���
		std::cout << "  ";
		std::cout.width(C_PHONNUMBER_WIDTH);
		std::cout << client->GetPhoneNumber();
		std::cout << "  ";
		///////////////////// �ּ� ĭ ���
		std::cout.width(C_ADRESS_WIDTH);
		std::cout << client->GetAddress();
		std::cout << "  ";
		///////////////////// �̸��� ĭ ���
		std::cout.width(C_EMAIL_WIDTH);
		std::cout << client->GetEmail();
		std::cout << " ��" << std::endl;
	}
	std::cout << "��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������" << std::endl;;
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