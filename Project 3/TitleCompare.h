/*****************************************
** File:    TitleCompare.h
** Project: CSCE 221 Project 3, Spring 2019
** Author:  Benjamin Gabay
** Date:    4/10/2019
** Section: 510
** E-mail:  benjigabay@tamu.edu
**
**  This file is the header for a Compare structure.
** This comparator is defined by title names and
** can take in Song objects to compare their data.
**
***********************************************/

#ifndef TITLE_COMPARE_H
#define TITLE_COMPARE_H

/* Declaration of the comparison functor for use with the Title index */

#include <string>
#include "Song.h"

struct TitleCompare
{
    /* 
     * Return whether or not song a's title is 
     * lexicographically less than song b's title
     */
    bool operator()(const Song *a, const Song *b, bool equal = false);

    /*
     * Return whether or not the song's title is
     * lexicographically less than the given title
     */
    bool operator()(const Song *song, const std::string &title, bool equal = false);

    /*
     * Return whether or not the given title is
     * lexicographically less than the song's title
     */
    bool operator()(const std::string &title, const Song *song, bool equal = false);

    /*
     * Return whether or not the first title is
     * lexicographically less than the second title
     */
    bool operator()(const std::string &titleA, const std::string &titleB, bool equal = false);
};

#endif
