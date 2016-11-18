#include "Tile.h"


Tile::Tile(Bitmap^ startTileBitmap, bool Walkable)
{
	TileBitmap = startTileBitmap;
	isWalkAble = Walkable;
}