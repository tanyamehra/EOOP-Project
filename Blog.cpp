#include "Blog.h"
#include "Person.h"
#include "Admin.h"
#include "Post.h"
#include <cstdlib>
#include <iostream>

using namespace std;

Blog::Blog(string description, string address, Person* author) : Website(description, address)
{
	this->author = author;
	Admin* authorAdmin = new Admin(author->GetName(), author->GetAddress(), author->GetIP(), author->GetAge(), "root", "admin", this);
	admins.push_back(authorAdmin);
}

Blog::~Blog() {}

Admin* Blog::GrantAdminToUser(User* user)
{
	return NULL;
}

User* Blog::DemoteAdmin(Admin* admin, bool memory)
{
	return NULL;
}

int Blog::CheckReadPermissions(Person* person) const
{
	if (person == NULL) return 0;
	return 1;
}

int Blog::CheckWritePermissions(Person* person) const
{
	if (person == NULL) return 0;
	return (person == author);
}

string Blog::WebsiteType() const
{
	return "Blog";
}

ostream& operator<< (ostream& output, const Blog& site)
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
	output << "by " << site.GetAdmin(0)->GetUsername() << endl << endl;
	
	for (unsigned int i = site.posts.size()-1; i >= 0 && i < site.posts.size(); i--)
	{
		Post* post = site.posts[i];
		output << "+ [" << i << "] " << post->GetTitle() << endl;
	}
	
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