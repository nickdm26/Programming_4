/*
Nick Muldrew
RougeLike Assignment
04/10/2016
*/

#include "Sprite.h"

/*
	The Sprite Constructer sets all the various variables that will be necessary for the sprite to be used correctly.
*/
Sprite::Sprite(Graphics^ startCanvas, array<String^>^ startSpriteSheet, int startNFrames, Random^ startRGen, Rectangle startBoundingRectangle, double reduction, TileMap^ startTileMap, int SpawnXPos, int SpawnYPos)
{
	canvas = startCanvas;
	east = gcnew Bitmap(startSpriteSheet[0]);
	nFrames = startNFrames;
	rGen = startRGen;
	boundingRectangle = startBoundingRectangle;
	imageReduction = reduction;
	myTileMap = startTileMap;
	xPos = SpawnXPos;
	yPos = SpawnYPos;	

	direction = 0;
	xVel = 4;
	yVel = 4;
	currentFrames = 0;
	Health = 300;
	CurrentHealth = Health;
	AttackDamage = 30;
	Score = 150;
	IsAlive = true;
	stop = false;
	IsAtEdge = false;	

	spriteImages = gcnew array<Bitmap^>(1);
	spriteImages[SPRITE_EAST] = east;

	frameHeight = east->Height;
	frameWidth = (east->Width) / nFrames;

	left = xPos - (frameWidth * imageReduction);
	right = xPos + frameWidth - (frameWidth * imageReduction);
	top = yPos - (frameHeight * imageReduction);
	bottom = yPos + frameHeight - (frameHeight * imageReduction);

	Color transparentColor = spriteImages[0]->GetPixel(0, 0);
	spriteImages[0]->MakeTransparent(transparentColor);
}

/*
	Draw is used to draw The Sprite itself to the canvas unless the tile it is on is covered in fog.
*/
void Sprite::Draw()
{
	int startX = currentFrames * frameWidth;
	int startY = 0;

	Rectangle pixelToDraw = Rectangle(startX, startY, frameWidth, frameHeight);
   	Bitmap^ currentBitmap = spriteImages[direction];
	array<int>^ postion = myTileMap->CalculatePostion(xPos, yPos);					//Checks if the Current Tile it is on is covered in fog
	bool TileFog = myTileMap->IsTileFog(postion[0], postion[1]);					//If the Tile is covered in fog then the sprite will not draw itself.
	if (!TileFog)
	{
		canvas->DrawImage(currentBitmap, xPos, yPos, pixelToDraw, GraphicsUnit::Pixel);
	}	
}

/*
	CollidedWithMe takes in another Sprite and returns a boolean representing if the otherSprite is overlapping with it.
*/
bool Sprite::CollidedWithMe(Sprite^ otherSprite)
{
	bool Collided = true;

	if (bottom < otherSprite->top)
	{
		Collided = false;
	}
	if (top > otherSprite->bottom)
	{
		Collided = false;
	}
	if (right < otherSprite->left)
	{
		Collided = false;
	}
	if (left > otherSprite->right)
	{
		Collided = false;
	}
	return Collided;
}

/*
	Move is the Parent Method that is later overridden by the child class.
*/
void Sprite::Move()
{
}

/*
	Wander Is the Parent method that is later overridden by the child class. 
*/
void Sprite::Wander()
{
}

/*
	UpdateFrame is used to increment the CurrentFrame by 1 and start back at 0 when it reaches the end.
	This method will stop working if the stop boolean is true.
*/
void Sprite::UpdateFrame()
{
	if (!stop)
	{
		currentFrames = (currentFrames + 1) % nFrames;
	}
}

/*
	AtBounds is used to set a boolean which represents wheather a Sprite is at its bounds.
	Takes the temporary X and Y Postions to work out if it will reach its bounds.
*/
void Sprite::AtBounds(int TempXPos, int TempYPos)
{
	IsAtEdge = false;
	if (TempXPos < boundingRectangle.Left)
	{
		IsAtEdge = true;
	}

	if ((TempXPos + frameWidth) > boundingRectangle.Right)
	{
		IsAtEdge = true;
	}

	if (TempYPos < boundingRectangle.Top)
	{
		IsAtEdge = true;
	}

	if ((TempYPos + frameHeight) > boundingRectangle.Bottom)
	{
		IsAtEdge = true;
	}
}

/*
	SpriteDirection is used to set the direction that the sprite should now be facing.
*/
void Sprite::SpriteDirection(int newspDirection)
{
	direction = newspDirection;
}

/*
	StopSprite is used to stop the sprites animation and to tell it that its dead.
*/
void Sprite::StopSprite()
{
	stop = true;
	IsAlive = false;
}