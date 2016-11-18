/*
Nicholas Muldrew
*/

#include "Chicken.h"


Chicken::Chicken(Graphics^ startCanvas, array<String^>^ startSpriteSheet, int startNFrames, Random^ startRGen)
{
	rGen = startRGen;
	directions = 4;
	direction = rGen->Next(0, 4);

	
	xVel = 4;
	yVel = 4;

	east = gcnew Bitmap(startSpriteSheet[0]);
	south = gcnew Bitmap(startSpriteSheet[1]);
	west = gcnew Bitmap(startSpriteSheet[2]);
	north = gcnew Bitmap(startSpriteSheet[3]);

	chickenImages = gcnew array<Bitmap^>(directions);
	chickenImages[CHICKEN_EAST] = east;
	chickenImages[CHICKEN_SOUTH] = south;
	chickenImages[CHICKEN_WEST] = west;
	chickenImages[CHICKEN_NORTH] = north;

	velocityDirections = gcnew array<Point^>(directions);
	velocityDirections[CHICKEN_EAST] = Point(1, 0);
	velocityDirections[CHICKEN_SOUTH] = Point(0, 1);
	velocityDirections[CHICKEN_WEST] = Point(-1, 0);
	velocityDirections[CHICKEN_NORTH] = Point(0, -1);

	canvas = startCanvas;
	nFrames = startNFrames;
	currentFrames = 0;
	
	frameHeight = east->Height;
	frameWidth = (east->Width) / nFrames;
	
	xPos = rGen->Next(0, 980);
	yPos = rGen->Next(0, 700);
	xVel *= velocityDirections[direction]->X;
	yVel *= velocityDirections[direction]->Y;

	for (int i = 0; i < directions; i++)
	{
		Color transparentColor = chickenImages[i]->GetPixel(0, 0);
		chickenImages[i]->MakeTransparent(transparentColor);
	}
}

void Chicken::Draw()
{
	int startX = currentFrames * frameWidth;
	int startY = 0;

	Rectangle pixelToDraw = Rectangle(startX, startY, frameWidth, frameHeight);
	Bitmap^ currentBitmap = chickenImages[direction];
	canvas->DrawImage(currentBitmap, xPos, yPos, pixelToDraw, GraphicsUnit::Pixel);
}

void Chicken::Erase()
{

}

void Chicken::Move()
{
	if (xPos <= 0)
	{
		xVel = xVel * -1;
		direction = CHICKEN_EAST;
	}

	if (xPos >= 980)
	{
		xVel = xVel * -1;
		direction = CHICKEN_WEST;
	}

	if (yPos <= 0)
	{
		yVel = yVel * -1;
		direction = CHICKEN_SOUTH;
	}

	if (yPos >= 700)
	{
		yVel = yVel * -1;
		direction = CHICKEN_NORTH;
	}
	xPos += xVel;
	yPos += yVel;
}

void Chicken::UpdateFrame()
{
	currentFrames = (currentFrames + 1) % nFrames;
}
