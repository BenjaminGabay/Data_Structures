/*****************************************
** File:    List221.h
** Project: CSCE 221 Project 1, Spring 2019
** Author:  Benjamin Gabay
** Date:    2/13/2019
** Section: 510
** E-mail:  benjigabay@tamu.edu
**
**	This file contains the header file with function and
** 	data member declarations for the abstract List221 class
**
**
***********************************************/

#ifndef LIST221_H
#define LIST221_H

#include <iostream>
#include "Node221.h"

template <class T>
class List221
{
	public:
		List221();							//Constructor
		List221(const List221<T>& source);	//Copy Constructor
		~List221();							//Destructor
		
		virtual int  Size() const = 0;	//Returns the size of a list
		virtual bool Empty() const = 0;	//Returns whether a list has data or not
		virtual bool Push(T obj) = 0;	//Pushes data into the list
		virtual bool Pop() = 0;			//Pops data from a list
		virtual bool Clear() = 0;		//Clears a list	
		
	protected:
		Node221<T>* head;
		Node221<T>* tail;
		//int size;
		
	//private:
};

#include "List221.cpp"
#endif