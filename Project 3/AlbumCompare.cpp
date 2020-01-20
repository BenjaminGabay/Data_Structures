/*****************************************
** File:    AlbumCompare.cpp
** Project: CSCE 221 Project 3, Spring 2019
** Author:  Benjamin Gabay
** Date:    4/10/2019
** Section: 510
** E-mail:  benjigabay@tamu.edu
**
**  This file contains the function definitions
** for a AlbumCompare structure.
**
***********************************************/

#include "AlbumCompare.h"

/*
    equal parameter is defaulted to false.
    If equal=FALSE; Return TRUE if the first value is less than the second value
                    Return FALSE if the first value is greater than or equal to the second value
    If equal=TRUE;  Return TRUE if the first value is equal to the second value
                    Return FALSE otherwise
*/

bool AlbumCompare::operator()(const Song *a, const Song *b, bool equal)
{
    std::string albumA = a->album;
    std::string albumB = b->album;
    return operator()(albumA, albumB, equal);
}

bool AlbumCompare::operator()(const Song *song, const std::string &album, bool equal)
{
    std::string albumS = song->album;
    return operator()(albumS, album, equal);
}

bool AlbumCompare::operator()(const std::string &album, const Song *song, bool equal)
{
    std::string albumS = song->album;
    return operator()(album, albumS, equal);
}

bool AlbumCompare::operator()(const std::string &albumA, const std::string &albumB, bool equal)
{

    if(equal && albumA.compare(albumB) == 0)
    {
        return true;
    }
    else if(!equal && albumA.compare(albumB) < 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}