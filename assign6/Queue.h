
//*****************************************************************
// FILE:      Queue.h
// AUTHOR:    Cristian Aguirre
// LOGON ID:  Z-1824863
// DUE DATE:  11/13/2017
// Assigment:  6
// PURPOSE: This program creates and implements a class to represent the Queue ADT using an array.
//
//*****************************************************************


#include <iostream>
#include <stdexcept>


using namespace std;

// Forward declaration of the Queue template class
template <class T>
class Queue;

// Forward declaration of the operator<< template function
template <class T>
std::ostream& operator<<(std::ostream&, const Queue<T>&);


template <class T>
class Queue
{	
	friend std::ostream& operator<< <>(std::ostream&, const Queue<T>&);

public:
	Queue();	//constructor
	~Queue();	//deconstroctor

	Queue(const Queue& Qobj);     //copy constructor 
	Queue& operator= (const Queue &Qobj);    //assign operator overload 

	void clear();
	size_t size()const;
	size_t capacity()const;
	bool empty()const;
	T front()const;
	T back()const;
	void push(T& );
	void pop();

	void reserve(size_t);

private:
	T* qArr;
	size_t qcapacity;
	size_t qsize;

	int qfront;
	int qback;

};

template <class T>
Queue<T>::Queue()		//constructor
{
	qcapacity = 0;
	qsize = 0;

	qfront = 0;
	qback = 0;

	qArr = nullptr;
}


template <class T>
Queue<T>::~Queue()	//deconstroctor
{
	delete[] qArr;
	qArr = nullptr;
}

template <class T>
Queue<T>::Queue(const Queue& other)   //copy constructor
{
	qcapacity = other.qcapacity;
	qsize = other.qsize;
	qArr = new int[qcapacity];

	for (size_t i = 0; i < qcapacity; ++i)
		qArr[i] = other.qArr[i];

	qfront = other.qfront;
	qback = other.qback;
}

template <class T>
Queue<T>& Queue<T>::operator=(const Queue<T>& Obj) //assignment operator = overload
{
	if (this != &Obj)
	{
		delete[] qArr;

		qcapacity = Obj.qcapacity;
		qsize = Obj.qsize;

		if (qcapacity == 0)
			qArr = nullptr;
		else
			qArr = new int[qcapacity];

		for (size_t i = 0; i < qsize; ++i)
			qArr[i] = Obj.qArr[i];
	}

	return *this;
}

template <class T>
std::ostream &operator<<(std::ostream& lhs, const Queue<T>& rhs)   //outstream operator overloads
{
	size_t current, i;

	for (current = rhs.qfront, i = 0; i < rhs.qsize; ++i)
	{
		// Print queue element at subscript i
		lhs << rhs.qArr[current] << ' ';

		// Increment i, wrapping around to front of queue array if necessary     
		current = (current + 1) % rhs.qcapacity;
	}

	return lhs;
}


template <class T> //This method should set the Queue size to 0
void Queue<T>::clear()
{
	qsize = 0;
	qArr[qfront] = 0;
	qArr[qback] = qcapacity - 1;
}


template <class T>
size_t Queue<T>::size()const       //returns size 
{
	return qsize;
}

template <class T>                   //returns capacity
size_t Queue<T>::capacity()const
{
	return qcapacity;
}

template <class T>                  //boolonian method asking if its empty or not 
bool Queue<T>::empty()const 
{
	if (qsize == 0)
		return true;
	else
		return false;
}



template <class T                           //throws underflow error if front is empty >
T Queue<T>::front()const
{
	if (empty())
		throw std::underflow_error("queue underflow on front()");

	else
		return qArr[qfront];
}



template <class T>                 //throws underflow error if back is empty
T Queue<T>::back()const
{
	if (empty())
		throw underflow_error("queue underflow on back()");
	
	else 
	return qArr[qback];
}

template <class T>
void Queue<T>::push(T& val)        //push pushes queues 
{
	if (qsize == qcapacity)
	{
		if (qcapacity == 0)
			reserve(1);
		else
			reserve(qcapacity * 2);
	}

	qback = (qback + 1) % qcapacity;
	qArr[qback] = val;
	qsize++;
}

template <class T>                //pops or removes queues and gives error if its empty
void Queue<T>::pop()
{
	if (empty())
		throw underflow_error("queue underflow on pop()");
	qfront = (qfront + 1) % qcapacity;
	--qsize;

}

template <class T>                 //reserve checks for size and capacity then deltes dinamically memory
void Queue<T>::reserve(size_t n)
{
	if (n < qsize || n == qcapacity)
		return;
	T* tempArr = new T[n];

	int current = qfront;
	for (size_t i = 0; i < qsize; i++)
	{
		tempArr[i] = qArr[current];
		current = (current + 1) % qcapacity;
	}

	qcapacity = n;
	qfront = 0;
	qback = qsize - 1;
	delete[] qArr;
	qArr = tempArr;
}
