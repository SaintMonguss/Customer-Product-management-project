#include "ProjectHeader.h"

#include <iostream>
#include <vector>


int main()
{
	system("mode con:cols=130 lines=40");
	Manager* CM = new ClientManager;
	CM->AddObj();
	CM->AddObj();
	CM->PrintObj();
	CM->ModiObj();
	CM->PrintObj();
	return 0;
}