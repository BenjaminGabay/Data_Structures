/*****************************************
** File:    main.cpp
** Project: CSCE 221 Project 3, Spring 2019
** Author:  Benjamin Gabay
** Date:    4/10/2019
** Section: 510
** E-mail:  benjigabay@tamu.edu
**
**  This file is the driver(or main) for Project 3
** to 
**
***********************************************/

#include <algorithm>
#include <iostream>
#include <cstdlib>
#include "Library.h"
#include "Song.h"
#include "Tree.h"
#include "TitleCompare.h"
#include "AlbumCompare.h"
#include "ArtistCompare.h"
#include "GenreCompare.h"
#include "YearCompare.h"

#define EXPECTED_ARGC 2

/* Print the given song to stdout */
void printSong(Song *song)
{
    std::cout << song << '\n';
}

int main(int argc, char **argv)
{
    std::cout << std::endl;

    if (argc != EXPECTED_ARGC)
    {
        std::cerr << "Usage: " << argv[0] << " <library-path>" << std::endl;
        return 1;
    }

    //Test tree with ints
    /*
    Tree<int> testTree;
    for(int i = 1; i <= 10; i++)
        testTree.insert(i);

    std::cout << testTree << '\n' << std::endl << std::endl;
    std::for_each(testTree.begin(), testTree.end(), printSong);
    std::cout << std::endl;
    */
    

    /* Read in the library */
    Library library(argv[1]);
    Tree<Song *, TitleCompare> titleIndex;
    Tree<Song *, AlbumCompare> albumIndex;
    Tree<Song *, ArtistCompare> artistIndex;
    Tree<Song *, GenreCompare> genreIndex;
    Tree<Song *, YearCompare> yearIndex;

    /* Populate the indexes */
    for (Library::const_iterator iter = library.begin(); iter != library.end(); iter++)
    {
        titleIndex.insert(*iter);
        albumIndex.insert(*iter);
        artistIndex.insert(*iter);
        genreIndex.insert(*iter);
        yearIndex.insert(*iter);
    }

#ifdef DEBUG    //include using "make CPPFLAGS=-DDEBUG"
    /* Level order printing (Uncomment desired tree)*/
    //std::cout << titleIndex << '\n' << std::endl;
    //std::cout << albumIndex << '\n' << std::endl;
    //std::cout << artistIndex << '\n' << std::endl;
    //std::cout << genreIndex << '\n' << std::endl;
    //std::cout << yearIndex << '\n' << std::endl;
    std::cout << std::endl;
#endif

    /* In order printing (Uncomment desired tree)*/
    //std::for_each(titleIndex.begin(), titleIndex.end(), printSong);
    //std::for_each(albumIndex.begin(), albumIndex.end(), printSong);
    //std::for_each(artistIndex.begin(), artistIndex.end(), printSong);
    //std::for_each(genreIndex.begin(), genreIndex.end(), printSong);
    //std::for_each(yearIndex.begin(), yearIndex.end(), printSong);
    //std::cout << std::endl;

    /* Genre Search: Thrash Metal */
    std::cout << "Genre Search: Thrash Metal" << std::endl;
    Song *key = *(titleIndex.begin());  //Element with "Thrash Metal" as artist to use as key
    std::for_each(genreIndex.find_range(key).first, genreIndex.find_range(key).second, printSong);

    std::cout << std::endl << std::endl;

    /* Artist Search: Blink-182 */
    std::cout << "Artist Search: Blink-182" << std::endl;
    key = artistIndex.getRoot()->keys[K1];   //Element with "Blink-182" as artist to use as key
    std::for_each(artistIndex.find_range(key).first, artistIndex.find_range(key).second, printSong);

    std::cout << std::endl;

    return 0;
}
