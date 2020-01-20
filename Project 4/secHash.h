/*****************************************
** File:    secHash.h
** Project: CSCE 221 Project 4, Spring 2019
** Author:  Benjamin Gabay
** Date:    5/1/2019
** Section: 510
** E-mail:  benjigabay@tamu.edu
**
**  This file is definitions for the secondary hash map
** structure. The secondary hash map has a list of cities
** belonging to it and then the ability to organize them
** into a hash map.
**
***********************************************/

//Header Guards
#ifndef SEC_HASH_H
#define SEC_HASH_H

//Included directories
#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include "City.h"

using namespace std;

//Constants for Prime1 and defined Prime2
const int PRIME1 = 16890581;
const int PRIME2 = 17027399;

/* 
 * Secondary hash map structure. Has a vector of cities belonging
 * to it and its organized hash map. It also stores the number of
 * hash functions attempted and the a, b, c constants used in the
 * hash function.
 */
struct secHash
{
    //Data Members
    vector<City*> cities;
    vector<City*> hashTable;
    int hashAttempts;
    int a;
    int b;
    int c;

    //Constructor
    secHash() : cities(), hashTable(), hashAttempts(0), a(0), b(0), c(0) {}
    
    //Returns collisions(size) in secondary map
    int getCollisions()
    {
        return cities.size();
    }

    //Makes the hash map out of the cities in the structure
    void makeHash()
    {
        int size = cities.size();
        vector<City*> temp(size, nullptr);
        hashTable = temp;
        if(hashTable.size() == 1)
        {
            hashTable[0] = cities[0];
        }
        else    //Hashing needs to be done
        {
            bool collision = true;
            while(collision)    //Attempt until no collisions
            {
                collision = false;
                hashAttempts++; //Increment number of hash function attempts
                //Create new hash function constants
                srand(hashAttempts);
                c = rand() % PRIME1 + 1;
                a = rand() % PRIME2 + 1;
                b = rand() % PRIME2;
                hashTable = temp;   //Reset hash table
                //Hash each city and see if collision is made
                for(int i = 0; i < size; ++i)
                {
                    int hashVal = h(g(cities[i]->name));
                    if(hashTable[hashVal] != nullptr)
                    {
                        collision = true;
                    }
                    hashTable[hashVal] = cities[i];
                }
            }
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
        int m = hashTable.size();
        //unsigned long int to allow for large number to be evaluated before mod
        unsigned long int val = a*x + b;
        return ((val % PRIME2) % m);    //Return hash key of city name string
    }
};


#endif
