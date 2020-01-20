/*****************************************
** File:    Tree.cpp
** Project: CSCE 221 Project 3, Spring 2019
** Author:  Benjamin Gabay
** Date:    4/10/2019
** Section: 510
** E-mail:  benjigabay@tamu.edu
**
**  This file is the class definitions for the Tree class
**
***********************************************/

#include <iostream>
#include "Tree.h"

#ifndef TREE_CPP
#define TREE_CPP

/* Stubs for the tree's methods */

//Tree constructor
template <typename DataType, typename Compare>
Tree<DataType, Compare>::Tree() : root(nullptr), numItems(0), height(0) {}

//Tree copy constuctor
template <typename DataType, typename Compare>
Tree<DataType, Compare>::Tree(const Tree<DataType, Compare> &other)
{
    this->root = other.root;
    this->numItems = other.numItems;  
    this->height = other.height; 
}

//Tree copy assignment operator
template <typename DataType, typename Compare>
Tree<DataType, Compare> &
Tree<DataType, Compare>::operator=(const Tree<DataType, Compare> &other)
{
    if(this != &other) // check for self assignment
    {
		// delete old data
		for(iterator it = begin(); it != end(); it++)
        {
            if(*it != nullptr)
            {
                delete *it;
                it.node->keys[it.keyI] = nullptr;
            }
        }
		delete this->root;
		this->root = nullptr;
		
		// update data members from other
		this->root = other.root;
        this->numItems = other.numItems;
        this->height = other.height;
	}
	return *this;
}

//Tree destructor
template <typename DataType, typename Compare>
Tree<DataType, Compare>::~Tree()
{
    //Set all inner values to nullptr
    for(iterator it = begin(); it != end(); it++)
    {
        if(*it != nullptr)
        {
            //delete *it;   (Not needed since Library destructor deletes Song objects)
            it.node->keys[it.keyI] = nullptr;
        }
    }
    //Delete all nodes
	delete this->root;
	this->root = nullptr;
}

//Insert the given data into the tree
template <typename DataType, typename Compare>
void Tree<DataType, Compare>::insert(DataType data)
{
    if(empty()) //If empty tree; put data in new node and assign root
    {
        root = new Node<DataType>(data);
        height++;   //Increment height to 1
    }
    else    //Else; find valid leaf to insert data apon
    {
        findLeaf(root, data);
        //All Children assigned, now assign parents
        assignParents(root);
    }
    numItems++; //Increment size
}

template <typename DataType, typename Compare>
void Tree<DataType, Compare>::findLeaf(Node<DataType> *node, DataType data)
{
    if(node->left == nullptr)   //If node is a leaf
    {
        insertUp(node, data);
    }
    else
    {
        if(node->keys[K2] == nullptr)   //if node is a 2-node
        {
            if(Compare()(data, node->keys[K1])) //Cascade down left subtree
            {
                findLeaf(node->left, data);
            }
            else    //Cascade down right subtree
            {
                findLeaf(node->right, data);
            }
        }
        else    //Node is a 3-node
        {
            if(Compare()(data, node->keys[K1])) //Cascade down left subtree
            {
                findLeaf(node->left, data);
            }
            else if(Compare()(data, node->keys[K2])) //Cascade down middle subtree
            {
                findLeaf(node->mid, data);
            }
            else    //Cascade down right subtree
            {
                findLeaf(node->right, data);
            }
        }  
    }
}

//Once leaf is found, insert data and percolate up as needed
//leftC and rightC are new children of split node to be attached to
//  node if a value moves up a level
template <typename DataType, typename Compare>
void Tree<DataType, Compare>::insertUp(Node<DataType> *node, DataType data, Node<DataType> *leftC, Node<DataType> *rightC)
{
    if(node == nullptr) //Node is new root
    {
        node = new Node<DataType>(data);
        node->left = leftC;
        node->right = rightC;
        root = node;
        height++;   //Incremet height
    }
    else if(node->keys[K2] == nullptr)   //If node is a 2-node
    {
        //Turn 2-node into 3-node; assign data to proper position
        if(Compare()(data, node->keys[K1]))
        {
            node->keys[K2] = node->keys[K1];
            node->keys[K1] = data;
            node->left = leftC;
            node->mid = rightC;
        }
        else
        {
            node->keys[K2] = data;
            node->mid = leftC;
            node->right = rightC;
        }
    }
    else    //Node is a 3-node
    {
        if(Compare()(data, node->keys[K1])) //k1 is middle key
        {
            DataType m = node->keys[K1];
            Node<DataType> *newNode = new Node<DataType>(data);
            node->keys[K1] = node->keys[K2];
            node->keys[K2] = nullptr;
            newNode->left = leftC;
            newNode->right = rightC;
            node->left = node->mid;
            node->mid = nullptr;
            insertUp(node->parent, m, newNode, node);
        }
        else if(Compare()(data, node->keys[K2])) //data is middle key
        {
            DataType m = data;
            Node<DataType> *newNode = new Node<DataType>(node->keys[K2]);
            node->keys[K2] = nullptr;
            newNode->right = node->right;
            newNode->left = rightC;
            node->right = leftC;
            node->mid = nullptr;
            insertUp(node->parent, m, node, newNode);
        }
        else    //k2 is middle key
        {
            DataType m = node->keys[K2];
            Node<DataType> *newNode = new Node<DataType>(data);
            node->keys[K2] = nullptr;
            newNode->left = leftC;
            newNode->right = rightC;
            node->right = node->mid;
            node->mid = nullptr;
            insertUp(node->parent, m, node, newNode);
        }
    }
}

