/*****************************************
** File:    Node221.h
** Project: CSCE 221 Project 1, Spring 2019
** Author:  Benjamin Gabay
** Date:    2/13/2019
** Section: 510
** E-mail:  benjigabay@tamu.edu
**
**	This file contains the header file for the Node221 class
**	with a constructor and data members declarations. Data members
**	include the node data, as well as pointers to their linked next
**	and previious nodes.
**
**
***********************************************/

#ifndef NODE221_H
#define NODE221_H

using namespace std;

template <class T>
class Node221
{
	public:
		Node221(T data);	//Constructor

		//Data members - Public to allow easy use/access
		T data;
		Node221<T>* next;
		Node221<T>* prev;
};

#include "Node221.cpp"
#endif