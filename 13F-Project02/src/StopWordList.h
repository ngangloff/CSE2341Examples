#include <cstring>
#include <iostream>

using namespace std;

#ifndef STOPWORDLIST_H
#define STOPWORDLIST_H

#include "Debug.h"

class StopWordList
{

private:
	char** stopWords;
	int size;
	int cap;

	void resize();

public:
	StopWordList();

	~StopWordList();

	StopWordList(const StopWordList& rhs);

	StopWordList& operator =(const StopWordList& rhs);

	void addWord(const char temp[]);

	bool isStopWord(const char* testWord);

	void printList(ostream& out);

};


#endif
