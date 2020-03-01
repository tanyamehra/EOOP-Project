#ifndef ADMIN_H
#define ADMIN_H


#include "User.h"

using namespace std;

class Website;

class Admin : public User {
public:
	Admin(string name, string address, string IP, unsigned int age, string username, string password, Website* site);
	virtual ~Admin();
	
	bool IsAdmin() const override;
	
	// Prints the admin's data
	friend ostream& operator<<(ostream& output, const Admin& admin);
};

#endif