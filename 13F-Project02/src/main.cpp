
#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

#include "Index.h"
#include "StopWordList.h"
#include "HelperFileParser.h"
#include "BookParser.h"


//void testLevel1();
//void testLevel2();
void testLevel3();
void testLevel4(int, char**);
void testLevel1();

int main(int argc, char** args)
{
    testLevel4(argc, args);

	//testLevel1();

	for(int i = 0; i < argc; i++)
		cout << args[i] << endl;
    return 0;
}

void testLevel4(int argc, char** args)
{

    if (argc != 4)
    {
        cerr << "Usage:  index <bookFile> <helperFile> <outputFile>" << endl;
        exit (1);
    }

    HelperFileParser hfp(args[2]);
    if(hfp.isFileOpen())
        hfp.parseFile();

    Index i(hfp.getStopWordList(), hfp.getCategoryMap());
    BookParser book(args[1]);
    book.parseBook(i);

    ofstream fileOut(args[3]);

    i.printList(fileOut);

}

void testLevel3()
{
    HelperFileParser hfp("helperfile.txt");
    if(hfp.isFileOpen())
        hfp.parseFile();

    Index i(hfp.getStopWordList(), hfp.getCategoryMap());

    i.addWord("dinosaur", 5);
    i.addWord("mark", 6);
    i.addWord("starbucks", 67);
    i.addWord("goodbye", 10);
    i.addWord("sam", 10);
    i.addWord("foobar", 10);
    i.addWord("happy", 10);
    i.addWord("sad", 10);
    i.addWord("paper", 10);
    i.addWord("pen", 10);
    i.addWord("pad", 11);
    i.addWord("pad", 12);
    i.addWord("pad", 13);
    i.addWord("pad", 14);
    i.addWord("pad", 15);
    i.addWord("pad", 16);
    i.addWord("pad", 17);
    i.addWord("pad", 18);
    i.addWord("pad", 10);
    i.addWord("pad", 10);
    i.addWord("pad", 10);
    i.addWord("pad", 10);
    i.addWord("pad", 10);
    i.addWord("pad", 10);
    i.addWord("a", 10);
    i.addWord("am", 10);
    i.addWord("the", 10);
    i.addWord("who", 10);

    i.printList(cout);

}

/*void testLevel2()
{
    HelperFileParser hfp("helperfile.txt");
    if(hfp.isFileOpen())
    {
        hfp.parseFile();
    }
}*/

void testLevel1()
{

    StopWordList l;

    l.addWord("mark");
    l.addWord("a");
    l.addWord("the");
    l.addWord("i");
    l.addWord("foo");
    l.addWord("bar");
    l.addWord("my");
    l.addWord("go");
    l.addWord("phone");
    l.addWord("he");
    l.addWord("she");

    l.printList(cout);

    Index i(l);

    cout << "Adding words" << endl;
    i.addWord("dinosaur", 5);
    i.addWord("mark", 6);
    i.addWord("starbucks", 67);
    i.addWord("goodbye", 10);
    i.addWord("sam", 10);
    i.addWord("foobar", 10);
    i.addWord("happy", 10);
    i.addWord("sad", 10);
    i.addWord("paper", 10);
    i.addWord("pen", 10);
    i.addWord("pad", 11);
    i.addWord("pad", 12);
    i.addWord("pad", 13);
    i.addWord("pad", 14);
    i.addWord("pad", 15);
    i.addWord("pad", 16);
    i.addWord("pad", 17);
    i.addWord("pad", 18);
    i.addWord("pad", 10);
    i.addWord("pad", 10);
    i.addWord("pad", 10);
    i.addWord("pad", 10);
    i.addWord("pad", 10);
    i.addWord("pad", 10);



    cout << "Printing List" << endl;
    i.printList(cout);



}
