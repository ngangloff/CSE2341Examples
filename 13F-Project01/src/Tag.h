/*
 * Tag.h
 *
 *  Created on: Sep 14, 2013
 *      Author: mark
 */

#include "TaggedLocations.h"

#ifndef TAG_H_
#define TAG_H_

class Tag
{
public:

	Tag();
	Tag(int, int, int, TaggedLocation);

	virtual ~Tag() {}

	void setTagger(int);
	void setTagged(int);
	void setTimeStamp(int);
	void setTaggedLocation(TaggedLocation);

	int getTagger();
	int getTagged();
	int getTimeStamp();
	TaggedLocation getTaggedLocation();

	virtual int getPoints() = 0;

private:
	int tagger;
	int tagged;
	int timeStamp;
	TaggedLocation location;

};

class ShoulderTag : public Tag
{
public:
	ShoulderTag(int tag, int tagd, int time, TaggedLocation loc):
		Tag(tag, tagd, time, loc) {}

	virtual int getPoints()
	{
		return 10;
	}
};

class LaserGunTag : public Tag
{
public:

	LaserGunTag(int tag, int tagd, int time, TaggedLocation loc):
		Tag(tag, tagd, time, loc) {}

	virtual int getPoints()
	{
		return 15;
	}
};

class BackTag : public Tag
{
public:

	BackTag(int tag, int tagd, int time, TaggedLocation loc):
		Tag(tag, tagd, time, loc) {}

	virtual int getPoints()
	{
		return 5;
	}
};

class ChestTag : public Tag
{
public:
	ChestTag(int tag, int tagd, int time, TaggedLocation loc):
		Tag(tag, tagd, time, loc) {}

	virtual int getPoints()
	{
		return 8;
	}
};




#endif /* TAG_H_ */
