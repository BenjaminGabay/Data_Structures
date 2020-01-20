/*****************************************
** File:    ArtistCompare.h
** Project: CSCE 221 Project 3, Spring 2019
** Author:  Benjamin Gabay
** Date:    4/10/2019
** Section: 510
** E-mail:  benjigabay@tamu.edu
**
**  This file is the header for a Compare structure.
** This comparator is defined by artist names and
** can take in Song objects to compare their data.
**
***********************************************/

#ifndef ARTIST_COMPARE_H
#define ARTIST_COMPARE_H

/* Declaration of the comparison functor for use with the Artist index */

#include <string>
#include "Song.h"

struct ArtistCompare
{
    /* 
     * Return whether or not song a's artist is 
     * lexicographically less than song b's artist
     */
    bool operator()(const Song *a, const Song *b, bool equal = false);

    /*
     * Return whether or not the song's artist is
     * lexicographically less than the given artist
     */
    bool operator()(const Song *song, const std::string &artist, bool equal = false);

    /*
     * Return whether or not the given artist is
     * lexicographically less than the song's artist
     */
    bool operator()(const std::string &artist, const Song *song, bool equal = false);

    /*
     * Return whether or not the first artist is
     * lexicographically less than the second artist
     */
    bool operator()(const std::string &artistA, const std::string &artistB, bool equal = false);
};

#endif
