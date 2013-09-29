#include <iostream>
#include <cstdlib>
#include <fstream>


#include "Index.h"
#include "Debug.h"
#include "Word.h"

using namespace std;

#ifndef BOOKPARSER_H
#define BOOKPARSER_H


/**
 * Class BookParser is a class that will parse a book to create an index.
 */

class BookParser
{
private:
	char* fileName;
	ifstream file;

public:

	/**
	 * BookParser Constructor
	 *
	 * fName is the name of the book file that this object will parse
	 *
	 * TODO Could have this accept a stream or add another constructor to do the same.
	 * This would allow a more flexible parser.
	 */
	BookParser(char* fName);

	/**
	 * Destructor closes the file.
	 *
	 * TODO Delete fileName?
	 */
	~BookParser();

	/**
	 * This method returns true if the file is currently open.
	 */
	bool isFileOpen();

	/**
	 * This method parses the book that the object was created with.
	 * All index entries are placed in the parameter object idx.
	 */
	void parseBook(Index& idx);

	/**
	 * converts a string to an integer using atoi function.
	 */
	int getPageNumber(char* str);

};


#endif
