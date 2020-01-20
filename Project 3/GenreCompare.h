/*****************************************
** File:    GenreCompare.h
** Project: CSCE 221 Project 3, Spring 2019
** Author:  Benjamin Gabay
** Date:    4/10/2019
** Section: 510
** E-mail:  benjigabay@tamu.edu
**
**  This file is the header for a Compare structure.
** This comparator is defined by genre names and
** can take in Song objects to compare their data.
**
***********************************************/

#ifndef GENRE_COMPARE_H
#define GENRE_COMPARE_H

/* Declaration of the comparison functor for use with the Genre index */

#include <string>
#include "Song.h"

struct GenreCompare
{
    /* 
     * Return whether or not song a's genre is 
     * lexicographically less than song b's genre
     */
    bool operator()(const Song *a, const Song *b, bool equal = false);

    /*
     * Return whether or not the song's genre is
     * lexicographically less than the given genre
     */
    bool operator()(const Song *song, const std::string &genre, bool equal = false);

    /*
     * Return whether or not the given genre is
     * lexicographically less than the song's genre
     */
    bool operator()(const std::string &genre, const Song *song, bool equal = false);

    /*
     * Return whether or not the first genre is
     * lexicographically less than the second genre
     */
    bool operator()(const std::string &genreA, const std::string &genreB, bool equal = false);
};

#endif
