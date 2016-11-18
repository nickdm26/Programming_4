#pragma once

#define EAST 0
#define SOUTH 1
#define WEST 2
#define NORTH 3
#define STOP 4

using namespace System;
using namespace System::ComponentModel;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

ref class KnightSprite
{
private:
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
	Bitmap^ east;
	Bitmap^ south;
	Bitmap^ west;
	Bitmap^ north;
	array<Bitmap^>^ knightImages;
	array<Point^>^ velocityDirections;
	Graphics^ canvas;
	Random^ rGen;
	int left;
	int right;
	int top;
	int bottom;


public:
	KnightSprite(Graphics^ startCanvas, array<String^>^ startSpriteSheet, int startNFrames, Random^ rGen);
	void Draw();
	void Erase();
	void Move();
	void UpdateFrame();
	void SpriteDirection(int spDirection);

};

