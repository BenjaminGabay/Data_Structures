/*****************************************
** File:    GenreCompare.cpp
** Project: CSCE 221 Project 3, Spring 2019
** Author:  Benjamin Gabay
** Date:    4/10/2019
** Section: 510
** E-mail:  benjigabay@tamu.edu
**
**  This file contains the function definitions
** for a GenreCompare structure.
**
***********************************************/

#include "GenreCompare.h"

/*
    equal parameter is defaulted to false.
    If equal=FALSE; Return TRUE if the first value is less than the second value
                    Return FALSE if the first value is greater than or equal to the second value
    If equal=TRUE;  Return TRUE if the first value is equal to the second value
                    Return FALSE otherwise
*/

bool GenreCompare::operator()(const Song *a, const Song *b, bool equal)
{
    std::string genreA = a->genre;
    std::string genreB = b->genre;
    return operator()(genreA, genreB, equal);
}

bool GenreCompare::operator()(const Song *song, const std::string &genre, bool equal)
{
    std::string genreS = song->genre;
    return operator()(genreS, genre, equal);
}

bool GenreCompare::operator()(const std::string &genre, const Song *song, bool equal)
{
    std::string genreS = song->genre;
    return operator()(genre, genreS, equal);
}

bool GenreCompare::operator()(const std::string &genreA, const std::string &genreB, bool equal)
{
    if(equal && genreA.compare(genreB) == 0)
    {
        return true;
    }
    else if(!equal && genreA.compare(genreB) < 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}