/*
	Nick Muldrew
	Programming 4
	July 31 2016
	The Gnome class is responsible for drawing itself to the canvas, erasing it, deciding if it was clicked
	and various other methods.
*/

#include "Gnome.h"

/*
	The Gnome Constructer does the default operations to set up the Gnome object
*/
Gnome::Gnome(Graphics^ startCanvas, int StartXPostion, int startYPostion)
{
	canvas = startCanvas;
	XPostion = StartXPostion;
	YPostion = startYPostion;
	isHamster = false;
	gnomeImage = Image::FromFile("../Pictures/gnome.JPG");
	hamsterImage = Image::FromFile("../Pictures/hamster.JPG");
	drawImage = gnomeImage;
}

/*
	The draw method draws the image onto the canvas
*/
void Gnome::draw()
{
	canvas->DrawImage(drawImage, XPostion, YPostion);
}

/*
	The erase method paints over the image in the same color as the background so it cant be seen
*/
void Gnome::erase()
{
	Brush^ whiteBrush = gcnew SolidBrush(Color::White);
	canvas->FillRectangle(whiteBrush, XPostion, YPostion, 62, 62);
}

/*
	The mouseOnGnome method takes the X and Y location and returns true if it is 
	on the area of the image. Otherwise returns false.
*/
bool Gnome::mouseOnGnome(int x, int y)
{
	bool xInZone = false;
	bool yInZone = false;
	if (x > XPostion && x < (XPostion + 62))
	{
		xInZone = true;
	}
	if (y > YPostion && y < (YPostion + 62))
	{
		yInZone = true;
	}
	if (xInZone && yInZone)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*
	THe getIsHamster method returns the boolean variable isHamster
*/
bool Gnome::getIsHamster()
{
	return isHamster;
}

/*
	The setIsHamster method sets the boolean variable isHamster
*/
void Gnome::setIsHamster(bool i)
{
	isHamster = i;
}

/*
The changeToGnome method changes the image so a gnome is displayed on the screen.
*/
void Gnome::changeToGnome()
{
	drawImage = gnomeImage;
	isHamster = false;
}

/*
	The changeToHamster method changes the image so a hamster is displayed on the screen.
*/
void Gnome::changeToHamster()
{
	drawImage = hamsterImage;
	isHamster = true;
}



