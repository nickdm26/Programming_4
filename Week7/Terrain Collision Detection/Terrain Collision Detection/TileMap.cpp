#include "TileMap.h"

TileMap::TileMap(TileList^ startTileList, Graphics^ startCanvas)
{
	canvas = startCanvas;
	
	Map_Cols = 16;
	Map_Rows = 12;
	map = gcnew array<int, 2>(Map_Cols, Map_Rows);
	tileList = startTileList;
	tileWidth = tileList->GetTileBitmap(0)->Width;
	tileHeight = tileList->GetTileBitmap(0)->Height;
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

bool TileMap::GetMapWalkAble(int C, int R)
{
	int mapentry = map[C, R];
	bool walkable = tileList->GetIsWalkAble(mapentry);
	return walkable;
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
			int Size = currentTileBitmap->Width;
			Rectangle rect = Rectangle(PosX, PosY, Size, Size);
			canvas->DrawImage(currentTileBitmap, rect);
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

array<int>^ TileMap::CalculatePostion(int xPos, int yPos)
{
	array<int>^ RowCol = gcnew array<int>(2);
	int col;
	int row;
	

	row = floor(yPos / tileHeight);
	col = floor(xPos / tileWidth);	
	RowCol[0] = col;
	RowCol[1] = row;
	return RowCol;
}