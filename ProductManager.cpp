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
	file.open("productlist.txt");
	if (!file.fail()) {
		for (const auto& v : productList) {
			Product* c = v.second;
			file << c->GetId() << ", ";
			file << c->GetName() << ", ";
			file << c->GetBrand() << ", ";
			file << c->GetPrice() << ", ";
			file << c->GetStock() << std::endl;
		}
	}
	file.close();
}


//상품 정보 추가
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
		std::cout << "메모리 할당 실패";
		return;
	}
	std::cout << "────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────" << std::endl;
	std::cout << "                                                            신규 상품 등록" << std::endl;
	std::cout << "────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────" << std::endl;
	std::cout << std::endl;;
	std::cout << "뒤로 가고 싶다면 -1 입력" << std::endl << std::endl;
	std::cout << "제품명 : ";
	std::cin.clear();
	cin.ignore(999, '\n');								//버퍼 청소 필요
	std::getline(std::cin, input, '\n');				// 한줄 전체를 받아야 함으로 getline() 사용
	if (static_cast<int>(atoi(input.c_str())) == -1)	// getline
		return;
	product->SetName(input);
	std::cout << "브랜드 : ";
	std::cin.clear();									// 위에가 getline 이므로 버퍼 청소 불필요
	std::getline(std::cin, input, '\n');				// 한줄 전체를 받아야 함으로 getline() 사용
	product->SetBrand(input);
	std::cout << "가격 : ";
	num = InputFormat::IntCin();
	product->SetPrice(num);
	std::cout << "재고 : ";
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
		std::cout << "키 ID 중복 발생, 신규 상품 등록 실패" << std::endl;
		std::cout << std::endl;
		return;
	}
	std::cout << "신규 상품 등록 완료!";
	Sleep(1500);										//화면 지연
	system("cls");
	return;
}

//상품 정보 삭제
void ProductManager::DelObj()
{
	int id;
	char check;
	Product* product;

	system("cls");
	printProductForm(productList);
	std::cout << std::endl;;
	std::cout << std::endl;;
	std::cout << "────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────" << std::endl;
	std::cout << "                                                           상품 정보 삭제" << std::endl;
	std::cout << "────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────" << std::endl;
	std::cout << std::endl;
	std::cout << "뒤로 가고 싶다면 -1 입력" << std::endl << std::endl;
	std::cout << "삭제할 상품의 ID를 입력 해주세요 : ";
	id = InputFormat::IntCin();
	if (id == -1)
		return;
	try
	{
		productList.at(id);
	}
	catch (std::out_of_range e)
	{
		std::cout << "해당하는 ID는 존재하지 않습니다!!" << std::endl;
		Sleep(1000);
		return;
	}
	product = productList.find(id)->second;				// 찾아서 클라이언트 객체를 할당
	std::cout << product->GetName() << " 상품 정보를 삭제 하시겠습니까?" << std::endl;
	do
	{
		cin.ignore(999, '\n');							//버퍼 청소
		std::cout << "[ Y / N ] : ";
		std::cin >> check;
		check = toupper(check);							// 대문자 전환
	} while ((check != 'Y') && (check != 'N'));
	if (check == 'N')
		return;
	productList.erase(id);
	std::cout <<"[" << product->GetName() << "]" << " 상품 정보를 삭제했습니다" << std::endl;
	Sleep(1500);
	system("cls");
}

//상품 정보 수정
void ProductManager::ModiObj()
{
	int id;
	Product* product;
	string tmp;
	int num;

	std::cout << "────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────" << std::endl;
	std::cout << "                                                          상품 정보 수정" << std::endl;
	std::cout << "────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────" << std::endl;
	std::cout << std::endl;
	std::cout << "뒤로 가고 싶다면 -1 입력" << std::endl << std::endl;
	std::cout << "수정할 상품의 ID를 입력 해주세요 : ";
	id = InputFormat::IntCin();
	if (id == -1)
		return;
	try
	{
		productList.at(id);
	}
	catch (std::out_of_range e)
	{
		std::cout << "해당하는 ID는 존재하지 않습니다!!" << std::endl;
		Sleep(1000);
		return;
	}
	product = productList.find(id)->second;				// 찾아서 클라이언트 객체를 할당
	std::cout << "현재 제품명 : [ " << product->GetName() << " ]" << std::endl;
	std::cout << "수정할 제품명 : ";
	std::cin.clear();
	cin.ignore(999, '\n');								//버퍼 청소 필요
	std::getline(std::cin, tmp, '\n');					// 한줄 전체를 받아야 함으로 getline() 사용
	product->SetName(tmp);
	std::cout << "현재 브랜드 : [ " << product->GetBrand() << " ]" << std::endl;
	std::cout << "수정할 브랜드 : ";
	std::cin.clear();
	std::getline(std::cin, tmp, '\n');					// 한줄 전체를 받아야 함으로 getline() 사용
	product->SetBrand(tmp);
	std::cout << "현재 가격 : [ " << product->GetPrice() << " ]" << std::endl;
	std::cout << "수정할 가격 : ";
	num = InputFormat::IntCin();
	product->SetPrice(num);
	std::cout << "현재 재고 : [ " << product->GetStock() << " ]" << std::endl;
	std::cout << "수정할 재고 : ";
	num = InputFormat::IntCin();
	product->SetStock(num);
	std::cout << std::endl;
	std::cout << "상품 정보 수정 완료";
	Sleep(1500);
	system("cls");
}