//After inserting, assign parents pointers to all children
template <typename DataType, typename Compare>
void Tree<DataType, Compare>::assignParents(Node<DataType> *node)
{
    if(node->left != nullptr)   //Node is not a leaf
    {
        node->left->parent = node;
        node->right->parent = node;
        assignParents(node->left);
        assignParents(node->right);
        if(node->mid != nullptr)    //Node has a middle child
        {
            node->mid->parent = node;
            assignParents(node->mid);
        }
    }
}

//Return whether or not tree is empty
template <typename DataType, typename Compare>
bool Tree<DataType, Compare>::empty() const
{
    if(size() == 0)
    {
        return true;
    } 
    return false;
}

//Return the current number of elements in the tree
template <typename DataType, typename Compare>
size_t Tree<DataType, Compare>::size() const
{
    /* Your code here... */    
    return numItems;
}

//Return iterator to first element of the tree; bottom left
template <typename DataType, typename Compare>
typename Tree<DataType, Compare>::iterator Tree<DataType, Compare>::begin()
{ 
    Node<DataType> *node = root;
    if(root != nullptr)
    {
        while(node->left != nullptr)    //Not a leaf
        {
            node = node->left;
        }
        return iterator(node, K1);
    }
    else
    {
        return iterator();
    }   
}

//Return a null iterator that will be reached after the end of the tree
template <typename DataType, typename Compare>
typename Tree<DataType, Compare>::iterator Tree<DataType, Compare>::end()
{
    return iterator();  //Default constructor returns null iterator
}

//Returns iterator pointer to the first appearence of key
template <typename DataType, typename Compare>
template <typename KeyType>
typename Tree<DataType, Compare>::iterator Tree<DataType, Compare>::find_first(KeyType key)
{   
    //Effectively uses iterator but has O(n) efficiency
    iterator it = begin();
    while(it != end() && !(Compare()(*it, key, true)))
    {
        it++;
    }
    return it;

    /*
        First occurence of key closest to the top can be done easily with O(logn)
        efficiency by cascading down the proper subtrees. But in order to find the
        first occurance of key in iterator order it would be much more complex because
        once the highest node with key is found, one must then search left in reverse
        iterator increment order to look at the values predecessor. This could be more
        easily accomplished with an iterator decrementer (iter--) function but I did not
        implement one.
    */    
}

//Returns iterator pointer to the last element of key
template <typename DataType, typename Compare>
template <typename KeyType>
typename Tree<DataType, Compare>::iterator Tree<DataType, Compare>::find_last(KeyType key)
{
    iterator it = find_first(key);  //Start at find_first iterator to avoid searching twice
    if(*it != nullptr)
    {
        iterator next = it;
        next++;
        while(next != end() && (Compare()(*next, key, true)))
        {
            it = next;
            next++;
        }
    }
    return it;
}

//Returns a pair of iterators to increment through all elements of key
//  Back iterator position is one past the last appearence of key
template <typename DataType, typename Compare>
template <typename KeyType>
std::pair<typename Tree<DataType, Compare>::iterator,
          typename Tree<DataType, Compare>::iterator>
Tree<DataType, Compare>::find_range(KeyType key)
{
    iterator front = find_first(key);
    iterator back = find_last(key);
    back++;
    return std::make_pair(front, back);
}

//Level order output of tree
template <typename DataType, typename Compare>
std::ostream &operator<<(std::ostream &stream, const Tree<DataType, Compare> &tree)
{
    for(int level = 0; level < tree.height; level++)
    {
        stream << "Level " << level << std::endl;
        printLevel(stream, tree.root, level);
    }

    return stream;
}

//Print given level
template <typename DataType>
std::ostream &printLevel(std::ostream &stream, Node<DataType> *node, int level)
{
    if(level == 0)
    {
        stream << "(" << node->keys[K1];
        if(node->keys[K2] != nullptr)  //Second key in  node
        {
            stream << ", " << node->keys[K2];
        }
        stream << ")" << std::endl;
    }
    else
    {
        printLevel(stream, node->left, level-1);
        if(node->mid != nullptr)  //3-node; has middle subtree
        {
            printLevel(stream, node->mid, level-1);
        }
        printLevel(stream, node->right, level-1);
    }

    return stream;
}

//Tree root getter function
//  Retruns pointer to root node of tree
template <typename DataType, typename Compare>
Node<DataType>* Tree<DataType, Compare>::getRoot() const
{
    return root;
}

#endif
