/*
 * Match.cpp
 *
 *  Created on: Sep 14, 2013
 *      Author: mark
 */

#include "Match.h"
#include "Tag.h"
#include <istream>
using namespace std;

Match::Match()
{
	// TODO Auto-generated constructor stub

}

Match::~Match()
{
	vector<Tag*>::iterator it;
	for(it = tags.begin(); it != tags.end(); ++it)
		delete *it;
}

void Match::loadMatch(istream& in)
{
	int numTags;
	int tempTagger, tempTagged, tempTimeStamp, tempLocation;

	in >> numTags;

	for (int i = 0; i < numTags; i++)
	{
		in >> tempTagger;
		in >> tempTagged;
		in >> tempTimeStamp;
		in >> tempLocation;

		TaggedLocation loc = static_cast<TaggedLocation>(tempLocation);

		if(loc == SHOULDER)
			tags.push_back(new ShoulderTag(tempTagger, tempTagged, tempTimeStamp, loc));
		else if (loc == BACK)
			tags.push_back(new BackTag(tempTagger, tempTagged, tempTimeStamp, loc));
		else if (loc == LASERGUN)
			tags.push_back(new LaserGunTag(tempTagger, tempTagged, tempTimeStamp, loc));
		else if (loc == CHEST)
			tags.push_back(new ChestTag(tempTagger, tempTagged, tempTimeStamp, loc));
	}

}

void Match::printMatch (ostream& out)
{
	vector<Tag*>::iterator it;
	for(it = tags.begin(); it != tags.end(); ++it)
		out << (*it)->getTagger() << " tagged " << (*it)->getTagged()
		<< " for " << (*it)->getPoints() << " points!" << endl;
}
