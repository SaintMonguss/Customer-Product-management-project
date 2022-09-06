#include "ProjectHeader.h"

#include <iostream>
#include <string>
#include <iomanip>
#include <stdio.h>
#include <windows.h>

ProductManager::ProductManager()
{
	std::ifstream file;
	file.open("productlist.txt");
	if (!file.fail()) {
		while (!file.eof()) {
			std::vector<string> row = parseCSV(file, ',');
			if (row.size()) {
				int id = atoi(row[0].c_str());
				int price = atoi(row[3].c_str());
				int stock = atoi(row[4].c_str());
				Product* c = new Product(id, row[1], row[2], price, stock);
				productList.insert({ id, c });

			}
		}
	}
	file.close();
}

ProductManager::~ProductManager()
{
	std::ofstream file;
	file.open("clientlist.txt");
	if (!file.fail()) {
		for (const auto& v : productList) {
			Product* c = v.second;
			file << c->GetId() << ", " << c->GetName() << ", ";
			file << c->GetBrand() << ", ";
			file << c->GetPrice() << ", ";
			file << c->GetStock() << std::endl;
		}
	}
	file.close();
}


//��ǰ ���� �߰�
void ProductManager::AddObj()
{
	string input;
	Product* product;
	int id;
	int num;
	if (productList.empty())
		id = 1;
	else
		id = (productList.rbegin()->first) + 1;
	try
	{
		product = new Product(id);
	}
	catch (const std::bad_alloc& e)
	{
		std::cout << "�޸� �Ҵ� ����";
		return;
	}
	std::cout << "����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������" << std::endl;
	std::cout << "                                           �ű� ��ǰ ���" << std::endl;
	std::cout << "����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������" << std::endl;
	std::cout << std::endl;;
	std::cout << "��ǰ�� : ";
	std::cin >> input;
	product->SetName(input);
	std::cout << "�귣�� : ";
	std::cin >> input;
	product->SetBrand(input);
	std::cout << "���� : ";
	num = InputFormat::IntCin();
	product->SetPrice(num);
	std::cout << "��� : ";
	num = InputFormat::IntCin();
	product->SetStock(num);
	try
	{
		auto tmp = (productList.insert({ id, product }));
		if (tmp.second == false)
			throw;
	}
	catch (...)
	{
		std::cout << std::endl;
		std::cout << "Ű ID �ߺ� �߻�, �ű� ��ǰ ��� ����" << std::endl;
		std::cout << std::endl;
		return;
	}
	std::cout << "�ű� ��ǰ ��� �Ϸ�!";
	Sleep(1500); //ȭ�� ����
	system("cls");
	return;
}

//��ǰ ���� ����
void ProductManager::DelObj()
{
	int id;
	char check;
	Product* product;

	system("cls");
	printProductForm(productList);
	std::cout << std::endl;;
	std::cout << std::endl;;
	std::cout << "����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������" << std::endl;
	std::cout << "                                           ��ǰ ���� ����" << std::endl;
	std::cout << "����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������" << std::endl;
	std::cout << std::endl;
	std::cout << "������ ��ǰ�� ID�� �Է� ���ּ��� : ";
	id = InputFormat::IntCin();

	try
	{
		productList.at(id);
	}
	catch (std::out_of_range e)
	{
		std::cout << "�ش��ϴ� ID�� �������� �ʽ��ϴ�!!" << std::endl;
		Sleep(1000);
		return;
	}
	product = productList.find(id)->second; // ã�Ƽ� Ŭ���̾�Ʈ ��ü�� �Ҵ�
	std::cout << product->GetName() << " ��ǰ ������ ���� �Ͻðڽ��ϱ�?" << std::endl;
	do
	{
		cin.ignore(999, '\n'); //���� û��
		std::cout << "[ Y / N ] : ";
		std::cin >> check;
		check = toupper(check); // �빮�� ��ȯ
	} while ((check != 'Y') && (check != 'N'));
	if (check == 'N')
		return;
	productList.erase(id);
	std::cout <<"[" << product->GetName() << "]" << " ��ǰ ������ �����߽��ϴ�" << std::endl;
	Sleep(1500);
	system("cls");
}

