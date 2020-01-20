/*****************************************
** File:    Queue221.cpp
** Project: CSCE 221 Project 1, Spring 2019
** Author:  Benjamin Gabay
** Date:    2/13/2019
** Section: 510
** E-mail:  benjigabay@tamu.edu
**
**	This file contains the definitions for the Queue221
**	class functions which is a child of the abstract List221 class
**
**
***********************************************/

#ifndef QUEUE221_CPP
#define QUEUE221_CPP

#include "Queue221.h"
#include "Stack221.h"

//Constructor
template <class T>
Queue221<T>::Queue221() : List221<T>() {}

//Copy Constructor
template <class T>
Queue221<T>::Queue221(Queue221<T>& source)
{
	this->head = nullptr;
	this->tail = nullptr;
	
	Queue221<T> q;
	while(!(source.Empty()))
	{
		q.Push(source.Front());
		source.Pop();
	}
	while(!(q.Empty()))
	{
		T data = q.Front();
		Push(data);
		source.Push(data);
		q.Pop();
	}
}

//Destructor
template <class T>
Queue221<T>::~Queue221()
{
	while(!Empty())
	{
		Pop();
	}
}

//Returns the size of a list
template <class T>
int Queue221<T>::Size() const
{
	int count = 0;
	Node221<T>* curr = this->head;
	while(curr != nullptr)
	{
		count++;
		curr = curr->next;
	}
	return count;
}

//Returns whether a list has data or not
template <class T>
bool Queue221<T>::Empty() const
{
	return (Size() == 0);
}

//Pushes data into the list
template <class T>
bool Queue221<T>::Push(T obj)
{
	Node221<T>* newNode = new Node221<T>(obj);
	if(this->head != nullptr)
	{
		newNode->next = this->head;
		this->head->prev = newNode;
	}
    this->head = newNode;
    if(this->tail == nullptr)
	{
		this->tail = newNode; // tail = head;
	}
	return true;	
}

//Pops data from a list
template <class T>
bool Queue221<T>::Pop()
{
	if(this->tail != nullptr)
	{
		Node221<T>* temp = this->tail;
		this->tail = this->tail->prev;
		if(this->tail == nullptr)
		{
			this->head = nullptr;
		}
		else
		{
			this->tail->next = nullptr;
		}
		delete temp;
		return true;
	}
	return false;	
}

//Clears a list
template <class T>
bool Queue221<T>::Clear()
{
	while(this->tail != nullptr)
	{
		Pop();
	}
	return (this->head == nullptr && this->tail == nullptr);
}

//Returns the item at the front of the queue
template <class T>
T Queue221<T>::Front()
{
	if(this->tail != nullptr)
	{
		return this->tail->data;
	}
	throw Exceptions221("Empty Queue - Could not retrieve front of queue");
}

//Returns the item at the back of the queue
template <class T>
T Queue221<T>::Back()
{
	if(this->head != nullptr)
	{
		return this->head->data;
	}
	throw Exceptions221("Empty Queue - Could not retrieve back of queue");
}

#endif