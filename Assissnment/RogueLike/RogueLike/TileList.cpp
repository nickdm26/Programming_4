/*
Nick Muldrew
RougeLike Assignment
04/10/2016
*/

#include "TileList.h"
#include "Tile.h"

/*
	The TileList Constructer creates a array of Tiles of the size specifed.
*/
TileList::TileList(int Size)
{
	tileArray = gcnew array<Tile^>(Size);
}

/*
	GetTileBitmap returns the Tile at the tileIndex when it is called.
*/
Bitmap^ TileList::GetTileBitmap(int tileIndex)
{
	Tile^ selectedTile = tileArray[tileIndex];
	return selectedTile->TileBitmap;
}

/*
	SetTileArrayEntry sets the Tile at the tileIndex when it is called.
*/
void TileList::SetTileArrayEntry(int tileIndex, Tile^ tileToEnter)
{
	tileArray[tileIndex] = tileToEnter;
}

/*
	GetTileWalkable returns a boolean of the Tile at the tileIndex in the Tilearray when called.
*/
bool TileList::GetIsWalkAble(int tileIndex)
{
	Tile^ selectedTile = tileArray[tileIndex];
	return selectedTile->isWalkable;
}

/*
	GetIsPortal returns a boolean of the tile at the tileIndex in the Tilearray when called.
*/
bool TileList::GetIsPortal(int tileIndex)
{
	Tile^ selectedTile = tileArray[tileIndex];
	return selectedTile->isPortal;
}
