#include "Internet.h"
#include "Website.h"
#include "CompanyWebsite.h"
#include "Person.h"
#include <cstdlib>
#include <sstream>
#include <iostream>

using namespace std;

Internet::Internet()
{
	lastIP = "127.0.0.1";
}

Internet::~Internet()
{
	this->Clear();
}

Internet& Internet::GetInternet()
{
	static Internet internet;
	return internet;
}

string Internet::NextIP()
{
	int firstDot = lastIP.find(".");
	int secondDot = lastIP.find(".", firstDot+1);
	int thirdDot = lastIP.find(".", secondDot+1);
	
	int parts[4] = {0}; 
	parts[0] = atoi(lastIP.substr(0, firstDot).c_str());
	parts[1] = atoi(lastIP.substr(firstDot+1, secondDot-firstDot-1).c_str());
	parts[2] = atoi(lastIP.substr(secondDot+1, thirdDot-secondDot-1).c_str());
	parts[3] = atoi(lastIP.substr(thirdDot).c_str());
	
	parts[3]++;
	if (parts[3] >= 255) 
	{
		parts[2]++;
		parts[3] = 0;
	}
	if (parts[2] >= 255)
	{
		parts[1]++;
		parts[2] = 0;
		parts[3] = 0;
	}
	if (parts[1] >= 255)
	{
		parts[0]++;
		parts[1] = 0;
		parts[2] = 0;
		parts[3] = 0;
	}
	
	stringstream ss;
	ss << parts[0] << '.' << parts[1] << '.' << parts[2] << '.' << parts[3];
	
	lastIP = ss.str();
	ss.str(string());
	
	return lastIP;
}

void Internet::Clear()
{
	for (unsigned int i = 0; i < people.size(); i++) 
	{
		cout << "Deleting " << *(people[i]);
		delete people[i];
	}
	for (unsigned int i = 0; i < websites.size(); i++) 
	{
		cout << "Deleting " << websites[i]->GetAddress() << endl;
		delete websites[i];
	}
	people.clear();
	websites.clear();
}

Person* Internet::GetPerson(unsigned int n) const
{
	if (n < people.size()) 
	{
		return people[n];
	} else 
	{
		return NULL;
	}
}

Website* Internet::GetWebsite(unsigned int n) const
{
	if (n < websites.size()) 
	{
		return websites[n];
	} else 
	{
		return NULL;
	}
}

Person* Internet::FindPersonByName(string name) const
{
	for (unsigned int i = 0; i < people.size(); i++)
	{
		if (people[i]->GetName() == name)
		{
			return people[i];
		}
	}
	return NULL;
}

Person* Internet::FindPersonByIP(string IP) const
{
	for (unsigned int i = 0; i < people.size(); i++)
	{
		if (people[i]->GetIP() == IP)
		{
			return people[i];
		}
	}
	return NULL;
}

Website* Internet::FindWebsiteByAddress(string address) const
{
	for (unsigned int i = 0; i < websites.size(); i++)
	{
		if (websites[i]->GetAddress() == address)
		{
			return websites[i];
		}
	}
	return NULL;
}

CompanyWebsite* Internet::FindCompanyWebsiteByCompanyName(string companyName) const
{
	for (unsigned int i = 0; i < websites.size(); i++)
	{
		if (websites[i]->WebsiteType() == "Company website")
		{
			CompanyWebsite* site = (CompanyWebsite*)websites[i];
			if (site->GetCompanyName() == companyName)
			{
				return site;
			}
		}
	}
	return NULL;
}

Person* Internet::CreatePerson(string name, string address, unsigned int age)
{
	Person* person = new Person(name, address, NextIP(), age);
	RegisterPerson(person);
	return person;
}

bool Internet::RegisterPerson(Person* person)
{
	if (person == NULL) return false;
	if (IsPersonRegistered(person)) 
	{
		return false;
	} else
	{
		people.push_back(person);
		return true;
	}
}

bool Internet::RegisterWebsite(Website* website)
{
	if (website == NULL) return false;
	if (IsWebsiteRegistered(website)) 
	{
		return false;
	} else
	{
		websites.push_back(website);
		return true;
	}
}

bool Internet::IsPersonRegistered(Person* person) const
{
	if (person == NULL) return false;
	for (unsigned int i = 0; i < people.size(); i++)
	{
		if (people[i] == person)
		{
			return true;
		}
	}
	return false;
}

bool Internet::IsWebsiteRegistered(Website* website) const
{
	if (website == NULL) return false;
	for (unsigned int i = 0; i < websites.size(); i++)
	{
		if (websites[i] == website)
		{
			return true;
		}
	}
	return false;
}

bool Internet::RemovePerson(Person* person)
{
	if (person == NULL) return false;
	if (IsPersonRegistered(person))
	{
		for (unsigned int i = 0; i < people.size(); i++)
		{
			if (people[i] == person)
			{
				people.erase(people.begin() + i);
				return true;
			}
		}
	}
	return false;
}

bool Internet::RemoveWebsite(Website* website)
{
	if (website == NULL) return false;
	if (IsWebsiteRegistered(website))
	{
		for (unsigned int i = 0; i < websites.size(); i++)
		{
			if (websites[i] == website)
			{
				websites.erase(websites.begin() + i);
				return true;
			}
		}
	}
	return false;
}

void Internet::PrintAllPeople() const
{
	for (unsigned int i = 0; i < people.size(); i++)
	{
		cout << '[' << i << "] " << *(people[i]);
	}
}

void Internet::PrintAllWebsites() const
{
	for (unsigned int i = 0; i < websites.size(); i++)
	{
		cout << '[' << i << "] " << websites[i]->GetAddress() << " - " << websites[i]->GetDescription() << endl;
	}
}

Internet& operator<< (Internet& internet, Website& website)
{
	internet.RegisterWebsite(&website);
	return internet;
}

Internet& operator<< (Internet& internet, Person& person)
{
	internet.RegisterPerson(&person);
	return internet;
}

Internet& operator>> (Internet& internet, Website& website)
{
	internet.RemoveWebsite(&website);
	return internet;
}

Internet& operator>> (Internet& internet, Person& person)
{
	internet.RemovePerson(&person);
	return internet;
}