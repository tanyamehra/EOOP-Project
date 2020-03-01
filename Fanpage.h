#ifndef FANPAGE_H
#define FANPAGE_H


#include <vector>
#include "Website.h"

using namespace std;

class Fan;

class Fanpage : public Website {
private:
	vector<Person*> likes;

public:
	Fanpage(string description, string address);
	virtual ~Fanpage();
	
	bool DoesFanLikeFanpage(Fan* fan);
	bool RegisterLike(Fan* fan);
	bool RemoveLike(Fan* fan);
	
	unsigned int CountLikes() const;
	
	string WebsiteType() const override;
	
	// Prints the fanpage
	friend ostream& operator<<(ostream& output, const Fanpage& fanpage);
};

#endif