//상품 정보 검색
void ProductManager::SerchObj()
{
	string name;
	map<int, Product*> serchList;

	system("cls");

	std::cout << "────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────" << std::endl;
	std::cout << "                                                          상품 정보 검색" << std::endl;
	std::cout << "────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────" << std::endl;
	std::cout << std::endl;

	std::cout << "검색할 대상의 제품명을 입력해 주세요 : ";
	std::cin.clear();
	cin.ignore(999, '\n');								//버퍼 청소 필요
	std::getline(std::cin, name, '\n');					// 한줄 전체를 받아야 함으로 getline() 사용

	for (auto itr = productList.begin(); itr != productList.end(); itr++)
	{
		if (name == itr->second->GetName())
			serchList[itr->first] = itr->second;
	}
	if (serchList.empty())
	{
		std::cout << "[" << name << "]" << " 의 검색 결과가 없습니다...";
		Sleep(1500);
		return;
	}
	system("cls");
	printProductForm(serchList);
	std::cout << std::endl;
	std::cout << name << " 검색 결과" << std::endl;
	std::cout << std::endl;
	std::cout << "이전 화면으로 돌아가려면 enter를 입력해 주세요...";
	while (getchar() != '\n');
	return;
}

// 상품 정보 조회
void ProductManager::PrintObj()
{
	system("cls");
	printProductForm(productList);
	std::cout << std::endl;
	std::cout << "이전 화면으로 돌아가려면 enter를 입력해 주세요...";
	while (getchar() != '\n');
	getchar();											// 제어 흐름 정지
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
		std::cout << "해당하는 ID는 존재하지 않습니다!!" << std::endl;
		Sleep(1000);
	}
	return product;
}

//출력 양식
void ProductManager::printProductForm(map<int, Product*>& productList) const
{
	Product* product;
	std::cout <<	 "┌───────┬─────────────────────────────────────────┬─────────────────────────────────────┬───────────────────┬─────────────────┐" << std::endl;;
	std::cout <<	 "│   ID                     제품명                                   브랜드                       가격                재고     │" << std::endl;;
	for (auto itr = productList.begin(); itr != productList.end(); itr++)
	{
		product = itr->second;
		std::cout << "├───────┼─────────────────────────────────────────┼─────────────────────────────────────┼───────────────────┼─────────────────┤" << std::endl;;
		std::cout << "│ ";
		///////////////////// ID 칸 양식
		cout.fill('0');
		std::cout.width(P_ID_WIDTH);
		std::cout << itr->first;
		cout.fill(' ');						// 공간 채움을 공백으로 다시 변경
		std::cout << " ";
		///////////////////// 제품명 칸 양식
		std::cout << "  ";
		std::cout.width(P_NAME_WIDTH);
		std::cout << product->GetName();
		std::cout << "  ";
		///////////////////// 브랜드 칸 양식
		std::cout << "  ";
		std::cout.width(P_BRAND_WIDTH);
		std::cout << product->GetBrand();

		std::cout << "  ";
		///////////////////// 가격 칸 양식
		std::cout.width(P_PRICE_WIDTH);
		std::cout << product->GetPrice();
		std::cout << "  ";
		///////////////////// 재고 칸 양식
		std::cout.width(P_STOCK_WIDTH);
		std::cout << product->GetStock();
		std::cout << " │" << std::endl;
	}
	std::cout << "└───────┴─────────────────────────────────────────┴─────────────────────────────────────┴───────────────────┴─────────────────┘" << std::endl;;
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