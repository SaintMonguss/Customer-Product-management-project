#include "Client.h"
#include <iostream>


Client::Client(int id)
	: m_id(id), m_name(""), m_phoneNumber(""), m_adress(""), m_Email("") {}

Client:: Client(int id, string name, string phoneNumber, string adress, string email)
	: m_id(id), m_name(name), m_phoneNumber(phoneNumber), m_adress(adress), m_Email(email) {}

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

string Client::GetEmail() const
{
	return m_Email;
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

void Client::SetEmail(string email)
{
	m_Email = email;
}