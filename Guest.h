#ifndef GUEST_H
#define GUEST_H

#include <vector>
#include "Person.h"

using namespace std;

class Website;

class Guest : public Person {
protected:
	vector<Website*> siteVisits;
public:
	Guest(string name, string address, string IP, unsigned int age);
	virtual ~Guest();
	
	void VisitSite(Website* site);
	unsigned int CountSpecificSiteVisits(Website* site) const; // How many times this person has visited the given website
	unsigned int CountSiteVisits(bool unique = false) const; // How many times this person has visited anything, or how many unique websites has this person visited, depending on the flag
	
	bool IsGuest() const override;
	
	// Prints the guest's data
	friend ostream& operator<<(ostream& output, const Guest& guest);
};

#endif