/*
 * StopWordList.cpp
 *
 *  Created on: Sep 29, 2013
 *      Author: Mark Fontenot
 */


#include "StopWordList.h"


void StopWordList::resize()
{
	if (DEBUGl3)
		cout << "Resizing the stop word list from " << cap << " to "
				<< (cap + 10) << endl;

	char** temp = new char*[cap + 10];
	for (int i = 0; i < cap; i++)
		temp[i] = stopWords[i];
	cap += 10;
	//clean up memory
	delete[] stopWords;
	stopWords = temp;
}

StopWordList::~StopWordList()
{
	for (int i = 0; i < size; i++)
		delete[] stopWords[i];
	delete[] stopWords;
}

StopWordList::StopWordList(const StopWordList& rhs)
{
	stopWords = new char*[rhs.cap];
	size = rhs.size;
	cap = rhs.cap;
	for (int i = 0; i < size; i++)
	{
		stopWords[i] = new char[strlen(rhs.stopWords[i]) + 1];
		strcpy(stopWords[i], rhs.stopWords[i]);
	}
}

StopWordList::StopWordList()
{
	size = 0;
	cap = 10;
	stopWords = new char*[cap];
}

StopWordList& StopWordList::operator =(const StopWordList& rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < size; i++)
			delete[] stopWords[i];
		delete[] stopWords;
		stopWords = new char*[rhs.cap];
		size = rhs.size;
		cap = rhs.cap;
		for (int i = 0; i < size; i++)
		{
			stopWords[i] = new char[strlen(rhs.stopWords[i]) + 1];
			strcpy(stopWords[i], rhs.stopWords[i]);
		}
	}
	return *this;
}

void StopWordList::addWord(const char temp[])
{
	if (size == cap)
		resize();

	stopWords[size] = new char[strlen(temp) + 1];
	strcpy(stopWords[size], temp);
	size++;
}

bool StopWordList::isStopWord(const char* testWord)
{
	for (int i = 0; i < size; i++)
	{
		if (strcmp(testWord, stopWords[i]) == 0)
			return true;
	}
	return false;
}

void StopWordList::printList(ostream& out)
{
	out << "StopWord List: " << endl;
	for (int i = 0; i < size; i++)
		out << "  " << stopWords[i] << endl;
}
