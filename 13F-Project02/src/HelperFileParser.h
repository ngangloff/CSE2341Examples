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
 * Note that the order of the stop section and category can
 * be switched in the above (categories above stop words)
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
	 * each other. Need to refactor that.
	 */
	void parseStop();

	void parseCategory();

public:
	HelperFileParser(char* fileName);
	HelperFileParser();
	~HelperFileParser();
	CategoryMap& getCategoryMap();
	StopWordList& getStopWordList();

	bool isFileOpen();

	void parseFile();

};



#endif
