#ifndef POST_H
#define POST_H


#include <vector>
#include <ctime>
#include <string>

using namespace std;

class Person;
class Website;

class Post {
private:
	string title;
	string content;
	Person* author;
	vector<Person*> contributors;
	time_t additionTime;
	time_t lastEditTime;
	Website* host;
	bool requiresLogin;
	vector<Person*> views;
	
public:
	Post(string title, string content, Person* author, Website* host, bool requiresLogin);
	~Post();
	bool EditPost(string newTitle, string newContent, Person* contributor); // Modify the post if the contributor has permissions to do so
	bool EditVisibility(bool requiresLogin, Person* requestSource); // Change whether the post is only visible to logged-in users (permissive)
	
	bool ReadPost(Person* reader); // A person tries to read the post (permissive)
	
	unsigned int CountViews(bool unique = true) const;
	
	Website* GetHost() const;
	Person* GetAuthor() const;
	string GetTitle() const;
	
	void ClearAuthor(bool clearAdmins = true);
	void ClearContributors(bool clearAdmins = true);
	bool RemoveContributorByUsername(string username);
	
	bool HasPersonContributed(Person* person) const;
	bool RegisterContribution(Person* person);
	int CountContributors() const;
	Person* GetContributor(unsigned int n) const;
	
	// Prints the post
	friend ostream& operator<<(ostream& output, const Post& post);
};

#endif