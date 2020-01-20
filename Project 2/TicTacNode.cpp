/*****************************************
** File:    TicTacNode.cpp
** Project: CSCE 221 Project 2, Spring 2019
** Author:  Benjamin Gabay
** Date:    3/13/2019
** Section: 510
** E-mail:  benjigabay@tamu.edu
**
**  This file contains the class method definitions
** for the TicTacNode class.    
**
***********************************************/

//Included Directories & Files
#include <sstream>
#include "TicTacNode.h"

//Constructs TicTacNode object and assigns map with given string of moves
TicTacNode::TicTacNode(string moves) : m_children()
{
    istringstream iss(moves);
    for(int i = 0; i < BOARD_SIZE; ++i)
    {
        m_board[i] = iss.get();
    }
}

//Overloaded assigmant operator
//Copies copy node data members to this data members
TicTacNode& TicTacNode::operator=(TicTacNode& copy)
{
    m_board = copy.m_board;
    m_children = copy.m_children;
    return *this;
}

//Overloaded comparison operator
//Compares all of the mappings in the nodes to see if boards match
bool operator==(TicTacNode& n1, TicTacNode& n2)
{
    for(int i = 0; i < BOARD_SIZE; ++i)
    {
        if(n1.getLoc(i) != n2.getLoc(i))
        {
            return false;
        }
    }
    return true;
}

//Outputs node if game board as 3x3 matrix and ends with new line
ostream& operator<<(ostream& os, TicTacNode& node)
{
    for(int i = 0; i < BOARD_SIZE; ++i)
    {
        if((i + 1) % 3 == 0)
        {
            os << node.getLoc(i) << endl;
        }
        else
        {
            os << node.getLoc(i);
        }
    }
    return os;
}