/*
Nick Muldrew
RougeLike Assignment
04/10/2016
*/

#include "Dungeon.h"

/*
	The Dungeon Constructer Instalises the Variables that it needs when created.
*/
Dungeon::Dungeon(Graphics^ StartCanvas, Random^ StartRGen, int startColumns, int startRows)
{
	canvas = StartCanvas;
	Columns = startColumns;
	Rows = startRows;
	rGen = StartRGen;
}

/*
	CreateDungeon is called when a new Dungeon is needed.
	It randomly chooses a amount of rooms to be created and creates a array of Rooms to be held for later use.
	Other Methods are then called to complete the creation of the dungeon.
*/
void Dungeon::CreateDungeon()
{
	LavaCount = 0;
	RoomNum = rGen->Next(MINROOMS, MAXROOMS);	
	PlaceHolderMap = gcnew array<Cell^, 2>(Columns, Rows);
	for (int col = 0; col < Columns; col++)
	{																
		for (int row = 0; row < Rows; row++)
		{																
			CellToChange = gcnew Cell(LAVA, true);
			PlaceHolderMap[col, row] = CellToChange;
		}
	}


	DungeonRooms = gcnew array<Room^>(RoomNum);

	CreateDungeonRooms();  
	AddPortal();
	AddCorridors();
	FillDungeon();
}

/*
	CreateDungeonRooms is used to fill up the array of rooms.
	It then places those rooms into the PlaceHolderMap.
	Only creates a room if it does not overlap with other rooms.
*/
void Dungeon::CreateDungeonRooms()
{
	for (int i = 0; i < RoomNum; i++)
	{
		DungeonRooms[i] = gcnew Room(rGen, Columns, Rows);			//Instalises each room in the DuneonRooms array.
	}

	DungeonRooms[0]->CreateRoom();									//Creates the first room and adds it to the PlaceHolderMap
	DungeonRooms[0]->AddRoomToArray(PlaceHolderMap);				//^^^

	for (int k = 1; k < RoomNum; k++)
	{
		bool overlap = false;
		while (!overlap)											//Each room is only created if it does not overlap with the others.
		{
			DungeonRooms[k]->CreateRoom();							//Creates each room
			overlap = DoesOverlap(DungeonRooms[k]);					//Checks if the room overlaps with the other rooms.
		}
		DungeonRooms[k]->AddRoomToArray(PlaceHolderMap);			//When the room does not overlap then it is added to the PlaceHolderMap for later mapulation.
	}
}

/*
	DoesOverlap is called to check if the room passed in is going to overlap with the other rooms.
	returns a boolean representing if the room overlaps or not.
*/
bool Dungeon::DoesOverlap(Room^ RoomToCheck)
{
	int RmX = RoomToCheck->getXPos();
	int RmY = RoomToCheck->getYPos();
	int RmHeight = RoomToCheck->getHeight();
	int RmWidth = RoomToCheck->getWidth();
	bool isTrue = true;
	
	for (int colCheck = RmX; colCheck < RmX + RmWidth; colCheck++)			//vvv
	{																		//vvv
		for (int rowCheck = RmY; rowCheck < RmY + RmHeight; rowCheck++)		//Loops through the PlaceHolderMap to check that each postion the RoomToCheck would take is empty.
		{																	//If its not empty then it returns false.
			if (PlaceHolderMap[colCheck, rowCheck]->GetTileIndex() != 0)
			{
				isTrue = false;
			}
		}
	}
	return isTrue;
}

/*
	AddPortal is called to add a portal to one of the random rooms.
*/
void Dungeon::AddPortal()
{
	int RoomWithHole = rGen->Next(RoomNum);
	DungeonRooms[RoomWithHole]->AddHoleToRoom();				//Tells the Random room to add a portal
	DungeonRooms[RoomWithHole]->AddRoomToArray(PlaceHolderMap); //The Room with a new portal is then added back to the PlacHolderMap
}

