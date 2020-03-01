#include "Post.h"
#include "Person.h"
#include "User.h"
#include "Website.h"
#include <ctime>
#include <map>
#include <iostream>

Post::Post(string title, string content, Person* author, Website* host, bool requiresLogin)
{
	this->title = title;
	this->content = content;
	this->author = author;
	this->host = host;
	this->requiresLogin = requiresLogin;
	
	this->additionTime = time(0);
	this->lastEditTime = this->additionTime;
	
	this->contributors.push_back(author);
}

Post::~Post() { }

bool Post::EditPost(string newTitle, string newContent, Person* contributor)
{
	if (contributor == NULL) return false;
	if (contributor->IsAdmin() || (contributor->IsUser() && (host->IsUserAdmin((User*)contributor) || (((User*)contributor)->IsLoggedIn() && contributor == author))))
	{
		this->title = newTitle;
		this->content = newContent;
		
		contributors.push_back(contributor);
		lastEditTime = time(0);
		
		return true;
	}
	else
	{
		return false;
	}
}

bool Post::EditVisibility(bool requiresLogin, Person* requestSource)
{
	if (requestSource == NULL) return false;
	if (requestSource->IsAdmin() || (requestSource->IsUser() && (host->IsUserAdmin((User*)requestSource) || (((User*)requestSource)->IsLoggedIn() && requestSource == author))))
	{
		this->requiresLogin = requiresLogin;
		return true;
	}
	else
	{
		return false;
	}
}

bool Post::ReadPost(Person* reader)
{
	if (reader == NULL) return false;
	if (host->CheckReadPermissions(reader))
	{
		views.push_back(reader);
		return true;
	}
	else
	{
		return false;
	}
}

unsigned int Post::CountViews(bool unique) const
{
	if (unique)
	{
		map<Person*, bool> uniqueViews;
		for (unsigned int i = 0; i < views.size(); i++) 
		{
			uniqueViews[views[i]] = true;
		}
		return uniqueViews.size();
	} else 
	{
		return views.size();
	}	
}

Website* Post::GetHost() const
{
	return host;
}

Person* Post::GetAuthor() const
{
	return author;
}

string Post::GetTitle() const
{
	return title;
}

void Post::ClearAuthor(bool clearAdmins)
{
	if (clearAdmins || (author != NULL && author->IsUser() && host->IsUserAdmin((User*)author)))
	{
		author = NULL;
	}
}

void Post::ClearContributors(bool clearAdmins)
{
	for (unsigned int i = 0; i < contributors.size(); i++)
	{
		if (clearAdmins || (contributors[i] != NULL && contributors[i]->IsUser() && host->IsUserAdmin((User*)contributors[i])))
		{
			contributors[i] = NULL;
		}
	}
}

bool Post::RemoveContributorByUsername(string username)
{
	for (unsigned int i = 0; i < contributors.size(); i++)
	{
		if (contributors[i] != NULL && contributors[i]->IsUser() && ((User*)contributors[i])->GetUsername() == username)
		{
			contributors[i] = NULL;
			return true;
		}
	}
	return false;
}

bool Post::HasPersonContributed(Person* person) const
{
	if (person == NULL) return false;
	for (unsigned int i = 0; i < contributors.size(); i++)
	{
		if (contributors[i] == person)
		{
			return true;
		}
	}
	return false;
}

bool Post::RegisterContribution(Person* person)
{
	if (person == NULL) return false;
	if (HasPersonContributed(person))
	{
		return false;
	} else
	{
		contributors.push_back(person);
		return true;
	}
}

int Post::CountContributors() const
{
	return contributors.size();
}

Person* Post::GetContributor(unsigned int n) const
{
	if (n < contributors.size()) 
	{
		return contributors[n];
	} else 
	{
		return NULL;
	}
}

ostream& operator<< (ostream& output, const Post& post)
{
	output << post.title << endl;
	string authorName;
	if (post.author == NULL)
	{
		authorName = "[deleted]";
	}
	else if (post.author->IsUser())
	{
		authorName = ((User*)post.author)->GetUsername();
	}
	else
	{
		authorName = post.author->GetName();
	}
	
	output << "\tby " << authorName << endl << endl;
	
	tm* ptm = localtime(&post.additionTime);
	char timeBuffer[32];
	strftime(timeBuffer, 32, "%Y-%m-%d %H:%M:%S", ptm);
	output << "Created: " << timeBuffer << endl;
	
	ptm = localtime(&post.lastEditTime);
	char editTimeBuffer[32];
	strftime(editTimeBuffer, 32, "%Y-%m-%d %H:%M:%S", ptm);
	
	string editorName;
	Person* editor = post.contributors[post.contributors.size()-1];
	if (editor == NULL)
	{
		editorName = "[deleted]";
	}
	else if (editor->IsUser())
	{
		editorName = ((User*)editor)->GetUsername();
	}
	else
	{
		editorName = editor->GetName();
	}
	
	output << "Last edited: " << editTimeBuffer << " by " << editorName << endl << endl;
	
	output << post.content << endl;
	
	return output;
}