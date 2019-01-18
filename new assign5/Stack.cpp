/*****************************************************************
 FILE:       Stack.cpp
 PROGRAMMER: Cristian Aguirre
 LOGON ID:   Z-1824863
 DUE DATE:   10/31/2017
 Assigment:  5
 PURPOSE: Encapsulating a dynamically-allocated array of integers.

*****************************************************************/


#include <iostream>
//#include <stdexcept>       //for the throw out_of_range
#include "Stack.h"

using std::ostream; 
using std::istream;
using std::cin;


Stack::Stack()     //constructor
{
	stackSize = 0;
	stackCapacity = 0;
	stkArrPtr = nullptr;
}

Stack::~Stack()   //deconstructor
{
if (stkArrPtr != nullptr)
delete[] stkArrPtr;
}

Stack::Stack(const Stack& stackObj)    //copy constructor
{
	stackCapacity = stackObj.stackCapacity;
	stackSize = stackObj.stackSize;

	if (stackCapacity == 0)
		stkArrPtr = nullptr;
	else
		stkArrPtr = new int[stackCapacity];

	for (size_t i = 0; i < stackSize; ++i)
		stkArrPtr[i] = stackObj.stkArrPtr[i];
}


Stack& Stack::operator=(const Stack& stackObj)   //assignment operator = overload
{
	if (this != &stackObj)
	{
		delete[] stkArrPtr;

		stackCapacity = stackObj.stackCapacity;
		stackSize = stackObj.stackSize;

		if (stackCapacity == 0)
			stkArrPtr = nullptr;
		else
			stkArrPtr = new int[stackCapacity];

		for (size_t i = 0; i < stackSize; ++i)
			stkArrPtr[i] = stackObj.stkArrPtr[i];
	}

	return *this;
}

ostream &operator<<(ostream& lhs, const Stack& rhs)   //outstream operator overloads
{ 
	if (rhs.stackSize == 0)
    return lhs;
for (unsigned i = 0; i < rhs.stackSize; i++)

lhs << rhs.stkArrPtr[i] << " ";

	return lhs;

}


void Stack::clear()          //This method should set the stack size to 0
{
	stackSize = 0;
}

size_t Stack::size() const     //This method should return the stack size.
{
	return stackSize;
}

size_t Stack::capacity()const   //This method should return the stack capacity.
{
	return stackCapacity;
}

bool Stack::empty() const       //This method should return true if the stack size is equal to 0; otherwise it should return false.
{
	if (stackSize == 0)
		return true;
	else
		return false;
}

int Stack::top() const       //Returns top item of the stack.
{
	return stkArrPtr[stackSize - 1];
}

void Stack::push(int val)    //Insert new item at top of stack.
{
	if (stackSize == stackCapacity)
	{
		if (stackCapacity == 0)
			reserve(1);
		else
			reserve(stackCapacity * 2);
	}
	
	stkArrPtr[stackSize] = val;
	++stackSize;
}

void Stack::pop()          //Remove top item from stack.
{
	--stackSize;
}

void Stack::reserve(size_t n)                //This method increases the capacity of the stack array. 
                                             //It takes a single integer argument, the new capacity. 
	                                         //The logic for this method should look something like this:
{
	if (n < stackSize || n == stackCapacity)
		return;

	int* tempArray = new int[n];             

	for (size_t i = 0; i < stackSize; ++i)
		{
		tempArray[i] = stkArrPtr[i];
		}

	stackCapacity = n;
	delete[] stkArrPtr;
	stkArrPtr = tempArray;
}

int Stack::operator[](size_t n) const
{
	return stkArrPtr[n];                //This method should return the element of the stack array at subscript n. 
}

int& Stack::operator[](size_t n)
{
	return stkArrPtr[n];
}


bool Stack::operator==(const Stack& rhs) const   //overload equality operator compairs objects
{
	if (stackSize != rhs.stackSize)
	return false;

	for (size_t i = 0; i < stackSize; i++)
        {
	if (stkArrPtr[i] != rhs.stkArrPtr[i])
	return false;
       	}
	return true;
}

