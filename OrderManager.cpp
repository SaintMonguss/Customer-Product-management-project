#include "ProjectHeader.h"

#include <iostream>
#include <string>
#include <iomanip>
#include <stdio.h>
#include <windows.h>

// ������ ���� �ҷ�����
OrderManager::OrderManager(Manager* CM, Manager* PM) : CM(CM), PM(PM) 
{
	//	std::vector<Client*> vecList;
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
				//				vecList.push_back(c);
			}
		}
	}
	file.close();
};

//�Ҹ��� ���� ����
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



//�ֹ� ���� �߰�
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
		std::cout << "�޸� �Ҵ� ����";
		return;
	}
	std::cout << "������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������" << std::endl;
	std::cout << "                                                            �ű� �ֹ� ���" << std::endl;
	std::cout << "������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������" << std::endl;
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
	product = static_cast<Product*>(PM->TossObj(num)); //void* �� Product*�� ĳ�����ѵ� �̸��� �޾ƿͼ� input�� ����
	input = product -> GetName(); 
	stockCheck = product->GetStock(); // ���� ���� ����
	order->SetProductId(num);
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
	if (stockCheck < num)
	{
		std::wcout << std::endl;
		std::cout << "���! ���� ��ǰ �������� �ֹ����� �����ϴ�. Ȯ���� �ʿ��մϴ�. " << std::endl;
	}
	// �ֹ� ���� ����
	order->SetOrderPrice(product->GetPrice());
	Sleep(1500); //ȭ�� ����
	
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
	std::cout << std::endl;
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
	std::cout << "������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������" << std::endl;
	std::cout << "                                                          �ֹ� �̷� ����" << std::endl;
	std::cout << "������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������" << std::endl;

	std::cout << std::endl; 
	std::cout << "�ڷ� ���� �ʹٸ� -1 �Է�" << std::endl << std::endl;
	std::cout << "������ �ֹ��� ID�� �Է� ���ּ��� : ";
	id = InputFormat::IntCin();
	if (id == -1)
		return;
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

	std::cout << "������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������" << std::endl;
	std::cout << "                                                       �ֹ� �̷� ����" << std::endl;
	std::cout << "������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������" << std::endl;
	std::cout << std::endl;
	std::cout << "������ �� �ִ� �׸��� �ֹ� ������ ��¥�Դϴ�.";
	std::cout << std::endl;
	std::cout << "�ڷ� ���� �ʹٸ� -1 �Է�" << std::endl << std::endl;
	std::cout << "������ �ֹ��� ID�� �Է� ���ּ��� : ";
	id = InputFormat::IntCin();
	if (id == -1)
		return;
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

	std::cout << "������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������" << std::endl;
	std::cout << "                                                          �ֹ� �̷� �˻�" << std::endl;
	std::cout << "������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������" << std::endl;
	std::cout << std::endl;
	std::cout << "�ڷ� ���� �ʹٸ� -1 �Է�" << std::endl << std::endl;
	std::cout << "�˻��� �̷��� ������ ID�� �Է��� �ּ��� : ";
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
	std::cout << "����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������" << std::endl;;
	std::cout << "��   ID          �ֹ���        ������ ID                      ��ǰ �̸�                ��ǰ ID         ����            ����     ��" << std::endl;;
	for (auto itr = orderList.begin(); itr != orderList.end(); itr++)
	{
		order = itr->second;
		std::cout << "����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������" << std::endl;;
		std::cout << "�� ";
		///////////////////// ID ĭ ���
		cout.fill('0');
		std::cout.width(O_ID_WIDTH);
		std::cout << itr->first;
		cout.fill(' '); // ���� ä���� �������� �ٽ� ����
		std::cout << " ";
		///////////////////// ��¥ ���
		std::cout << "   ";
		std::cout << order->GetDate().GetYear() << "�� ";
		std::cout.width(2);
		std::cout << order->GetDate().GetMonth();
		std::cout << "�� ";
		std::cout.width(2);
		std::cout << order->GetDate().GetDay();
		std::cout << "��";
		std::cout << "  ";
		///////////////////// ������ ���̵� ���
		std::cout << "  ";
		std::cout.width(O_CLIENTID_WIDTH);
		cout.fill('0');
		std::cout << order->GetClientId();
		cout.fill(' '); // ���� ä���� �������� �ٽ� ����
		std::cout << "  ";
		///////////////////// ��ǰ �� ���
		std::cout << "  ";
		std::cout.width(O_PRODUCTNAME_WIDTH);
		std::cout << order->GetProductName();
		std::cout << " ";
		///////////////////// ��ǰ ID ���
		std::cout << "  ";
		cout.fill('0');
		std::cout.width(O_PRODUCTID_WIDTH);
		std::cout << order->GetProductId();
		cout.fill(' '); // ���� ä���� �������� �ٽ� ����
		std::cout << " ";
		///////////////////// ���� ���
		std::cout << "  ";
		std::cout.width(O_PRICE_WIDTH);
		std::cout << order->GetOrderPrice();
		std::cout << " ";
		///////////////////// ���� ���
		std::cout.width(O_STOCK_WIDTH);
		std::cout << order->GetOrderStock();
		std::cout << " ��" << std::endl;
	}
	std::cout << "����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������" << std::endl;;
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