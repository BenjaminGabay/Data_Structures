/*****************************************
** File:    Project4.cpp
** Project: CSCE 221 Project 4, Spring 2019
** Author:  Benjamin Gabay
** Date:    5/1/2019
** Section: 510
** E-mail:  benjigabay@tamu.edu
**
**  This file is the driver(or main) for Project 4
** to create a "Perfect Hashing" map of hash maps so
** that there are no collisions. This driver tests the
** create hash map structures.
**
***********************************************/

//Included directories
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include "mainHash.h"

//Expected argument constants
#define EXPECTED_ARGC 2

//Constant defining the city to search for
const string SEARCH_FOR_CITY = "Ringgold, GA";

int main(int argc, char **argv)
{
cout << endl;

//Ensure there is is a command line input argument given
if (argc != EXPECTED_ARGC)
{
    cerr << "Usage: " << argv[0] << " <inputFile.txt>" << std::endl;
    return 1;
}

//Create input file from argument
ifstream inFile(argv[1]);

if (!inFile)    //Make sure file opened successfully
{
    cout << "Bad input file path" << endl;
    return 1;
}

City *city = nullptr;
vector<City*> cities;
while(inFile.good())
{
    //Input city from input file
    string name;
    double lat;
    double lon;
    getline(inFile, name);
    inFile >> lat >> lon;
    city = new City(name, lat, lon);
    cities.push_back(city); //Add to list of cities

    city = nullptr;
    //Skip to next line if at the end of a line and file
    //hasn't reached the end.
    while(inFile.good() && (inFile.peek() == '\n'))
    {
        inFile.get();
    }
}

int size = cities.size();   //Define number of cities read in

//Create main hash table and add all cities to it
mainHash mHashTable(size);
for(int i = 0; i < size; ++i)
{
    mHashTable.add(cities[i]);
}
mHashTable.makeSecHash();   //Create secondary hash tables

//Outputs
cout << "p1: " << PRIME1 << endl;
cout << "p2: " << PRIME2 << endl;
cout << "a: " << mHashTable.a << endl;
cout << "b: " << mHashTable.b << endl;
cout << "c: " << mHashTable.c << endl;
cout << endl;

cout << "number of cities: " << cities.size() << endl;
cout << "maximum collisions: " << mHashTable.maxCollisions << endl;

vector<int> numCities(10, 0);
for(int i = 0; i < size; ++i)
{
    numCities[mHashTable.sHashTable[i].cities.size()] += 1;
}
for(int i = 0; i < 10; ++i)
{
    cout << "# primary slots with " << i << " cities: " << numCities[i] << endl;
}

cout << "** cities in the slot with most collisions **" << endl;
int numCol = 9;
bool done = false;
while(!done)
{
    if(numCities[numCol] > 0)
    {
        for(int i = 0; i < size; ++i)
        {
            int col = mHashTable.sHashTable[i].cities.size();
            if(col == numCol)
            {
                for(int j = 0; j < numCol; ++j)
                {
                    cout << mHashTable.sHashTable[i].cities[j]->name << " ";
                    cout << "(" << mHashTable.sHashTable[i].cities[j]->latitude << " ";
                    cout << mHashTable.sHashTable[i].cities[j]->longitude << ")" << endl;
                }
            }
        }
        done = true;
    }
    else
    {
        numCol--;
    }
}

vector<int> numAttempts(10, 0);
for(int i = 0; i < size; ++i)
{
    int attempts = mHashTable.sHashTable[i].hashAttempts;
    if(attempts > 0 && attempts < 11)
    {
        numAttempts[attempts-1] += 1;
    }
}
for(int i = 0; i < 10; ++i)
{
    cout << "# secondary hash tables trying " << i+1 << " hash functions: " << numAttempts[i] << endl;
}

cout << "number of secondary hash tables with more than one item: " << size - numCities[0] - numCities[1] << endl;

double hashesAttempted = 0;
double count = 0;
for(int i = 0; i < size; ++i)
{
    int attempts = mHashTable.sHashTable[i].hashAttempts;
    if(attempts > 0)
    {
        hashesAttempted += attempts;
        count++;
    }
}
cout << "avreage # of hash functions tried: " << hashesAttempted/count << endl;

/* Search for the defined SEARCH_FOR_CITY */
//Find main hash key
int key = mHashTable.h(mHashTable.g(SEARCH_FOR_CITY));
//Find secondary hash key
int key2 = mHashTable.sHashTable[key].h(mHashTable.sHashTable[key].g(SEARCH_FOR_CITY));
//Get city at hash mapped posotion
City *searchedCity = mHashTable.sHashTable[key].hashTable[key2];
cout << "city details: " << key << endl;
cout << SEARCH_FOR_CITY << " ";
//Output location coordinates of city if found; otherwise output "n/a" for location
if(searchedCity->name == SEARCH_FOR_CITY)
{
    cout << "(" << searchedCity->latitude << " ";
    cout << searchedCity->longitude << ")" << endl;
}
else
{
    cout << "(n/a)";
}

//Delete all city pointers
for(int i = 0; i < size; ++i)
{
    delete cities[i];
}

return 0;
}
