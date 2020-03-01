#include "Guest.h"
#include "Website.h"
#include <iostream>
#include <map>
#include <cstdlib>

using namespace std;

Guest::Guest (string name, string address, string IP, unsigned int age) : Person(name, address, IP, age) { }

Guest::~Guest () 
{
	for (unsigned int i = 0; i < siteVisits.size(); i++) 
	{
		siteVisits[i]->RemoveGuestVisitsByGuest(this);
	}
}

unsigned int Guest::CountSiteVisits(bool unique) const
{
	if (unique)
	{
		map<Website*, bool> uniqueSiteVisits;
		for (unsigned int i = 0; i < siteVisits.size(); i++) 
		{
			uniqueSiteVisits[siteVisits[i]] = true;
		}
		return uniqueSiteVisits.size();
	} else 
	{
		return siteVisits.size();
	}
}

unsigned int Guest::CountSpecificSiteVisits(Website* site) const
{
	if (site == NULL) return 0;
	unsigned int count;
	for (unsigned int i = 0; i < siteVisits.size(); i++) 
	{
		if (siteVisits[i] == site)
		{
			count++;
		}
	}
	
	return count;
}

bool Guest::IsGuest() const
{
	return true;
}

void Guest::VisitSite(Website* site)
{
	if (site == NULL) return;
	siteVisits.push_back(site);
	site->RegisterGuestVisit(this);
}

ostream& operator<< (ostream& output, const Guest& guest)
{
	output << "[Guest] " << guest.IP << ": " << guest.name << '(' << guest.age << "), " << guest.address << endl;
	output << "\tSite visits:" << endl;
	for (unsigned int i = 0; i < guest.siteVisits.size(); i++)
	{
		output << '\t' << guest.siteVisits[i]->GetAddress() << endl;
	}
	return output;
}