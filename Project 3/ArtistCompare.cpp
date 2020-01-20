/*****************************************
** File:    ArtistCompare.cpp
** Project: CSCE 221 Project 3, Spring 2019
** Author:  Benjamin Gabay
** Date:    4/10/2019
** Section: 510
** E-mail:  benjigabay@tamu.edu
**
**  This file contains the function definitions
** for a ArtistCompare structure.
**
***********************************************/

#include "ArtistCompare.h"

/*
    equal parameter is defaulted to false.
    If equal=FALSE; Return TRUE if the first value is less than the second value
                    Return FALSE if the first value is greater than or equal to the second value
    If equal=TRUE;  Return TRUE if the first value is equal to the second value
                    Return FALSE otherwise
*/

bool ArtistCompare::operator()(const Song *a, const Song *b, bool equal)
{
    std::string artistA = a->artist;
    std::string artistB = b->artist;
    return operator()(artistA, artistB, equal);
}

bool ArtistCompare::operator()(const Song *song, const std::string &artist, bool equal)
{
    std::string artistS = song->artist;
    return operator()(artistS, artist, equal);
}

bool ArtistCompare::operator()(const std::string &artist, const Song *song, bool equal)
{
    std::string artistS = song->artist;
    return operator()(artist, artistS, equal);
}

bool ArtistCompare::operator()(const std::string &artistA, const std::string &artistB, bool equal)
{
    if(equal && artistA.compare(artistB) == 0)
    {
        return true;
    }
    else if(!equal && artistA.compare(artistB) < 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}