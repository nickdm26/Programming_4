/*
Nick Muldrew
RougeLike Assignment
04/10/2016
*/

#include "SpriteList.h"
#include "Sprite.h"

/*
	SpriteList does nothing when it is first instalised.
*/
SpriteList::SpriteList()
{
}

/*
	AddSprite is Used to add a sprite to a list so the Sprites can be kept track of.
*/
void SpriteList::addSprite(Sprite^ newSprite)
{
	if (tail == nullptr)
	{
		head = newSprite;		//If the List is empty then start it.
		tail = newSprite;
	}
	else
	{
		tail->Next = newSprite;		//The Last sprite in the List now points to the Sprite which was just added.
		tail = newSprite;			//The Sprite Which was just added is now the last in the List.
	}
}

/*
	DeleteSprite Is used to delete a Sprite from the List.
*/
void SpriteList::deleteSprite(Sprite^ SpriteDelete)
{
	if (head != nullptr)						//As long as the list contains Sprites.
	{
		Sprite^ nodeWalker = head;
		if (nodeWalker == SpriteDelete)			//If the Sprite to Delete is the first in the list
		{
			if (head->Next == nullptr)			//A special delete must be used if it deletes the only sprite in the list.
			{
				head = nullptr;
				tail = nullptr;
			}
			else
			{
				head = head->Next;				//Overrites the First Sprite in the List with the 2nd.
			}
		}
		else
		{
			while (nodeWalker->Next != SpriteDelete)	//Loop through the list till the sprite to delete is found.
			{
				nodeWalker = nodeWalker->Next;
			}
			Sprite^ deleteMe = nodeWalker->Next;
			nodeWalker->Next = deleteMe->Next;			//When it is found, The prevoius Sprite now points at the Sprite that the Sprite which is getting deleted points at.
		}
	}
}

/*
	DeleteSprites is used to delete all the sprites from the list.
*/
void SpriteList::deleteSprites()
{
	Sprite^ nodeWalker = head;
	while (nodeWalker != nullptr)			//Uses a while to loop through and call DeleteSprite on each Sprite in the list.
	{

		deleteSprite(nodeWalker);
		nodeWalker = nodeWalker->Next;
	}
}

/*
	DeleteAllDeadSprites is used to Delete all of the Sprites in the list that are not alive.
*/
void SpriteList::deleteAllDeadSprites()
{
	Sprite^ nodeWalker = head;
	while (nodeWalker != nullptr)
	{
		if (!nodeWalker->IsAlive)						//If the Sprite is not alive then it gets deleted.
		{
			deleteSprite(nodeWalker);
		}
		nodeWalker = nodeWalker->Next;
	}
}

/*
	WanderSprites is used to loop through the list of sprites and tell them to wander.
*/
void SpriteList::wanderSprites()
{
	Sprite^ nodeWalker = head;
	while (nodeWalker != nullptr)
	{
		nodeWalker->Wander();
		nodeWalker = nodeWalker->Next;
	}
}

/*
	UpdateSprites is used to loop through the list of sprites and tell them to update what frame they are on.
*/
void SpriteList::UpdateSprites()
{
	Sprite^ nodeWalker = head;
	while (nodeWalker != nullptr)
	{
		nodeWalker->UpdateFrame();
		nodeWalker = nodeWalker->Next;
	}
}

/*
	DrawSprites is used to loop through the list of Sprites and tell each of them to draw themselves to the canvas.
*/
void SpriteList::drawSprites()
{
	Sprite^ nodeWalker = head;
	while (nodeWalker != nullptr)
	{
		nodeWalker->Draw();
		nodeWalker = nodeWalker->Next;
	}
}

/*
	CheckCollisions is used to Loop through the list of sprites and tell them to check if they collide with the sprite being passed in.
	If One of the sprites does collide then it returns the first one it collides with.
	If it collides with none then it returns null.
*/
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

