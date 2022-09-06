#include "ProjectHeader.h"

#include <Windows.h>
#include <iostream>

int PrintUI::PrintMainUI()
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
	std::cout << std::endl;
	std::cout << "���� : ";
	choice = InputFormat::IntCin();
	return choice;
}

void PrintUI::PrintClientUI(Manager* CM)
{
	int choice = 0;

	do
	{
		system("cls");
		std::cout << "����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������" << std::endl;
		std::cout << "                                          �� ���� �޴�" << std::endl;
		std::cout << "����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������" << std::endl;
		std::cout << std::endl;
		std::cout << "1. �� ���" << std::endl;
		std::cout << "2. �� ���� ��ȸ" << std::endl;
		std::cout << "3. �� ���� �˻�" << std::endl;
		std::cout << "4. �� ���� ����" << std::endl;
		std::cout << "5. �� ���� ����" << std::endl;
		std::cout << "6. �ڷΰ���" << std::endl;
		std::cout << "���� : ";

		choice = InputFormat::IntCin();
		switch (choice)
		{
		case 1:
			system("cls"); //ȭ�� û��
			CM->AddObj();
			break;
		case 2:
			system("cls"); //ȭ�� û��
			CM->PrintObj();
			break;
		case 3:
			system("cls"); //ȭ�� û��
			CM->SerchObj();
			break;
		case 4:
			system("cls"); //ȭ�� û��
			CM->ModiObj();
			break;
		case 5:
			system("cls"); //ȭ�� û��
			CM->DelObj();
			break;
		case 6: // ���� ���� ȭ������
			system("cls"); //ȭ�� û��
			break;
		default:
			std::cout << "�߸��� ����Դϴ�" << std::endl;
			Sleep(1500);
			system("cls");
			break;
		}
	} while (choice != 6);
	return;
}

void PrintUI::PrintProductUI(Manager* PM)
{
	int choice = 0;

	do
	{
		system("cls");
		std::cout << "����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������" << std::endl;
		std::cout << "                                          ��ǰ ���� �޴�" << std::endl;
		std::cout << "����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������" << std::endl;
		std::cout << std::endl;
		std::cout << "1. ��ǰ ���" << std::endl;
		std::cout << "2. ��ǰ ���� ��ȸ" << std::endl;
		std::cout << "3. ��ǰ ���� �˻�" << std::endl;
		std::cout << "4. ��ǰ ���� ����" << std::endl;
		std::cout << "5. ��ǰ ���� ����" << std::endl;
		std::cout << "6. �ڷΰ���" << std::endl;
		std::cout << "���� : ";
		choice = InputFormat::IntCin();
		
		switch (choice)
		{
		case 1:
			system("cls"); //ȭ�� û��
			PM->AddObj();
			break;
		case 2:
			system("cls"); //ȭ�� û��
			PM->PrintObj();
			break;
		case 3:
			system("cls"); //ȭ�� û��
			PM->SerchObj();
			break;
		case 4:
			system("cls"); //ȭ�� û��
			PM->ModiObj();
			break;
		case 5:
			system("cls"); //ȭ�� û��
			PM->DelObj();
			break;
		case 6: // ���� ���� ȭ������
			system("cls"); //ȭ�� û��
			break;
		default:
			std::cout << "�߸��� ����Դϴ�" << std::endl;
			Sleep(1500);
			system("cls");
			break;
		}
	} while (choice != 6);

	return;
}

void PrintUI::PrintOrderUI(Manager* OM)
{
	int choice = 0;

	do
	{
		system("cls");
		std::cout << "����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������" << std::endl;
		std::cout << "                                      �ֹ� �̷� ���� �޴�" << std::endl;
		std::cout << "����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������" << std::endl;
		std::cout << std::endl;
		std::cout << "1. �ֹ� �̷� ���" << std::endl;
		std::cout << "2. �ֹ� �̷� ��ȸ" << std::endl;
		std::cout << "3. �ֹ� �̷� �˻�" << std::endl;
		std::cout << "4. �ֹ� �̷� ����" << std::endl;
		std::cout << "5. �ֹ� �̷� ����" << std::endl;
		std::cout << "6. �ڷΰ���" << std::endl;
		std::cout << "���� : ";

		choice = InputFormat::IntCin();
		switch (choice)
		{
		case 1:
			system("cls"); //ȭ�� û��
			OM->AddObj();
			break;
		case 2:
			system("cls"); //ȭ�� û��
			OM->PrintObj();
			break;
		case 3:
			system("cls"); //ȭ�� û��
			OM->SerchObj();
			break;
		case 4:
			system("cls"); //ȭ�� û��
			OM->ModiObj();
			break;
		case 5:
			system("cls"); //ȭ�� û��
			OM->DelObj();
			break;
		case 6: // ���� ���� ȭ������
			system("cls"); //ȭ�� û��
			break;
		default:
			std::cout << "�߸��� ����Դϴ�" << std::endl;
			Sleep(1500);
			system("cls");
			break;
		}
	} while (choice != 6);
	return;
}
