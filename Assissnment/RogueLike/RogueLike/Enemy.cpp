/*
Nick Muldrew
RougeLike Assignment
04/10/2016
*/
#include "Enemy.h"

/*
	Enemy inherits from Sprite. 
	The Enemy Constructer sets all the various variables that will be necessary for the sprite to be used correctly.
*/
Enemy::Enemy(Graphics^ startCanvas, array<String^>^ startSpriteSheet, int startNFrames, Random^ startRGen, Rectangle startBoundingRectangle, double reduction, TileMap^ startTileMap, int SpawnXPos, int SpawnYPos, int StartEnemyType)
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
	EnemyType = StartEnemyType;
	east = gcnew Bitmap(startSpriteSheet[EnemyType]);
	
	direction = 0;
	xVel = 2 ;
	yVel = 2;
	currentFrames = 0;
	IsAlive = true;
	stop = false;
	IsAtEdge = false;	
	
	spriteImages = gcnew array<Bitmap^>(1);
	spriteImages[SPRITE_EAST] = east;				//SpriteImages only take 1 Bitmap because its a EnemySprite.

	frameHeight = east->Height;
	frameWidth = (east->Width) / nFrames;
	
	left = xPos - (frameWidth * imageReduction);
	right = xPos + frameWidth - (frameWidth * imageReduction);
	top = yPos - (frameHeight * imageReduction);
	bottom = yPos + frameHeight - (frameHeight * imageReduction);	
	
	Color transparentColor = spriteImages[0]->GetPixel(0, 0);		//Makes the OutSide of the image transparent.
	spriteImages[0]->MakeTransparent(transparentColor);	

	if (EnemyType == SuperEnemy)					//Depending upon what type The enmey is then variables are set with diffrent values to make the enemy types unique.
	{
		xVel = 4;
		yVel = 4;
		AttackDamage = 50;
		Health = 600;
	}
	else if (EnemyType == StrongEnemy)
	{
		AttackDamage = 50;
	}
	else if (EnemyType == TankyEnemy)
	{
		Health = 600;		
	}
	CurrentHealth = Health;
}

/*
	Wander Overrides its parents Wander method.
	It randomly selects a direction to move the sprite in.
*/
void Enemy::Wander()
{
	int WanderProb = 5;
	if (rGen->Next(WanderProb) == 0)
	{
		xVel *= -1;
	}
	if (rGen->Next(WanderProb) == 0)
	{
		yVel *= -1;
	}

	Move();
}

/*
	Move Overrides its parent Move method.
	Moves the EnemySprite as long its not at its bounds and on a walkable tile.
*/
void Enemy::Move()
{
	int tempXPos = xPos;
	int tempYPos = yPos;
	tempXPos += xVel;
	tempYPos += yVel;

	array<int>^ postion;

	if (xVel > 0 && yVel > 0)
	{
		postion = myTileMap->CalculatePostion(tempXPos + frameWidth, tempYPos + frameHeight);
	}
	else if (xVel > 0)
	{
		postion = myTileMap->CalculatePostion(tempXPos + frameWidth, tempYPos);
	}
	else if (yVel > 0)
	{
		postion = myTileMap->CalculatePostion(tempXPos, tempYPos + frameHeight);
	}	
	else
	{
		postion = myTileMap->CalculatePostion(tempXPos, tempYPos);
	}
	
	bool IsTileWalkable = myTileMap->GetMapWalkAble(postion[0], postion[1]);		//Holds a bool representing if the tile its going to move onto is walkable.
	
	AtBounds(tempXPos, tempYPos);
	if (!IsAtEdge && IsTileWalkable)
	{
		xPos += xVel;							//Moves the Sprite if the tile its going to move onto is walkable and within the bounds.
		yPos += yVel;
	}

	left = xPos - (frameWidth * imageReduction);
	right = xPos + frameWidth - (frameWidth * imageReduction);
	top = yPos - (frameHeight * imageReduction);
	bottom = yPos + frameHeight - (frameHeight * imageReduction);
}


