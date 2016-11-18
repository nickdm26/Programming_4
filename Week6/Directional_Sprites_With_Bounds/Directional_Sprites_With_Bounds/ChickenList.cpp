/*
Nicholas Muldrew
*/

#include "ChickenList.h"
#include "Chicken.h"


ChickenList::ChickenList()
{
}

void ChickenList::addChicken(Chicken^ newSprite)
{
	if (tail == nullptr)
	{
		head = newSprite;
		tail = newSprite;
	}
	else
	{
		tail->Next = newSprite;
		tail = newSprite;
	}
}

void ChickenList::deleteChicken(Chicken^ SpriteDelete)
{
	if (head != nullptr)
	{
		Chicken^ nodeWalker = head;
		if (nodeWalker == SpriteDelete)
		{
			if (head->Next == nullptr)
			{
				head = nullptr;
				tail = nullptr;
				SpriteDelete->Erase();
			}
			else
			{
				head = head->Next;
				SpriteDelete->Erase();
			}
		}
		else
		{
			while (nodeWalker->Next != SpriteDelete)
			{
				nodeWalker = nodeWalker->Next;
			}
			Chicken^ deleteMe = nodeWalker->Next;
			nodeWalker->Next = deleteMe->Next;
		}
	}
}

void ChickenList::deleteChickens()
{
	Chicken^ nodeWalker = head;
	while (nodeWalker != nullptr)
	{

		deleteChicken(nodeWalker);
		nodeWalker = nodeWalker->Next;
	}
}

void ChickenList::deleteAllDeadChickens()
{
	Chicken^ nodeWalker = head;
	while (nodeWalker != nullptr)
	{
		if (!nodeWalker->IsAlive)
		{
			deleteChicken(nodeWalker);
		}
		nodeWalker = nodeWalker->Next;
	}
}


void ChickenList::moveChickens(int action)
{
	Chicken^ nodeWalker = head;
	while (nodeWalker != nullptr)
	{

		nodeWalker->Move(action);
		nodeWalker = nodeWalker->Next;
	}
}

void ChickenList::drawChickens()
{
	Chicken^ nodeWalker = head;
	while (nodeWalker != nullptr)
	{

		nodeWalker->Draw();
		nodeWalker->UpdateFrame();
		nodeWalker = nodeWalker->Next;
	}
}

void ChickenList::hideChickens()
{
	Chicken^ nodeWalker = head;
	while (nodeWalker != nullptr)
	{
		nodeWalker->Erase();
		nodeWalker = nodeWalker->Next;
	}
}

