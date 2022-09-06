#include "ProjectHeader.h"

#include <Windows.h>
#include <iostream>

int PrintUI::PrintMainUI()
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
	std::cout << std::endl;
	std::cout << "선택 : ";
	choice = InputFormat::IntCin();
	return choice;
}

void PrintUI::PrintClientUI(Manager* CM)
{
	int choice = 0;

	do
	{
		system("cls");
		std::cout << "────────────────────────────────────────────────────────────────────────────────────────────" << std::endl;
		std::cout << "                                          고객 관리 메뉴" << std::endl;
		std::cout << "────────────────────────────────────────────────────────────────────────────────────────────" << std::endl;
		std::cout << std::endl;
		std::cout << "1. 고객 등록" << std::endl;
		std::cout << "2. 고객 정보 조회" << std::endl;
		std::cout << "3. 고객 정보 검색" << std::endl;
		std::cout << "4. 고객 정보 수정" << std::endl;
		std::cout << "5. 고객 정보 삭제" << std::endl;
		std::cout << "6. 뒤로가기" << std::endl;
		std::cout << "선택 : ";

		choice = InputFormat::IntCin();
		switch (choice)
		{
		case 1:
			system("cls"); //화면 청소
			CM->AddObj();
			break;
		case 2:
			system("cls"); //화면 청소
			CM->PrintObj();
			break;
		case 3:
			system("cls"); //화면 청소
			CM->SerchObj();
			break;
		case 4:
			system("cls"); //화면 청소
			CM->ModiObj();
			break;
		case 5:
			system("cls"); //화면 청소
			CM->DelObj();
			break;
		case 6: // 메인 선택 화면으로
			system("cls"); //화면 청소
			break;
		default:
			std::cout << "잘못된 명령입니다" << std::endl;
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
		std::cout << "────────────────────────────────────────────────────────────────────────────────────────────" << std::endl;
		std::cout << "                                          상품 관리 메뉴" << std::endl;
		std::cout << "────────────────────────────────────────────────────────────────────────────────────────────" << std::endl;
		std::cout << std::endl;
		std::cout << "1. 상품 등록" << std::endl;
		std::cout << "2. 상품 정보 조회" << std::endl;
		std::cout << "3. 상품 정보 검색" << std::endl;
		std::cout << "4. 상품 정보 수정" << std::endl;
		std::cout << "5. 상품 정보 삭제" << std::endl;
		std::cout << "6. 뒤로가기" << std::endl;
		std::cout << "선택 : ";
		choice = InputFormat::IntCin();
		
		switch (choice)
		{
		case 1:
			system("cls"); //화면 청소
			PM->AddObj();
			break;
		case 2:
			system("cls"); //화면 청소
			PM->PrintObj();
			break;
		case 3:
			system("cls"); //화면 청소
			PM->SerchObj();
			break;
		case 4:
			system("cls"); //화면 청소
			PM->ModiObj();
			break;
		case 5:
			system("cls"); //화면 청소
			PM->DelObj();
			break;
		case 6: // 메인 선택 화면으로
			system("cls"); //화면 청소
			break;
		default:
			std::cout << "잘못된 명령입니다" << std::endl;
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
		std::cout << "────────────────────────────────────────────────────────────────────────────────────────────" << std::endl;
		std::cout << "                                      주문 이력 관리 메뉴" << std::endl;
		std::cout << "────────────────────────────────────────────────────────────────────────────────────────────" << std::endl;
		std::cout << std::endl;
		std::cout << "1. 주문 이력 등록" << std::endl;
		std::cout << "2. 주문 이력 조회" << std::endl;
		std::cout << "3. 주문 이력 검색" << std::endl;
		std::cout << "4. 주문 이력 수정" << std::endl;
		std::cout << "5. 주문 이력 삭제" << std::endl;
		std::cout << "6. 뒤로가기" << std::endl;
		std::cout << "선택 : ";

		choice = InputFormat::IntCin();
		switch (choice)
		{
		case 1:
			system("cls"); //화면 청소
			OM->AddObj();
			break;
		case 2:
			system("cls"); //화면 청소
			OM->PrintObj();
			break;
		case 3:
			system("cls"); //화면 청소
			OM->SerchObj();
			break;
		case 4:
			system("cls"); //화면 청소
			OM->ModiObj();
			break;
		case 5:
			system("cls"); //화면 청소
			OM->DelObj();
			break;
		case 6: // 메인 선택 화면으로
			system("cls"); //화면 청소
			break;
		default:
			std::cout << "잘못된 명령입니다" << std::endl;
			Sleep(1500);
			system("cls");
			break;
		}
	} while (choice != 6);
	return;
}
