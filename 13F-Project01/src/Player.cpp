/*
 * Player.cpp
 *
 *  Created on: Sep 14, 2013
 *      Author: mark
 */

#include "Player.h"

Player::Player()
{
	playerId = -1;
}

Player::Player(const string& name, int id)
{
	playerName = name;
	playerId = id;
}

void Player::setName(const string& newName)
{
	playerName = newName;
}

string Player::getName() const
{
	return playerName;
}

void Player::setPlayerId(int id)
{
	playerId = id;
}

int Player::getPlayerId() const
{
	return playerId;
}

Player::~Player()
{

}

