#include "SpriteList.h"


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
				//SpriteDelete->Erase(Color Black);
			}
			else
			{
				head = head->Next;
				//SpriteDelete->Erase();
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

void SpriteList::moveSprites()
{
	Sprite^ nodeWalker = head;
	while (nodeWalker != nullptr)
	{
		
		nodeWalker->Erase();
		nodeWalker->Wander();
		nodeWalker->Move();
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

