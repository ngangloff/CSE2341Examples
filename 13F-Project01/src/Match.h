/*
 * Match.h
 *
 *  Created on: Sep 14, 2013
 *      Author: mark
 */

#include "Team.h"
#include "Tag.h"


#ifndef MATCH_H_
#define MATCH_H_

class Match
{
public:
	Match();
	virtual ~Match();

	void loadMatch(istream& in);
	void printMatch(ostream& out);



private:
	vector<Tag*> tags;
};

#endif /* MATCH_H_ */
