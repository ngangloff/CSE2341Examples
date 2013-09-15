/*
 * Tag.cpp
 *
 *  Created on: Sep 14, 2013
 *      Author: mark
 */

#include "Tag.h"
#include "TaggedLocations.h"


Tag::Tag(int taggerParam, int taggedParam, int time, TaggedLocation loc)
		:tagger(taggerParam), tagged(taggedParam), timeStamp(time), location(loc)
{
}

Tag::Tag()
{
	tagger = tagged = timeStamp = -1;
	location = UNINITIALIZED;
}

void Tag::setTagger(int taggerParam)
{
	tagger = taggerParam;
}

void Tag::setTagged(int taggedParam)
{
	tagged = taggedParam;
}

void Tag::setTimeStamp(int time)
{
	timeStamp = time;
}

void Tag::setTaggedLocation(TaggedLocation t)
{
	location = t;
}

int Tag::getTagger()
{
	return tagger;
}

int Tag::getTagged()
{
	return tagged;
}

int Tag::getTimeStamp()
{
	return timeStamp;
}

TaggedLocation Tag::getTaggedLocation()
{
	return location;
}

