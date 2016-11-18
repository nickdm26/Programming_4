#include "Approacher.h"


Approacher::Approacher(Graphics^ startCanvas, Bitmap^ startSpriteSheet, int startNFrames, Random^ startRGen,
	int startSpeed, Rectangle startTerritory) :SimpleSprite(startCanvas, startSpriteSheet, startNFrames, startRGen, startSpeed, startTerritory)
{

}

void Approacher::orient(SimpleSprite^ target)
{	
	int tarX = target->getXPos();
	int tarY = target->getYPos();
	int xDelta = tarX - xPos;
	int yDelta = tarY - yPos;

	double angle = computeAngleToTarget(target);

	xVel = (int)(Math::Cos(angle) * speed);
	yVel = (int)(Math::Sin(angle) * speed);
}