/*****************************************
** File:    mainHash.h
** Project: CSCE 221 Project 4, Spring 2019
** Author:  Benjamin Gabay
** Date:    5/1/2019
** Section: 510
** E-mail:  benjigabay@tamu.edu
**
**  This file is definitions for the main hash map
** structure. Each position in the hash map has its
** own secondary hash map for organize all collided
** elements into a collision free map.
**
***********************************************/

//Header Guards
#ifndef MAIN_HASH_H
#define MAIN_HASH_H

//Included directories
#include "secHash.h"
#include <iostream>
#include <stdlib.h>


/* 
 * Main hash map structure. Has a vector of secondary hash tables
 * to place the cities into. It also stores the maximum number of
 * collisions at any position and the a, b, c constants used in the
 * hash function.
 */
struct mainHash
{
    //Data members
    vector<secHash> sHashTable;
    int maxCollisions;
    int a;
    int b;
    int c;

    //Constructor
    mainHash(int m) : sHashTable(m), maxCollisions(0)
    {
        //Sets the a,b, and c hash constants
        srand(0);
        c = rand() % PRIME1 + 1;
        a = rand() % PRIME2 + 1;
        b = rand() % PRIME2;
    }

    //Adds a city to the hash map by placing it in the proper
    //secondary hash map
    void add(City *city)
    {
        int hashVal = h(g(city->name)); //Find hash key value
        sHashTable[hashVal].cities.push_back(city); //Add to proper secondary hash table
        //Update maximum collisions element
        if(maxCollisions < sHashTable[hashVal].getCollisions())
        {
            maxCollisions = sHashTable[hashVal].getCollisions();
        }
    }

    //First hash function
    int g(string str)
    {
        //unsigned long int to allow for large number to be evaluated before mod
        unsigned long int val = 0;
        int size = str.length();
        for(int i = 0; i < size; ++i)
        {
            //This hash function was found from the Wikipedia links found in
            //the project description to hash strings. The original documented
            //function raised a large number (c) by a relatively large power that
            //was too large to calculate in c++. Commented out were some if the other
            //hash functions I attempted.
            int cStr = str[i];
            val = ((val * c) + cStr) % PRIME1;
            //val += (cStr * pow(c, i)) % PRIME1;
            //val += ((cStr % PRIME1) * (PRIME1 - (static_cast<int>(pow(PRIME1-c, i)) % c))) % PRIME1;
        }
        return val;
    }

    //Second hash function taking input from the first hash function
    int h(int x)
    {
        int m = sHashTable.size();
        //unsigned long int to allow for large number to be evaluated before mod
        unsigned long int val = a*x + b;
        return ((val % PRIME2) % m);    //Return hash key of city name string
    }

    //Iterate through all secondary hash tables to create their hash tables
    //from the cities they have. Meant to be done after all cities have been added
    //to hash table or would need to be done after a new element is added.
    void makeSecHash()
    {
        int size = sHashTable.size();
        for(int i = 0; i < size; ++i)
        {
            if(sHashTable[i].cities.size() != 0)
            {
                sHashTable[i].makeHash();   //Make secondary hash table at position
            }
        }
    }    
};

#endif
