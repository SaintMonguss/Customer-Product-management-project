#ifndef __CLIENTMANAGER_H__
#define __CLIENTMANAGER_H__

#include <iostream>
#include <map>

#include "Manager.h"
#include "Client.h"


using std::cout;
using std::cin;
using std::string;
using std::map;

class ClientManager : public Manager
{
private:
	map<int, Client*> clientList;

public:
	ClientManager() {};
	ClientManager(map<int, Client*>);

	virtual void AddObj() override;
	virtual void DelObj(int) override;
	virtual void ModiObj(int) override;
	virtual void SerchObj(int) override;
	virtual void SerchObj(string) override;
	virtual void PrintObj() override;
};

#endif