#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

ref class Gnome
{

private:
	Graphics^ canvas;
	Image^ gnomeImage;
	Image^ hamsterImage;
	Image^ drawImage;
	bool isHamster;
	int XPostion;
	int YPostion;

public:
	Gnome(Graphics^ startCanvas, int startXPostion, int startYPostion);
	void draw();
	void erase();
	bool mouseOnGnome(int x, int y);
	void changeToHamster();
	void changeToGnome();
	bool getIsHamster();
	void setIsHamster(bool i);

};

