#pragma once
#include "Sprite.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

ref class SpriteList
{
private:
	Sprite^ head;
	Sprite^ tail;

public:
	SpriteList();
	void addSprite(Sprite^ newSprite);
	void deleteSprite(Sprite^ SpriteDelete);
	void moveSprites();
	void drawSprites();
	void hideSprites();
};

