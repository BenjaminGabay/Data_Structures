/*****************************************
** File:    Stack221.cpp
** Project: CSCE 221 Project 1, Spring 2019
** Author:  Benjamin Gabay
** Date:    2/13/2019
** Section: 510
** E-mail:  benjigabay@tamu.edu
**
**	This file contains the definitions for the Stack221
**	class functions which is a child of the abstract List221 class
**
**
***********************************************/

#ifndef STACK221_CPP
#define STACK221_CPP

#include "Stack221.h"
#include "Queue221.h"

//Constructor
template <class T>
Stack221<T>::Stack221() : List221<T>() {}

//Copy Constructor
template <class T>
Stack221<T>::Stack221(Stack221<T>& source)
{
	this->head = nullptr;
	this->tail = nullptr;
	
	Stack221<T> s;
	while(!(source.Empty()))
	{
		s.Push(source.Top());
		source.Pop();
	}
	while(!(s.Empty()))
	{
		T data = s.Top();
		Push(data);
		source.Push(data);
		s.Pop();
	}	
}

//Destructor
template <class T>
Stack221<T>::~Stack221()
{
	while(!Empty())
	{
		Pop();
	}
	cout << "Deleted" << endl;
}


//Returns the size of a list
template <class T>
int Stack221<T>::Size() const
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
bool Stack221<T>::Empty() const
{
	return (Size() == 0);
}

//Pushes data into the list
template <class T>
bool Stack221<T>::Push(T obj)
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
bool Stack221<T>::Pop()
{
	if(this->head != nullptr)
	{
		Node221<T>* temp = this->head;
		this->head = this->head->next;
		if(this->head == nullptr)
		{
			this->tail = nullptr;
		}
		else
		{
			this->head->prev = nullptr;
		}
		delete temp;
		return true;
	}
	return false;	
}

//Clears a list
template <class T>
bool Stack221<T>::Clear()
{
	while(this->head != nullptr)
	{
		Pop();
	}
	return (this->head == nullptr && this->tail == nullptr);
}

//Returns the top item on the stack
template <class T>
T Stack221<T>::Top()
{
	if(this->head != nullptr)
	{
		return this->head->data;
	}
	throw Exceptions221("Empty Stack - Could not retrieve top of stack");
}

#endif