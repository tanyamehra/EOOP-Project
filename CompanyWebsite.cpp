#include "CompanyWebsite.h"
#include "Person.h"
#include <cstdlib>
#include <iostream>

using namespace std;

CompanyWebsite::CompanyWebsite(string description, string address, string companyName, string companyAddress, string companyContact)
	: Website(description, address)
{
	this->companyName = companyName;
	this->companyAddress = companyAddress;
	this->companyContact = companyContact;
	lastEditor = NULL;
}

CompanyWebsite::~CompanyWebsite() { }

int CompanyWebsite::CheckReadPermissions(Person* person) const
{
	if (person == NULL) return 0;
	return 1;
}

int CompanyWebsite::CheckWritePermissions(Person* person) const
{
	if (person == NULL) return 0;
	if (person->IsAdmin() || (person->IsUser() && IsUserAdmin((User*)person)))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

Post* CompanyWebsite::CreatePost(string title, string content, Person* author, bool requiresLogin)
{
	return NULL;
}

bool CompanyWebsite::UpdateCompanyData(string companyName, string companyAddress, string companyContact, Person* requestSource)
{

	if (CheckWritePermissions(requestSource))
	{
		this->companyName = companyName;
		this->companyAddress = companyAddress;
		this->companyContact = companyContact;
		
		this->lastEditor = requestSource;
		
		return true;
	}
	else
	{
		return false;
	}
}

string CompanyWebsite::GetCompanyName() const
{
	return companyName;
}

string CompanyWebsite::WebsiteType() const
{
	return "Company website";
}

ostream& operator<< (ostream& output, const CompanyWebsite& site)
{
	for (int i = 0; i < 60; i++)
	{
		output << '=';
	}
	output << endl;
	for (int i = 0; i < 60; i++)
	{
		output << '-';
	}
	output << endl << site.GetAddress() << "\t[" << site.WebsiteType() << ']' << endl;
	for (int i = 0; i < 60; i++)
	{
		output << '-';
	}
	output << endl << endl << site.GetDescription() << endl << endl;
	
	output << site.companyName << endl;
	output << site.companyAddress << endl;
	output << site.companyContact << endl << endl;
	
	output << endl << "Guest visits: " << site.CountGuestVisits() << endl;
	
	tm* ptm = localtime(&site.creationTime);
	char timeBuffer[32];
	strftime(timeBuffer, 32, "%Y-%m-%d %H:%M:%S", ptm);
	
	output << "Created: " << timeBuffer << endl << endl;
	
	for (int i = 0; i < 60; i++)
	{
		output << '=';
	}
	return output;
}