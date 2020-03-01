#include "NewsPortal.h"
#include "Post.h"
#include "Person.h"
#include "Guest.h"
#include "User.h"
#include <iostream>
#include <cstdlib>

using namespace std;

NewsPortal::NewsPortal(string description, string address) : Website(description, address) 
{
	this->mainHeadline = NULL;
}

NewsPortal::~NewsPortal() {}

bool NewsPortal::SetMainHeadline(Post* headline, Person* requestSource)
{
	if (headline == NULL || requestSource == NULL) return false;
	if ((requestSource->IsAdmin() || (requestSource->IsUser() && IsUserAdmin((User*)requestSource))) && headline->GetHost() == (Website*)this)
	{
		headline->EditVisibility(false, requestSource);
		mainHeadline = headline;
		return true;
	}
	else
	{
		return false;
	}
}

void NewsPortal::RegisterGuestVisit(Guest* guest)
{
	if (guest == NULL) return;
	Website::RegisterGuestVisit(guest);
	if (mainHeadline != NULL)
	{
		mainHeadline->ReadPost((Person*)guest);
	}
}

string NewsPortal::WebsiteType() const
{
	return "News portal";
}

ostream& operator<< (ostream& output, const NewsPortal& site)
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
	
	if (site.mainHeadline)
	{
		for (int i = 0; i < 60; i++)
		{
			output << '!';
		}
		output << endl << *(site.mainHeadline) << endl;
		for (int i = 0; i < 60; i++)
		{
			output << '!';
		}
		output << endl << endl;
	}
	
	for (unsigned int i = site.posts.size()-1; i >= 0 && i < site.posts.size(); i--)
	{
		Post* post = site.posts[i];
		string authorName;
		if (post->GetAuthor()->IsUser())
		{
			authorName = ((User*)post->GetAuthor())->GetUsername();
		}
		else
		{
			authorName = post->GetAuthor()->GetName();
		}
		
		output << "+ [" << i << "] " << authorName << ": " << post->GetTitle() << endl;
	}
	
	output << endl << "Guest visits: " << site.CountGuestVisits() << endl;
	output << endl << "Registered users: " << site.CountUsers() << endl;
	
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