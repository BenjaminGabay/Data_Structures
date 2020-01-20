/*****************************************
** File:    Stack221.h
** Project: CSCE 221 Project 1, Spring 2019
** Author:  Benjamin Gabay
** Date:    2/13/2019
** Section: 510
** E-mail:  benjigabay@tamu.edu
**
**	This file contains the header file with the function
**	and data member declarations for the Stack221 class.
**
**
***********************************************/

#ifndef STACK221_H
#define STACK221_H

#include "List221.h"
#include "Exceptions221.h"

template <class T>
class Stack221 : public List221<T>
{
	public:
		Stack221();								//Constructor
		Stack221(Stack221<T>& source);	//Copy Constructor
		~Stack221();							//Destructor
		
		int  Size() const;	//Returns the size of a list
		bool Empty() const;	//Returns whether a list has data or not
		bool Push(T obj);	//Pushes data into the list
		bool Pop();			//Pops data from a list
		bool Clear();		//Clears a list
		
		T Top();			//Returns the top item on the stack
};

#include "Stack221.cpp"
#endif