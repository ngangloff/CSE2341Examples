/*
 * HelperFileParser.cpp
 *
 *  Created on: Sep 29, 2013
 *      Author: mark
 */


#include "HelperFileParser.h"

/**
 * CONSTRUCTORS
 */

HelperFileParser::HelperFileParser()
{
	helperFile = NULL;
	categoriesDone = stopWordsDone = false;
}

HelperFileParser::HelperFileParser(char* fileName)
{
	stopWordsDone = categoriesDone = false;
	helperFile = new char[strlen(fileName) + 1];
	strcpy(helperFile, fileName);
	file.open(helperFile);
	if (!file)
		cerr << "Cannot file Helper File" << endl;
}

/**
 * DESTRUCTOR
 */
HelperFileParser::~HelperFileParser()
{
	file.close();
}

/**
 * PRIVATE MEMBER FUNCTIONS
 */
void HelperFileParser::parseStop()
{
	if (DEBUGl1)
		cout << "Parsing Stop Words" << endl;

	char tempStopWord[55];
	if (categoriesDone)
		file.ignore();

	while (file >> tempStopWord)
	{
		if (tempStopWord[0] == '[')
			break;
		else
		{
			Word::toUpper(tempStopWord);
			if (DEBUGl2)
				cout << tempStopWord << endl;
			stopwords.addWord(tempStopWord);
		}
	}
	stopWordsDone = true;
}

void HelperFileParser::parseCategory()
{
	if (DEBUGl1)
		cout << "Parsing Categories" << endl;

	char line[55];
	char category[55];
	//char tempSubCat[55];
	if (stopWordsDone)
		file.ignore();

	file.getline(line, 55);
	while (file.good())
	{

		if (DEBUGl2)
			cout << "Just read " << line << endl;

		//we want everything in upperCase, so just
		//make everything in the line uppercase
		Word::toUpper(line);

		char* searchChar = line;
		//bool foundEndOfString = false;

		//find the = and
		//put a null character in the space before
		while (*searchChar != '=')
			searchChar++;
		*(searchChar - 1) = '\0';

		//put the category in category var
		strcpy(category, line);

		//advance searchChar to next space
		searchChar++;

		//put nulls in all other spaces
		int len = strlen(searchChar);
		for (int i = 0; i < len; i++)
			if (searchChar[i] == ' ')
				searchChar[i] = '\0';

		//start next section at space after =
		char* tempLocation = searchChar;
		int count = 0;

		//Keep going while we haven't encountered
		//as many characters as there are left in the
		//string (value of len)
		while (count < len)
		{
			//curStrLen is the length from tempLocation to
			//the next space (length of the next word)
			int curStrLen = strlen(tempLocation);

			//add to map as long as the string as
			//at least one character
			if (curStrLen > 0)
			{
				//add category map to the map
				if (DEBUGl2)
					cout << tempLocation << " -> " << category << endl;
				map.addEntry(tempLocation, category);
			}

			//add the number of characters to count that we just
			//handled
			count += curStrLen + 1;
			tempLocation += curStrLen + 1;  //pointer arrithmetic
		}

		//get the next line from the file
		file.getline(line, 55);
	}
	if (DEBUGl1)
	{
		cout << "Printing the Map" << endl;
		map.printmap();
	}
}

/**
 * PUBLIC MEMBER FUNCTIONS
 */

StopWordList& HelperFileParser::getStopWordList()
{
	return stopwords;
}

CategoryMap& HelperFileParser::getCategoryMap()
{
	return map;
}

bool HelperFileParser::isFileOpen()
{
	return file.is_open();
}

/**
 * This method is highly coupled to parseStop and parseCategory.
 *
 * TODO: consider refactoring.
 */
void HelperFileParser::parseFile()
{
	char temp[12];
	file >> temp;
	if (strcmp(temp, "[stop]") == 0)
	{
		parseStop();
		parseCategory();
	} else
	{
		parseCategory();
		parseStop();
	}
}


