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

using namespace std;

void makeSampleData(stringstream& sample)
{
	sample << "The Cowboys" << endl
			<< "3" << endl
			<< "1 Bob\n2 Sally\n3Sam\n";


}

int main ()
{
	stringstream sampleData;
	makeSampleData(sampleData);

	Player p1("Bob", 1);
	Player p2("Sally", 2);
	Player p3("Sam", 3);

	Team t;
	t.setTeamName("The Cowboys");
	t.addPlayer(p1);
	t.addPlayer(p2);
	t.addPlayer(p3);

	t.print(cout);


	return 0;
}
