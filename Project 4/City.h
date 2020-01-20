/*****************************************
** File:    City.h
** Project: CSCE 221 Project 4, Spring 2019
** Author:  Benjamin Gabay
** Date:    5/1/2019
** Section: 510
** E-mail:  benjigabay@tamu.edu
**
**  This file is definitions for the City structure.
** Each city has a name, latitude position, and
** longitude position.
**
***********************************************/

//Header Guards
#ifndef CITY_H
#define CITY_H

//Included directories
#include <string>

using namespace std;

/* 
 * City structure. Stores the name and position of the
 * city. Structure can be constructed with its data and
 * its data members can be accessed.
 */
struct City
{
    //Constructor
    City(string n = "", double la = 0.0, double lo = 0.0) : name(n), latitude(la), longitude(lo) {}

    //Data members
    string name;
    double latitude;
    double longitude;
};


#endif
