#include "TileMap.h"



TileMap::TileMap(TileList^ startTileList, Graphics^ startCanvas)
{
	canvas = startCanvas;
	tileWidth = 32;
	tileHeight = 32;
	Map_Cols = 30;
	Map_Rows = 20;
	map = gcnew array<int, 2>(Map_Cols, Map_Rows);
	tileList = startTileList;

}


void TileMap::SetMapEntry(int col, int row, int tileIndex)
{
	map[col, row] = tileIndex;
}

int TileMap::GetMapEntry(int C, int R)
{
	int mapentry = map[C, R];
	return mapentry;
}

void TileMap::DrawMap()
{
	for (int coloum = 0; coloum < Map_Cols; coloum++)
	{
		for (int row = 0; row < Map_Rows; row++)
		{
			int PosX = coloum * tileWidth;
			int PosY = row * tileHeight;

			int currenTileIndex = map[coloum, row];
			Bitmap^ currentTileBitmap = tileList->GetTileBitmap(currenTileIndex);
			canvas->DrawImage(currentTileBitmap, PosX, PosY);
		}
	}
}

void TileMap::LoadMapFromFile(String^ mapFileName)
{
	StreamReader^ sr = File::OpenText(mapFileName);
	
	String^ currentLine = "";

	array<String^>^ indexHolder = gcnew array<String^>(Map_Cols);

	int rowCounter = 0;
	
	while (currentLine = sr->ReadLine())
	{
		indexHolder = currentLine->Split(',');
		for (int colCounter = 0; colCounter < Map_Cols; colCounter++)
		{
			int indexValue = Convert::ToInt16(indexHolder[colCounter]);
			map[colCounter, rowCounter] = indexValue;
		}
		rowCounter++;
	}	                                     
}