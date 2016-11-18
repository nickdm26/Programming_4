#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

ref class Sprite
{
private:
	Graphics^ canvas;
	Bitmap^ spriteSheet;
	Random^ rGen;
	int nFrames;
	int currentFrames;
	int xPos;
	int yPos;
	int frameWidth;
	int frameHeight;
	int xVel;
	int yVel;
	void initialise(Graphics^ startCanvas, Bitmap^ startSpriteSheet, int startNFrames, Random^ startRGen);

public:
	Sprite^ Next;
	Sprite(Graphics^ startCanvas, Bitmap^ startSpriteSheet, int startNFrames, Random^ startRGen);
	Sprite(Graphics^ startCanvas, Bitmap^ startSpriteSheet, int startNFrames, Random^ startRGen, int cf);
	void Draw();
	void Erase();
	void Move();
	void UpdateFrame();
	void SetSpriteSheet(Bitmap^ newSpriteSheet, int newNFrames);
	void Wander();
	

};

