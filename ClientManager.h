#ifndef __CLIENTMANAGER_H__
#define __CLIENTMANAGER_H__

#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <sstream>

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
	ClientManager();
	~ClientManager();

    std::vector<string> parseCSV(std::istream& , char);
  
	virtual void AddObj() override;
	virtual void DelObj() override;
	virtual void ModiObj() override;
	virtual void SerchObj() override;
	virtual void PrintObj() override;
	virtual void* TossObj(int) override;
	void printClientForm(map<int, Client*> &) const;
};

#endif