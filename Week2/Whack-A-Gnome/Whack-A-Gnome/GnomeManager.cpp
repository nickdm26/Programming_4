/*
	Nick Muldrew
	Programming 4
	July 31 2016
	The GnomeManager class is responsible for holding all of the gnomes
	Telling the gnomes to draw to the canvas, erasing themselves and changing them into hamsters.
*/

#include "GnomeManager.h"
#include "Gnome.h"

/*
	The GnomeManager Constructer takes a sets a Random object, The graphics canvas and the number of gnomes to be drawn
	It then creates an array and fills it up with gnome objects.
*/
GnomeManager::GnomeManager(Random^ startRandom, Graphics^ startCanvas, int startNGnomes)
{
	rGen = startRandom;
	canvas = startCanvas;
	gnomeNum = startNGnomes;
	gnomeArray = gcnew array<Gnome^>(gnomeNum);

	for (int i = 0; i < gnomeNum; i++)
	{
		int newX = rGen->Next(10, 938);
		int newY = rGen->Next(10, 538);
		gnomeArray[i] = gcnew Gnome(canvas, newX, newY);
	}
}

/*
	The drawAll method loops through all the gnomes and tells them to draw themselves.
*/
void GnomeManager::drawAll()
{
	for (int i = 0; i < gnomeNum; i++)
	{
		gnomeArray[i]->draw();
	}
}

/*
	The drawOne method takes a int representing the index for a gnome and then tells that gnome to draw itself.	
*/
void GnomeManager::drawOne(int gnomeIndex)
{
	gnomeArray[gnomeIndex]->draw();
}

/*
	The drawAllHamsters loops through the array of gnomes and tells them to draw all the hamsters.
*/
void GnomeManager::drawAllHamsters()
{
	for (int i = 0; i < gnomeNum; i++)
	{
		if (isAHamster(i))
		{
			gnomeArray[i]->draw();
		}		
	}
}

/*
	The eraseAll method tells loops through the array of gnomes and tells them all to erase themselves.
*/
void GnomeManager::eraseAll()
{
	for (int i = 0; i < gnomeNum; i++)
	{
		gnomeArray[i]->erase();
	}
}

/*
	The eraseOne method takes a int representing the index of a gnome and tells that gnome to erase itself.
*/
void GnomeManager::eraseOne(int gnomeIndex)
{
	gnomeArray[gnomeIndex]->erase();
}

/*
	The gnomeClicked method takes a index to check the gnome as well as the X and Y location of the mouse.
	If the mouse was within the correct cordinates then it changes the gnomes image to a hamster.
*/
void GnomeManager::gnomeClicked(int gnomeIndex, int x, int y){
	if (gnomeArray[gnomeIndex]->mouseOnGnome(x, y))
	{
		gnomeArray[gnomeIndex]->changeToHamster();
	}
}

/*
	The isAHamster method takes a int which is a index for the gnome array and then checks if that gnome is a hamster.
	Returns true or false depending upon if its a hamster or not.
*/
bool GnomeManager::isAHamster(int gnomeIndex)
{
	return gnomeArray[gnomeIndex]->getIsHamster();
}

/*
	The isAllHamster method loops through the array of gnomes and returns true or false depending if they are all hamsters.
*/
bool GnomeManager::isAllHamster()
{
	bool allHamsters = true;
	for (int i = 0; i < gnomeNum; i++)
	{
		if (!isAHamster(i))
		{
			allHamsters = false;
		}
	}
	return allHamsters;
}

/*
	The resetAll method is used to clear the screen and reset all the gnomes to new postions.
	It calls the eraseAll method then fills the gnomes Array up again with new postions.
*/
void GnomeManager::resetAll(){
	eraseAll();
	for (int i = 0; i < gnomeNum; i++)
	{
		int newX = rGen->Next(10, 900);
		int newY = rGen->Next(10, 500);
		gnomeArray[i] = gcnew Gnome(canvas, newX, newY);
	}
}

/*
	The hamstersHit method loops through the array of gnomes checking which are hamsters.
	It then returns the number which are hamsters.
*/
int GnomeManager::hamstersHit()
{
	int hamsters = 0;
	for (int i = 0; i < gnomeNum; i++)
	{
		if (isAHamster(i))
		{
			hamsters++;
		}
	}
	return hamsters;
}
