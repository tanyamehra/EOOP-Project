#ifndef FAN_H
#define FAN_H


#include <vector>
#include "Guest.h"

using namespace std;

class Fanpage;

class Fan : public Guest {
protected:
	vector<Website*> likedFanpages;
public:
	Fan(string name, string address, string IP, unsigned int age);
	virtual ~Fan();
	
	bool isFanpageLiked(Fanpage* fp) const;
	bool LikeFanpage(Fanpage* fp);
	bool UnLikeFanpage(Fanpage* fp);
	
	unsigned int CountLikedFanpages() const;
	
	// Prints the fan's data
	friend ostream& operator<<(ostream& output, const Fan& fan);
};

#endif