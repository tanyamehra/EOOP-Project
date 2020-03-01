#include "Admin.h"
#include "Website.h"
#include <iostream>

using namespace std;

Admin::Admin(string name, string address, string IP, unsigned int age, string username, string password, Website* site)
	: User(name, address, IP, age, username, password, site) { }

Admin::~Admin()
{
	site->DemoteAdmin(this, false);
}

bool Admin::IsAdmin() const
{
	return true;
}

ostream& operator<< (ostream& output, const Admin& admin)
{
	output << "[Admin] " << admin.username << '[' << admin.IP << "], ";
	output << admin.GetSite()->GetAddress() << endl;
	return output;
}