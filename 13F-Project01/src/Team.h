/*
 * Team.h
 *
 *  Created on: Sep 14, 2013
 *      Author: mark
 *
 *  Team represents a collection of players in laser-tag
 */

#include <string>
#include <vector>
#include <ostream>
#include <istream>
#include <set>
#include "Player.h"
using namespace std;

#ifndef TEAM_H_
#define TEAM_H_

class Team {
public:
	Team();
	virtual ~Team();

	void initializeTeam(istream&);

	void setTeamName(const string& name);
	string getTeamName() const;

	void addPlayer(const Player&);
	string getPlayerNameById(int id) const;

	void print(ostream&);

	bool isTeamMember(int id) const
	{
		for(vector<Player>::const_iterator it = players.begin();
				it != players.end();
				++it)
		{
			if(it->getPlayerId() == id)
				return true;
		}
		return false;
	}

private:
	string name;
	vector<Player> players;
};

#endif /* TEAM_H_ */
