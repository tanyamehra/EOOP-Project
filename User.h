#ifndef USER_H
#define USER_H


#include <vector>
#include "Person.h"

using namespace std;

class Website;

class User : public Person {
protected:
	string username;
	string password;
	bool loggedIn;
	Website* site;
public:
	User(string name, string address, string IP, unsigned int age, string username, string password, Website* site);
	virtual ~User();
	
	string GetUsername() const;
	string GetPassword() const;
	bool ComparePassword(string password) const; // Checks if the provided password is correct
	bool IsLoggedIn() const; // Used for permissions
	void SetLoggedIn(bool loggedIn);
	Website* GetSite() const;
	
	bool IsUser() const override;
	
	// Prints the user's data
	friend ostream& operator<<(ostream& output, const User& user);
};

#endif