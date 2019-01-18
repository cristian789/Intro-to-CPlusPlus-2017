#ifndef STACK_H
#define STACK_H

//*****************************************************************
// FILE:      Stack.h
// AUTHOR:    Cristian Aguirre
// LOGON ID:  Z-1824863
// DUE DATE:  10/31/2017
// Assigment:  5
// PURPOSE: Stack header file defines all functions for the Stack.cpp
//
//*****************************************************************

class Stack
{

	friend std::ostream &operator<<(std::ostream& , const Stack& );


public:
	Stack();    //constructor
	~Stack();   //destructor

	Stack(const Stack& stackObj);    //copy constructor

	Stack& operator= (const Stack &stackObj);    //assign operator overload 

	void clear();
	size_t size() const;
	size_t capacity() const;
	bool empty() const;
	int top() const;
	void push(int );
	void pop();
	void reserve(size_t);
	
	int operator[](size_t) const;
	int& operator[](size_t);
	bool operator==(const Stack &)const;

private:

	int* stkArrPtr;
	size_t stackCapacity;
	size_t stackSize;

};


#endif
