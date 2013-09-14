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
	virtual ~Tag();


private:
	int tagger;
	int tagged;
	int timeStamp;
	TaggedLocation location;

};

#endif /* TAG_H_ */
