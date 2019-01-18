#ifndef SORTS_H
#define SORTS_H

/*****************************************************************/
// FILE:      Sorts.h
// AUTHOR:    Cristian Aguirre
// LOGON ID:  Z-1824863
// DUE DATE:  11/29/2017
// Assigment: 8, part 2
// PURPOSE:   Pair of C++ template functions to read a series of items 
//			  from an input file, and then print the items.
/*****************************************************************/



#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <stdexcept>
#include <vector>

using std::ostream;
using std::cout;
using std::endl;
using std::ifstream;
using std::vector;
using std::setw;


template <class T> void buildList(vector<T>&, const char*);
template <class T> void printList(const vector<T>&, int, int);

template <class T> bool lessThan(const T& item1, const T& item2);
template <class T> bool greaterThan(const T& item1, const T& item2);


template <class T>
void buildList(vector<T>& set, const char* filename)
{
	T item;
	ifstream inFile(filename);

	if (!inFile)
	{
		cout << "filename is empty or not taken";
		exit(1);
	}

	inFile >> item;
		while (inFile)
		{
			set.push_back(item);
			inFile >> item;
		}
		inFile.close();
}


template <class T>
void printList(const vector<T>&set, int itemWidth, int numPerLine)
{

	int count = 0;

	for (int i = 0; i< (int) set.size(); i++) {

		cout << setw(itemWidth + 1) << set[i];

		count++;

		if (count == numPerLine) {
			cout << endl;
			count = 0;
		}
	}
}

template <class T>
bool lessThan(const T& item1, const T& item2)
{
	if (item1 < item2)
		return true;
	else
		return false;
}

template <class T>
bool greaterThan(const T& item1, const T& item2)
{
	if (item1 > item2)
		return true;
	else
		return false;
}


#endif  /*STACK_H*/
