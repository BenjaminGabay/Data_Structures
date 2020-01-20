/*****************************************
** File:    Node221.cpp
** Project: CSCE 221 Project 1, Spring 2019
** Author:  Benjamin Gabay
** Date:    2/13/2019
** Section: 510
** E-mail:  benjigabay@tamu.edu
**
**	This file contains the constructor definition for the
**	Node221 class to be used in lists.
**
**
***********************************************/

#ifndef NODE221_CPP
#define NODE221_CPP

#include "Node221.h"

template <class T>
Node221<T>::Node221(T data) : data(data), next(nullptr), prev(nullptr) {}

#endif