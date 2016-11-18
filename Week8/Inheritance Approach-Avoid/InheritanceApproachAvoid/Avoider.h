#pragma once
#include "SimpleSprite.h"

ref class Avoider :public SimpleSprite
{
public:
	Avoider(Graphics^ startCanvas, Bitmap^ startSpriteSheet, int startNFrames, Random^ startRGen,
		int startSpeed, Rectangle startTerritory);

	virtual void orient(SimpleSprite^ target) override;
};

