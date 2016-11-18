/*
Nick Muldrew
RougeLike Assignment
04/10/2016
*/

#include "Cell.h"

/*
	Cell constructer sets the TileIndex and if it is fog or not when the Cell is created.
*/
Cell::Cell(int StartTileIndex, bool StartFog)
{
	TileIndex = StartTileIndex;
	Fog = StartFog;
}
