/*
 * Index.cpp
 *
 *  Created on: Sep 29, 2013
 *      Author: mark
 */


#include <cstdio>
using namespace std;

#include "Index.h"

void MyIndex::resize()
{
	if (DEBUGl3)
		cout << "Resizing index from " << wordListCapacity << " to "
				<< (wordListCapacity + 10) << endl;

	Word** temp = new Word*[wordListCapacity + 10];
	for (int i = 0; i < wordListSize; i++)
		temp[i] = wordList[i];
	delete[] wordList;
	wordList = temp;
	wordListCapacity += 10;
}

void MyIndex::sortIdx()
{
	for (int i = 0; i < wordListSize - 1; i++)
	{
		int curSmallest = i;
		for (int j = i + 1; j < wordListSize; j++)
			if (*wordList[j] < *wordList[curSmallest])
				curSmallest = j;
		if (curSmallest != i)
		{
			Word* temp = wordList[i];
			wordList[i] = wordList[curSmallest];
			wordList[curSmallest] = temp;
		}
	}
}

MyIndex::MyIndex()
{
	wordListSize = 0;
	wordListCapacity = 10;
	wordList = new Word*[wordListCapacity];
}

MyIndex::MyIndex(StopWordList& swlarg, CategoryMap& cm) :
		swl(swlarg), catmap(cm)
{
	wordListSize = 0;
	wordListCapacity = 10;
	wordList = new Word*[wordListCapacity];
}

MyIndex::MyIndex(StopWordList& swlarg) :
		swl(swlarg), catmap(*(new CategoryMap))
{
	wordListSize = 0;
	wordListCapacity = 10;
	wordList = new Word*[wordListCapacity];
}

MyIndex::MyIndex(const MyIndex&)
{
	wordList = NULL;
	wordListCapacity = 0;
	wordListSize = 0;
}

MyIndex::~MyIndex()
{
	for (int i = 0; i < wordListSize; i++)
		delete wordList[i];
	delete[] wordList;
}

void MyIndex::addWord(char str[], int page, bool cat)
{
	if (wordListSize == wordListCapacity)
		resize();

	//ignore the word if it is a stop word
	if (!swl.isStopWord(str))
	{
		//determine if the word is a subcategory of
		//some particular category.
		//
		//if the cat param is true, category test and add
		//will be skipped
		char* newCat = NULL;
		if (!cat)
			newCat = catmap.contains(str);
		if (newCat) //word is a subcat
		{
			if (DEBUGl2)
				cout << "adding " << newCat << " instead of " << str << endl;

			//Add the subcat to the index with page number -1
			//Note that -1 is not a valid page number, so we'll
			//use this when outputting
			addWord(str, -1, true);

			//call this function recursively to add newCat
			//to the index
			addWord(newCat, page, true);
		}
		//check to see if the word is already in the index.  If
		//it is, just add page to its list.
		else if (isInIndex(str))  //check if already in index
		{
			for (int i = 0; i < wordListSize; i++)
			{
				if (wordList[i]->equals(str))
				{
					wordList[i]->addPageToList(page);
					break;
				}

			}
		}
		//not a stop word, not a sub cat, not already in index.
		else
		{
			wordList[wordListSize] = new Word(str);
			wordList[wordListSize]->addPageToList(page);
			wordListSize++;
		}
	}
}

bool MyIndex::isInIndex(char str[])
{
	for (int i = 0; i < wordListSize; i++)
	{
		if (wordList[i]->equals(str))
			return true;
	}
	return false;
}

void MyIndex::printList(ostream& out)
{
	//sort the index
	sortIdx();
	int* tempPages;
	char currentLetter = 0;
	for (int i = 0; i < wordListSize; i++)
	{
		char* str = wordList[i]->getWord();
		if (str[0] != currentLetter)
		{
			out << "[" << str[0] << "]" << endl;
			currentLetter = str[0];
		}
		int numPages = wordList[i]->getNumPages();
		tempPages = new int[numPages];
		wordList[i]->getPageList(tempPages);
		//if the first page number is a -1, then
		//this is a subcategory
		if (tempPages[0] == -1)
		{
			char* category = catmap.contains(str);
			char output[155];
			strcpy(output, "For ");
			strcat(output, str);
			strcat(output, ", see ");
			strcat(output, category);
			strcat(output, ".");
			if (strlen(output) > 50)
			{
				//find comma
				int i = 0;
				while (output[i] != ',')
					i++;
				//put null at space after comma
				output[i + 1] = '\0';
				out << output << endl;
				out << "    " << (output + i + 2) << endl;
			} else
				out << output << endl;

			delete[] category;
		} else
		{
			//Handle wrapping
			char tempOutput[55];
			strcpy(tempOutput, str);
			strcat(tempOutput, ": ");
			char tempPageNumber[50];
			//fill up temp output up to 49 characters.
			//when it gets that full, flush it out to the output
			//and then reinitialize it with 4 spaces at the beginning
			//for the indent on 2nd line
			for (int i = 0; i < numPages; i++)
			{
				sprintf(tempPageNumber, "%d", tempPages[i]);
				int currPageLen = strlen(tempPageNumber);
				//if the current length of tempOutput and the length
				//of the next page to be added exceed 49 (don't forget the comma)
				//flush tempOutput and start over at the beginning with 4 spaces
				//for indent
				if (strlen(tempOutput) + currPageLen > 49)
				{
					out << tempOutput << endl;
					strcpy(tempOutput, "    ");
				}
				strcat(tempOutput, tempPageNumber);
				if (i != numPages - 1)
					//don't put a comma after the last page number
					strcat(tempOutput, ", ");
			}
			//flush the last set of contents of the buffer
			out << tempOutput << endl;
		}
		delete[] tempPages;
		delete[] str;
	}
}
