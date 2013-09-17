/*
 * Team.cpp
 *
 *  Created on: Sep 14, 2013
 *      Author: mark
 */

#include "Team.h"

Team::Team() {
	// TODO Auto-generated constructor stub

}

Team::~Team() {
	// TODO Auto-generated destructor stub
}

void Team::initializeTeam(istream& in)
{
	getline(in, name);

	int numPlayers;
	int tempId;
	string tempName;

	in >> numPlayers;
	for (int i = 0; i < numPlayers; i++)
	{
		in >> tempId >> tempName;
		players.push_back(Player(tempName, tempId));
	}

}

void Team::setTeamName(const string& name) {
	this->name = name;
}

string Team::getTeamName()const
{
	return name;
}

void Team::addPlayer(const Player& p) {
	players.push_back(p);
}

string Team::getPlayerNameById(int id) const
{
	vector<Player>::const_iterator it;
	for (it = players.begin(); it != players.end(); ++it) {
		if (it->getPlayerId() == id)
			return it->getName();
	}
	return string("not found");
}

void Team::print(ostream& out)
{
	out << "Team Name = " << name << endl;
	out << "Players: " << endl;
	vector<Player>::iterator it;
	int counter = 0;

	for (it = players.begin(); it != players.end(); ++it)
	{
		out << "\t" <<  ++counter << ": " << it->getPlayerId() << " " << it->getName() << endl;
	}
}
