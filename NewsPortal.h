#ifndef NEWS_PORTAL_H
#define NEWS_PORTAL_H


#include <vector>
#include "Website.h"

using namespace std;

class Post;

class NewsPortal : public Website {
private:
	Post* mainHeadline;

public:
	NewsPortal(string description, string address);
	virtual ~NewsPortal();
	
	bool SetMainHeadline(Post* headline, Person* requestSource); // Changes the headline (permissive)
	
	void RegisterGuestVisit(Guest* guest) override;
	
	string WebsiteType() const override;
	
	friend ostream& operator<<(ostream& output, const NewsPortal& NewsPortal);
};

#endif