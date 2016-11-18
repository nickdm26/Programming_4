#pragma once

#include "SimpleSprite.h"

ref class Approacher :public SimpleSprite
{
public:
	Approacher(Graphics^ startCanvas, Bitmap^ startSpriteSheet, int startNFrames, Random^ startRGen,
		int startSpeed, Rectangle startTerritory);

	virtual void orient(SimpleSprite^ target) override;
};

