#pragma once
#include "Sprite.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO;

public enum EnemyTypes { SuperEnemy, StrongEnemy, TankyEnemy };

ref class Enemy :public Sprite
{
public:
	int EnemyType;

	Enemy(Graphics^ startCanvas, array<String^>^ startSpriteSheet, int startNFrames, Random^ startRGen, Rectangle startBoundingRectangle, double reduction, TileMap^ startTileMap, int SpawnXPos, int SpawnYPos, int StartEnemyType);
	virtual void Move() override;
	virtual void Wander() override;
};

