/*
Nick Muldrew
RougeLike Assignment
04/10/2016
*/
#include "Room.h"

/*
	The Room Constructer instalises the variables which are passed into it.
*/
Room::Room(Random^ StartrGen, int startColoums, int startRows)
{
	rGen = StartrGen;
	Coloums = startColoums;
	Rows = startRows;
}

/*
	CreateRoom Is used to randomly create a Room and store it as a 2d array.
*/
void Room::CreateRoom()
{
	Height = rGen->Next(MinRoomHeight, MaxRoomHeight);		//Randomly picks a number between a Min and Max to represent a Height and Width.
	Width = rGen->Next(MinRoomWidth, MaxRoomWidth);			//^^^

	XPos = rGen->Next(Coloums - Width);						//Randomly selects a X and Y Postion which will fit within a Dungeon.
	YPos = rGen->Next(Rows - Height);

	RoomMap = gcnew array<Cell^, 2>(Width, Height);			//Creates a 2d array with the random Width and height.
		for (int i = 0; i < Width; i++)
	{
		for (int j = 0; j < Height; j++)					//Loops through the RoomMap array and sets the outide edges to be Wall tiles.
		{													//The insides are set to be a Floor Tile
			if (i == Width - 1 || i == 0){
				CellToAdd = gcnew Cell(WALL, true);
				RoomMap[i, j] = CellToAdd;
			}
			else if (j == Height - 1 || j == 0){
				CellToAdd = gcnew Cell(WALL, true);
				RoomMap[i, j] = CellToAdd;
			}
			else
			{
				CellToAdd = gcnew Cell(FLOOR, true);
				RoomMap[i, j] = CellToAdd;
			}
		}
	}
}

/*
	AddRoomToArray gets passed the PlaceHolder Map from the Dungeon class and The Room then adds itself into that array.
*/
void Room::AddRoomToArray(array<Cell^, 2>^ RoomPostion)
{
	for (int col = XPos; col < (XPos + Width); col++)
	{
		for (int row = YPos; row < (YPos + Height); row++)
		{
			RoomPostion[col, row] = RoomMap[col - XPos, row - YPos];
		}
	}
}

/*
	AddHoleToRoom randomly selects a X and Y postion to place a Portal at within the Room.
*/
void Room::AddHoleToRoom()
{
	int HoleXPos = rGen->Next( 1, (Width - 1));
	int HoleYPos = rGen->Next(1, (Height - 1));
	CellToAdd = gcnew Cell(HOLE, true);
	RoomMap[HoleXPos, HoleYPos] = CellToAdd;
}