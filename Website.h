#ifndef WEBSITE_H
#define WEBSITE_H

#include <ctime>
#include <vector>
#include <string>

using namespace std;

class Person;
class Guest;
class User;
class Admin;
class Post;

class Website {
protected:
	string description;
	string address;
	vector<Person*> users;
	vector<Person*> admins;
	vector<Person*> guestVisits;
	vector<string> bannedIPs;
	vector<Post*> posts;
	time_t creationTime;

public:
	Website(string description, string address);
	virtual ~Website();
	
	unsigned int CountUsers() const;
	unsigned int CountAdmins() const;
	unsigned int CountGuestVisits(bool unique = false) const; // Size of .guestVisits, if unique is true it only counts every individual guest once
	
	virtual void RegisterGuestVisit(Guest* guest); // Adds a guest to guestVisits
	
	User* RegisterUser(Person* person, string username, string password); // Creates an User from a Person if their IP is not banned
	bool LogIn(string username, string password); // Tries to log-in an user with these credentials
	bool LogOut(string username); // Logs an user out
	bool RemoveUser(User* user, bool memory = true); // Removes an user from the site
	
	virtual Admin* GrantAdminToUser(User* user); // Creats an Admin from an User if it doesn't exist
	virtual User* DemoteAdmin(Admin* admin, bool memory = true); // Removes an Admin from the list, then finds and returns the corresponding User
	
	bool BanIPAddress(string IP); // Adds an IP into banned IPs
	bool UnBanIPAddress(string IP); // Removes an IP from banned IPs if it's there
	
	unsigned int RemoveGuestVisitsByGuest(Guest* guest); // Removes all recorded guest visits from a specific guest
	unsigned int ClearGuestVisits(); // Removes all recorded guest visits
	unsigned int RemoveAllUsers(bool removeAdmins = true);
	
	bool IsIPBanned(string IP) const;
	bool IsUserRegistered(User* user) const;
	bool IsUserAdmin(User* user) const;
	bool IsAdminRegistered(Admin* admin) const;
	
	User* FindUserByUsername(string username) const;
	Admin* FindAdminByUsername(string username) const;
	
	string GetDescription() const;
	string GetAddress() const;
	time_t GetCreationTime() const;
	
	// Get n-th element of the respective vector
	User* GetUser(unsigned int n) const;
	Admin* GetAdmin(unsigned int n) const;
	Post* GetPost(unsigned int n) const;
	
	// Checks permissions, which will allow different actions depending on site type and person type
	virtual int CheckReadPermissions(Person* person) const;
	virtual int CheckWritePermissions(Person* person) const;
	
	// Sends a request to create a new post on the site if given author has permissions to do so
	virtual Post* CreatePost(string title, string content, Person* author, bool requiresLogin);
	
	// Describes which type of a website it is, used when printing the list of all websites
	virtual string WebsiteType() const;
	
	// Prints the website
	friend ostream& operator<<(ostream& output, const Website& website);
};

#endif