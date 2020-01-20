/*****************************************
** File:    Queue221.h
** Project: CSCE 221 Project 1, Spring 2019
** Author:  Benjamin Gabay
** Date:    2/13/2019
** Section: 510
** E-mail:  benjigabay@tamu.edu
**
**	This file contains the header file with the function
**	and data member declarations for the Queue221 class.
**
**
***********************************************/

#ifndef QUEUE221_H
#define QUEUE221_H

#include "List221.h"
#include "Exceptions221.h"

template <class T>
class Queue221 : public List221<T>
{
	public:
		Queue221();								//Constructor
		Queue221(Queue221<T>& source);	//Copy Constructor
		~Queue221();							//Destructor
		
		int  Size() const;	//Returns the size of a list
		bool Empty() const;	//Returns whether a list has data or not
		bool Push(T obj);	//Pushes data into the list
		bool Pop();			//Pops data from a list
		bool Clear();		//Clears a list
		
		T Front();			//Returns the item at the front of the queue
		T Back();			//Returns the item at the back of the queue
};

#include "Queue221.cpp"
#endif