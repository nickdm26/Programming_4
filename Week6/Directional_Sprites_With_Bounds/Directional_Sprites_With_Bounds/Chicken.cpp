/*
Nicholas Muldrew
*/

#include "Chicken.h"


Chicken::Chicken(Graphics^ startCanvas, array<String^>^ startSpriteSheet, int startNFrames, Random^ startRGen, Rectangle startBoundingRectangle)
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
	velocityDirections[CHICKEN_EAST] = Point(4, 0);
	velocityDirections[CHICKEN_SOUTH] = Point(0, 4);
	velocityDirections[CHICKEN_WEST] = Point(-4, 0);
	velocityDirections[CHICKEN_NORTH] = Point(0, -4);

	canvas = startCanvas;
	nFrames = startNFrames;
	currentFrames = 0;
	boundingRectangle = startBoundingRectangle;
	IsAlive = true;

	frameHeight = east->Height;
	frameWidth = (east->Width) / nFrames;

	xPos = rGen->Next(0, boundingRectangle.Right);
	yPos = rGen->Next(0, boundingRectangle.Bottom);
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
	Brush^ mybrush = gcnew SolidBrush(Color::White);
	canvas->FillRectangle(mybrush, xPos, yPos, frameWidth, frameHeight);
}


void Chicken::Move(int action)
{
	switch (action)
	{
	case STOP:
		Stop();
		break;
	case DIE:
		Die();
		break;
	case WRAP:
		Wrap();
		break;
	case BOUNCE:
		Bounce();
		break;
	}
	if (!stop)
	{
		xPos += velocityDirections[direction]->X;
		yPos += velocityDirections[direction]->Y;
	}
	
}

void Chicken::UpdateFrame()
{
	if (!stop)
	{
		currentFrames = (currentFrames + 1) % nFrames;
	}
	
}

void Chicken::Stop()
{
	if (xPos < boundingRectangle.Left)
	{
		//xVel = 0;
		stop = true;
	}

	if ((xPos + frameWidth) > boundingRectangle.Right)
	{
		//xVel = 0;
		stop = true;
	}

	if (yPos < boundingRectangle.Top)
	{
		//yVel = 0;
		stop = true;
	}

	if ((yPos + frameHeight) > boundingRectangle.Bottom)
	{
		//yVel = 0;
		stop = true;
	}
}

void Chicken::Die()
{
	if (xPos < boundingRectangle.Left)
	{
		IsAlive = false;
	}

	if ((xPos + frameWidth) > boundingRectangle.Right)
	{
		IsAlive = false;
	}

	if (yPos < boundingRectangle.Top)
	{
		IsAlive = false;
	}

	if ((yPos + frameHeight) > boundingRectangle.Bottom)
	{
		IsAlive = false;
	}
}

void Chicken::Wrap()
{
	if (xPos < boundingRectangle.Left)
	{
		xPos = boundingRectangle.Right - frameWidth;
	}

	if ((xPos + frameWidth) > boundingRectangle.Right)
	{
		xPos = boundingRectangle.Left;
	}

	if (yPos < boundingRectangle.Top)
	{
		yPos = boundingRectangle.Bottom - frameHeight;
	}

	if ((yPos + frameHeight) > boundingRectangle.Bottom)
	{
		yPos = boundingRectangle.Top;
	}
}

void Chicken::Bounce()
{
	if (xPos < boundingRectangle.Left)
	{
		//xVel = xVel * -1;
		direction = CHICKEN_EAST;
	}

	if ((xPos + frameWidth) > boundingRectangle.Right)
	{
		//xVel = xVel * -1;
		direction = CHICKEN_WEST;
	}

	if (yPos < boundingRectangle.Top)
	{
		//yVel = yVel * -1;
		direction = CHICKEN_SOUTH;
	}

	if ((yPos + frameHeight) > boundingRectangle.Bottom)
	{
		//yVel = yVel * -1;
		direction = CHICKEN_NORTH;
	}
}