/*
	AddCorridors is called to add corridors between the rooms to the PlaceHolderMap.
	Loops through the Rooms and CreateCorridor is called to create a room between to rooms.
*/
void Dungeon::AddCorridors()
{
	for (int i = 1; i < RoomNum; i++)
	{
		CreateCorridor(DungeonRooms[i - 1], DungeonRooms[i]);
	}
}

/*
	CreateCorridor is Called to add a Corridor between 2 rooms to the PlaceHolderMap.
	The Corridor is created in 2 parts a X section and a Y Section.
*/
void Dungeon::CreateCorridor(Room^ Room1, Room^ Room2)
{
	int Room1CenterX = Room1->getXPos() + (Room1->getWidth() / 2);			//vvv
	int Room1CenterY = Room1->getYPos() + (Room1->getHeight() / 2);			//vvv
	int Room2CenterX = Room2->getXPos() + (Room2->getWidth() / 2);			//Calculates the Center X and Y point of both rooms.
	int Room2CenterY = Room2->getYPos() + (Room2->getHeight() / 2);			//^^^

	if (Room1CenterX < Room2CenterX)											//When creating the X section.
	{																			//If Room 1 is futher to the left then the for loop starts at room 1s center and ends at room 2s center.
		for (int colCheck = Room1CenterX; colCheck <= Room2CenterX; colCheck++)
		{
			if (PlaceHolderMap[colCheck, Room1CenterY]->GetTileIndex() == FLOOR)
			{
				PlaceHolderMap[colCheck, Room1CenterY]->SetTileIndex(FLOOR);
			}
			else if (PlaceHolderMap[colCheck, Room1CenterY]->GetTileIndex() == DOOR)
			{
				PlaceHolderMap[colCheck, Room1CenterY]->SetTileIndex(DOOR);
			}
			else if (PlaceHolderMap[colCheck, Room1CenterY]->GetTileIndex() == WALL)			//If a Wall is encounterd then replace it with a door otherwise the tiles stay the same.
			{
				PlaceHolderMap[colCheck, Room1CenterY]->SetTileIndex(DOOR);
			}
			else if (PlaceHolderMap[colCheck, Room1CenterY]->GetTileIndex() == HOLE)
			{
				PlaceHolderMap[colCheck, Room1CenterY]->SetTileIndex(HOLE);
			}
			else{
				PlaceHolderMap[colCheck, Room1CenterY]->SetTileIndex(CORRIDOR);				//If none of these tiles are encountered then change the tile to a Corridor.
			}
		}
	}
	else
	{																			//If Room 2 is futher to the left then the for loop starts at room 2s center and ends at room 1s center.
		for (int colCheck = Room2CenterX; colCheck <= Room1CenterX; colCheck++)
		{
			if (PlaceHolderMap[colCheck, Room1CenterY]->GetTileIndex() == FLOOR)
			{
				PlaceHolderMap[colCheck, Room1CenterY]->SetTileIndex(FLOOR);
			}
			else if (PlaceHolderMap[colCheck, Room1CenterY]->GetTileIndex() == DOOR)
			{
				PlaceHolderMap[colCheck, Room1CenterY]->SetTileIndex(DOOR);
			}
			else if (PlaceHolderMap[colCheck, Room1CenterY]->GetTileIndex() == WALL)			//If a Wall is encounterd then replace it with a door otherwise the tiles stay the same.
			{
				PlaceHolderMap[colCheck, Room1CenterY]->SetTileIndex(DOOR);
			}
			else if (PlaceHolderMap[colCheck, Room1CenterY]->GetTileIndex() == HOLE)
			{
				PlaceHolderMap[colCheck, Room1CenterY]->SetTileIndex(HOLE);
			}
			else{
				PlaceHolderMap[colCheck, Room1CenterY]->SetTileIndex(CORRIDOR);				//If none of these tiles are encountered then change the tile to a Corridor.
			}
		}
	}


	if (Room1CenterY < Room2CenterY)											//When creating the X section.
	{																			//If Room 1 is futher to the left then the for loop starts at room 1s center and ends at room 2s center.
		for (int rowCheck = Room1CenterY; rowCheck <= Room2CenterY; rowCheck++)
		{
			if (PlaceHolderMap[Room2CenterX, rowCheck]->GetTileIndex() == FLOOR)
			{
				PlaceHolderMap[Room2CenterX, rowCheck]->SetTileIndex(FLOOR);
			}
			else if (PlaceHolderMap[Room2CenterX, rowCheck]->GetTileIndex() == DOOR)
			{
				PlaceHolderMap[Room2CenterX, rowCheck]->SetTileIndex(DOOR);
			}
			else if (PlaceHolderMap[Room2CenterX, rowCheck]->GetTileIndex() == WALL)			//If a Wall is encounterd then replace it with a door otherwise the tiles stay the same.
			{
				PlaceHolderMap[Room2CenterX, rowCheck]->SetTileIndex(DOOR);
			}
			else if (PlaceHolderMap[Room2CenterX, rowCheck]->GetTileIndex() == HOLE)
			{
				PlaceHolderMap[Room2CenterX, rowCheck]->SetTileIndex(HOLE);
			}
			else{
				PlaceHolderMap[Room2CenterX, rowCheck]->SetTileIndex(CORRIDOR);				//If none of these tiles are encountered then change the tile to a Corridor.
			}
		}
	}
	else
	{																			//If Room 2 is futher to the left then the for loop starts at room 2s center and ends at room 1s center.
		for (int rowCheck = Room2CenterY; rowCheck <= Room1CenterY; rowCheck++)
		{
			if (PlaceHolderMap[Room2CenterX, rowCheck]->GetTileIndex() == FLOOR)
			{
				PlaceHolderMap[Room2CenterX, rowCheck]->SetTileIndex(FLOOR);
			}
			else if (PlaceHolderMap[Room2CenterX, rowCheck]->GetTileIndex() == DOOR)
			{
				PlaceHolderMap[Room2CenterX, rowCheck]->SetTileIndex(DOOR);
			}
			else if (PlaceHolderMap[Room2CenterX, rowCheck]->GetTileIndex() == WALL)			//If a Wall is encounterd then replace it with a door otherwise the tiles stay the same.
			{
				PlaceHolderMap[Room2CenterX, rowCheck]->SetTileIndex(DOOR);
			}
			else if (PlaceHolderMap[Room2CenterX, rowCheck]->GetTileIndex() == HOLE)
			{
				PlaceHolderMap[Room2CenterX, rowCheck]->SetTileIndex(HOLE);
			}
			else{
				PlaceHolderMap[Room2CenterX, rowCheck]->SetTileIndex(CORRIDOR);				//If none of these tiles are encountered then change the tile to a Corridor.
			}
		}
	}
}


