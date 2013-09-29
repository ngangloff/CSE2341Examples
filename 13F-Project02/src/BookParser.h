#include <iostream>
#include <cstdlib>

#include "Index.h"
#include "Debug.h"
#include "Word.h"

using namespace std;

#ifndef BOOKPARSER_H
#define BOOKPARSER_H

class BookParser
{
private:
	char* fileName;
	ifstream file;

public:
	BookParser(char* fName);

	~BookParser();

	bool isFileOpen();

	void parseBook(MyIndex& idx);

	int getPageNumber(char* str);

};


#endif
