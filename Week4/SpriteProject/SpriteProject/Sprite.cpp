#include "Sprite.h"


Sprite::Sprite(Graphics^ startCanvas, Bitmap^ startSpriteSheet, int startNFrames, Random^ startRGen)
{
	canvas = startCanvas;
	spriteSheet = startSpriteSheet;
	nFrames = startNFrames;
	currentFrames = 0;
	rGen = startRGen;
	frameHeight = spriteSheet->Height;
	frameWidth = (spriteSheet->Width) / nFrames;
	xVel = 2;
	yVel = 2;
	xPos = rGen->Next(0, 950);
	yPos = rGen->Next(0, 700);	
}

Sprite::Sprite(Graphics^ startCanvas, Bitmap^ startSpriteSheet, int startNFrames, Random^ startRGen, int newCurrentFrame)
{
		initialise(startCanvas, startSpriteSheet, startNFrames, startRGen);
		currentFrames = newCurrentFrame;
}

void Sprite::initialise(Graphics^ startCanvas, Bitmap^ startSpriteSheet, int startNFrames, Random^ startRGen)
{
	canvas = startCanvas;
	spriteSheet = startSpriteSheet;
	nFrames = startNFrames;
	currentFrames = 0;
	rGen = startRGen;
	frameHeight = spriteSheet->Height;
	frameWidth = (spriteSheet->Width) / nFrames;
	xVel = 2;
	yVel = 2;
	xPos = rGen->Next(0, 950);
	yPos = rGen->Next(0, 700);
}

void Sprite::Draw()
{
		int startX = currentFrames * frameWidth;
		int startY = 0;

		Rectangle pixelToDraw = Rectangle(startX, startY, frameWidth, frameHeight);
		canvas->DrawImage(spriteSheet, xPos, yPos, pixelToDraw, GraphicsUnit::Pixel);
}

void Sprite::Erase()
{
	spriteSheet->MakeTransparent(spriteSheet->GetPixel(0, 0));
}

void Sprite::Move()
{
	if (xPos <= 0)
	{
		xVel = 2;
	}
		
	if (xPos >= 980)
	{
		xVel = -2;
	}
	
	if (yPos <= 0)
	{
		yVel = 2;
	}

	if (yPos >= 725)
	{
		yVel = -2;
	}
	xPos += xVel;
	yPos += yVel;
}

void Sprite::UpdateFrame()
{
	currentFrames = (currentFrames + 1) % nFrames;	
}

void Sprite::SetSpriteSheet(Bitmap^ newSpriteSheet, int newNFrames)
{
	spriteSheet = newSpriteSheet;
	nFrames = newNFrames;
	frameHeight = spriteSheet->Height;
	frameWidth = (spriteSheet->Width) / nFrames;
}

void Sprite::Wander()
{
	int rNum = rGen->Next(5);
	int rNum2 = rGen->Next(5);

	if (rNum < 1)
	{
		xVel = xVel * -1;
	}
	if (rNum2 < 1)
	{
		yVel = yVel * -1;
	}
}
