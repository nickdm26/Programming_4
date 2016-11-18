#include "Creature.h"


Creature::Creature(Graphics^ startcanvas, Random^ startRandom, int startworldWidth, int startworldHeight, String^ imageFileName) :Thing(startcanvas, startRandom, startworldWidth, startworldHeight, imageFileName)
{

	

}

void Creature::UpdateState(array<Thing^>^ foodInWorld, array<Thing^>^ obstaclesInWorld)
{
	myFoodIndex = FindNearIndex(foodInWorld);
	switch (creatureState)
	{
	case WANDERING:
		
		if (myFoodIndex > 0)
		{
			creatureState = ECreatureState::EATING;
		} 
		else if (wanderingTicks > wanderingLimit)
		{
			creatureState = ECreatureState::ORIENTING;
		}
		break;
	case EATING:
		if (eatingTicks > eatingTime)
		{
			creatureState = ECreatureState::ORIENTING;
		}
		break;
	case ORIENTING:
		creatureState = ECreatureState::WANDERING;

		break;
	default:
		break;
	}
}

void Creature::PerformAction(array<Thing^>^ foodInWorld, array<Thing^>^ obstaclesInWorld)
{
	
	switch (creatureState)
	{
	case WANDERING:
		Move();
		wanderingTicks++;
		eatingTicks = 0;
		break;

	case EATING:
		if (eatingTicks > eatingTime - 1){
			radius += 5;
			foodInWorld[myFoodIndex]->SetIsAlive(false);
		}
		eatingTicks++;
		wanderingTicks = 0;

		break;

	case ORIENTING:
		ChangeRandomdirection();
		wanderingTicks = 0;
		eatingTicks = 0;
		break;

	default:
		break;
	}
	Draw();
	
}

int Creature::FindNearIndex(array<Thing^>^ otherGuys)
{
	double distance = 50;
	bool alive = true;

	for (int i = 0; i < otherGuys->Length; i++)
	{
		distance = ComputeDistance(otherGuys[i]);
		alive = otherGuys[i]->GetIsAlive();
		if (distance < 30 && alive)
		{
			return i;
		}
	}

	return -1;
}
