/*****************************************
** File:    TreeIterator.cpp
** Project: CSCE 221 Project 3, Spring 2019
** Author:  Benjamin Gabay
** Date:    4/10/2019
** Section: 510
** E-mail:  benjigabay@tamu.edu
**
**  This file is the class and function definitions
** for the Tree Iterator
**
***********************************************/

#include "Tree.h"

#ifndef TREE_ITERATOR_CPP
#define TREE_ITERATOR_CPP

//Iterator constructor
template <typename DataType, typename Compare>
Tree<DataType, Compare>::iterator::iterator(Node<DataType> *node, int keyI) : node(node), keyI(keyI) {}

//Iterator copy constructor
template <typename DataType, typename Compare>
Tree<DataType, Compare>::iterator::iterator(const iterator &other)
{
    this->node = other.node;
    this->keyI = other.keyI;
}

//Iterator copy assignment operator
template <typename DataType, typename Compare>
typename Tree<DataType, Compare>::iterator &
Tree<DataType, Compare>::iterator::operator=(const iterator &other)
{
    this->node = other.node;
    this->keyI = other.keyI;

    return *this;
}

//Iterator equal comparsion operator
template <typename DataType, typename Compare>
bool Tree<DataType, Compare>::iterator::operator==(const iterator &other) const
{
    if(this->node == other.node && this->keyI == other.keyI)
    {
        return true;
    }
    return false;
}

//Iterator not-equal operator; opposite functionality of equal operator
template <typename DataType, typename Compare>
bool Tree<DataType, Compare>::iterator::operator!=(const iterator &other) const
{
    //"Not" the output of the "==" operator
    if(this->node != other.node || this->keyI != other.keyI)
    {
        return true;
    }
    return false;
}

//Dereference iterator operator to find value that iterator is pointing to
template <typename DataType, typename Compare>
DataType Tree<DataType, Compare>::iterator::operator*() const
{
    if(node == nullptr || keyI == NULL_INDEX)
    {
        return nullptr; //Null iterator (past the end)
    }
    return node->keys[keyI];
}

//Prefix iterator incrementer (++iter)
//Increment to item's successor
template <typename DataType, typename Compare>
typename Tree<DataType, Compare>::iterator & Tree<DataType, Compare>::iterator::operator++()
{
    //Call postfix incrementer to reduce repetative code
    operator++(0); 
    return *this;
}

//Postfix iterator incrementer (iter++)
//Increment to items successor
template <typename DataType, typename Compare>
typename Tree<DataType, Compare>::iterator Tree<DataType, Compare>::iterator::operator++(int unused)
{
    //If already at end, do not iterate
    if(node == nullptr || keyI == NULL_INDEX)
    {
        return *this;
    }
    else if(node->keys[K2] == nullptr)  //Node is a 2-node
    {
        if(node->right != nullptr)  //Node has a right subtree
        {
            //Go-to lowest value of right subtree
            node = node->right;
            while(node->left != nullptr)
            {
                node = node->left;
            }
            keyI = K1;
        }
        else    //Node does not have a right subtree
        {
            //Go-to first ancestor that is to the right of this node
            Node<DataType> *nextNode = node->parent;
            while(nextNode != nullptr && node == nextNode->right)
            {
                node = nextNode;
                nextNode = node->parent;
            }
            if(nextNode == nullptr) //End of iterator
            {
                keyI = NULL_INDEX;
            }
            else if(nextNode->keys[K2] == nullptr)  //Next node is a 2-node
            {
                keyI = K1;
            }
            else    //Next node is a 3-node
            {
                if(node == nextNode->left)  //Node is from left of 3-node
                {
                    keyI = K1;
                }
                else    //Node is from middle of 3-node
                {
                    keyI = K2;
                }
            }
            node = nextNode;
        }
    }
    else    //Node is a 3-node
    {
        if(keyI == K1)  //Current element is smallest in 3-node
        {
            if(node->mid != nullptr)    //Node has a middle subtree
            {
                //Go-to lowest value of middle subtree
                node = node->mid;
                while(node->left != nullptr)
                {
                    node = node->left;
                }
                keyI = K1;
            }
            else    //If leaf, move to second key 
            {
                keyI = K2;
            }
        }
        else    //Current element is largest in 3-node
        {
            if(node->right != nullptr)  //Node has a right subtree
            {
                //Go-to lowest value of right subtree
                node = node->right;
                while(node->left != nullptr)
                {
                    node = node->left;
                }
                keyI = K1;
            }
            else    //Node does not have right subtree
            {
                //Go-to first ancestor that is to the right of this node
                Node<DataType> *nextNode = node->parent;
                while(nextNode != nullptr && node == nextNode->right)
                {
                    node = nextNode;
                    nextNode = node->parent;
                }
                if(nextNode == nullptr) //End of iterator
                {
                    keyI = NULL_INDEX;
                }
                else if(nextNode->keys[K2] == nullptr)  //Next node is a 2-node
                {
                    keyI = K1;
                }
                else    //Next node is a 3-node
                {
                    if(node == nextNode->left)  //Node is from left of 3-node
                    {
                        keyI = K1;
                    }
                    else    //Node is from middle of 3-node
                    {
                        keyI = K2;
                    }
                }
                node = nextNode;
            }
        }    
    }
    return *this;
}

#endif
