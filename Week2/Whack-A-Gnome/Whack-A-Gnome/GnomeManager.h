#pragma once

#include "Gnome.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

ref class GnomeManager
{

private:
	int gnomeNum;
	array<Gnome^>^ gnomeArray;
	Graphics^ canvas;
	Random^ rGen;

public:
	GnomeManager(Random^ startRandom, Graphics^ startCanvas, int startNGnomes);

	void drawAll();
	void drawOne(int gnomeIndex);
	void drawAllHamsters();
	void eraseAll();
	void eraseOne(int gnomeIndex);

	void gnomeClicked(int gnomeIndex, int x, int y);
	bool isAHamster(int gnomeIndex);
	bool isAllHamster();
	int hamstersHit();
	void resetAll();
};