//��ǰ ���� ����
void ProductManager::ModiObj()
{
	int id;
	Product* product;
	string tmp;
	int num;

	std::cout << "����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������" << std::endl;
	std::cout << "                                           ��ǰ ���� ����" << std::endl;
	std::cout << "����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������" << std::endl;
	std::cout << std::endl;
	std::cout << "������ ��ǰ�� ID�� �Է� ���ּ��� : ";
	id = InputFormat::IntCin();
	try
	{
		productList.at(id);
	}
	catch (std::out_of_range e)
	{
		std::cout << "�ش��ϴ� ID�� �������� �ʽ��ϴ�!!" << std::endl;
		Sleep(1000);
		return;
	}
	product = productList.find(id)->second; // ã�Ƽ� Ŭ���̾�Ʈ ��ü�� �Ҵ�
	std::cout << "���� ��ǰ�� : [ " << product->GetName() << " ]" << std::endl;
	std::cout << "������ ��ǰ�� : ";
	std::cin >> tmp;
	product->SetName(tmp);
	std::cout << "���� �귣�� : [ " << product->GetBrand() << " ]" << std::endl;
	std::cout << "������ �귣�� : ";
	std::cin >> tmp;
	product->SetBrand(tmp);
	std::cout << "���� ���� : [ " << product->GetPrice() << " ]" << std::endl;
	std::cout << "������ ���� : ";
	num = InputFormat::IntCin();
	product->SetPrice(num);
	std::cout << "���� ��� : [ " << product->GetStock() << " ]" << std::endl;
	std::cout << "������ ��� : ";
	num = InputFormat::IntCin();
	product->SetStock(num);
	std::cout << std::endl;
	std::cout << "��ǰ ���� ���� �Ϸ�";
	Sleep(1500);
	system("cls");
}

//��ǰ ���� �˻�
void ProductManager::SerchObj()
{
	string name;
	map<int, Product*> serchList;

	system("cls");

	std::cout << "����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������" << std::endl;
	std::cout << "                                           ��ǰ ���� �˻�" << std::endl;
	std::cout << "����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������" << std::endl;
	std::cout << std::endl;

	std::cout << "�˻��� ����� ��ǰ���� �Է��� �ּ��� : ";
	std::cin >> name;

	for (auto itr = productList.begin(); itr != productList.end(); itr++)
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
	printProductForm(serchList);
	std::cout << std::endl;
	std::cout << name << " �˻� ���" << std::endl;
	std::cout << std::endl;
	std::cout << "���� ȭ������ ���ư����� enter�� �Է��� �ּ���...";
	while (getchar() != '\n');
	getchar(); // ���� �帧 ����
	return;
}

// ��ǰ ���� ��ȸ
void ProductManager::PrintObj()
{
	system("cls");
	printProductForm(productList);
	std::cout << std::endl;
	std::cout << "���� ȭ������ ���ư����� enter�� �Է��� �ּ���...";
	while (getchar() != '\n');
	getchar(); // ���� �帧 ����
	return;
}


void* ProductManager::TossObj(int id)
{
	Product* product = nullptr;
	try
	{
		product = productList.at(id);
	}
	catch (std::out_of_range e)
	{
		std::cout << "�ش��ϴ� ID�� �������� �ʽ��ϴ�!!" << std::endl;
		Sleep(1000);
	}
	return product;
}

//��� ���
void ProductManager::printProductForm(map<int, Product*>& productList) const
{
	Product* product;
	std::cout <<	 "��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������" << std::endl;;
	std::cout <<	 "��   ID                     ��ǰ��                                   �귣��                       ����                ���     ��" << std::endl;;
	for (auto itr = productList.begin(); itr != productList.end(); itr++)
	{
		product = itr->second;
		std::cout << "��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������" << std::endl;;
		std::cout << "�� ";
		///////////////////// ID ĭ ���
		cout.fill('0');
		std::cout.width(P_ID_WIDTH);
		std::cout << itr->first;
		cout.fill(' '); // ���� ä���� �������� �ٽ� ����
		std::cout << " ";
		///////////////////// ��ǰ�� ĭ ���
		std::cout << "  ";
		std::cout.width(P_NAME_WIDTH);
		std::cout << product->GetName();
		std::cout << "  ";
		///////////////////// �귣�� ĭ ���
		std::cout << "  ";
		std::cout.width(P_BRAND_WIDTH);
		std::cout << product->GetBrand();

		std::cout << "  ";
		///////////////////// ���� ĭ ���
		std::cout.width(P_PRICE_WIDTH);
		std::cout << product->GetPrice();
		std::cout << "  ";
		///////////////////// ��� ĭ ���
		std::cout.width(P_STOCK_WIDTH);
		std::cout << product->GetStock();
		std::cout << " ��" << std::endl;
	}
	std::cout << "��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������" << std::endl;;
	return;
}

std::vector<string> ProductManager::parseCSV(std::istream& file, char delimiter)
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