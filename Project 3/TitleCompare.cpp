/*****************************************
** File:    TitleCompare.cpp
** Project: CSCE 221 Project 3, Spring 2019
** Author:  Benjamin Gabay
** Date:    4/10/2019
** Section: 510
** E-mail:  benjigabay@tamu.edu
**
**  This file contains the function definitions
** for a TitleCompare structure.
**
***********************************************/

#include "TitleCompare.h"

/*
    equal parameter is defaulted to false.
    If equal=FALSE; Return TRUE if the first value is less than the second value
                    Return FALSE if the first value is greater than or equal to the second value
    If equal=TRUE;  Return TRUE if the first value is equal to the second value
                    Return FALSE otherwise
*/

bool TitleCompare::operator()(const Song *a, const Song *b, bool equal)
{
    std::string titleA = a->title;
    std::string titleB = b->title;
    return operator()(titleA, titleB, equal);
}

bool TitleCompare::operator()(const Song *song, const std::string &title, bool equal)
{
    std::string titleS = song->title;
    return operator()(titleS, title, equal);
}

bool TitleCompare::operator()(const std::string &title, const Song *song, bool equal)
{
    std::string titleS = song->title;
    return operator()(title, titleS, equal);
}

bool TitleCompare::operator()(const std::string &titleA, const std::string &titleB, bool equal)
{
    if(equal && titleA.compare(titleB) == 0)
    {
        return true;
    }
    else if(!equal && titleA.compare(titleB) < 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}