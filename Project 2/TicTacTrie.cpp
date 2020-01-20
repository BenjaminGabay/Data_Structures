/*****************************************
** File:    TicTacTrie.cpp
** Project: CSCE 221 Project 2, Spring 2019
** Author:  Benjamin Gabay
** Date:    3/13/2019
** Section: 510
** E-mail:  benjigabay@tamu.edu
**
**  This file contains the class method definitions
** for the TicTacTrie class.
**
***********************************************/

//Included Directories & Files
#include "TicTacTrie.h"

//Adds given TicTacToe game to the tree and updates tree and data members
void TicTacTrie::addGame(TicTacToe t)
{
    //Update number of X wins, O wins, and draws from game results
    if(t.getResults() == X_WINS)
    {
        m_xWins++;
    }
    if(t.getResults() == O_WINS)
    {
        m_oWins++;
    }
    if(t.getResults() == DRAW)
    {
        m_draws++;
    }

    //If first game to be added to tree then make root the head of the game
    //  making tree be the given game linked list
    if(root == nullptr)
    {
        root = t.getHead();
    }
    //Else parse through existing tree and add new game nodes appropriately
    else
    {
        //Parse through tree and new game until either has reached end
        TicTacNode* parent = root;
        TicTacNode* nodeToAdd = nullptr;
        bool done = false;
        if(t.getHead()->m_children.empty())
        {
            done = true;
        }
        else
        {
            nodeToAdd = t.getHead()->m_children[0];
        }
        while(!done)
        {
            int nodeLoc = -1; //nodeLoc is -1 if new node to add
            for(int i = 0; i < (int)parent->m_children.size(); ++i)
            {
                if(*(nodeToAdd) == *(parent->m_children[i]))
                {
                    nodeLoc = i;
                }
            }

            //If node is not new to tree then move to next node
            if(nodeLoc == -1)
            {
                parent->m_children.push_back(nodeToAdd);
                done = true;
            }
            //Else add node as a child of the parent, adding rest of list
            // to tree as new branch
            else
            {
                if(parent->m_children[nodeLoc]->m_children.empty())
                {
                    done = true;
                    parent->m_children[nodeLoc] = nodeToAdd;
                }
                else
                {
                    parent = parent->m_children[nodeLoc];
                }
                if(nodeToAdd->m_children.empty())
                {
                    done = true;
                }
                else
                {
                    nodeToAdd = nodeToAdd->m_children[0];
                }
            }            
        }
    }
    //Update size of tree by recounting
    m_size = countNodes(root);
}

//Helper function to recursively count the nodes in the tree
int TicTacTrie::countNodes(const TicTacNode* node) const
{
    //Count number of extended children of given node
    int numChildren = 0;
    for(int i = 0; i < (int)node->m_children.size(); ++i)
    {
        numChildren += countNodes(node->m_children[i]);
    }
    //Return self plus number of children 
    return numChildren + 1;
}