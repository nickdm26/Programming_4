#pragma once
#include "TileMap.h"
#include "TileList.h"
#include "Tile.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO;

#define SPRITE_EAST 0
#define SPRITE_SOUTH 1
#define SPRITE_WEST 2
#define SPRITE_NORTH 3

#define EAST 0
#define SOUTH 1
#define WEST 2
#define NORTH 3

ref class Sprite
{
protected:
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
	int Health;
	int CurrentHealth;
	int AttackDamage;
	int Score;

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
	Sprite(Graphics^ startCanvas, array<String^>^ startSpriteSheet, int startNFrames, Random^ startRGen, Rectangle startBoundingRectangle, double reduction, TileMap^ startTileMap, int SpawnXPos, int SpawnYPos);
	void Draw();
	virtual void Move();
	virtual void Wander();
	void UpdateFrame();
	bool CollidedWithMe(Sprite^ otherSprite);
	void SpriteDirection(int newspDirection);
	void StopSprite();
	void AtBounds(int TempXPos, int TempYPos);

	int GetHealth() { return Health; }
	int GetCurrentHealth() { return CurrentHealth; }
	int GetAttackDamage() { return AttackDamage; }
	int GetScore() { return Score; }
	void SetHealth(int StHealth) { Health = StHealth; }
	void SetCurrentHealth(int StCurrentHealth) { CurrentHealth = StCurrentHealth; }
	void SetAttackDamage(int StDamage) { AttackDamage = StDamage; }
	int GetXPos() { return xPos; }
	int GetYPos() { return yPos; }
	
};

