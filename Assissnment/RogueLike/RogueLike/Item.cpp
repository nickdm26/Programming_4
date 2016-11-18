/*
Nick Muldrew
RougeLike Assignment
04/10/2016
*/
#include "Item.h"

/*
	Item inherits from Sprite.
	The Item Constructer sets all the various variables that will be necessary for the sprite to be used correctly.
*/
Item::Item(Graphics^ startCanvas, array<String^>^ startSpriteSheet, int startNFrames, Random^ startRGen, Rectangle startBoundingRectangle, double reduction, TileMap^ startTileMap, int SpawnXPos, int SpawnYPos, int StartItemType)
	:Sprite(startCanvas, startSpriteSheet, startNFrames, startRGen, startBoundingRectangle, reduction, startTileMap, SpawnXPos, SpawnYPos)
{
	canvas = startCanvas;
	nFrames = startNFrames;
	rGen = startRGen;
	boundingRectangle = startBoundingRectangle;
	imageReduction = reduction;
	myTileMap = startTileMap;
	xPos = SpawnXPos;
	yPos = SpawnYPos;
	ItemType = StartItemType;
	east = gcnew Bitmap(startSpriteSheet[ItemType]);

	direction = 0;
	xVel = 4;
	yVel = 4;
	currentFrames = 0;
	Health = 0;
	AttackDamage = 0;
	IsAlive = true;
	stop = false;
	IsAtEdge = false;

	spriteImages = gcnew array<Bitmap^>(1);
	spriteImages[SPRITE_EAST] = east;					//SpriteImages only take 1 Bitmap because its a EnemySprite.

	frameHeight = east->Height;
	frameWidth = (east->Width) / nFrames;

	left = xPos - (frameWidth * imageReduction);
	right = xPos + frameWidth - (frameWidth * imageReduction);
	top = yPos - (frameHeight * imageReduction);
	bottom = yPos + frameHeight - (frameHeight * imageReduction);

	Color transparentColor = spriteImages[0]->GetPixel(0, 0);				//Makes the OutSide of the image transparent.
	spriteImages[0]->MakeTransparent(transparentColor);


	if (ItemType == TREASURE)									//Depending upon what type The Item is then variables are set with diffrent values to make the Item unique.
	{
		Health = 0;
		AttackDamage = 0;
		Score = 1000;
	}
	else if (ItemType == ATTACKPOWER)
	{
		Health = 0;
		AttackDamage = 25;
	}
	else if (ItemType == MAXHEALTH)
	{
		Health = 500;
		AttackDamage = 0;
	}
	CurrentHealth = Health;
}
