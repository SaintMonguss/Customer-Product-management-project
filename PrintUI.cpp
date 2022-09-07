#include "ProjectHeader.h"

#include <Windows.h>
#include <iostream>

//¸Þ´º Ãâ·ÂÀ» À§ÇÑ ±â´ÉÀÌ ¸ð¿©ÀÖ´Â Å¬·¡½º

int PrintUI::PrintMainUI()
{
	int choice;
	std::cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << std::endl;
	std::cout << "                                                       °í°´ »óÇ° ÅëÇÕ °ü¸® ÇÁ·Î±×·¥" << std::endl;
	std::cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << std::endl;
	std::cout << std::endl;
	std::cout << "1. °í°´ °ü¸®" << std::endl;
	std::cout << "2. »óÇ° °ü¸®" << std::endl;
	std::cout << "3. ÁÖ¹®/ÀÌ·Â °ü¸®" << std::endl;
	std::cout << "4. Á¾·á" << std::endl;
	std::cout << std::endl;
	std::cout << "¼±ÅÃ : ";
	choice = InputFormat::IntCin();
	return choice;
}

void PrintUI::PrintClientUI(Manager* CM)
{
	int choice = 0;

	do
	{
		system("cls");
		std::cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << std::endl;
		std::cout << "                                                            °í°´ °ü¸® ¸Þ´º" << std::endl;
		std::cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << std::endl;
		std::cout << std::endl;
		std::cout << "1. °í°´ µî·Ï" << std::endl;
		std::cout << "2. °í°´ Á¤º¸ Á¶È¸" << std::endl;
		std::cout << "3. °í°´ Á¤º¸ °Ë»ö" << std::endl;
		std::cout << "4. °í°´ Á¤º¸ ¼öÁ¤" << std::endl;
		std::cout << "5. °í°´ Á¤º¸ »èÁ¦" << std::endl;
		std::cout << "6. µÚ·Î°¡±â" << std::endl;
		std::cout << std::endl;
		std::cout << "¼±ÅÃ : ";

		choice = InputFormat::IntCin();
		switch (choice)
		{
		case 1:
			system("cls"); //È­¸é Ã»¼Ò
			CM->AddObj();
			break;
		case 2:
			system("cls"); //È­¸é Ã»¼Ò
			CM->PrintObj();
			break;
		case 3:
			system("cls"); //È­¸é Ã»¼Ò
			CM->SerchObj();
			break;
		case 4:
			system("cls"); //È­¸é Ã»¼Ò
			CM->ModiObj();
			break;
		case 5:
			system("cls"); //È­¸é Ã»¼Ò
			CM->DelObj();
			break;
		case 6: // ¸ÞÀÎ ¼±ÅÃ È­¸éÀ¸·Î
			system("cls"); //È­¸é Ã»¼Ò
			break;
		default:
			std::cout << "Àß¸øµÈ ¸í·ÉÀÔ´Ï´Ù" << std::endl;
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
		std::cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << std::endl;
		std::cout << "                                                            »óÇ° °ü¸® ¸Þ´º" << std::endl;
		std::cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << std::endl;
		std::cout << std::endl;
		std::cout << "1. »óÇ° µî·Ï" << std::endl;
		std::cout << "2. »óÇ° Á¤º¸ Á¶È¸" << std::endl;
		std::cout << "3. »óÇ° Á¤º¸ °Ë»ö" << std::endl;
		std::cout << "4. »óÇ° Á¤º¸ ¼öÁ¤" << std::endl;
		std::cout << "5. »óÇ° Á¤º¸ »èÁ¦" << std::endl;
		std::cout << "6. µÚ·Î°¡±â" << std::endl;
		std::cout << std::endl;
		std::cout << "¼±ÅÃ : ";
		choice = InputFormat::IntCin();
		
		switch (choice)
		{
		case 1:
			system("cls"); //È­¸é Ã»¼Ò
			PM->AddObj();
			break;
		case 2:
			system("cls"); //È­¸é Ã»¼Ò
			PM->PrintObj();
			break;
		case 3:
			system("cls"); //È­¸é Ã»¼Ò
			PM->SerchObj();
			break;
		case 4:
			system("cls"); //È­¸é Ã»¼Ò
			PM->ModiObj();
			break;
		case 5:
			system("cls"); //È­¸é Ã»¼Ò
			PM->DelObj();
			break;
		case 6: // ¸ÞÀÎ ¼±ÅÃ È­¸éÀ¸·Î
			system("cls"); //È­¸é Ã»¼Ò
			break;
		default:
			std::cout << "Àß¸øµÈ ¸í·ÉÀÔ´Ï´Ù" << std::endl;
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
		std::cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << std::endl;
		std::cout << "                                                        ÁÖ¹® ÀÌ·Â °ü¸® ¸Þ´º" << std::endl;
		std::cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << std::endl;
		std::cout << std::endl;
		std::cout << "1. ÁÖ¹® ÀÌ·Â µî·Ï" << std::endl;
		std::cout << "2. ÁÖ¹® ÀÌ·Â Á¶È¸" << std::endl;
		std::cout << "3. ÁÖ¹® ÀÌ·Â °Ë»ö" << std::endl;
		std::cout << "4. ÁÖ¹® ÀÌ·Â ¼öÁ¤" << std::endl;
		std::cout << "5. ÁÖ¹® ÀÌ·Â »èÁ¦" << std::endl;
		std::cout << "6. µÚ·Î°¡±â" << std::endl;
		std::cout << std::endl;
		std::cout << "¼±ÅÃ : ";

		choice = InputFormat::IntCin();
		switch (choice)
		{
		case 1:
			system("cls"); //È­¸é Ã»¼Ò
			OM->AddObj();
			break;
		case 2:
			system("cls"); //È­¸é Ã»¼Ò
			OM->PrintObj();
			break;
		case 3:
			system("cls"); //È­¸é Ã»¼Ò
			OM->SerchObj();
			break;
		case 4:
			system("cls"); //È­¸é Ã»¼Ò
			OM->ModiObj();
			break;
		case 5:
			system("cls"); //È­¸é Ã»¼Ò
			OM->DelObj();
			break;
		case 6: // ¸ÞÀÎ ¼±ÅÃ È­¸éÀ¸·Î
			system("cls"); //È­¸é Ã»¼Ò
			break;
		default:
			std::cout << "Àß¸øµÈ ¸í·ÉÀÔ´Ï´Ù" << std::endl;
			Sleep(1500);
			system("cls");
			break;
		}
	} while (choice != 6);
	return;
}
