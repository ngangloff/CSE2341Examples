#include <cstring>
#include <iostream>

using namespace std;

#ifndef STOPWORDLIST_H
#define STOPWORDLIST_H

#include "Debug.h"

/**
 * StopWordList represents a list of stopwords that will be checked
 * during parsing and indexing of a book.
 */

class StopWordList
{

private:
	char** stopWords;
	int size;
	int cap;

	void resize();

public:

	/**
	 * Constructors and destructor
	 */
	StopWordList();
	~StopWordList();
	StopWordList(const StopWordList& rhs);

	/**
	 * operator = ensures deep copy
	 */
	StopWordList& operator =(const StopWordList& rhs);

	/**
	 * Adds a word to the stop word list
	 */
	void addWord(const char temp[]);

	/**
	 * returns true if param is a stop word
	 */
	bool isStopWord(const char* testWord);

	/**
	 * prints the list to an output stream.
	 */
	void printList(ostream& out);

};


#endif
