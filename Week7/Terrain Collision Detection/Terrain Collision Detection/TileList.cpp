#include "TileList.h"
#include "Tile.h"

TileList::TileList()
{
	tileArray = gcnew array<Tile^>(13);
}

Bitmap^ TileList::GetTileBitmap(int tileIndex)
{
	Tile^ selectedTile = tileArray[tileIndex];
	return selectedTile->TileBitmap;
}

void TileList::SetTileArrayEntry(int tileIndex, Tile^ tileToEnter)
{
	tileArray[tileIndex] = tileToEnter;
}

bool TileList::GetIsWalkAble(int tileIndex)
{
	Tile^ selectedTile = tileArray[tileIndex];
	return selectedTile->isWalkAble;
}