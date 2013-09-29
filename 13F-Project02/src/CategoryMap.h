#include <iostream>
using namespace std;
#include "Debug.h"
#include <cstring>

#ifndef CATEGORYMAP_H
#define CATEGORYMAP_H

/**
 *
 * Stores the data in an inverse order.
 * If helperfile contains:
 *    apple = ipod ipad macbook
 * this structure will look like
 *    ipod->apple
 *    ipad->apple
 *    macbook->apple
 *
 *
 */
class CategoryMap
{
private:
	char** subCategories;
	char** categories;
	int size;
	int capacity;

	void copyContents(const CategoryMap& cm);

	void resize();

public:

	CategoryMap();

	CategoryMap(const CategoryMap& rhs);

	CategoryMap& operator =(const CategoryMap& rhs);

	/**
	 * returns the category associated with a particular
	 * subcategory
	 *
	 * potential source of memory leak
	 */
	char* contains(char word[]);

	void addEntry(char* subcat, char* cat);

	void printmap();

};


#endif
