#include <fstream>
using namespace std;

#include "Debug.h"
#include "StopWordList.h"
#include "CategoryMap.h"
#include "Word.h"

#ifndef HELPERFILEPARSER_H
#define HELPERFILEPARSER_H

/**
 * HelperFileParser parses a file that is in the form of
 * the following
 *
 * [stop]
 * a an the who I
 * am is not
 * [category]
 * apple = iphone ipad macbook
 * automobile = car truck toyota ford
 * a = b  c d     e f  g     h
 * b =    d e   f g
 *
 * This implementation supports the order of the stop section and category section
 * being switched in the above (categories above stop words)
 */

class HelperFileParser
{
private:
	StopWordList stopwords;
	CategoryMap map;
	char* helperFile;
	ifstream file;

	//Used to differentiate sections of the file
	//in the case that it isn't stop words followed
	//by categores.
	bool stopWordsDone;
	bool categoriesDone;

	/**
	 * parseStop and ParseCategories are quite dependent on
	 * each other.
	 *
	 * TODO:  Refactor the parseStop and parseCategory methods. Reduce coupling.
	 */
	void parseStop();
	void parseCategory();

public:
	/**
	 * Constructors
	 *
	 * TODO: 1-arg constructor is tied to a file name.  Refactor to accept a stream?
	 */
	HelperFileParser(char* fileName);
	HelperFileParser();
	~HelperFileParser();

	/**
	 * Returns a reference to this object's Category Map.
	 *
	 * TODO:  Should this method return an const reference?
	 */
	CategoryMap& getCategoryMap();

	/**
	 * Returns a reference to this object's Stop Word List.
	 *
	 * TODO: Should this method return a const reference?
	 */
	StopWordList& getStopWordList();

	/**
	 * Returns true if the associated file is open. Maybe there is a better way?
	 */
	bool isFileOpen();

	/**
	 * Causes the file to be parsed.
	 */
	void parseFile();

};

#endif
