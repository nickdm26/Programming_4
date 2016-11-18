#pragma once
#include "Tile.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

ref class TileList
{
private:
	array<Tile^>^ tileArray;

public:
	TileList(int Size);

	Bitmap^ GetTileBitmap(int tileIndex);
	bool GetIsWalkAble(int tileIndex);
	bool GetIsPortal(int tileIndex);

	void SetTileArrayEntry(int tileIndex, Tile^ tileToEnter);

	int GetTileArrayLength() { return tileArray->Length; }
};

