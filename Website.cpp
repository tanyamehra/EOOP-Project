#include "Website.h"
#include "Guest.h"
#include "User.h"
#include "Admin.h"
#include "Post.h"
#include <iostream>
#include <map>
#include <cstdlib>

using namespace std;

Website::Website(string description, string address)
{
	this->description = description;
	this->address = address;
	
	this->creationTime = time(0);
}

Website::~Website()
{
	RemoveAllUsers();
	ClearGuestVisits();
	
	for (unsigned int i = 0; i < posts.size(); i++)
	{
		delete posts[i];
	}
	posts.clear();
}

unsigned int Website::CountUsers() const
{
	return users.size();
}

unsigned int Website::CountAdmins() const
{
	return admins.size();
}

unsigned int Website::CountGuestVisits(bool unique) const
{
	if (unique)
	{
		map<Guest*, bool> uniqueGuestVisits;
		for (unsigned int i = 0; i < guestVisits.size(); i++) 
		{
			uniqueGuestVisits[(Guest*)guestVisits[i]] = true;
		}
		return uniqueGuestVisits.size();
	} else 
	{
		return guestVisits.size();
	}
}

void Website::RegisterGuestVisit(Guest* guest)
{
	if (guest == NULL) return;
	guestVisits.push_back(guest);
}

User* Website::RegisterUser(Person* person, string username, string password)
{
	if (person == NULL) return NULL;
	if (IsIPBanned(person->GetIP()) || FindUserByUsername(username)) 
	{
		return NULL;
	}
	
	User* user = new User(person->GetName(), person->GetAddress(), person->GetIP(), person->GetAge(), username, password, this);
	users.push_back(user);
	
	return user;
}

bool Website::LogIn(string username, string password)
{
	User* user = FindUserByUsername(username);
	if (!user || user->IsLoggedIn())
	{
		return false;
	}
	if (user->ComparePassword(password))
	{
		user->SetLoggedIn(true);
		return true;
	}
	else
	{
		return false;
	}
}

bool Website::LogOut(string username)
{
	User* user = FindUserByUsername(username);
	if (!user || !user->IsLoggedIn())
	{
		return false;
	}
	else
	{
		user->SetLoggedIn(false);
		return true;
	}
}

bool Website::RemoveUser(User* user, bool memory)
{
	if (user == NULL) return false;
	if (IsUserRegistered(user))
	{
		for (unsigned int i = 0; i < users.size(); i++)
		{
			if (users[i] == (Person*)user)
			{
				Person* temp = users[i];
				users.erase(users.begin() + i);
				if (memory) delete temp;
				return true;
			}
		}
		for (unsigned int i = 0; i < posts.size(); i++)
		{
			posts[i]->RemoveContributorByUsername(user->GetUsername());
		}
	}
	return false;
}

Admin* Website::GrantAdminToUser(User* user)
{
	if (user == NULL) return NULL;
	Admin* admin = FindAdminByUsername(user->GetUsername());
	if (admin)
	{
		return admin;
	}
	else
	{
		admin = new Admin(user->GetName(), user->GetAddress(), user->GetIP(), user->GetAge(), user->GetUsername(), user->GetPassword(), this);
		admins.push_back(admin);
		return admin;
	}
}

User* Website::DemoteAdmin(Admin* admin, bool memory)
{
	if (admin == NULL) return NULL;
	if (IsAdminRegistered(admin))
	{
		User* user = FindUserByUsername(admin->GetUsername());
		for (unsigned int i = 0; i < admins.size(); i++)
		{
			if (admins[i] == (Person*)admin)
			{
				Person* temp = admins[i];
				admins.erase(admins.begin() + i);
				if (memory) delete temp;
				return user;
			}
		}
	}
	return NULL;
}

bool Website::BanIPAddress(string IP)
{
	if (IsIPBanned(IP))
	{
		return false;
	}
	else
	{
		bannedIPs.push_back(IP);
		return true;
	}
}

bool Website::UnBanIPAddress(string IP)
{
	if (IsIPBanned(IP))
	{
		for (unsigned int i = 0; i < bannedIPs.size(); i++)
		{
			if (bannedIPs[i] == IP)
			{
				bannedIPs.erase(bannedIPs.begin() + i);
				return true;
			}
		}
	}
	return false;
}

