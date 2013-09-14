/*
 * DefaultMethods.cpp
 *
 *  Created on: Sep 11, 2013
 *      Author: mark
 */

#include <iostream>
using namespace std;

class TestClass
{
public:
	TestClass ()
	{
		cout << "Constructor" << endl;
	}

	TestClass(const TestClass& tc)
	{
		cout << "Copy Constructor" << endl;
	}

	TestClass& operator= (const TestClass& tc)
	{
		cout << "Assignment Operator" << endl;
		return (*this);
	}

	~TestClass()
	{
		cout << "Destructor" << endl;
	}
};

