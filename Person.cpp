#include "Person.h"
#include <iostream>

using namespace std;

Person::Person(string name, string address, string IP, unsigned int age)
{
	this->name = name;
	this->address = address;
	this->IP = IP;
	this->age = age;
}

Person::~Person() {}

string Person::GetAddress() const
{
	return address;
}

unsigned int Person::GetAge() const
{
	return age;	
}

string Person::GetIP() const
{
	return IP;
}

string Person::GetName() const
{
	return name;
}

bool Person::IsAdmin() const
{
	return false;
}

bool Person::IsGuest() const
{
	return false;
}

bool Person::IsUser() const
{
	return false;
}

ostream& operator<< (ostream& output, const Person& person)
{
	output << "[Person] " << person.IP << ": " << person.name << '(' << person.age << "), " << person.address << endl;
	return output;
}