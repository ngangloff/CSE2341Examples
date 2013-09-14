/*
 * driverTest.cpp
 *
 *  Created on: Sep 14, 2013
 *      Author: mark
 */


#include "Player.h"
#include "Team.h"
#include <sstream>
#include <string>
#include <iostream>

using namespace std;

/**
 * makeSampleData
 *
 * Method to initialize a stringstream object with some
 * sample data to mimic what would be in an input file.
 */
void makeSampleData(ostream& sample)
{
	sample << "The Cowboys" << endl
			<< "3" << endl
			<< "1 Bob\n2 Sally\n3Sam\n";
}

/**
 * initializeTeam
 *
 * Create some player objects and put them in the Team object
 * that is passed by reference
 */
void initializeTeam1(Team& t)
{
	Player p1("Bob", 1);
	Player p2("Sally", 2);
	Player p3("Sam", 3);
	t.setTeamName("The Cowboys");
	t.addPlayer(p1);
	t.addPlayer(p2);
	t.addPlayer(p3);
}

int main ()
{
	stringstream sampleData;
	makeSampleData(sampleData);

	Team t1;
	initializeTeam1(t1);
	t1.print(cout);




	return 0;
}
