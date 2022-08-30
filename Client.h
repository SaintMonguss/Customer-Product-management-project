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
	string m_email;

public:
	Client() 
	{
		m_name = "", m_phoneNumber = "", m_adress = "", m_email = "";
	}

	Client(string, string, string, string);

	string GetName() const;

	string GetPhonNumber() const;

	string GetAdress() const;

	string Getemail() const;

	void SetName(string );

	void SetPhoneNumber(string );

	void SetAdress(string );

	void Setemail(string );
};

#endif