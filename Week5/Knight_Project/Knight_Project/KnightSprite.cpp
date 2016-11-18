/*
Nicholas Muldrew
*/

#include "KnightSprite.h"

KnightSprite::KnightSprite(Graphics^ startCanvas, array<String^>^ startSpriteSheet, int startNFrames, Random^ startRGen)
{
	directions = 4;
	direction = EAST;
	east = gcnew Bitmap(startSpriteSheet[0]);
	south = gcnew Bitmap(startSpriteSheet[1]);
	west = gcnew Bitmap(startSpriteSheet[2]);
	north = gcnew Bitmap(startSpriteSheet[3]);

	knightImages = gcnew array<Bitmap^> (directions);
	knightImages[EAST] = east;
	knightImages[SOUTH] = south;
	knightImages[WEST] = west;
	knightImages[NORTH] = north;

	velocityDirections = gcnew array<Point^> (directions);
	velocityDirections[EAST] = Point(1, 0);
	velocityDirections[SOUTH] = Point(0, 1);
	velocityDirections[WEST] = Point(-1, 0);
	velocityDirections[NORTH] = Point(0, -1);

	canvas = startCanvas;
	nFrames = startNFrames;
	rGen = startRGen;
	frameHeight = east->Height;
	frameWidth = (east->Width) / nFrames;
	xVel = 7;
	yVel = 7;
	xPos = rGen->Next(0, 950);
	yPos = rGen->Next(0, 700);

	for (int i = 0; i < directions; i++)
	{
		Color transparentColor = knightImages[i]->GetPixel(0, 0);
		knightImages[i]->MakeTransparent(transparentColor);
	}
}

void KnightSprite::Draw()
{
	int startX = currentFrames * frameWidth;
	int startY = 0;

	Rectangle pixelToDraw = Rectangle(startX, startY, frameWidth, frameHeight);
	Bitmap^ currentBitmap = knightImages[direction];
	canvas->DrawImage(currentBitmap, xPos, yPos, pixelToDraw, GraphicsUnit::Pixel);
}

void KnightSprite::Erase()
{
	
}

void KnightSprite::Move()
{
	xPos += xVel * velocityDirections[direction]->X;
	yPos += yVel * velocityDirections[direction]->Y;
}

void KnightSprite::UpdateFrame()
{
	currentFrames = (currentFrames + 1) % nFrames;
}

void KnightSprite::SpriteDirection(int newspDirection)
{
	direction = newspDirection;
}