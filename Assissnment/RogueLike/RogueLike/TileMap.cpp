/*
Nick Muldrew
RougeLike Assignment
04/10/2016
*/

#include "TileMap.h"

/*
	When the TileMap Constructer is called it sets the various variables as well as the TileHeight and the TileWidth.
	It also creates a 2d array to hold a representation of a Tile.
*/
TileMap::TileMap(TileList^ startTileList, Graphics^ startCanvas, int StartColoums, int StartRows)
{
	tileList = startTileList;
	canvas = startCanvas;
	Map_Cols = StartColoums;
	Map_Rows = StartRows;
	tileWidth = tileList->GetTileBitmap(0)->Width;
	tileHeight = tileList->GetTileBitmap(0)->Height;
	map = gcnew array<Cell^, 2>(Map_Cols, Map_Rows);
}

/*
	SetMapEntry is used to set the Tiles Index at the specfic coloum and row.
*/
void TileMap::SetMapEntry(int col, int row, Cell^ newCell)
{
	map[col, row] = newCell;
}

/*
	GetMapEntry is used to return what Tile is held at the Specfic Coloum and Row.
*/
int TileMap::GetMapEntry(int C, int R)
{
	int mapentry = map[C, R]->GetTileIndex();
	return mapentry;
}

/*
	GetMapWalkabel is used to return the boolean representing if the tile can be walked on at the specfic Coloum and Row.
*/
bool TileMap::GetMapWalkAble(int C, int R)
{
	int mapEntry = map[C, R]->GetTileIndex();
	bool walkable = tileList->GetIsWalkAble(mapEntry);
	return walkable;
}

/*
	GetMapPortal is used to return the boolean representing if the tile is a portal at the specfic Coloum and Row.
*/
bool TileMap::GetMapPortal(int C, int R)
{
	int mapEntry = map[C, R]->GetTileIndex();
	bool portal = tileList->GetIsPortal(mapEntry);
	return portal;
}

/*
	DrawMap is used to Interate over the entire 2d TileMap array drawing the tile at each postion in it.
*/
void TileMap::DrawMap()
{
	for (int coloum = 0; coloum < Map_Cols; coloum++)
	{
		for (int row = 0; row < Map_Rows; row++)
		{
			int PosX = coloum * tileWidth;
			int PosY = row * tileHeight;

			int currenTileIndex = map[coloum, row]->GetTileIndex();
			if (map[coloum, row]->GetFog())
			{
				currenTileIndex = FOG;
			}
			Bitmap^ currentTileBitmap = tileList->GetTileBitmap(currenTileIndex);
			canvas->DrawImage(currentTileBitmap,Rectangle( PosX, PosY, tileWidth, tileHeight));		//Uses a rectangle because it solves some issues with the pictures DPI.
		}
	}
}

/*
	CalculatePostion gets passed in a X and Y postion.
	It then calculates what Coloum and Row that X and Y are on.
	Returns The Row and Coloum as a array.
*/
array<int>^ TileMap::CalculatePostion(int XPos, int YPos)
{
	array<int>^ RowCol = gcnew array<int>(2);
	int col;
	int row;

	row = floor(YPos / tileHeight);
	col = floor(XPos / tileWidth);
	RowCol[0] = col;
	RowCol[1] = row;
	return RowCol;
}