#include "Avoider.h"


Avoider::Avoider(Graphics^ startCanvas, Bitmap^ startSpriteSheet, int startNFrames, Random^ startRGen,
	int startSpeed, Rectangle startTerritory) :SimpleSprite(startCanvas, startSpriteSheet, startNFrames, startRGen, startSpeed, startTerritory)
{
}

void Avoider::orient(SimpleSprite^ target)
{
	int tarX = target->getXPos();
	int tarY = target->getYPos();
	int xDelta = tarX - xPos;
	int yDelta = tarY - yPos;

	double angle = computeAngleToTarget(target);

	yVel = (int)((Math::Cos(angle) * speed) * -1);
	xVel = (int)((Math::Sin(angle) * speed) * -1);
}