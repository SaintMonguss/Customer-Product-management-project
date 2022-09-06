#include "ProjectHeader.h"

#include <iostream>
#include <string>
#include <iomanip>
#include <stdio.h>
#include <windows.h>


OrderManager::OrderManager(Manager* CM, Manager* PM) : CM(CM), PM(PM) {};

//�ֹ� ���� �߰�
void OrderManager::AddObj()
{
	string input;
	Order* order;
	Product *product;
	Date date;
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
		std::cout << "�޸� �Ҵ� ����";
		return;
	}
	std::cout << "����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������" << std::endl;
	std::cout << "                                           �ű� �ֹ� ���" << std::endl;
	std::cout << "����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������" << std::endl;
	std::cout << std::endl;;
	std::cout << "�ڷ� ���� �ʹٸ� -1 �Է�" << std::endl << std::endl;
	do
	{
		std::cout << "��ǰ ID : ";
		num = InputFormat::IntCin();
		if (num == -1)
		{
			return;
		}
	} while (!(PM->TossObj(num))); // ���� üũ
	product = static_cast<Product*>(PM->TossObj(num));
	input = product -> GetName(); //std::any�� Product*�� ĳ�����ѵ� �̸��� �޾ƿͼ� input�� ����
	order->SetProductName(input);
	do
	{
		std::cout << "�ֹ� ���� [��] (yyyy) : ";
		num = InputFormat::IntCin();
	} while (!date.SetYear(num));
	do
	{
		std::cout << "�ֹ� ���� [��] (mm): ";
		num = InputFormat::IntCin();
	} while (!date.SetMonth(num));
	do
	{
		std::cout << "�ֹ� ���� [��] (dd): ";
		num = InputFormat::IntCin();
	} while (!date.SetDay(num));
	order->SetDate(date);

	std::cout << "������ ID : ";
	num = InputFormat::IntCin();
	order->SetClientId(num);
	// �ֹ� ���� ����
	std::cout << "���� ���� : ";
	num = InputFormat::IntCin();
	order->SetOrderStock(num);
	// �ֹ� ���� ����
	order->SetOrderPrice(product->GetPrice());
	

	try
	{
		auto tmp = (orderList.insert({ id, order }));
		if (tmp.second == false)
			throw;
	}
	catch (...)
	{
		std::cout << std::endl;
		std::cout << "Ű ID �ߺ� �߻�, �ֹ� �̷� �߰� ����" << std::endl;
		std::cout << std::endl;
		return;
	}
	std::cout << "�ֹ� �̷� ��� �Ϸ�!";
	Sleep(1500); //ȭ�� ����
	system("cls");
	return;
}

// �ֹ� ���� ����
void OrderManager::DelObj()
{
	int id;
	char check;
	Order *order;

	system("cls");
	printOrderForm(orderList);
	std::cout << std::endl;;
	std::cout << std::endl;;
	std::cout << "����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������" << std::endl;
	std::cout << "                                           �ֹ� �̷� ����" << std::endl;
	std::cout << "����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������" << std::endl;
	std::cout << std::endl; 
	std::cout << "������ �ֹ��� ID�� �Է� ���ּ��� : ";
	id = InputFormat::IntCin();

	try
	{
		orderList.at(id);
	}
	catch (std::out_of_range e)
	{
		std::cout << "�ش��ϴ� �ֹ� ID�� �������� �ʽ��ϴ�!!" << std::endl;
		Sleep(1000);
		return;
	}
	order = orderList.find(id)->second; // ã�Ƽ� Ŭ���̾�Ʈ ��ü�� �Ҵ�
	std::cout << "[" << order->GetOrderId() << "]" << " �� �ֹ� �̷��� ���� �Ͻðڽ��ϱ�?" << std::endl;
	do
	{
		cin.ignore(999, '\n'); //���� û��
		std::cout << "[ Y / N ] : ";
		std::cin >> check;
		check = toupper(check); // �빮�� ��ȯ
	} while ((check != 'Y') && (check != 'N'));
	if (check == 'N')
		return;
	orderList.erase(id);
	std::cout << "[" << order->GetOrderId() << "]" << " �� �ֹ� �̷��� �����߽��ϴ�" << std::endl;
	Sleep(1500);
	system("cls");
}
// �ֹ� �̷� ����
void OrderManager::ModiObj()
{
	int id;
	int num;
	Date date;
	Order* order;
	string tmp;

	std::cout << "����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������" << std::endl;
	std::cout << "                                           �ֹ� �̷� ����" << std::endl;
	std::cout << "����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������" << std::endl;
	std::cout << std::endl;
	std::cout << "������ �� �ִ� �׸��� �ֹ� ������ ��¥�Դϴ�.";
	std::cout << std::endl;
	std::cout << "������ �ֹ��� ID�� �Է� ���ּ��� : ";
	id = InputFormat::IntCin();
	try
	{
		orderList.at(id);
	}
	catch (std::out_of_range e)
	{
		std::cout << "�ش��ϴ� ID�� �������� �ʽ��ϴ�!!" << std::endl;
		Sleep(1000);
		return;
	}
	order = orderList.find(id)->second; // ã�Ƽ� Ŭ���̾�Ʈ ��ü�� �Ҵ�
	std::cout << "���� ���� : [ " << order->GetOrderStock() << " ]" << std::endl;
	std::cout << "������ ���� : ";
	num = InputFormat::IntCin();
	order->SetOrderStock(num);
	std::cout << "���� ��¥ : [ " 
		<< order->GetDate().GetYear()<< "�� " 
		<< order->GetDate().GetMonth() << "�� "
		<< order->GetDate().GetDay() << "��" 
		<< "]" << std::endl;
	do
	{
		std::cout << "������ ���� [��] (yyyy) : ";
		num = InputFormat::IntCin();
	} while (!date.SetYear(num));
	do
	{
		std::cout << "�ֹ� ���� [��] (mm): ";
		num = InputFormat::IntCin();
	} while (!date.SetMonth(num));
	do
	{
		std::cout << "�ֹ� ���� [��] (dd): ";
		num = InputFormat::IntCin();
	} while (!date.SetDay(num));
	order->SetDate(date);

	std::cout << "�ֹ� ���� ���� �Ϸ�";
	Sleep(1500);
	system("cls");
}

