#include "ProjectHeader.h"

#include <iostream>

// �̸� �״�� ������ �Է� �ޱ� ���� �Լ�
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
			std::cout << "���ڸ� �Է����ּ��� : ";
		}
	} while (isInt);
	return num;
}