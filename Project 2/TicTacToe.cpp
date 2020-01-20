/*****************************************
** File:    TicTacToe.cpp
** Project: CSCE 221 Project 2, Spring 2019
** Author:  Benjamin Gabay
** Date:    3/13/2019
** Section: 510
** E-mail:  benjigabay@tamu.edu
**
**  This file contains the class method definitions
** for the TicTacToe class.
**
***********************************************/

//Included Directories & Files
#include <fstream>
#include "TicTacToe.h"

//Reads in given file name to build game as linked list of nodes
void TicTacToe::readGame(string fileName)
{
    //Creates input file stream from given file name
    ifstream input = ifstream(fileName);

    //Builds linked list of game nodes
    TicTacNode* prev = nullptr;
    string line;
	while(getline(input, line))
	{
        string board = line;
        //get rest of board
        getline(input, line);
        board.append(line);
        getline(input, line);
        board.append(line);
        
        //Create game node
        TicTacNode* curr = new TicTacNode(board);

        //Add node to linked list
        if(head == nullptr)
        {
            head = curr;
        }
        else
        {
            prev->m_children.push_back(curr);
        }
        prev = curr;

        //skip blank line between boards
        if(input.peek() != EOF)
        {
            getline(input, line);
        }
    }
    m_isOver = true;    //Set game status to game over
	input.close();  //Close input file stream

    //After game is over the most previous node is the tail of list
    tail = prev;
    
    //Update game results based on tail node of game
    if(playerWins('X'))
    {
        m_results = X_WINS;
    }
    else if(playerWins('O'))
    {
        m_results = O_WINS;
    }
    else
    {
        m_results = DRAW;
    }
}

//Helper function to determine if specific player won or not
bool TicTacToe::playerWins(const char player)
{
    //Check if player wins on any row
    for(int i = 0; i < 3; ++i)
    {
        if(tail->getLoc(i*3) == player && tail->getLoc(i*3+1) == player && tail->getLoc(i*3+2) == player)
        {
            return true;
        }
    }

    //Check if player wins on any column
    for(int i = 0; i < 3; ++i)
    {
        if(tail->getLoc(i) == player && tail->getLoc(i+3) == player && tail->getLoc(i+6) == player)
        {
            return true;
        }
    }

    //Check if player wins along diagnol from top left to bottom right
    if(tail->getLoc(0) == player && tail->getLoc(4) == player && tail->getLoc(8) == player)
    {
        return true;
    }

    //Check if player wins along diagnol from top right to bottom left
    if(tail->getLoc(2) == player && tail->getLoc(4) == player && tail->getLoc(6) == player)
    {
        return true;
    }

    //Return false if player never won
    return false;
}