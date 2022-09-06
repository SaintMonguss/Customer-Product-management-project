#ifndef __CLIENT_H__
#define __CLIENT_H__

#include <iostream>

using std::cout;
using std::cin;
using std::string;



class Client
{
private:
	const int m_id;
	string m_name;
	string m_phoneNumber;
	string m_address;
	string m_Email;

public:
	Client(const int id);
	Client(int ,string, string, string, string);
	
	int GetId() const;
	string GetName() const;
	string GetPhoneNumber() const;
	string GetAddress() const;
	string GetEmail() const;

	void SetName(string );
	void SetPhoneNumber(string );
	void SetAddress(string );
	void SetEmail(string );
};

#endif