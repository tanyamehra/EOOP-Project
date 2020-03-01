#include "User.h"
#include "Website.h"
#include <iostream>

using namespace std;

User::User(string name, string address, string IP, unsigned int age, string username, string password, Website* site) 
	: Person(name, address, IP, age)
{
	this->username = username;
	this->password = password;
	this->site = site;
	
	this->loggedIn = false;
}

User::~User() 
{
	site->RemoveUser(this, false);
}

bool User::ComparePassword(string password) const
{
	return (this->password == password);
}

string User::GetUsername() const
{
	return username;
}

string User::GetPassword() const
{
	return password;
}

Website* User::GetSite() const
{
	return site;
}

bool User::IsLoggedIn() const
{
	return loggedIn;
}

void User::SetLoggedIn(bool loggedIn)
{
	this->loggedIn = loggedIn;
}

bool User::IsUser() const
{
	return true;
}

ostream& operator<< (ostream& output, const User& user)
{
	output << "[User] " << user.username << '[' << user.IP << "] - ";
	if (user.IsLoggedIn())
	{
		output << "Online";
	}
	else
	{
		output << "Offline";
	}
	output << ", " << user.GetSite()->GetAddress() << endl;
	return output;
}