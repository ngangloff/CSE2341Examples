/*
 * BookParser.cpp
 *
 *  Created on: Sep 29, 2013
 *      Author: mark fontenot
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

void BookParser::parseBook(Index& idx)
{
	if (DEBUGl4)
		cout << "Parsing Book in file " << fileName << endl;

	//currentWord is the word that has most recently been read from the file.
	char currentWord[51] = {0};
	char currentPageString[10] = {0};
	int currentPage;
	file >> currentWord;
	while (currentWord[1] != '-')
	{
		/**
		 * Handling a page number.
		 *
		 * If we read a page number, we need to keep track of it
		 * so that for the words that follow, we'll be able to add this page number
		 * to the list of pages numbers associated with that word.
		 */
		if (currentWord[0] == '[')
		{
			if (DEBUGl2)
				cout << "before: *" << currentWord << "* *" << currentPageString
						<< "*" << endl;

			//copy from 2nd character of currentWord to before the closing ]
			//which is at strlen(currentWord)
			int count = 1;

			//isolate just the number (remove the brackets);
			/**
			 * TODO It is likely possible to do this by overwriting the ] of the page
			 * number with null and passing currentWord+1 to getPageNumber.
			 */
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

