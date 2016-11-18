/*
Nicholas Muldrew
*/

#include "SpriteList.h"
#include "Sprite.h"


SpriteList::SpriteList()
{
}

void SpriteList::addSprite(Sprite^ newSprite)
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

void SpriteList::deleteSprite(Sprite^ SpriteDelete)
{
	if (head != nullptr)
	{
		Sprite^ nodeWalker = head;
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
			Sprite^ deleteMe = nodeWalker->Next;
			nodeWalker->Next = deleteMe->Next;
		}
	}
}

void SpriteList::deleteSprites()
{
	Sprite^ nodeWalker = head;
	while (nodeWalker != nullptr)
	{

		deleteSprite(nodeWalker);
		nodeWalker = nodeWalker->Next;
	}
}

void SpriteList::deleteAllDeadSprites()
{
	Sprite^ nodeWalker = head;
	while (nodeWalker != nullptr)
	{
		if (!nodeWalker->IsAlive)
		{
			deleteSprite(nodeWalker);
		}
		nodeWalker = nodeWalker->Next;
	}
}


void SpriteList::moveSprites(int action)
{
	Sprite^ nodeWalker = head;
	while (nodeWalker != nullptr)
	{

		nodeWalker->Move(action);
		nodeWalker = nodeWalker->Next;
	}
}

void SpriteList::drawSprites()
{
	Sprite^ nodeWalker = head;
	while (nodeWalker != nullptr)
	{

		nodeWalker->Draw();
		nodeWalker->UpdateFrame();
		nodeWalker = nodeWalker->Next;
	}
}

void SpriteList::hideSprites()
{
	Sprite^ nodeWalker = head;
	while (nodeWalker != nullptr)
	{
		nodeWalker->Erase();
		nodeWalker = nodeWalker->Next;
	}
}

Sprite^ SpriteList::checkCollisions(Sprite^ otherSprite)
{
	Sprite^ nodeWalker = head;
	Sprite^ temp;
	bool checkOtherGuy;
	while (nodeWalker != nullptr)
	{
		if (!nodeWalker->stop)
		{
			checkOtherGuy = nodeWalker->CollidedWithMe(otherSprite);
			if (checkOtherGuy)
			{
				return nodeWalker;
			}
		}		
		nodeWalker = nodeWalker->Next;
	}
	return nullptr;
}

