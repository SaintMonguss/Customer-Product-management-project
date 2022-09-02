#include "ProjectHeader.h"

#include <iostream>
#include <string>
#include <iomanip>
#include <stdio.h>
#include <windows.h>


ClientManager::ClientManager(map<int, Client*> CL) : clientList(CL) {};

//°í°´ Á¤º¸ Ãß°¡
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
		std::cout << "¸Þ¸ð¸® ÇÒ´ç ½ÇÆÐ";
		return;
	}
	std::cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << std::endl;
	std::cout << "                                           ½Å±Ô °í°´ µî·Ï                                   " << std::endl;
	std::cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << std::endl;
	std::cout << std::endl;;
	std::cout << "ÀÌ¸§ : ";
	std::cin >> input;
	client->SetName(input);
	std::cout << "¿¬¶ôÃ³( - ¾øÀÌ ÀÔ·Â) : ";
	std::cin >> input;
	client->SetPhoneNumber(input);
	std::cout << "ÁÖ¼Ò : ";
	cin.ignore(10, '\n'); // ¹öÆÛ¿¡ ³²Àº °³Çà »èÁ¦
	std::getline(std::cin, input, '\n'); //TODO: 32±ÛÀÚ ±îÁö ¹ÞÀ»¼ö ÀÖ°Ô Á¦ÇÑ ÇØ¾ßÇÔ
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
		std::cout << "Å° ID Áßº¹ ¹ß»ý, °í°´ Ãß°¡ ½ÇÆÐ" << std::endl;
		std::cout << std::endl;
		return;
	}
	std::cout << "½Å±Ô °í°´ µî·Ï ¿Ï·á!";
	Sleep(1500); //È­¸é Áö¿¬
	system("cls");
	return;
}

void ClientManager::DelObj()
{
	int id;
	char check;
	Client *client;


	std::cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << std::endl;
	std::cout << "                                           °í°´ Á¤º¸ »èÁ¦                                   " << std::endl;
	std::cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << std::endl;
	std::cout << std::endl;;
	PrintObj(); // °í°´ Á¤º¸ Ãâ·Â 
	std::cout << std::endl;
	std::cout << "»èÁ¦ÇÒ °í°´ÀÇ ID¸¦ ÀÔ·Â ÇØÁÖ¼¼¿ä : ";
	cin.ignore(10,'\n'); //¹öÆÛ Ã»¼Ò
	std::cin >> id;

	try
	{
		clientList.at(id);
	}
	catch (std::out_of_range e)
	{
		std::cout << "ÇØ´çÇÏ´Â ID´Â Á¸ÀçÇÏÁö ¾Ê½À´Ï´Ù!!" << std::endl;
		return;
	}
	client = clientList.find(id)->second; // Ã£¾Æ¼­ Å¬¶óÀÌ¾ðÆ® °´Ã¼¸¦ ÇÒ´ç
	std::cout << client->GetName() << " °í°´ Á¤º¸¸¦ »èÁ¦ ÇÏ½Ã°Ú½À´Ï±î?"<<std::endl;
	do
	{
		cin.ignore(999, '\n'); //¹öÆÛ Ã»¼Ò
		std::cout << "[ Y / N ] : ";
		std::cin >> check;
		check = toupper(check); // ´ë¹®ÀÚ ÀüÈ¯
	} while ((check != 'Y') && (check != 'N'));
	if (check == 'N')
		return;
	clientList.erase(id);
	std::cout << client->GetName() << " °í°´ Á¤º¸¸¦ »èÁ¦Çß½À´Ï´Ù" << std::endl;
	Sleep(1500);
	system("cls");
}
void ClientManager::ModiObj()
{

}
void ClientManager::SerchObj()
{
	string name;
	Client* client;

	system("cls");

	// Ãâ·Â ¾ç½Ä
	std::cout << "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¨¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¨¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¨¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¨¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤" << std::endl;;
	std::cout << "¦¢   ID       ÀÌ¸§          ¹øÈ£                                      ÁÖ¼Ò                                       E-mail        ¦¢" << std::endl;;
	// Ãâ·Â ¾ç½Ä
	std::cout << "°Ë»öÇÒ ´ë»óÀÇ ÀÌ¸§À» ÀÔ·ÂÇØ ÁÖ¼¼¿ä : ";
	cin.ignore(999, '\n'); //¹öÆÛ Ã»¼Ò
	std::cin >> name;
	system("cls");
	//for (auto itr = clientList.begin(); itr != clientList.end(); itr++)
	//{
	//	if (name == itr->second->GetName())
	//	{

	//	}

	//}

	// ÀÌºÎºÐÀ» ÇÔ¼ö·Î µû·Î ¸¸µé¾î¼­ »©´Â°Ô ¸Â´Ù´Â ÆÇ´Ü. »ó¼Ó ÀÎÅÍÆäÀÌ½º¸¦ ¿À¹ö¶óÀÌµùÇÑ ÇÔ¼ö³»¿¡¼­ ³»ºÎ ÇÔ¼ö¸¦ ´Ù½Ã ºÒ·¯¼­ ¾²´Â°ÍÀº ¹®Á¦ ¾øÀ½
}

void ClientManager::PrintObj()
{
	Client* client;
	system("cls");
	std::cout << "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¨¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¨¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¨¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¨¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤" << std::endl;;
	std::cout << "¦¢   ID       ÀÌ¸§          ¹øÈ£                                      ÁÖ¼Ò                                       E-mail        ¦¢" << std::endl;;
	
	
	for(auto itr = clientList.begin(); itr != clientList.end(); itr++)
	{
		client = itr->second;
		std::cout << "¦§¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦«¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦«¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦«¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦«¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦©" << std::endl;;
		std::cout << "¦¢ ";
		///////////////////// ID Ä­ ¾ç½Ä
		cout.fill('0');
		std::cout.width(6);
		std::cout << itr->first;
		cout.fill(' '); // °ø°£ Ã¤¿òÀ» °ø¹éÀ¸·Î ´Ù½Ã º¯°æ
		std::cout << " ";
		///////////////////// ÀÌ¸§ Ä­ ¾ç½Ä
		std::cout << "  ";
		std::cout.width(8);
		std::cout << client->GetName();
		std::cout << "  ";
		///////////////////// ¹øÈ£ Ä­ ¾ç½Ä
		std::cout << "  ";
		std::cout.width(11);
		std::cout << client->GetPhonNumber();
		std::cout << "  ";
		///////////////////// ÁÖ¼Ò Ä­ ¾ç½Ä
		std::cout.width(63);
		std::cout << client->GetAdress();
		std::cout << "  ";
		///////////////////// ÀÌ¸ÞÀÏ Ä­ ¾ç½Ä
		std::cout.width(24);
		std::cout << client->GetEmail();
		std::cout << " ¦¢" <<std::endl;
	}

	std::cout << "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦ª¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦ª¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦ª¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦ª¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥" << std::endl;;
}
