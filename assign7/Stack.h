
#ifndef STACK_H
#define STACK_H

/*****************************************************************/
// FILE:      Stack.h
// AUTHOR:    Cristian Aguirre
// LOGON ID:  Z-1824863
// DUE DATE:  11/16/2017
// Assigment:  7
// PURPOSE: Stack header file defines all functions for the Stack.cpp
//
/*****************************************************************/

#include <iostream>
#include <stdexcept>

using std::ostream;
using std::underflow_error;



									  // Forward declaration of the Node template struct
template <class T>
struct Node;



template <class T>
struct Node
{
	T data;
	Node<T>* next;

	Node(const T& = T(), Node<T>* next = nullptr);
};
														//method definitions 
template <class T>
Node<T>::Node(const T& newData, Node<T>* newNext)
{
	data = newData;
	next = newNext;
};





/******************************************************************/

											// Forward declaration of the Stack template class
template <class T>
class Stack;


											// Forward declaration of the operator<< template function
template <class T>
std::ostream& operator<<(std::ostream&, const Stack<T>&);




template <class T>
class Stack
{
friend std::ostream& operator<< <>(std::ostream&, const Stack<T>&);

private:
	size_t  stkSize;
	Node<T>*stkTop;

	void copyList(const Stack<T>&);

public:
	Stack();
	~Stack();
	Stack(const Stack<T>& other);
	Stack<T>& operator= (const Stack<T>&);
	
	void clear();
	size_t  size() const;	
	bool   empty() const;
	
	const T& top() const;
	void push(const T&);
	void pop();

};
								// Method definitions

template<class T>			//constructor
Stack<T>::Stack()
{
	stkTop = nullptr;
	stkSize = 0;
}

template<class T>			//deconstructor
Stack<T>::~Stack()
{
	clear();
}

template<class T>			//copy constructor
Stack<T>::Stack(const Stack<T>& other)
{
	stkTop = nullptr;
	copyList(other);
	stkSize = other.stkSize;
}

template<class T>             //The assignment operator
Stack<T>& Stack<T>::operator=(const Stack<T>& other)
{

		if (this != &other)
		{
			clear();
			copyList(other);
			stkSize = other.stkSize;
		}

		return *this;


}

template <class T>
std::ostream &operator<<(std::ostream& lhs, const Stack<T>& rhs)   //outstream operator overloads
{
	Node<T>* ptr;
	for (ptr = rhs.stkTop; ptr != nullptr; ptr = ptr->next)
		lhs << ptr->data <<' ';

	return lhs;
}

template <class T>							//This method clears and takes no arguments and returns nothing
void Stack<T>::clear()
{
	while (!empty())
		pop();
}

template <class T>						// returns the stack size
size_t Stack<T>::size()const
{
	return stkSize;
}

template <class T>						//boolenian statement
bool Stack<T>::empty()const				
{
	if (stkSize == 0)
		return true;
	else
		return false;
}

template <class T>							//returns the data stored in the top node of 
const T& Stack<T>::top() const				//the stack(i.e., the first node in the linked list).
{
	if (empty())
		throw underflow_error("Stack underflow on call to top()");

	return stkTop->data;
}

template <class T>						//The method should insert the item at the top 
void Stack<T>::push(const T&item)		//of the stack (at the front of the linked list).
{
	Node<T>* newNode = new Node<T>(item, stkTop);
	stkTop = newNode;
	stkSize++;
}

template <class T>					//removes the node at the top of the stack.
void Stack<T>::pop()
{
	if (empty())
		throw underflow_error("Stack underflow on call to pop()");

		Node<T>* delNode = stkTop;
	stkTop = stkTop->next;       // or stkTop = delNode->next;
	delete delNode;
	stkSize--;
}


template <class T>								//copies the list and cheks if its null
void Stack<T>::copyList(const Stack<T>& other)
{
	Node<T>* ptr, *newNode, *last = nullptr;
	for (ptr = other.stkTop; ptr != nullptr; ptr = ptr->next)
	{
		newNode = new Node<T>(ptr->data);
		if (last == nullptr)
			stkTop = newNode;
		else
			last->next = newNode;

		last = newNode;
	}
}

#endif   /*STACK_H*/
