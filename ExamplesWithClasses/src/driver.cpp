/*
 * driver.cpp
 *
 *  Created on: Sep 11, 2013
 *      Author: mark
 */

#include "DefaultMethods.h"
#include <iostream>
using namespace std;

void SimpleTest1() {
	cout << "TestClass tc;" << endl;
	TestClass tc;
	cout << endl << "TestClass* tcPtr, *tcPtr2;" << endl;
	TestClass *tcPtr, *tcPtr2;
	cout << endl << "tcPtr = new TestClass();\ntcPtr2 = new TestClass(tc);"
			<< endl;
	tcPtr = new TestClass();
	tcPtr2 = new TestClass(tc);
	cout << endl << "tc = *tcPtr;" << endl;
	tc = *tcPtr;
	cout << endl << "delete tcPtr;" << endl;
	delete tcPtr;
	cout << endl << "delete tcPtr2;" << endl;
	delete tcPtr2;
}

void SimpleTest2() {
	//SimpleTest1();
	TestClass* temp;
	temp = new TestClass[3];

	cout << "Before delete[]" << endl;
	delete[] temp;
	cout << "After Deletion" << endl;

	temp = new TestClass[3];
	cout << "Before delete" << endl;
	delete[] temp;
	cout << "After Deletion" << endl;
}

int main ()
{
	//SimpleTest1();
	SimpleTest2();
	return 0;
}


