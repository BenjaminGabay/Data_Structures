/*****************************************
** File:    driver.cpp
** Project: CSCE 221 Project 2, Spring 2019
** Author:  Benjamin Gabay
** Date:    3/13/2019
** Section: 510
** E-mail:  benjigabay@tamu.edu
**
**  This file is the driver(or main) for Project 2
** to read in a file of file names each containing
** games to add to a tree.
**
***********************************************/

//Included Directories/Files
#include <fstream>
#include "TicTacTrie.h"

//Constant defining number of arguments of command line
const int NUM_ARGS = 2;

int main(int argc, char* argv[])
{
    //Exit if incorrect number of command line arguments
	if(argc != NUM_ARGS)
    {
		cout << "Usage: " << argv[0] << " file_name_list" << endl;
		return 1;
	}
    //Otherwise read in input file of input file games
    else
    {
        ifstream files = ifstream(argv[1]);
        //Exit if input file fails to open
        if(!files.is_open())
        {
            cout << "Error: Unable to open " << argv[1] << endl;
            return 1;
        }
        //Otherwise read in all game files from input file to make tree
        else
        {
            //Make TicTacToe tree
            TicTacTrie tree;

            //Add every game from each file to tree
            string fileName;
    	    while(getline(files, fileName) && fileName != "")
	        {
                //Output game file being read in
                cout << "======================" << endl;
                cout << "Reading: " << fileName << endl;
                cout << "======================" << endl;

                //Create and read game from file
		        TicTacToe game;
                game.readGame(fileName);

                //Output results of game
                if(game.getResults() == X_WINS)
                {
                    cout << "Player X wins!" << endl;
                }
                else if(game.getResults() == O_WINS)
                {
                    cout << "Player O wins!" << endl;
                }
                else if(game.getResults() == DRAW)
                {
                    cout << "The game was a draw!" << endl;
                }
                else
                {
                    cout << "The game did not end." << endl;
                }

                //Output final board of game
                cout << "Game Board:" << endl;
                cout << *(game.getTail()) << endl;

                //Add game to tree
                tree.addGame(game);
            }
            //Output final tree statistics
            cout << "Final Trie Statistics" << endl;
            cout << "=====================" << endl;
            cout << "Player X Wins:  " << tree.getXWins() << endl;
            cout << "Player O Wins:  " << tree.getOWins() << endl;
            cout << "Draws:  " << tree.getDraws() << endl;
            cout << "Trie Size:      " << tree.getSize();

            //Close input file and exit
            files.close();
            return 0;
        }
	}
}