/*
 * CategoryMap.cpp
 *
 *  Created on: Sep 29, 2013
 *      Author: mark
 */




#include "CategoryMap.h"


void CategoryMap::copyContents(const CategoryMap& cm)
{
	size = cm.size;
	capacity = cm.capacity;
	subCategories = new char*[cm.capacity];
	categories = new char*[cm.capacity];
	for (int i = 0; i < cm.size; i++)
	{
		subCategories[i] = new char[strlen(cm.subCategories[i]) + 1];
		categories[i] = new char[strlen(cm.categories[i]) + 1];
		strcpy(subCategories[i], cm.subCategories[i]);
		strcpy(categories[i], cm.categories[i]);
	}
}

void CategoryMap::resize()
{
	if (DEBUGl3)
		cout << "Resizing the Category Map from " << capacity << " to "
				<< (capacity + 10) << endl;

	char** tempSubCat;
	char** tempCat;
	tempSubCat = new char*[capacity + 10];
	tempCat = new char*[capacity + 10];
	for (int i = 0; i < capacity; i++)
	{
		tempSubCat[i] = subCategories[i];
		tempCat[i] = categories[i];
	}
	delete[] subCategories;
	delete[] categories;
	capacity += 10;
	subCategories = tempSubCat;
	categories = tempCat;
}

CategoryMap::CategoryMap(const CategoryMap& rhs)
{
	copyContents(rhs);
}

CategoryMap::CategoryMap()
{
	subCategories = new char*[10];
	categories = new char*[10];
	size = 0;
	capacity = 10;
}

CategoryMap& CategoryMap::operator =(const CategoryMap& rhs)
{
	if (this != &rhs)
	{
		delete[] subCategories;
		delete[] categories;
		copyContents(rhs);
	}
	return *this;
}

char* CategoryMap::contains(char word[])
{
	char* tempCopy = NULL;
	for (int i = 0; i < size; i++)
	{
		if (strcmp(subCategories[i], word) == 0)
		{
			tempCopy = new char[strlen(categories[i]) + 1];
			strcpy(tempCopy, categories[i]);
			break;
		}
	}
	return tempCopy;
}

void CategoryMap::addEntry(char* subcat, char* cat)
{
	if (size == capacity)
		resize();

	subCategories[size] = new char[strlen(subcat) + 1];
	categories[size] = new char[strlen(cat) + 1];
	strcpy(subCategories[size], subcat);
	strcpy(categories[size], cat);
	size++;
}

void CategoryMap::printmap()
{
	for (int i = 0; i < size; i++)
	{
		cout << subCategories[i] << " -> " << categories[i] << endl;
	}
}
