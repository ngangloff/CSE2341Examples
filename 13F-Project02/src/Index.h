#include <cstring>
#include <iostream>

using namespace std;

#include "Word.h"
#include "StopWordList.h"
#include "CategoryMap.h"
#include "Debug.h"

#ifndef INDEX_H
#define INDEX_H

/**
 * Index represents the main index of this app.  It holds a list of
 * word objects.
 */

class Index
{
private:

	Word** wordList;
	int wordListSize;
	int wordListCapacity;

	StopWordList swl;
	CategoryMap catmap;

	/**
	 * resize the wordList array
	 */
	void resize();

	//I don't think I ever want to copy one of these
	Index(const Index&);

	/**
	 * Sort the words in the index
	 * Using a basic selection sort
	 * Referenced: http://www.algolist.net/Algorithms/Sorting/Selection_sort
	 */
	void sortIdx();

public:

	/**
	 * Constructors & Destructor
	 */
	Index();
	Index(StopWordList& swlarg);
	Index(StopWordList& swlarg, CategoryMap& cm);
	~Index();

	/**
	 * adds a word to the index at a given page number
	 * if its not a stop word.  Handles categories as well.
	 */
	void addWord(char str[], int page, bool cat = false);

	/**
	 * Returns true if the parameter word (str) is in the index.
	 */
	bool isInIndex(char str[]);

	/**
	 * Print the index in the required format given a particular
	 * output stream
	 */
	void printList(ostream& out);

};

#endif
