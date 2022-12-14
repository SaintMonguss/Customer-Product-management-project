#include "ProjectHeader.h"

#include <iostream>
#include <string>
#include <iomanip>
#include <stdio.h>
#include <windows.h>

// 생성자 파일 불러오기
OrderManager::OrderManager(Manager* CM, Manager* PM) : CM(CM), PM(PM) 
{
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
			}
		}
	}
	file.close();
};

//소멸자 파일 저장
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



//주문 정보 추가
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
		std::cout << "메모리 할당 실패";
		return;
	}
	std::cout << "────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────" << std::endl;
	std::cout << "                                                            신규 주문 등록" << std::endl;
	std::cout << "────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────" << std::endl;
	std::cout << std::endl;;
	std::cout << "뒤로 가고 싶다면 -1 입력" << std::endl << std::endl;
	do
	{
		std::cout << "상품 ID : ";
		num = InputFormat::IntCin();
		if (num == -1)
		{
			return;
		}
	} while (!(PM->TossObj(num)));							// 예외 체크
	product = static_cast<Product*>(PM->TossObj(num));		//void* 를 Product*로 캐스팅한뒤 이름을 받아와서 input에 대입
	input = product -> GetName(); 
	stockCheck = product->GetStock();						// 현재 수량 저장
	order->SetProductId(num);
	order->SetProductName(input);
	do
	{
		std::cout << "주문 날자 [년] (yyyy) : ";
		num = InputFormat::IntCin();
	} while (!date.SetYear(num));
	do
	{
		std::cout << "주문 날자 [월] (mm): ";
		num = InputFormat::IntCin();
	} while (!date.SetMonth(num));
	do
	{
		std::cout << "주문 날자 [일] (dd): ";
		num = InputFormat::IntCin();
	} while (!date.SetDay(num));
	order->SetDate(date);

	std::cout << "구매자 ID : ";
	num = InputFormat::IntCin();
	order->SetClientId(num);
	// 주문 수량 설정
	std::cout << "구매 수량 : ";
	num = InputFormat::IntCin();

	order->SetOrderStock(num);
	if (stockCheck < num)
	{
		std::wcout << std::endl;
		std::cout << "경고! 현재 상품 수량보다 주문량이 많습니다. 확인이 필요합니다. " << std::endl;
	}
	// 주문 가격 설정
	order->SetOrderPrice(product->GetPrice());
	Sleep(1500); //화면 지연
	
	try
	{
		auto tmp = (orderList.insert({ id, order }));
		if (tmp.second == false)
			throw;
	}
	catch (...)
	{
		std::cout << std::endl;
		std::cout << "키 ID 중복 발생, 주문 이력 추가 실패" << std::endl;
		std::cout << std::endl;
		return;
	}
	std::cout << std::endl;
	std::cout << "주문 이력 등록 완료!";
	Sleep(1500);											//화면 지연
	system("cls");
	return;
}

// 주문 정보 삭제
void OrderManager::DelObj()
{
	int id;
	char check;
	Order *order;

	system("cls");
	printOrderForm(orderList);
	std::cout << std::endl;;
	std::cout << std::endl;;
	std::cout << "────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────" << std::endl;
	std::cout << "                                                          주문 이력 삭제" << std::endl;
	std::cout << "────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────" << std::endl;

	std::cout << std::endl; 
	std::cout << "뒤로 가고 싶다면 -1 입력" << std::endl << std::endl;
	std::cout << "삭제할 주문의 ID를 입력 해주세요 : ";
	id = InputFormat::IntCin();
	if (id == -1)
		return;
	try
	{
		orderList.at(id);
	}
	catch (std::out_of_range e)
	{
		std::cout << "해당하는 주문 ID는 존재하지 않습니다!!" << std::endl;
		Sleep(1000);
		return;
	}
	order = orderList.find(id)->second;					// 찾아서 클라이언트 객체를 할당
	std::cout << "[" << order->GetOrderId() << "]" << " 번 주문 이력을 삭제 하시겠습니까?" << std::endl;
	do
	{
		cin.ignore(999, '\n');							//버퍼 청소
		std::cout << "[ Y / N ] : ";
		std::cin >> check;
		check = toupper(check);							// 대문자 전환
	} while ((check != 'Y') && (check != 'N'));
	if (check == 'N')
		return;
	orderList.erase(id);
	std::cout << "[" << order->GetOrderId() << "]" << " 번 주문 이력을 삭제했습니다" << std::endl;
	Sleep(1500);
	system("cls");
}
// 주문 이력 수정
void OrderManager::ModiObj()
{
	int id;
	int num;
	Date date;
	Order* order;
	string tmp;

	std::cout << "────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────" << std::endl;
	std::cout << "                                                       주문 이력 수정" << std::endl;
	std::cout << "────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────" << std::endl;
	std::cout << std::endl;
	std::cout << "수정할 수 있는 항목은 주문 수량과 날짜입니다.";
	std::cout << std::endl;
	std::cout << "뒤로 가고 싶다면 -1 입력" << std::endl << std::endl;
	std::cout << "수정할 주문의 ID를 입력 해주세요 : ";
	id = InputFormat::IntCin();
	if (id == -1)
		return;
	try
	{
		orderList.at(id);
	}
	catch (std::out_of_range e)
	{
		std::cout << "해당하는 ID는 존재하지 않습니다!!" << std::endl;
		Sleep(1000);
		return;
	}
	order = orderList.find(id)->second;					// 찾아서 클라이언트 객체를 할당
	std::cout << "현재 수량 : [ " << order->GetOrderStock() << " ]" << std::endl;
	std::cout << "수정할 수량 : ";
	num = InputFormat::IntCin();
	order->SetOrderStock(num);
	std::cout << "현재 날짜 : [ " 
		<< order->GetDate().GetYear()<< "년 " 
		<< order->GetDate().GetMonth() << "월 "
		<< order->GetDate().GetDay() << "일" 
		<< "]" << std::endl;
	do
	{
		std::cout << "수정할 날자 [년] (yyyy) : ";
		num = InputFormat::IntCin();
	} while (!date.SetYear(num));
	do
	{
		std::cout << "주문 날자 [월] (mm): ";
		num = InputFormat::IntCin();
	} while (!date.SetMonth(num));
	do
	{
		std::cout << "주문 날자 [일] (dd): ";
		num = InputFormat::IntCin();
	} while (!date.SetDay(num));
	order->SetDate(date);

	std::cout << "주문 정보 수정 완료";
	Sleep(1500);
	system("cls");
}

