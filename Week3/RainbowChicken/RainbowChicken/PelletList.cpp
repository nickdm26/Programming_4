/*
Nick Muldrew
Programming 4
August 4 2016
The PelletList class is a linked list used to hold Pellets.
It does varouis things such as add, delete and count the Pellets in the List.
*/
#include "PelletList.h"

PelletList::PelletList(){}

/*
	The addPellet class adds a Pellet to the list.
	If the tail is a nullptr then it means the list is empty and sets the newPellet as the head and tail.
	if not then it sets the tails next to point at the newPellet then sets the tail to the newPellet.
*/
void PelletList::addPellet(Pellet^ newPellet)
{
	if (tail == nullptr)
	{
		head = newPellet;
		tail = newPellet;
	}
	else
	{
		tail->Next = newPellet;
		tail = newPellet;
	}
}

/*
	The deletePellet method is used to delete the Pellet passed in from the Linked List.

*/
void PelletList::deletePellet(Pellet^ pelletDelete)
{
		Pellet^ nodeWalker = head;
		if (nodeWalker == pelletDelete) //If the Pellet to delete is equal to the head
		{                               
			if (head->Next == nullptr) //Set the head and tail to nullptr if there is only 1 node in the list because you just deleted it.
			{
				head = nullptr;
				tail = nullptr;
				pelletDelete->erase();
			}
			else
			{
				head = head->Next;      //If there is more then 1 node in the list and you want to delete the head
				pelletDelete->erase();  //Set the head to point to the next Pellet in the list, then tell that first Pellet to delete itself
			}
		}
		else
		{
			while (nodeWalker->Next != pelletDelete)   //If nodeWalker->Next is not the Pellet that needs deleting then increment nodeWalker
			{
				nodeWalker = nodeWalker->Next;
			}
				Pellet^ deleteMe = nodeWalker->Next;  //makes a tempraoy Pellet for the one that needs to be deleted.
				nodeWalker->Next = deleteMe->Next;    //Sets the Pellet behind PelletDelete to point to the Pellet in front of PelletDelete
				deleteMe->erase();                    //The temporay Pellet is then told erase itself.
		}
}

/*
	The deleteAllDeadPellets loops through all the Pellets and if the Pellet is not alive then it gets passed to the deletePellet method to get deleted.
	It then comes back and keeps looping through them.
*/
void PelletList::deleteAllDeadPellets()
{
	Pellet^ nodeWalker = head;
	while (nodeWalker != nullptr)
	{
		if (!nodeWalker->IsAlive)
		{
			deletePellet(nodeWalker);
		}
		nodeWalker = nodeWalker->Next;
	}
}

/*
	The MovePellets method is used to loop through all the Pellets and tell them to move which then is updated on the Graphics canvas.
*/
void PelletList::movePellets()
{
	Pellet^ nodeWalker = head;
	while (nodeWalker != nullptr)
	{
		nodeWalker->move();
		nodeWalker = nodeWalker->Next;
	}
}

/*
	The DrawPellets method is used to loop through all the Pellets and tell them to draw themselves on the Graphics canvas.
*/
void PelletList::drawPellets()
{
	Pellet^ nodeWalker = head;
	while (nodeWalker != nullptr)
	{
		nodeWalker->move();
		nodeWalker->draw();
		nodeWalker = nodeWalker->Next;
	}
}

/*
	The CountPellets method is used to return the number of pellets in the list.
	It does this by incrementing over the pellets unless it is equal to nullptr.
*/
int PelletList::countPellets()
{
	Pellet^ nodeWalker = head;

	int count = 0;
	while (nodeWalker != nullptr)
	{
		count++;
		nodeWalker = nodeWalker->Next;
	}
	return count;
}