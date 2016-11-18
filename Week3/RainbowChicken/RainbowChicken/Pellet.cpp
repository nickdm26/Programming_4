/*
Nick Muldrew
Programming 4
August 4 2016
The Pellet class is an little ball which is fired from the chicken. It has methods to draw itself to the screen as well as move and erase itself.
*/

#include "Pellet.h"

/*
	The Pellet constructer sets the various variables such as the lacation, Graphics canvas and the Random number generator.
	It uses rGen to select a random color for the brush.
	The brush is then used to choose the color of the Ellipse to be drawn to the screen.
*/
Pellet::Pellet(int startXPos, int startYPos, Graphics^ startCanvas, Random^ startRGen)
{
	xPos = startXPos;
	yPos = startYPos;
	canvas = startCanvas;
	rGen = startRGen;
	IsAlive = true;
	diameter = PELLET_DIAMETER;
	speed = rGen->Next(1, 4);
	brush = gcnew SolidBrush(Color::FromArgb(rGen->Next(0, 255), rGen->Next(0,255), rGen->Next(0,255)));
	brushBlack = gcnew SolidBrush(Color::Black);
}

/*
	The draw method is used to draw a Ellipse to the screen at the X and Y postion.
*/
	void Pellet::draw()	
	{
		canvas->FillEllipse(brush, xPos, yPos, 10, 10);
	}

	/*
		The move method is used to paint over the current pellet on the screen then paint a new one slighty above it.
		If the pellet go's above the top of the screen then it is no longer alive and sets boolean for that.
	*/
	void Pellet::move()
	{
		canvas->FillEllipse(brushBlack, xPos, yPos, diameter, diameter);
		yPos -= speed;
		canvas->FillEllipse(brush, xPos, yPos, diameter, diameter);
		if (yPos < 0)
		{
			IsAlive = false;
		}
	}

	/*
		The erase method tells the pellet class to delete itself from the canvas.
		It does this by painting over itself the same color as the background.
	*/
	void Pellet::erase()
	{
		canvas->FillEllipse(brushBlack, xPos, yPos, diameter, diameter);
	}

