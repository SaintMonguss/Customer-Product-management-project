#ifndef __CLIENT_H__
#define __CLIENT_H__

#include <iostream>

using std::cout;
using std::cin;
using std::string;



class Client
{
private:
	string m_name;
	string m_phoneNumber;
	string m_adress;
	string m_Email;

public:
	Client() 
	{
		m_name = "", m_phoneNumber = "", m_adress = "", m_Email = "";
	}

	Client(string, string, string, string);

	string GetName() const;

	string GetPhonNumber() const;

	string GetAdress() const;

	string GetEmail() const;

	void SetName(string );

	void SetPhoneNumber(string );

	void SetAdress(string );

	void SetEmail(string );
};

#endif