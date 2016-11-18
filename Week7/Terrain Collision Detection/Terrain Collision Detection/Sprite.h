#include "TileMap.h"
#include "TileList.h"
#include "Tile.h"

#pragma once

#define SPRITE_EAST 0
#define SPRITE_SOUTH 1
#define SPRITE_WEST 2
#define SPRITE_NORTH 3

#define EAST 0
#define SOUTH 1
#define WEST 2
#define NORTH 3

#define STOP 0
#define DIE 1
#define WRAP 2
#define BOUNCE 3

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO;

ref class Sprite
{
private:
	Graphics^ canvas;
	Bitmap^ spriteSheet;
	Random^ rGen;
	Bitmap^ east;
	Bitmap^ south;
	Bitmap^ west;
	Bitmap^ north;
	array<Bitmap^>^ spriteImages;
	array<Point^>^ velocityDirections;
	int nFrames;
	int currentFrames;
	int xPos;
	int yPos;
	int frameWidth;
	int frameHeight;
	int xVel;
	int yVel;
	int directions;
	int direction;
	double imageReduction;

	Rectangle boundingRectangle;
	int left;
	int right;
	int top;
	int bottom;
	bool IsAtEdge;
	TileMap^ myTileMap;


public:
	Sprite^ Next;
	bool stop;
	property bool IsAlive;
	Sprite(Graphics^ startCanvas, array<String^>^ startSpriteSheet, int startNFrames, Random^ startRGen, Rectangle startBoundingRectangle, double reduction, TileMap^ startTileMap);
	void Draw();
	void Erase();
	void Move(int action);
	void UpdateFrame();
	void Stop();
	void Die();
	void Wrap();
	void Bounce();
	bool CollidedWithMe(Sprite^ otherSprite);
	void SpriteDirection(int newspDirection);
	void StopSprite();
	void AtBounds();
};

