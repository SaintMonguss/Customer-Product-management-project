#include "ProjectHeader.h"

#include <iostream>


Client::Client(int id)
	: m_id(id), m_name(""), m_phoneNumber(""), m_address(""), m_Email("") {}

Client:: Client(int id, string name, string phoneNumber, string address, string email)
	: m_id(id), m_name(name), m_phoneNumber(phoneNumber), m_address(address), m_Email(email) {}

int Client::GetId() const
{
	return m_id;
}


string Client::GetName() const
{
	return m_name;
}

string Client::GetPhoneNumber() const
{
	return m_phoneNumber;
}

string Client::GetAddress() const
{
	return m_address;
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

void Client::SetAddress(string address)
{
	m_address = address;
}

void Client::SetEmail(string email)
{
	m_Email = email;
}