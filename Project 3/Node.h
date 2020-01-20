/*****************************************
** File:    Node.h
** Project: CSCE 221 Project 3, Spring 2019
** Author:  Benjamin Gabay
** Date:    4/10/2019
** Section: 510
** E-mail:  benjigabay@tamu.edu
**
**  This file defines the Node structure for the
** 2-3 tree.
**
***********************************************/

//Header Gaurds
#ifndef NODE_H
#define NODE_H

//Structure Constants
const int K1 = 0;
const int K2 = 1;
const int MAX_KEYS = 2;

/* Node structure for use in 2-3 trees */
template <typename DataType>
struct Node
{
    //Constructor; sets K1 to given value and everything else to nullptr
    Node(DataType key) : left(nullptr), mid(nullptr), right(nullptr), parent(nullptr)
    {
        keys[K1] = key;
        keys[K2] = nullptr;
    }

    //Destructor; recursively deletes all children before self
    ~Node()
    {
		delete left;
        delete mid;
		delete right;
		parent = nullptr;
    }
    
    //Structure Data Members
    DataType keys[MAX_KEYS];
    Node<DataType> *left;
    Node<DataType> *mid;
    Node<DataType> *right;
    Node<DataType> *parent;
};

#endif
