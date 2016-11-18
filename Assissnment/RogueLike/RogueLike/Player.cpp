/*
Nick Muldrew
RougeLike Assignment
04/10/2016
*/
#include "Player.h"

/*
	Player inherits from Sprite.
	The Player Constructer sets all the various variables that will be necessary for the sprite to be used correctly.
*/
Player::Player(Graphics^ startCanvas, array<String^>^ startSpriteSheet, int startNFrames, Random^ startRGen, Rectangle startBoundingRectangle, double reduction, TileMap^ startTileMap, int SpawnXPos, int SpawnYPos)
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
			
	directions = 4;
	xVel = 4;
	yVel = 4;
	currentFrames = 0;
	Health = 1000;
	CurrentHealth = Health;
	AttackDamage = 50;

	IsAlive = true;
	stop = false;
	IsAtEdge = false;
	OnPortal = false;
	direction = rGen->Next(0, 4);

	east = gcnew Bitmap(startSpriteSheet[0]);		//The PlayerSprite takes 4 diffrent bitmaps for its 4 diffrent directions.
	south = gcnew Bitmap(startSpriteSheet[1]);
	west = gcnew Bitmap(startSpriteSheet[2]);
	north = gcnew Bitmap(startSpriteSheet[3]);

	spriteImages = gcnew array<Bitmap^>(directions);
	spriteImages[SPRITE_EAST] = east;
	spriteImages[SPRITE_SOUTH] = south;
	spriteImages[SPRITE_WEST] = west;
	spriteImages[SPRITE_NORTH] = north;				//Sets each Bitmap to a direction.

	velocityDirections = gcnew array<Point^>(directions);
	velocityDirections[SPRITE_EAST] = Point(4, 0);
	velocityDirections[SPRITE_SOUTH] = Point(0, 4);	
	velocityDirections[SPRITE_WEST] = Point(-4, 0);
	velocityDirections[SPRITE_NORTH] = Point(0, -4);	

	xVel *= velocityDirections[direction]->X;
	yVel *= velocityDirections[direction]->Y;
	
	for (int i = 0; i < directions; i++)
	{
		Color transparentColor = spriteImages[i]->GetPixel(0, 0);		//Makes the OutSide of the Players images transparent.
		spriteImages[i]->MakeTransparent(transparentColor);
	}
}

/*
	Move Overrides its parent Move method.
	Calculates where the Player will next move to and checks that next location can be walked on.
	If it cant be walked on then the PlayerSprite does not move.
*/
void Player::Move()
{
	int tempXPos = xPos;
	int tempYPos = yPos;
	tempXPos += velocityDirections[direction]->X;
	tempYPos += velocityDirections[direction]->Y;
	
	switch (direction)									//The Temp X and Y Postions have to be modifded depending upon what direction its facing.
	{
	case SPRITE_NORTH:				
		tempXPos += (frameWidth / 2);
		break;
	case SPRITE_EAST:
		tempXPos += frameWidth;
		tempYPos += (frameHeight / 2);
		break;
	case SPRITE_SOUTH:
		tempXPos += (frameWidth / 2);
		tempYPos += frameHeight;
		break;
	case SPRITE_WEST:
		tempYPos += (frameHeight / 2);
		break;
	}

	array<int>^ postion = myTileMap->CalculatePostion(tempXPos, tempYPos);
	bool IsTileWalkable = myTileMap->GetMapWalkAble(postion[0], postion[1]);			//Holds a bool representing if the tile its going to move onto is walkable.
	OnPortal = myTileMap->GetMapPortal(postion[0], postion[1]);							//Holds a bool representing if the tile its going to move onto is a portal.

	if (IsTileWalkable)																	//If the next tile is walkable then the playerSprite moves.
	{
		xPos += velocityDirections[direction]->X;
		yPos += velocityDirections[direction]->Y;
	}
	
	left = xPos - (frameWidth * imageReduction);
	right = xPos + frameWidth - (frameWidth * imageReduction);
	top = yPos - (frameHeight * imageReduction);
	bottom = yPos + frameHeight - (frameHeight * imageReduction);
}
