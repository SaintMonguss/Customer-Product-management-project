#include "ProjectHeader.h"

#include <Windows.h>
#include <iostream>
#include <vector>

int main()
{
	system("mode con:cols=135 lines=40");
	Manager* CM = new ClientManager;
	Manager* PM = new ProductManager;
	Manager* OM = new OrderManager(CM, PM);
	int choice = 0;

	do
	{
		choice = PrintUI::PrintMainUI();
		switch (choice)
		{
		case 1:
			PrintUI::PrintClientUI(CM);
			break;
		case 2:
			PrintUI::PrintProductUI(PM);
			break;
		case 3:
			PrintUI::PrintOrderUI(OM);
			break;
		case 4: // 종료
			break;
		default:
			std::cout << "잘못된 명령입니다" << std::endl;
			break;
		}

	} while (choice != 4);
	
	
	delete CM;
	delete PM;
	delete OM;
	return 0;
}

