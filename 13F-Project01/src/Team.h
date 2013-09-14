/*
 * Team.h
 *
 *  Created on: Sep 14, 2013
 *      Author: mark
 */

#include <string>
#include <vector>
#include <ostream>
#include "Player.h"
using namespace std;

#ifndef TEAM_H_
#define TEAM_H_

class Team {
public:
	Team();
	virtual ~Team();

	void setTeamName(const string& name);
	string getTeamName();

	void addPlayer(const Player&);
	string getPlayerNameById(int id);

	void print(ostream&);

private:
	string name;
	vector<Player> players;
};

#endif /* TEAM_H_ */
