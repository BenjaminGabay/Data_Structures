/*****************************************
** File:    YearCompare.cpp
** Project: CSCE 221 Project 3, Spring 2019
** Author:  Benjamin Gabay
** Date:    4/10/2019
** Section: 510
** E-mail:  benjigabay@tamu.edu
**
**  This file contains the function definitions
** for a YearCompare structure.
**
***********************************************/

#include "YearCompare.h"

/*
    equal parameter is defaulted to false.
    If equal=FALSE; Return TRUE if the first value is less than the second value
                    Return FALSE if the first value is greater than or equal to the second value
    If equal=TRUE;  Return TRUE if the first value is equal to the second value
                    Return FALSE otherwise
*/

bool YearCompare::operator()(const Song *a, const Song *b, bool equal)
{
    int yearA = a->year;
    int yearB = b->year;
    return operator()(yearA, yearB, equal);
}

bool YearCompare::operator()(const Song *song, const int &year, bool equal)
{
    int yearS = song->year;
    return operator()(yearS, year, equal);
}

bool YearCompare::operator()(const int &year, const Song *song, bool equal)
{
    int yearS = song->year;
    return operator()(year, yearS, equal);
}

bool YearCompare::operator()(const int &yearA, const int &yearB, bool equal)
{
    if(equal && yearA == yearB)
    {
        return true;
    }
    else if(!equal && yearA < yearB)
    {
        return true;
    }
    else
    {
        return false;
    }
}