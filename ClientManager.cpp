#include "ProjectHeader.h"

#include <iostream>
#include <string>
#include <iomanip>
#include <stdio.h>
#include <windows.h>


ClientManager::ClientManager(map<int, Client*> CL) : clientList(CL) {};

//고객 정보 추가
void ClientManager::AddObj()
{
	string input;
	Client* client;
	int id;
	if (clientList.empty())
		id = 1;
	else
		id = (clientList.rbegin()->first) + 1;
	try
	{
		client = new Client(id);
	}
	catch (const std::bad_alloc& e)
	{
		std::cout << "메모리 할당 실패";
		return;
	}
	std::cout << "────────────────────────────────────────────────────────────────────────────────────────────" << std::endl;
	std::cout << "                                           신규 고객 등록                                   " << std::endl;
	std::cout << "────────────────────────────────────────────────────────────────────────────────────────────" << std::endl;
	std::cout << std::endl;;
	std::cout << "이름 : ";
	std::cin >> input;
	client->SetName(input);
	std::cout << "연락처( - 없이 입력) : ";
	std::cin >> input;
	client->SetPhoneNumber(input);
	std::cout << "주소 : ";
	cin.ignore(10, '\n'); // 버퍼에 남은 개행 삭제
	std::getline(std::cin, input, '\n'); //TODO: 32글자 까지 받을수 있게 제한 해야함
	client->SetAdress(input);
	std::cout << "E-mail : ";
	std::cin >> input;
	client->SetEmail(input);
	try
	{
		auto tmp = (clientList.insert({ id, client }));
		if (tmp.second == false)
			throw;
	}
	catch (...)
	{
		std::cout << std::endl;
		std::cout << "키 ID 중복 발생, 고객 추가 실패" << std::endl;
		std::cout << std::endl;
		return;
	}
	std::cout << "신규 고객 등록 완료!";
	Sleep(1500); //화면 지연
	system("cls");
	return;
}

void ClientManager::DelObj()
{
	int id;
	char check;
	Client *client;


	std::cout << "────────────────────────────────────────────────────────────────────────────────────────────" << std::endl;
	std::cout << "                                           고객 정보 삭제                                   " << std::endl;
	std::cout << "────────────────────────────────────────────────────────────────────────────────────────────" << std::endl;
	std::cout << std::endl;;
	PrintObj(); // 고객 정보 출력 
	std::cout << std::endl;
	std::cout << "삭제할 고객의 ID를 입력 해주세요 : ";
	cin.ignore(10,'\n'); //버퍼 청소
	std::cin >> id;

	try
	{
		clientList.at(id);
	}
	catch (std::out_of_range e)
	{
		std::cout << "해당하는 ID는 존재하지 않습니다!!" << std::endl;
		return;
	}
	client = clientList.find(id)->second; // 찾아서 클라이언트 객체를 할당
	std::cout << client->GetName() << " 고객 정보를 삭제 하시겠습니까?"<<std::endl;
	do
	{
		cin.ignore(999, '\n'); //버퍼 청소
		std::cout << "[ Y / N ] : ";
		std::cin >> check;
		check = toupper(check); // 대문자 전환
	} while ((check != 'Y') && (check != 'N'));
	if (check == 'N')
		return;
	clientList.erase(id);
	std::cout << client->GetName() << " 고객 정보를 삭제했습니다" << std::endl;
	Sleep(1500);
	system("cls");
}
void ClientManager::ModiObj()
{

}
void ClientManager::SerchObj()
{
	system("cls");
	
}

void ClientManager::PrintObj()
{
	system("cls");
	std::cout << "┌───────┬───────────┬──────────────┬────────────────────────────────────────────────────────────────┬─────────────────────────┐" << std::endl;;
	std::cout << "│   ID       이름          번호                                      주소                                       E-mail        │" << std::endl;;
	
	
	for(auto itr = clientList.begin(); itr != clientList.end(); itr++)
	{
		Client* client = itr->second;
		std::cout << "├───────┼───────────┼──────────────┼────────────────────────────────────────────────────────────────┼─────────────────────────┤" << std::endl;;
		std::cout << "│ ";
		///////////////////// ID 칸 양식
		cout.fill('0');
		std::cout.width(6);
		std::cout << itr->first;
		cout.fill(' '); // 공간 채움을 공백으로 다시 변경
		std::cout << " ";
		///////////////////// 이름 칸 양식
		std::cout << "  ";
		std::cout.width(8);
		std::cout << client->GetName();
		std::cout << "  ";
		///////////////////// 번호 칸 양식
		std::cout << "  ";
		std::cout.width(11);
		std::cout << client->GetPhonNumber();
		std::cout << "  ";
		///////////////////// 주소 칸 양식
		std::cout.width(63);
		std::cout << client->GetAdress();
		std::cout << "  ";
		///////////////////// 이메일 칸 양식
		std::cout.width(24);
		std::cout << client->GetEmail();
		std::cout << " │" <<std::endl;
	}

	std::cout << "└───────┴───────────┴──────────────┴────────────────────────────────────────────────────────────────┴─────────────────────────┘" << std::endl;;
}
