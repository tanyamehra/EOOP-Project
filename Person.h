#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <vector>

using namespace std;

class Person {
protected:
	string name;
	string address;
	string IP;
	unsigned int age;
public:
	Person(string name, string address, string IP, unsigned int age);
	virtual ~Person();
	
	string GetName() const;
	string GetAddress() const;
	string GetIP() const;
	unsigned int GetAge() const;
	
	// Used to figure out the type of the person when determining permissions
	virtual bool IsGuest() const;
	virtual bool IsUser() const;
	virtual bool IsAdmin() const;
	
	// Prints the person's data
	friend ostream& operator<<(ostream& output, const Person& person);
};

#endif