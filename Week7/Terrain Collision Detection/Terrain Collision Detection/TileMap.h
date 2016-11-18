#pragma once
#include "Tile.h"
#include "TileList.h"
#include <cmath>

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
	array<int, 2>^ map;
	Graphics^ canvas;
	int tileWidth;
	int tileHeight;
	int Map_Cols;
	int Map_Rows;
	
public:
	TileMap(TileList^ startTileList, Graphics^ startCanvas);
	void SetMapEntry(int col, int row, int tileIndex);
	int GetMapEntry(int col, int row);
	bool GetMapWalkAble(int col, int row);

	void DrawMap();
	void LoadMapFromFile(String^ mapFileName);
	array<int>^ CalculatePostion(int xPos, int yPos);

};

