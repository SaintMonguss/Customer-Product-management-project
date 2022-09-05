#include "ProjectHeader.h"

#include <Windows.h>
#include <iostream>
#include <vector>

int PrintMainUI();
void PrintClientUI(Manager*);

int main()
{
	system("mode con:cols=135 lines=40");
	const Manager* CM = new ClientManager;
	const Manager* PM = new ProductManager;
	int choice = 0;

	do
	{
		choice = PrintMainUI();
		switch (choice)
		{
		case 1:
			PrintClientUI(CM);
			break;
		case 2:
			PrintProductUI();
			break;
		case 3:
			PrintOrderUI();
			break;
		case 4: // ����
			break;
		default:
			std::cout << "�߸��� ����Դϴ�" << std::endl;
			break;
		}



	} while (choice != 4);
	
	

	return 0;
}

int PrintMainUI()
{
	int choice;
	std::cout << "����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������" << std::endl;
	std::cout << "                                     �� ��ǰ ���� ���� ���α׷�" << std::endl;
	std::cout << "����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������" << std::endl;
	std::cout << std::endl;
	std::cout << "1. �� ����" << std::endl;
	std::cout << "2. ��ǰ ����" << std::endl;
	std::cout << "3. �ֹ�/�̷� ����" << std::endl;
	std::cout << "4. ����" << std::endl;
	std::cout << "���� : ";
	std::cin >> choice;
	return choice;
}

void PrintClientUI(Manager *CM)
{
	int choice = 0;

	do
	{
		std::cout << "����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������" << std::endl;
		std::cout << "                                          �� ���� �޴�" << std::endl;
		std::cout << "����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������" << std::endl;
		std::cout << std::endl;
		std::cout << "1. �� ���" << std::endl;
		std::cout << "2. �� ���� �˻�" << std::endl;
		std::cout << "3. �� ���� ����" << std::endl;
		std::cout << "4. �� ���� ����" << std::endl;
		std::cout << "5. �ڷΰ���" << std::endl;
		std::cout << "���� : ";
		std::cin >> choice;
	
		switch (choice)
		{
		case 1:
			CM->AddObj();
			break;
		case 2:
			CM->SerchObj();
			break;
		case 3:
			CM->ModiObj();
			break;
		case 4:
			CM->DelObj();
			break;
		case 5: // ���� ���� ȭ������
			break;
		default:
			std::cout << "�߸��� ����Դϴ�" << std::endl;
			Sleep(1500);
			system("cls");
			break;
		}
	} while (choice != 5);

	return;
}