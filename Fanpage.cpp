#include "Fanpage.h"
#include "Fan.h"
#include "Post.h"
#include "User.h"
#include <cstdlib>
#include <iostream>

using namespace std;

Fanpage::Fanpage(string description, string address) : Website(description, address) { }

Fanpage::~Fanpage() { }

bool Fanpage::DoesFanLikeFanpage(Fan* fan)
{
	if (fan == NULL) return false;
	for (unsigned int i = 0; i < likes.size(); i++)
	{
		if (likes[i] == (Person*)fan)
		{
			return true;
		}
	}
	return false;
}

bool Fanpage::RegisterLike(Fan* fan)
{
	if (fan == NULL) return false;
	if (!DoesFanLikeFanpage(fan))
	{
		likes.push_back(fan);
		return true;
	}
	else
	{
		return false;
	}
}

bool Fanpage::RemoveLike(Fan* fan)
{
	if (fan == NULL) return false;
	if (DoesFanLikeFanpage(fan))
	{
		for (unsigned int i = 0; i < likes.size(); i++)
		{
			if (likes[i] == (Person*)fan)
			{
				likes.erase(likes.begin() + i);
				return true;
			}
		}
	}
	return false;
}

unsigned int Fanpage::CountLikes() const
{
	return likes.size();
}

string Fanpage::WebsiteType() const
{
	return "Fanpage";
}

ostream& operator<< (ostream& output, const Fanpage& site)
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
	output << "Likes: " << site.CountLikes() << endl << endl;
	
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