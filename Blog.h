#ifndef BLOG_H
#define BLOG_H


#include <vector>
#include "Website.h"

using namespace std;

class Person;
class Admin;
class User;

class Blog : public Website {
private:
	Person* author;

public:
	Blog(string description, string address, Person* author);
	virtual ~Blog();
	
	// There is only one admin on a blog
	Admin* GrantAdminToUser(User* user) override;
	User* DemoteAdmin(Admin* admin, bool memory) override;
	
	int CheckReadPermissions(Person* person) const override;
	int CheckWritePermissions(Person* person) const override;
	
	string WebsiteType() const override;
	
	// Prints the blog
	friend ostream& operator<<(ostream& output, const Blog& blog);
};

#endif