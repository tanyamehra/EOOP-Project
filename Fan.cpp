#include "Fan.h"
#include "Fanpage.h"
#include <cstdlib>
#include <iostream>

Fan::Fan(string name, string address, string IP, unsigned int age) : Guest(name, address, IP, age) { }

Fan::~Fan() {}

unsigned int Fan::CountLikedFanpages() const
{
	return likedFanpages.size();
}

bool Fan::isFanpageLiked(Fanpage* fp) const
{
	if (fp == NULL) return false;
	for (unsigned int i = 0; i < likedFanpages.size(); i++)
	{
		if (likedFanpages[i] == (Website*)fp)
		{
			return true;
		}
	}
	return false;
}

bool Fan::LikeFanpage(Fanpage* fp)
{
	if (fp == NULL) return false;
	if (isFanpageLiked(fp))
	{
		return false;
	} else
	{
		likedFanpages.push_back((Website*)fp);
		fp->RegisterLike(this);
		return true;
	}
}

bool Fan::UnLikeFanpage(Fanpage* fp)
{
	if (fp == NULL) return false;
	if (isFanpageLiked(fp))
	{
		for (unsigned int i = 0; i < likedFanpages.size(); i++)
		{
			if (likedFanpages[i] == (Website*)fp)
			{
				likedFanpages.erase(likedFanpages.begin() + i);
				fp->RemoveLike(this);
				return true;
			}
		}
	}
	return false;
}

ostream& operator<< (ostream& output, const Fan& fan)
{
	output << "[Fan] " << fan.IP << ": " << fan.name << '(' << fan.age << "), " << fan.address << endl;
	output << "\tLiked fanpages:" << endl;
	for (unsigned int i = 0; i < fan.likedFanpages.size(); i++)
	{
		output << '\t' << fan.likedFanpages[i]->GetAddress() << endl;
	}
	return output;
}