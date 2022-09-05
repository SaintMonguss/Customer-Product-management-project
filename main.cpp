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
		case 4: // 종료
			break;
		default:
			std::cout << "잘못된 명령입니다" << std::endl;
			break;
		}



	} while (choice != 4);
	
	

	return 0;
}

int PrintMainUI()
{
	int choice;
	std::cout << "────────────────────────────────────────────────────────────────────────────────────────────" << std::endl;
	std::cout << "                                     고객 상품 통합 관리 프로그램" << std::endl;
	std::cout << "────────────────────────────────────────────────────────────────────────────────────────────" << std::endl;
	std::cout << std::endl;
	std::cout << "1. 고객 관리" << std::endl;
	std::cout << "2. 상품 관리" << std::endl;
	std::cout << "3. 주문/이력 관리" << std::endl;
	std::cout << "4. 종료" << std::endl;
	std::cout << "선택 : ";
	std::cin >> choice;
	return choice;
}

void PrintClientUI(Manager *CM)
{
	int choice = 0;

	do
	{
		std::cout << "────────────────────────────────────────────────────────────────────────────────────────────" << std::endl;
		std::cout << "                                          고객 관리 메뉴" << std::endl;
		std::cout << "────────────────────────────────────────────────────────────────────────────────────────────" << std::endl;
		std::cout << std::endl;
		std::cout << "1. 고객 등록" << std::endl;
		std::cout << "2. 고객 정보 검색" << std::endl;
		std::cout << "3. 고객 정보 수정" << std::endl;
		std::cout << "4. 고객 정보 삭제" << std::endl;
		std::cout << "5. 뒤로가기" << std::endl;
		std::cout << "선택 : ";
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
		case 5: // 메인 선택 화면으로
			break;
		default:
			std::cout << "잘못된 명령입니다" << std::endl;
			Sleep(1500);
			system("cls");
			break;
		}
	} while (choice != 5);

	return;
}