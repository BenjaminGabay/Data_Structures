/*****************************************
** File:    TicTacToe.h
** Project: CSCE 221 Project 2, Spring 2019
** Author:  Benjamin Gabay
** Date:    3/13/2019
** Section: 510
** E-mail:  benjigabay@tamu.edu
**
**  This is the header file for the TicTacToe class.
** Each game is essentially a linked list of nodes
** of all the moves of the game and variables representing
** the status of the game.
**
***********************************************/

//Header Guards
#ifndef TICTACTOE_H
#define TICTACTOE_H

//Included Directories & Files
#include "TicTacNode.h"

//Constants to define int value for results of game
const int DID_NOT_END = 0;
const int X_WINS = 1;
const int O_WINS = 2;
const int DRAW = 3;

class TicTacToe
{
    //Public class methods
    public:
        //Constructor for TicTacToe class
	    TicTacToe() : m_isOver(false), m_results(DID_NOT_END), head(nullptr), tail(nullptr) {}
        void readGame(string fileName);             //Reads in game moves from file to create game
        bool getIsOver() const {return m_isOver;}   //Returns whether or not the game is over
        int getResults() const {return m_results;}  //Returns results of game
        TicTacNode* getHead() const {return head;}  //Returns pointer to head of linked list of game nodes
        TicTacNode* getTail() const {return tail;}  //Returns pointer to tail of linked list of game nodes

    //Private helper methods and data members
	private:
        bool playerWins(const char player);         //Helper function to determin if given player is winnner
        bool m_isOver;          //Variable indicating if game is over
        int m_results;          //Variable indicating results of game
        TicTacNode* head;       //Pointer to head node of list
        TicTacNode* tail;       //Pointer to tail node of list
};

#endif