// 주문 정보 검색
void OrderManager::SerchObj() 
{
	int id;
	map<int, Order*> serchList;

	system("cls");

	std::cout << "────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────" << std::endl;
	std::cout << "                                                          주문 이력 검색" << std::endl;
	std::cout << "────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────" << std::endl;
	std::cout << std::endl;
	std::cout << "뒤로 가고 싶다면 -1 입력" << std::endl << std::endl;
	std::cout << "검색할 이력의 구매자 ID를 입력해 주세요 : ";
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
		std::cout << "[" << id << "]" << " 고객의 주문 이력이 없습니다...";
		Sleep(1500);
		return;
	}
	system("cls");
	printOrderForm(serchList);
	std::cout << std::endl;
	std::cout << "[" << id << "]" << " 주문 이력 검색 결과" << std::endl;
	std::cout << std::endl;
	std::cout << "이전 화면으로 돌아가려면 enter를 입력해 주세요...";
	while (getchar() != '\n');
	getchar();										// 제어 흐름 정지
	return;
	
}

//주문 정보 조회
void OrderManager::PrintObj()
{
	system("cls");
	printOrderForm(orderList);
	std::cout << std::endl;
	std::cout << "이전 화면으로 돌아가려면 enter를 입력해 주세요...";
	while (getchar() != '\n');
	getchar();										// 제어 흐름 정지
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
		std::cout << "해당하는 ID는 존재하지 않습니다!!" << std::endl;
		Sleep(1000);
	}
	return order;
}


// 고객 관련 출력 템플릿
void OrderManager::printOrderForm(map<int, Order*> &orderList) const
{
	Order* order;
	std::cout << "┌───────┬───────────────────┬──────────┬────────────────────────────────────────────┬────────┬──────────────────┬──────────────┐" << std::endl;;
	std::cout << "│   ID          주문일        구매자 ID                      상품 이름                상품 ID         가격            수량     │" << std::endl;;
	for (auto itr = orderList.begin(); itr != orderList.end(); itr++)
	{
		order = itr->second;
		std::cout << "├───────┼───────────────────┼──────────┼────────────────────────────────────────────┼────────┼──────────────────┼──────────────┤" << std::endl;;
		std::cout << "│ ";
		///////////////////// ID 칸 양식
		cout.fill('0');
		std::cout.width(O_ID_WIDTH);
		std::cout << itr->first;
		cout.fill(' ');								// 공간 채움을 공백으로 다시 변경
		std::cout << " ";
		///////////////////// 날짜 양식
		std::cout << "   ";
		std::cout << order->GetDate().GetYear() << "년 ";
		std::cout.width(2);
		std::cout << order->GetDate().GetMonth();
		std::cout << "월 ";
		std::cout.width(2);
		std::cout << order->GetDate().GetDay();
		std::cout << "일";
		std::cout << "  ";
		///////////////////// 구매자 아이디 양식
		std::cout << "  ";
		std::cout.width(O_CLIENTID_WIDTH);
		cout.fill('0');
		std::cout << order->GetClientId();
		cout.fill(' ');								// 공간 채움을 공백으로 다시 변경
		std::cout << "  ";
		///////////////////// 제품 명 양식
		std::cout << "  ";
		std::cout.width(O_PRODUCTNAME_WIDTH);
		std::cout << order->GetProductName();
		std::cout << " ";
		///////////////////// 제품 ID 양식
		std::cout << "  ";
		cout.fill('0');
		std::cout.width(O_PRODUCTID_WIDTH);
		std::cout << order->GetProductId();
		cout.fill(' ');								// 공간 채움을 공백으로 다시 변경
		std::cout << " ";
		///////////////////// 가격 양식
		std::cout << "  ";
		std::cout.width(O_PRICE_WIDTH);
		std::cout << order->GetOrderPrice();
		std::cout << " ";
		///////////////////// 수량 양식
		std::cout.width(O_STOCK_WIDTH);
		std::cout << order->GetOrderStock();
		std::cout << " │" << std::endl;
	}
	std::cout << "└───────┴───────────────────┴──────────┴────────────────────────────────────────────┴────────┴──────────────────┴──────────────┘" << std::endl;;
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