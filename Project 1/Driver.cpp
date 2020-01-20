/*****************************************
** File:    driver.cpp
** Project: CSCE 221 Project 1, Spring 2019
** Author:  Benjamin Gabay
** Date:    2/13/2019
** Section: 510
** E-mail:  benjigabay@tamu.edu
**
**	This file contains the main driver program to test the
**	different functions made for our Stack221 and Queue221 classes
**
**
***********************************************/

#include "List221.h"
#include "Stack221.h"
#include "Queue221.h"

int main(int argc, char *argv[])
{
    Stack221<int> *myStack = new Stack221<int>();
    Queue221<int> myQueue;
    	
    try
	{
		//Load
        for (int i = 0; i < 10;)
		{
			myStack->Push(i);
			cout << "Added to Stack: " << myStack->Top() << endl;
			myQueue.Push(i++);
			cout << "Added to Queue: " << myQueue.Back() << endl;
        }
		cout << endl;
		
		//Print and unload
		cout << "Printing Stack" << endl;
		while(!(myStack->Empty()))
		{
			cout << myStack->Top() << " ";
			myStack->Pop();
		}
		cout << endl << endl;
		cout << "Printing Queue" << endl;
		while(!(myQueue.Empty()))
		{
			cout << myQueue.Front() << " ";
			myQueue.Pop();
		}
		cout << endl << endl << "------Making copies------" << endl << endl;
		
		//Reload
        for (int i = 0; i < 10;)
		{
			myStack->Push(i);
			myQueue.Push(i++);
        }
		
		//Make copies
		Stack221<int> *myStack2 = new Stack221<int>(*myStack);
		Queue221<int> myQueue2 = myQueue;
		
		//Print and unload original & copies
		cout << "Printing Stack" << endl;
		while(!(myStack->Empty()))
		{
			cout << myStack->Top() << " ";
			myStack->Pop();
		}
		cout << endl;
		cout << "Printing Queue" << endl;
		while(!(myQueue.Empty()))
		{
			cout << myQueue.Front() << " ";
			myQueue.Pop();
		}
		cout << endl << endl;
		cout << "Printing Stack2" << endl;
		while(!(myStack2->Empty()))
		{
			cout << myStack2->Top() << " ";
			myStack2->Pop();
		}
		cout << endl;
		cout << "Printing Queue2" << endl;
		while(!(myQueue2.Empty()))
		{
			cout << myQueue2.Front() << " ";
			myQueue2.Pop();
		}
		
		delete myStack2;	//Delete stack copy
		
		cout << endl << endl << "------Clearing Lists------" << endl << endl;
		
		//Reload
        for (int i = 0; i < 10;)
		{
			myStack->Push(i);
			myQueue.Push(i++);
        }
		
		//Clear lists
		cout << "Stack size: " << myStack->Size() << endl;
		cout << "Queue size: " << myQueue.Size() << endl;
		cout << "Stack cleared = " << myStack->Clear() << endl;
		cout << "Queue cleared = " << myQueue.Clear() << endl;
		cout << "Stack size: " << myStack->Size() << endl;
		cout << "Queue size: " << myQueue.Size() << endl << endl;
		
		//Display Lists to confirm they've been cleared
		cout << "Printing Stack" << endl;
		while(!(myStack2->Empty()))
		{
			cout << myStack2->Top() << " ";
			myStack2->Pop();
		}
		cout << endl;
		cout << "Printing Queue" << endl;
		while(!(myQueue2.Empty()))
		{
			cout << myQueue2.Front() << " ";
			myQueue2.Pop();
		}	 
    }
    catch (Exceptions221 &E) //Catch any Exceptions thrown
	{
        cout << "Exception: " << E.GetMessage() << endl;
    }
    
	cout << endl << endl << "------Deleting Stack------" << endl << endl;
	
    delete myStack;	//Delete stack
}
