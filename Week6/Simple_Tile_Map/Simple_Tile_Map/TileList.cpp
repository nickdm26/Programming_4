#include "TileList.h"
#include "Tile.h"


TileList::TileList()
{
	tileArray = gcnew array<Tile^>(3);
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
