
#include <cstring>
#include <ctype.h>
#include <algorithm>
#include "Debug.h"

using namespace std;

#ifndef WORD_H
#define WORD_H

class Word
{

private:
	char* string;
	int* pageList;
	int pageSize; //number of pages in the list
	int pageCap;  //total number of pages that can be stored

	void resizePageList();

public:
	/**
	 * This constructor constructs the word
	 * with the parameter value and initializes
	 * the pageList
	 */
	Word(char* input);

	/**
	 * copy constructor for word
	 * ensures deep copy
	 */
	Word(const Word& rhs);

	~Word();

	/**
	 * overloaded assignment operator
	 * to ensure that deep copy is performed
	 */
	Word& operator =(const Word& rhs);

	/**
	 * determines if this word matches the
	 * parameter value word
	 */
	bool equals(char* temp);

	/**
	 * addPageToList will add a page number
	 * to the list of pages this word appears on
	 * only if that page number doesn't already
	 * exist in the list.
	 */
	void addPageToList(int newPage);

	/**
	 * isOnPage determines if a page number
	 * has already been added to the page list
	 * of this word
	 */
	bool isOnPage(int pageNum);

	/**
	 * returns the number of pages that this
	 * word appears on
	 */
	int getNumPages();

	/*
	 * We'll make the caller responsible for sending an
	 * array to us.  They will need to call getNumPages to
	 * find out how big the array needs to be.
	 *
	 * This is not optimal.... Glaring hole/potential seg fault.
	 */
	void getPageList(int* tempPageList);

	/**
	 * returns a copy of this word
	 */
	char* getWord();

	/**
	 * helper function (ergo static) that
	 * converts a string to upper case
	 */
	static void toUpper(char* str);

	bool operator <(const Word& rhs);

};



#endif
