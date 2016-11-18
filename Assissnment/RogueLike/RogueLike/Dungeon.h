#pragma once
#include "Tile.h"
#include "TileList.h"
#include "TileMap.h"
#include "Room.h"
#include "Cell.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO;

#define MINROOMS 10
#define MAXROOMS 20

//http://opengameart.org/content/base-character-spritesheet-16x16
//http://opengameart.org/content/sewer-tileset

ref class Dungeon
{
private:
	Graphics^ canvas;
	Random^ rGen;
	TileMap^ DungeonTileMap;
	array<Room^>^ DungeonRooms;
	array<Cell^, 2>^ PlaceHolderMap;
	int RoomNum;
	int Columns;
	int Rows;
	int LavaCount;
	Cell^ CellToChange;

public:
	Dungeon(Graphics^ StartCanvas, Random^ StartRGen, int startColumns, int startRows);
	void CreateDungeon();
	void CreateDungeonRooms();
	void AddCorridors();
	void CreateCorridor(Room^ Room1, Room^ Room2);
	void AddPortal();
	void DrawDungeon();
	void FillDungeon();
	bool DoesOverlap(Room^ RoomToCheck);
	TileMap^ StartTileMap();	
	void PlayerSight(int PlayerXPos, int PlayerYPos);

	array<Room^>^ getRooms() { return DungeonRooms; }
	TileMap^ GetDungeonTileMap() { return DungeonTileMap; }
	array<int>^ getTileDimensions();
};

