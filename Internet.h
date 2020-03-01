#ifndef INTERNET_H
#define INTERNET_H

#include <vector>
#include <cstdlib>
#include <iostream>

#include "Admin.h"
#include "Person.h"
#include "Guest.h"
#include "Fan.h"
#include "User.h"
#include "Website.h"
#include "Blog.h"
#include "NewsPortal.h"
#include "Fanpage.h"
#include "CompanyWebsite.h"
#include "Post.h"

using namespace std;

class Internet {
private:
	vector<Person*> people;
	vector<Website*> websites;
	string lastIP;
	
	// Internet is a singleton
	Internet();
	~Internet();
	
	string NextIP();
	
public:
	Internet(const Internet&);
	Internet operator= (const Internet&);
	
	static Internet& GetInternet();
	
	Person* GetPerson(unsigned int n) const;
	Website* GetWebsite(unsigned int n) const;
	
	Person* FindPersonByName(string name) const;
	Person* FindPersonByIP(string IP) const;
	Website* FindWebsiteByAddress(string address) const;
	CompanyWebsite* FindCompanyWebsiteByCompanyName(string companyName) const;
	
	Person* CreatePerson(string name, string address, unsigned int age);
	bool RegisterPerson(Person* person);
	bool RegisterWebsite(Website* website);
	
	bool IsPersonRegistered(Person* person) const;
	bool IsWebsiteRegistered(Website* website) const;
	
	bool RemovePerson(Person* person);
	bool RemoveWebsite(Website* website);
	
	void Clear();
	
	void PrintAllPeople() const;
	void PrintAllWebsites() const;
	
	// Adds the website/person to the internet
	friend Internet& operator<<(Internet& internet, Website& website);
	friend Internet& operator<<(Internet& internet, Person& person);
	
	// Removes the website/person from the internet
	friend Internet& operator>>(Internet& internet, Website& website);
	friend Internet& operator>>(Internet& internet, Person& person);
};

#endif