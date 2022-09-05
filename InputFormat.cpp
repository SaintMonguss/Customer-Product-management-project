#include "ProjectHeader.h"

#include <iostream>

// 이름 그대로 정수만 입력 받기 위한 함수
int InputFormat::IntCin()
{
	int num;
	bool isInt = false;
	do
	{
		std::cin >> num;
		if (isInt = !std::cin)
		{
			std::cin.clear();
			std::cin.ignore(999, '\n');
			std::cout << "숫자만 입력해주세요 : ";
		}
	} while (isInt);
	return num;
}