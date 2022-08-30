#include "Client.h"
#include <iostream>


Client:: Client(string name, string phoneNumber, string adress, string email)
	: m_name(name), m_phoneNumber(phoneNumber), m_adress(adress), m_email(email) {}

string Client::GetName() const
{
	return m_name;
}

string Client::GetPhonNumber() const
{
	return m_phoneNumber;
}

string Client::GetAdress() const
{
	return m_adress;
}

string Client::Getemail() const
{
	return m_email;
}

void Client::SetName(string name)
{
	m_name = name;
}

void Client::SetPhoneNumber(string phoneNumber)
{
	m_phoneNumber = phoneNumber;
}

void Client::SetAdress(string adress)
{
	m_adress = adress;
}

void Client::Setemail(string email)
{
	m_email = email;
}