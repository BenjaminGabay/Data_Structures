/*****************************************
** File:    YearCompare.h
** Project: CSCE 221 Project 3, Spring 2019
** Author:  Benjamin Gabay
** Date:    4/10/2019
** Section: 510
** E-mail:  benjigabay@tamu.edu
**
**  This file is the header for a Compare structure.
** This comparator is defined by year date and
** can take in Song objects to compare their data.
**
***********************************************/

#ifndef YEAR_COMPARE_H
#define YEAR_COMPARE_H

/* Declaration of the comparison functor for use with the Year index */

#include <string>
#include "Song.h"

struct YearCompare
{
    /* 
     * Return whether or not song a's year is 
     * numerically less than song b's year
     */
    bool operator()(const Song *a, const Song *b, bool equal = false);

    /*
     * Return whether or not the song's year is
     * numerically less than the given year
     */
    bool operator()(const Song *song, const int &year, bool equal = false);

    /*
     * Return whether or not the given year is
     * numerically less than the song's year
     */
    bool operator()(const int &year, const Song *song, bool equal = false);

    /*
     * Return whether or not the first year is
     * numerically less than the second year
     */
    bool operator()(const int &yearA, const int &yearB, bool equal = false);
};

#endif
