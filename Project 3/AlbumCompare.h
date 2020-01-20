/*****************************************
** File:    AlbumCompare.h
** Project: CSCE 221 Project 3, Spring 2019
** Author:  Benjamin Gabay
** Date:    4/10/2019
** Section: 510
** E-mail:  benjigabay@tamu.edu
**
**  This file is the header for a Compare structure.
** This comparator is defined by album names and
** can take in Song objects to compare their data.
**
***********************************************/

#ifndef ALBUM_COMPARE_H
#define ALBUM_COMPARE_H

/* Declaration of the comparison functor for use with the Album index */

#include <string>
#include "Song.h"

struct AlbumCompare
{
    /* 
     * Return whether or not song a's album is 
     * lexicographically less than song b's album
     */
    bool operator()(const Song *a, const Song *b, bool equal = false);

    /*
     * Return whether or not the song's album is
     * lexicographically less than the given album
     */
    bool operator()(const Song *song, const std::string &album, bool equal = false);

    /*
     * Return whether or not the given album is
     * lexicographically less than the song's album
     */
    bool operator()(const std::string &album, const Song *song, bool equal = false);

    /*
     * Return whether or not the first album is
     * lexicographically less than the second album
     */
    bool operator()(const std::string &albumA, const std::string &albumB, bool equal = false);
};

#endif