/*
	FillDungeon is called to fill the DungeonTileMap which holds the Dungeon.
	It loops through the PlaceHolderMap and passes each point into the DungeonTileMap.
*/
void Dungeon::FillDungeon()
{
	DungeonTileMap = StartTileMap();						//DungeonTileMap is instalised by calling the StartTileMap method.
	for (int cols = 0; cols < Columns; cols++)
	{
		for (int rows = 0; rows < Rows; rows++)
		{			
			Cell^ mapNum = PlaceHolderMap[cols, rows];
			DungeonTileMap->SetMapEntry(cols, rows, mapNum);
		}
	}
}

/*
	DrawDungeon is called to draw the dungeon to the canvas.
*/
void Dungeon::DrawDungeon()
{
	DungeonTileMap->DrawMap();
}

/*
	getTileDimensions is used to return the width and the height of the tiles in use.
*/
array<int>^ Dungeon::getTileDimensions()
{
	array<int>^ Dimensions = gcnew array<int>(2);
	Dimensions[0] = DungeonTileMap->getWidth();
	Dimensions[1] = DungeonTileMap->getHeight();
	return Dimensions;
}

/*
	PlayerSight is used to change the fog around the player into viewable tiles.
	It Get passed in the Coloum and Row that the player is currently at and then it changes the placeHolder maps value to be not fog.
*/
void Dungeon::PlayerSight(int PlayerXPos, int PlayerYPos)
{
	int PlayerSightWidth = 3;
	int PlayerSightHeight = 3;
	int StartAtXPos = PlayerXPos;
	int StartAtYPos = PlayerYPos;

	if ((PlayerXPos - PlayerSightWidth) < 0)
	{
		
		StartAtXPos = 0;
	}
	else
	{
		StartAtXPos -= PlayerSightWidth;
	}

	if ((PlayerYPos - PlayerSightHeight) < PlayerSightHeight)
	{
		
		StartAtYPos = 0;
	}
	else
	{
		StartAtYPos -= PlayerSightHeight;
	}

	for (int col = StartAtXPos; col < (PlayerXPos + PlayerSightWidth + 3); col++)
	{
		for (int row = StartAtYPos; row < (PlayerYPos + PlayerSightHeight + 3); row++)
		{
			if (!(col >= Columns))
			{
				if (!(row >= Rows))
				{
					PlaceHolderMap[col, row]->SetFog(false);
				}				
			}			
		}
	}
	FillDungeon();			//The TileMap has to be set again because the values in the Placeholder map have changed.
}

