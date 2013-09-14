/*
 * Player.h
 *
 *  Created on: Sep 14, 2013
 *      Author: mark
 */

#include <string>
using namespace std;

#ifndef PLAYER_H_
#define PLAYER_H_

class Player {
public:
	Player();
	Player(const string& name, int id);
	~Player();

	void setName(const string& newName);
	string getName();

	void setPlayerId(int);
	int getPlayerId();

private:
	int playerId;
	string playerName;
};

#endif /* PLAYER_H_ */
