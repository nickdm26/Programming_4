#pragma once

#include "Cell.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO;

#define MinRoomHeight 5
#define MaxRoomHeight 14
#define MinRoomWidth 5
#define MaxRoomWidth 14

ref class Room
{
private:
	Random^ rGen;
	int Height;
	int Width;
	int XPos;
	int YPos;
	int Coloums;
	int Rows;
	array<Cell^, 2>^ RoomMap;
	Cell^ CellToAdd;

public:
	Room(Random^ StartrGen, int startColoums, int startRows);
	void CreateRoom();
	void AddRoomToArray(array<Cell^, 2>^ RoomPostion);
	void AddHoleToRoom();

	int getHeight() { return Height; }
	int getWidth() { return Width; }
	int getXPos() { return XPos; }
	int getYPos() { return YPos; }
	array<Cell^, 2>^ getRoomArray() { return RoomMap; }	
};