/*
	StartTileMap is used to instalise the DungeonTileMap.
	IT creats all the Bitmaps to be used and then saving them into tiles.
	The tiles are then added into a tileList using a Enum so they can be accessed using a word instead of a array number.
	The TileList is then used to instalise the TileMap and then the TileMap is returned instalise DungeonTileMap.
*/
TileMap^ Dungeon::StartTileMap()
{
	Bitmap^ LavaBitMap = gcnew Bitmap("../Images/Lava.png");
	Bitmap^ floorBitMap = gcnew Bitmap("../Images/Floor.png");
	Bitmap^ wallBitMap = gcnew Bitmap("../Images/Wall.png");
	Bitmap^ corriderBitMap = gcnew Bitmap("../Images/Corrider.png");
	Bitmap^ doorBitMap = gcnew Bitmap("../Images/Door.png");
	Bitmap^ holeBitMap = gcnew Bitmap("../Images/Hole.png");
	Bitmap^ fogBitMap = gcnew Bitmap("../Images/Fog.png");

	Tile^ LavaTile = gcnew Tile(LavaBitMap, false, false);
	Tile^ floorTile = gcnew Tile(floorBitMap, true, false);
	Tile^ wallTile = gcnew Tile(wallBitMap, false, false);
	Tile^ corriderTile = gcnew Tile(corriderBitMap, true, false);
	Tile^ doorTile = gcnew Tile(doorBitMap, true, false);
	Tile^ holeTile = gcnew Tile(holeBitMap, true, true);
	Tile^ fogTile = gcnew Tile(fogBitMap, false, false);

	TileList^ MainTileList = gcnew TileList(7);
	MainTileList->SetTileArrayEntry(LAVA, LavaTile);	
	MainTileList->SetTileArrayEntry(WALL, wallTile);
	MainTileList->SetTileArrayEntry(FLOOR, floorTile);
	MainTileList->SetTileArrayEntry(CORRIDOR, corriderTile);
	MainTileList->SetTileArrayEntry(DOOR, doorTile);
	MainTileList->SetTileArrayEntry(HOLE, holeTile);
	MainTileList->SetTileArrayEntry(FOG, fogTile);

	TileMap^ preparedMap = gcnew TileMap(MainTileList, canvas, Columns, Rows);
	return preparedMap;
}