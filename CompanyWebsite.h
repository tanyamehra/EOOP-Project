#ifndef COMPANY_WEBSITE_H
#define COMPANY_WEBSITE_H

#include <vector>
#include "Website.h"

using namespace std;

class Person;
class Admin;
class User;

class CompanyWebsite : public Website {
private:
	string companyName;
	string companyAddress;
	string companyContact;
	Person* lastEditor;

public:
	CompanyWebsite(string description, string address, string companyName, string companyAddress, string companyContact);
	virtual ~CompanyWebsite();
	
	int CheckReadPermissions(Person* person) const override;
	int CheckWritePermissions(Person* person) const override;
	
	// There are no posts on a company website
	Post* CreatePost(string title, string content, Person* author, bool requiresLogin) override;
	
	// Updates the company's data (permissive)
	bool UpdateCompanyData(string companyName, string companyAddress, string companyContact, Person* requestSource);
	
	string GetCompanyName() const;
	string WebsiteType() const override;
	
	// Prints the website
	friend ostream& operator<<(ostream& output, const CompanyWebsite& companyWebsite);
};

#endif