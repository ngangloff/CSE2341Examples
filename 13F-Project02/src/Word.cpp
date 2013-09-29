/*
 * Word.cpp
 *
 *  Created on: Sep 29, 2013
 *      Author: Mark Fontenot
 */


#include "Word.h"


/**
 * CONSTRUCTORS
 */
Word::Word(char* input)
{
	string = new char[strlen(input) + 1];
	strcpy(string, input);
	pageList = new int[10];
	pageSize = 0;
	pageCap = 10;
}

Word::Word(const Word& rhs)
{
	string = new char[strlen(rhs.string) + 1];
	strcpy(string, rhs.string);
	pageList = new int[rhs.pageCap];
	for (int i = 0; i < rhs.pageCap; i++)
		pageList[i] = rhs.pageList[i];
	pageCap = rhs.pageCap;
	pageSize = rhs.pageSize;
}

/**
 * DESTRUCTOR
 */

Word::~Word()
{
	delete[] string;
	delete[] pageList;
}

/**
 * PRIVATE METHODS
 */
void Word::resizePageList()
{
	if (DEBUGl3)
		cout << "Resizing Page List from " << pageCap << " to "
				<< (pageCap + 10) << endl;

	int* temp = new int[pageCap + 10];
	for (int i = 0; i < pageCap; i++)
		temp[i] = pageList[i];
	delete[] pageList;
	pageCap += 10;
	pageList = temp;
}

/**
 * OVERLOADED OPERATORS
 */

Word& Word::operator =(const Word& rhs)
{
	if (this != &rhs)
	{
		delete[] string;
		delete[] pageList;
		string = new char[strlen(rhs.string) + 1];
		strcpy(string, rhs.string);
		pageList = new int[rhs.pageCap];
		for (int i = 0; i < rhs.pageCap; i++)
			pageList[i] = rhs.pageList[i];
		pageCap = rhs.pageCap;
		pageSize = rhs.pageSize;
	}
	return *this;
}

bool Word::operator <(const Word& rhs)
{
	return (strcmp(this->string, rhs.string) < 0);
}

/**
 * OTHER MEMBER FUNCTIONS
 */
bool Word::equals(char* temp)
{
	if (strcmp(string, temp) == 0)
		return true;

	return false;
}

void Word::addPageToList(int newPage)
{
	if (pageSize == pageCap)
		resizePageList();

	//only add this page number if
	//it doesn't already appear in the list
	if (!isOnPage(newPage))
	{
		pageList[pageSize] = newPage;
		pageSize++;
	}
}

bool Word::isOnPage(int pageNum)
{
	for (int i = 0; i < pageSize; i++)
		if (pageList[i] == pageNum)
			return true;
	return false;
}

int Word::getNumPages()
{
	return pageSize;
}

void Word::getPageList(int* tempPageList)
{

	//Strictly speaking, this breaks the rules of the project handout
	//but you can see how the sort algo works.
	sort(pageList, pageList + pageSize);

	//copying contents into the parameter array.
	for (int i = 0; i < pageSize; i++)
		tempPageList[i] = pageList[i];
}

char* Word::getWord()
{
	char* temp = new char[strlen(string) + 1];
	strcpy(temp, string);
	return temp;
}

/**
 * STATIC METHOD
 */
void Word::toUpper(char* str)
{
	int len = strlen(str);
	for (int i = 0; i < len; i++)
		str[i] = toupper(str[i]);
}



