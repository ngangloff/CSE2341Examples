/*
 * BookParser.cpp
 *
 *  Created on: Sep 29, 2013
 *      Author: mark
 */

#include "BookParser.h"


BookParser::BookParser(char* fName)
{
	fileName = new char[strlen(fName) + 1];
	strcpy(fileName, fName);
	file.open(fileName);
	if (!file.is_open())
		cerr << "ERROR:  Cannot open Book Parser File" << endl;
}

BookParser::~BookParser()
{
	file.close();
}

bool BookParser::isFileOpen()
{
	return file.is_open();
}

void BookParser::parseBook(MyIndex& idx)
{
	if (DEBUGl4)
		cout << "Parsing Book in file " << fileName << endl;

	char currentWord[51] = {};
	char currentPageString[10] = {};
	int currentPage;
	file >> currentWord;
	while (currentWord[1] != '-')
	{
		//check if page number and handle if so
		if (currentWord[0] == '[')
		{
			if (DEBUGl2)
				cout << "before: *" << currentWord << "* *" << currentPageString
						<< "*" << endl;

			//copy from 2nd character of currentWord to before the closing ]
			//which is at strlen(currentWord)
			int count = 1;
			while (currentWord[count] != ']')
			{
				if (DEBUGl2)
					cout << "  count = " << count << endl;
				currentPageString[count - 1] = currentWord[count];
				count++;
			}
			currentPageString[count - 1] = '\0';

			if (DEBUGl4)
				cout << "After: " << currentWord << " " << currentPageString
						<< endl;

			currentPage = getPageNumber(currentPageString);

			if (DEBUGl4)
				cout << "    Handling new page number: " << currentPage << endl;
		} else
		{
			//convert the word to upper case
			Word::toUpper(currentWord);
			if (DEBUGl4)
				cout << "  Handling word " << currentWord << endl;

			//add to the index (passed in as param) with current page
			idx.addWord(currentWord, currentPage);
		}
		//get next word
		file >> currentWord;
	}
}

int BookParser::getPageNumber(char* str)
{
	return atoi(str);
}