unsigned int Website::RemoveGuestVisitsByGuest(Guest* guest)
{
	if (guest == NULL) return 0;
	unsigned int count = 0;
	for (unsigned int i = 0; i < guestVisits.size(); i++)
	{
		if (guestVisits[i] == (Person*)guest)
		{
			guestVisits.erase(guestVisits.begin() + i);
			count++;
			i--;
		}
	}
	return count;
}

unsigned int Website::ClearGuestVisits()
{
	unsigned int count = guestVisits.size();
	guestVisits.clear();
	
	return count;
}

unsigned int Website::RemoveAllUsers(bool removeAdmins)
{
	for (unsigned int i = 0; i < posts.size(); i++)
	{
		posts[i]->ClearAuthor(removeAdmins);
		posts[i]->ClearContributors(removeAdmins);
	}
	
	unsigned int count = 0;
	for (unsigned int i = 0; i < users.size(); i++)
	{
		if (removeAdmins || !IsUserAdmin((User*)users[i]))
		{
			Person* temp = users[i];
			delete temp;
			count++;
			i--;
		}
	}
	if (removeAdmins)
	{
		for (unsigned int i = 0; i < admins.size(); i++)
		{
			delete admins[i];
		}
		admins.clear();
	}
	
	return count;
}

bool Website::IsIPBanned(string IP) const
{
	for (unsigned int i = 0; i < bannedIPs.size(); i++)
	{
		if (bannedIPs[i] == IP)
		{
			return true;
		}
	}
	return false;
}

bool Website::IsUserRegistered(User* user) const
{
	if (user == NULL) return false;
	for (unsigned int i = 0; i < users.size(); i++)
	{
		if (users[i] == (Person*)user)
		{
			return true;
		}
	}
	return false;
}

bool Website::IsUserAdmin(User* user) const
{
	if (user == NULL) return false;
	return FindAdminByUsername(user->GetUsername()) != NULL;
}

bool Website::IsAdminRegistered(Admin* admin) const
{
	if (admin == NULL) return false;
	for (unsigned int i = 0; i < admins.size(); i++)
	{
		if (admins[i] == (Person*)admin)
		{
			return true;
		}
	}
	return false;
}

User* Website::FindUserByUsername(string username) const
{
	for (unsigned int i = 0; i < users.size(); i++)
	{
		if (((User*)users[i])->GetUsername() == username)
		{
			return (User*)users[i];
		}
	}
	return NULL;
}

Admin* Website::FindAdminByUsername(string username) const
{
	for (unsigned int i = 0; i < admins.size(); i++)
	{
		if (((Admin*)admins[i])->GetUsername() == username)
		{
			return (Admin*)admins[i];
		}
	}
	return NULL;
}

string Website::GetDescription() const
{
	return description;
}

string Website::GetAddress() const
{
	return address;
}

time_t Website::GetCreationTime() const
{
	return creationTime;
}

User* Website::GetUser(unsigned int n) const
{
	return (User*)users[n];
}

Admin* Website::GetAdmin(unsigned int n) const
{
	return (Admin*)admins[n];
}

Post* Website::GetPost(unsigned int n) const
{
	return posts[n];
}

int Website::CheckReadPermissions(Person* person) const
{
	if (person == NULL) return 0;
	return 1;
}

int Website::CheckWritePermissions(Person* person) const
{
	if (person == NULL) return 0;
	if ((person->IsUser() && ((User*)person)->IsLoggedIn()) || person->IsAdmin())
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

Post* Website::CreatePost(string title, string content, Person* author, bool requiresLogin)
{
	if (CheckWritePermissions(author))
	{
		Post* post = new Post(title, content, author, this, requiresLogin);
		posts.push_back(post);
		return post;
	}
	else
	{
		return NULL;
	}
}

string Website::WebsiteType() const
{
	return "Website";
}

ostream& operator<< (ostream& output, const Website& site)
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
	
	for (unsigned int i = site.posts.size()-1; i >= 0 && i < site.posts.size(); i--)
	{
		Post* post = site.posts[i];
		string authorName;
		if (post->GetAuthor() == NULL)
		{
			authorName = "[deleted]";
		}
		else if (post->GetAuthor()->IsUser())
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