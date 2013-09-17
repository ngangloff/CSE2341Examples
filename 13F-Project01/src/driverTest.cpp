/*
 * driverTest.cpp
 *
 *  Created on: Sep 14, 2013
 *      Author: mark
 */


#include "Player.h"
#include "Team.h"
#include "Match.h"
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
void makeSampleData(ostream& team1, ostream& team2, ostream& sampleMatch)
{
	team1 << "The Cowboys" << endl
			<< "3" << endl
			<< "1 Bob\n2 Sally\n3Sam\n";

	team2 << "The Sharks" << endl
			<< "3" << endl
			<<"4 Jack\n5 Jill\n6 Kenny\n";


	sampleMatch << 6 << endl
			<< 6 << " " << 1 << " " <<  8388 << " " << 2 << endl
			<< 3 << " " << 5 << " " <<  10111 << " " <<  1 << endl
			<< 4 << " " << 2 << " " <<  12123 << " " <<  3 << endl
			<< 2 << " " << 4 << " " <<  13131 << " " <<  1 << endl
			<< 2 << " " << 5 << " " <<  14155 << " " <<  2 << endl
			<< 3 << " " << 5 << " " <<  15555 << " " <<  4 << endl;

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
	stringstream sampleteam1;
	stringstream sampleteam2;
	stringstream sampleMatch;
	makeSampleData(sampleteam1, sampleteam2, sampleMatch);

	Team t1;
	t1.initializeTeam(sampleteam1);
	t1.print(cout);

	Team t2;
	t2.initializeTeam(sampleteam2);
	t2.print(cout);

	Match m;
	m.loadMatch(sampleMatch);
	m.printMatch(cout);

	cout << "Low Verbosity" << endl;
	cout << "---------------------------------------" << endl;
	m.outputLowVerbosity(cout, t1, t2);
	cout << "---------------------------------------" << endl;


	return 0;
}
