#pragma once
#include "Tile.h"
#include "TileList.h"
#include <cmath>
#include "Cell.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO;

ref class TileMap
{
private:
	TileList^ tileList;
	array<Cell^, 2>^ map;
	Graphics^ canvas;
	int tileWidth;
	int tileHeight;
	int Map_Cols;
	int Map_Rows;


public:
	TileMap(TileList^ startTileList, Graphics^ startCanvas, int StartColoums, int StartRows);
	void SetMapEntry(int col, int row, Cell^ newCell);
	int GetMapEntry(int col, int row);
	bool GetMapWalkAble(int col, int row);
	bool GetMapPortal(int col, int row);
	array<int>^ CalculatePostion(int xPos, int yPos);
	void DrawMap();

	bool IsTileFog(int col, int row) { return map[col, row]->GetFog(); }
	int getCols() { return Map_Cols; }
	int getRows() { return Map_Rows; }
	int getWidth() { return tileWidth; }
	int getHeight() { return tileHeight; }
};

