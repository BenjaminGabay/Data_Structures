/*****************************************
** File:    List221.cpp
** Project: CSCE 221 Project 1, Spring 2019
** Author:  Benjamin Gabay
** Date:    2/13/2019
** Section: 510
** E-mail:  benjigabay@tamu.edu
**
**	This file contains the definitions for the abstract List221
**	class functions which is a doubly linked list that can be
**	inherited by the Stack221 and Queue221 classes.
**
**
***********************************************/

#ifndef LIST221_CPP
#define LIST221_CPP

#include "List221.h"

template <class T>
List221<T>::List221() : head(nullptr), tail(nullptr) {}

template <class T>
List221<T>::List221(const List221<T>& source) : head(nullptr), tail(nullptr)
{
	Node221<T>* curr = source.head;
	Node221<T>* prev = nullptr;
	while(curr != nullptr)
	{
		Node221<T>* newNode = new Node221<T>(curr->data);
		if(head == nullptr)
		{
			head = newNode;
		}
		if(prev != nullptr)
		{
			prev->next = newNode;
		}	
		prev = newNode;
		curr = curr->next;
	}
	tail = prev;
}

template <class T>
List221<T>::~List221()
{
	while(head != nullptr)
	{
		Node221<T>* temp = head->next;
		delete head;
		head = temp;
	}
}

#endif