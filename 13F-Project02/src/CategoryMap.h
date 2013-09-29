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

	/**
	 * Default Constructor
	 */
	CategoryMap();


	/**
	 * Copy c'tor
	 */
	CategoryMap(const CategoryMap& rhs);

	/**
	 * operator =.  Makes sure that deep copy happens.
	 *
	 * TODO:  Does this really need to be public? Do we really want to allow copying?
	 */
	CategoryMap& operator =(const CategoryMap& rhs);

	/**
	 * returns the category associated with a particular
	 * subcategory
	 *
	 * TODO:  This is a memory leak looking for a place to happen.
	 */
	char* contains(char word[]);


	/**
	 * Adds an entry to the category map
	 */
	void addEntry(char* subcat, char* cat);

	/**
	 * prints the map to std out.  Mostly just for debugging purposes.
	 *
	 * TODO:  Could refactor this to print to a parameter stream
	 */
	void printmap();

};


#endif
