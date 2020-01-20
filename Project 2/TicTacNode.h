/*****************************************
** File:    TicTacNode.h
** Project: CSCE 221 Project 2, Spring 2019
** Author:  Benjamin Gabay
** Date:    3/13/2019
** Section: 510
** E-mail:  benjigabay@tamu.edu
**
**  This is the header file for the TicTacNode class
** Each node has a map representing the game board
** and a vector of pointers to all of its children.
**
***********************************************/

//Header Guards
#ifndef TICTACNODE_H
#define TICTACNODE_H

//Included Directories
#include <iostream>
#include <vector>
#include <map>

using namespace std;

//Constant for number of mappings in board
const int BOARD_SIZE = 9;

//Constant for default board
const string BLANK_BOARD = "---------";

class TicTacNode
{
    //Public class methods and data members
    public:
        TicTacNode(string moves = BLANK_BOARD);                 //Constructor with default default_board parameter
        TicTacNode& operator=(TicTacNode& copy);                //Overloaded assignment operator
        void setLoc(int loc, char sym) {m_board[loc] = sym;}    //Set map pair
        char getLoc(int loc) {return m_board.at(loc);}          //Return mapping at key location

        vector<TicTacNode*> m_children;         //Vector of pointers to children

    //Private data members
    private:
        map<int, char> m_board;                 //Map of key locations to the symbal at board location
};

//Overloaded operators for class
bool operator==(TicTacNode& n1, TicTacNode& n2);                //Overloaded comparison operator
ostream& operator<<(ostream& os, TicTacNode& node);             //Overloaded output operator

#endif