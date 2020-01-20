/*****************************************
** File:    TicTacTrie.h
** Project: CSCE 221 Project 2, Spring 2019
** Author:  Benjamin Gabay
** Date:    3/13/2019
** Section: 510
** E-mail:  benjigabay@tamu.edu
**
**  This is the header file for the TicTacTrie class.
** Each game is essentially a trie(tree) of nodes of all
** of the TicTacToe games added and variables representing
** the status and information of the tree.
**
***********************************************/

//Header Guards
#ifndef TICTACTRIE_H
#define TICTACTRIE_H

//Included Directories & Files
#include "TicTacToe.h"

class TicTacTrie
{
    //Public class methods
    public:
        //Constructor for TicTacTrie class
	    TicTacTrie() : m_xWins(0), m_oWins(0), m_draws(0), m_size(0), root(nullptr) {}
        void addGame(TicTacToe t);                  //Adds given TicTacToe game to the tree of nodes
        int getXWins() const {return m_xWins;}      //Returns number of games X wins
        int getOWins() const {return m_oWins;}      //Returns number of games O wins
        int getDraws() const {return m_draws;}      //Returns number of games ending in a draw
        int getSize() const {return m_size;}        //Returns the number of nodes in the tree

    //Private class helper methods and data members
	private:
        int countNodes(const TicTacNode* node) const;   //Recursively counts the nodes in the tree
        int m_xWins;        //Variable counting the number of games X wins
        int m_oWins;        //Variable counting the number of games O wins
        int m_draws;        //Variable counting the number of games ending in a draw
        int m_size;         //Variable counting the number of nodes in the tree
        TicTacNode* root;   //Pointer to the top node root of the tree
};

#endif