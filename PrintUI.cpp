#include "ProjectHeader.h"

#include <Windows.h>
#include <iostream>

//詭景 轎溘擊 嬪и 晦棟檜 賅罹氈朝 贗楚蝶

int PrintUI::PrintMainUI()
{
	int choice;
	std::cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << std::endl;
	std::cout << "                                                       堅偌 鼻ヶ 鱔м 婦葬 Щ煎斜極" << std::endl;
	std::cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << std::endl;
	std::cout << std::endl;
	std::cout << "1. 堅偌 婦葬" << std::endl;
	std::cout << "2. 鼻ヶ 婦葬" << std::endl;
	std::cout << "3. 輿僥/檜溘 婦葬" << std::endl;
	std::cout << "4. 謙猿" << std::endl;
	std::cout << std::endl;
	std::cout << "摹鷗 : ";
	choice = InputFormat::IntCin();
	return choice;
}

void PrintUI::PrintClientUI(Manager* CM)
{
	int choice = 0;

	do
	{
		system("cls");
		std::cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << std::endl;
		std::cout << "                                                            堅偌 婦葬 詭景" << std::endl;
		std::cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << std::endl;
		std::cout << std::endl;
		std::cout << "1. 堅偌 蛔煙" << std::endl;
		std::cout << "2. 堅偌 薑爾 褻��" << std::endl;
		std::cout << "3. 堅偌 薑爾 匐儀" << std::endl;
		std::cout << "4. 堅偌 薑爾 熱薑" << std::endl;
		std::cout << "5. 堅偌 薑爾 餉薯" << std::endl;
		std::cout << "6. 菴煎陛晦" << std::endl;
		std::cout << std::endl;
		std::cout << "摹鷗 : ";

		choice = InputFormat::IntCin();
		switch (choice)
		{
		case 1:
			system("cls");						//�飛� 羶模
			CM->AddObj();
			break;
		case 2:
			system("cls");						//�飛� 羶模
			CM->PrintObj();
			break;
		case 3:
			system("cls");						//�飛� 羶模
			CM->SerchObj();
			break;
		case 4:
			system("cls");						//�飛� 羶模
			CM->ModiObj();
			break;
		case 5:
			system("cls");						//�飛� 羶模
			CM->DelObj();
			break;
		case 6:									// 詭檣 摹鷗 �飛橉虞�
			system("cls");						//�飛� 羶模
			break;
		default:
			std::cout << "澀跤脹 貲滄殮棲棻" << std::endl;
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
		std::cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << std::endl;
		std::cout << "                                                            鼻ヶ 婦葬 詭景" << std::endl;
		std::cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << std::endl;
		std::cout << std::endl;
		std::cout << "1. 鼻ヶ 蛔煙" << std::endl;
		std::cout << "2. 鼻ヶ 薑爾 褻��" << std::endl;
		std::cout << "3. 鼻ヶ 薑爾 匐儀" << std::endl;
		std::cout << "4. 鼻ヶ 薑爾 熱薑" << std::endl;
		std::cout << "5. 鼻ヶ 薑爾 餉薯" << std::endl;
		std::cout << "6. 菴煎陛晦" << std::endl;
		std::cout << std::endl;
		std::cout << "摹鷗 : ";
		choice = InputFormat::IntCin();
		
		switch (choice)
		{
		case 1:
			system("cls");							//�飛� 羶模
			PM->AddObj();
			break;
		case 2:
			system("cls");							//�飛� 羶模
			PM->PrintObj();
			break;
		case 3:
			system("cls");							//�飛� 羶模
			PM->SerchObj();
			break;
		case 4:
			system("cls");							//�飛� 羶模
			PM->ModiObj();
			break;
		case 5:
			system("cls");							//�飛� 羶模
			PM->DelObj();
			break;
		case 6:										// 詭檣 摹鷗 �飛橉虞�
			system("cls");							//�飛� 羶模
			break;
		default:
			std::cout << "澀跤脹 貲滄殮棲棻" << std::endl;
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
		std::cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << std::endl;
		std::cout << "                                                        輿僥 檜溘 婦葬 詭景" << std::endl;
		std::cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << std::endl;
		std::cout << std::endl;
		std::cout << "1. 輿僥 檜溘 蛔煙" << std::endl;
		std::cout << "2. 輿僥 檜溘 褻��" << std::endl;
		std::cout << "3. 輿僥 檜溘 匐儀" << std::endl;
		std::cout << "4. 輿僥 檜溘 熱薑" << std::endl;
		std::cout << "5. 輿僥 檜溘 餉薯" << std::endl;
		std::cout << "6. 菴煎陛晦" << std::endl;
		std::cout << std::endl;
		std::cout << "摹鷗 : ";

		choice = InputFormat::IntCin();
		switch (choice)
		{
		case 1:
			system("cls");							//�飛� 羶模
			OM->AddObj();
			break;
		case 2:
			system("cls");							//�飛� 羶模
			OM->PrintObj();
			break;
		case 3:
			system("cls");							//�飛� 羶模
			OM->SerchObj();
			break;
		case 4:
			system("cls");							//�飛� 羶模
			OM->ModiObj();
			break;
		case 5:
			system("cls");							//�飛� 羶模
			OM->DelObj();
			break;
		case 6:										// 詭檣 摹鷗 �飛橉虞�
			system("cls");							//�飛� 羶模
			break;
		default:
			std::cout << "澀跤脹 貲滄殮棲棻" << std::endl;
			Sleep(1500);
			system("cls");
			break;
		}
	} while (choice != 6);
	return;
}