// �ֹ� ���� �˻�
void OrderManager::SerchObj() 
{
	int id;
	map<int, Order*> serchList;

	system("cls");

	std::cout << "����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������" << std::endl;
	std::cout << "                                           �ֹ� �̷� �˻�" << std::endl;
	std::cout << "����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������" << std::endl;
	std::cout << std::endl;

	std::cout << "�˻��� �̷��� ������ ID�� �Է��� �ּ��� : ";
	id = InputFormat::IntCin();

	for (auto itr = orderList.begin(); itr != orderList.end(); itr++)
	{
		if (id == itr->second->GetClientId())
			serchList[itr->first] = itr->second;
	}
	if (serchList.empty())
	{
		std::cout << "[" << id << "]" << " ���� �ֹ� �̷��� �����ϴ�...";
		Sleep(1500);
		return;
	}
	system("cls");
	printOrderForm(serchList);
	std::cout << std::endl;
	std::cout << "[" << id << "]" << " �ֹ� �̷� �˻� ���" << std::endl;
	std::cout << std::endl;
	std::cout << "���� ȭ������ ���ư����� enter�� �Է��� �ּ���...";
	while (getchar() != '\n');
	getchar(); // ���� �帧 ����
	return;
	
}

//�ֹ� ���� ��ȸ
void OrderManager::PrintObj()
{
	system("cls");
	printOrderForm(orderList);
	std::cout << std::endl;
	std::cout << "���� ȭ������ ���ư����� enter�� �Է��� �ּ���...";
	while (getchar() != '\n');
	getchar(); // ���� �帧 ����
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
		std::cout << "�ش��ϴ� ID�� �������� �ʽ��ϴ�!!" << std::endl;
		Sleep(1000);
	}
	return order;
}


// �� ���� ��� ���ø�
void OrderManager::printOrderForm(map<int, Order*> &orderList) const
{
	Order* order;
	std::cout << "��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������" << std::endl;;
	std::cout << "��   ID       ����          ������ id                                  ��ǰ �̸�                  ����               ����        ��" << std::endl;;
	for (auto itr = orderList.begin(); itr != orderList.end(); itr++)
	{
		order = itr->second;
		std::cout << "��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������" << std::endl;;
		std::cout << "�� ";
		///////////////////// ID ĭ ���
		cout.fill('0');
		std::cout.width(C_ID_WIDTH);
		std::cout << itr->first;
		cout.fill(' '); // ���� ä���� �������� �ٽ� ����
		std::cout << " ";
		///////////////////// ��¥ ���
		std::cout << "  ";
		std::cout.width(C_NAME_WIDTH);
		std::cout
			<< order->GetDate().GetYear() << "�� "
			<< order->GetDate().GetMonth() << "�� "
			<< order->GetDate().GetDay() << "��";
		std::cout << "  ";
		///////////////////// ��ǰ �� ���
		std::cout << "  ";
		std::cout.width(C_PHONNUMBER_WIDTH);
		std::cout << order->GetProductName();
		std::cout << "  ";
		///////////////////// ���� ���
		std::cout.width(C_ADRESS_WIDTH);
		std::cout << order->GetOrderPrice();
		std::cout << "  ";
		///////////////////// ���� ���
		std::cout.width(C_EMAIL_WIDTH);
		std::cout << order->GetOrderStock();
		std::cout << " ��" << std::endl;
	}
	std::cout << "��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������" << std::endl;;
	return;
}

