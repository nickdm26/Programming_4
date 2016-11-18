/*
Nick Muldrew
RougeLike Assignment
04/10/2016
*/
#include "Tile.h"

/*
	The Tile Constructer when created saves a Bitmap and two booleans representing if its Walkable or a Portal.
*/
Tile::Tile(Bitmap^ startTileBitmap, bool Walkable, bool Portal)
{
	TileBitmap = startTileBitmap;
	isWalkable = Walkable;
	isPortal = Portal;
}
