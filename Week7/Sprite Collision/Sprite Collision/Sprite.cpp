/*
Nicholas Muldrew
*/

#include "Sprite.h"


Sprite::Sprite(Graphics^ startCanvas, array<String^>^ startSpriteSheet, int startNFrames, Random^ startRGen, Rectangle startBoundingRectangle, double reduction)
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

	spriteImages = gcnew array<Bitmap^>(directions);
	spriteImages[SPRITE_EAST] = east;
	spriteImages[SPRITE_SOUTH] = south;
	spriteImages[SPRITE_WEST] = west;
	spriteImages[SPRITE_NORTH] = north;

	velocityDirections = gcnew array<Point^>(directions);
	velocityDirections[SPRITE_EAST] = Point(4, 0);
	velocityDirections[SPRITE_SOUTH] = Point(0, 4);
	velocityDirections[SPRITE_WEST] = Point(-4, 0);
	velocityDirections[SPRITE_NORTH] = Point(0, -4);

	canvas = startCanvas;
	nFrames = startNFrames;
	currentFrames = 0;
	boundingRectangle = startBoundingRectangle;
	IsAlive = true;

	frameHeight = east->Height;
	frameWidth = (east->Width) / nFrames;

	imageReduction = reduction;
	left = xPos - (frameWidth * imageReduction);
	right = xPos + frameWidth - (frameWidth * imageReduction);
	top = yPos - (frameHeight * imageReduction);
	bottom = yPos + frameHeight - (frameHeight * imageReduction);

	
	xPos = rGen->Next(0, boundingRectangle.Right);
	yPos = rGen->Next(0, boundingRectangle.Bottom);
	xVel *= velocityDirections[direction]->X;
	yVel *= velocityDirections[direction]->Y;
	stop = false;

	for (int i = 0; i < directions; i++)
	{
		Color transparentColor = spriteImages[i]->GetPixel(0, 0);
		spriteImages[i]->MakeTransparent(transparentColor);
	}
}

void Sprite::Draw()
{
	int startX = currentFrames * frameWidth;
	int startY = 0;

	Rectangle pixelToDraw = Rectangle(startX, startY, frameWidth, frameHeight);
	Bitmap^ currentBitmap = spriteImages[direction];
	canvas->DrawImage(currentBitmap, xPos, yPos, pixelToDraw, GraphicsUnit::Pixel);
}

void Sprite::Erase()
{
	Brush^ mybrush = gcnew SolidBrush(Color::White);
	canvas->FillRectangle(mybrush, xPos, yPos, frameWidth, frameHeight);
}

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


void Sprite::Move(int action)
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

	left = xPos - (frameWidth * imageReduction);
	right = xPos + frameWidth - (frameWidth * imageReduction);
	top = yPos - (frameHeight * imageReduction);
	bottom = yPos + frameHeight - (frameHeight * imageReduction);

}

void Sprite::UpdateFrame()
{
	if (!stop)
	{
		currentFrames = (currentFrames + 1) % nFrames;
	}

}

void Sprite::Stop()
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

void Sprite::Die()
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

void Sprite::Wrap()
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

void Sprite::Bounce()
{
	if (xPos < boundingRectangle.Left)
	{
		//xVel = xVel * -1;
		direction = SPRITE_EAST;
	}

	if ((xPos + frameWidth) > boundingRectangle.Right)
	{
		//xVel = xVel * -1;
		direction = SPRITE_WEST;
	}

	if (yPos < boundingRectangle.Top)
	{
		//yVel = yVel * -1;
		direction = SPRITE_SOUTH;
	}

	if ((yPos + frameHeight) > boundingRectangle.Bottom)
	{
		//yVel = yVel * -1;
		direction = SPRITE_NORTH;
	}
}

void Sprite::SpriteDirection(int newspDirection)
{
	direction = newspDirection;
}

void Sprite::StopSprite()
{
	stop = true;
}