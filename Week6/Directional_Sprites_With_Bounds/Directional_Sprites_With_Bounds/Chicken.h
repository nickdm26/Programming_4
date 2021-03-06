#pragma once

#define CHICKEN_EAST 0
#define CHICKEN_SOUTH 1
#define CHICKEN_WEST 2
#define CHICKEN_NORTH 3

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

ref class Chicken
{
private:
	Graphics^ canvas;
	Bitmap^ spriteSheet;
	Random^ rGen;
	Bitmap^ east;
	Bitmap^ south;
	Bitmap^ west;
	Bitmap^ north;
	array<Bitmap^>^ chickenImages;
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
	bool stop;
	Rectangle boundingRectangle;


public:
	Chicken^ Next;
	property bool IsAlive;
	Chicken(Graphics^ startCanvas, array<String^>^ startSpriteSheet, int startNFrames, Random^ startRGen, Rectangle startBoundingRectangle);
	void Draw();
	void Erase();
	void Move(int action);
	void UpdateFrame();
	void Stop();
	void Die();
	void Wrap();
	void Bounce();
};

