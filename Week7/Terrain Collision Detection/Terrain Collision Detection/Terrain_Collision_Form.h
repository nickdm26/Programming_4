#pragma once
#include "Tile.h"
#include "TileList.h"
#include "TileMap.h"
#include "Sprite.h"

namespace TerrainCollisionDetection {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Terrain_Collision_Form
	/// </summary>
	public ref class Terrain_Collision_Form : public System::Windows::Forms::Form
	{
	public:
		Terrain_Collision_Form(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Terrain_Collision_Form()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		TileList^ mainTileList;
		TileMap^ myTileMap;
		Graphics^ mainCanvas;
		Graphics^ offScreenCanvas;
		Bitmap^ offScreenBitmap;
		Sprite^ mySprite;
		Random^ rGen;
		array<String^>^ SpriteImages;


	private: System::Windows::Forms::Timer^  timer1;
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &Terrain_Collision_Form::timer1_Tick);
			// 
			// Terrain_Collision_Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1040, 753);
			this->Name = L"Terrain_Collision_Form";
			this->Text = L"Terrain_Collision_Form";
			this->Load += gcnew System::EventHandler(this, &Terrain_Collision_Form::Terrain_Collision_Form_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Terrain_Collision_Form::Terrain_Collision_Form_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Terrain_Collision_Form_Load(System::Object^  sender, System::EventArgs^  e) 
	{
		mainCanvas = CreateGraphics();
		offScreenBitmap = gcnew Bitmap(Width, Height);
		offScreenCanvas = Graphics::FromImage(offScreenBitmap);

		rGen = gcnew Random();
		SpriteImages = gcnew array<String^>(4);
		SpriteImages[SPRITE_EAST] = "../images/Chicken East.bmp";
		SpriteImages[SPRITE_SOUTH] = "../images/Chicken South.bmp";
		SpriteImages[SPRITE_WEST] = "../images/Chicken West.bmp";
		SpriteImages[SPRITE_NORTH] = "../images/Chicken North.bmp";

		
		myTileMap = generateTileMap();
		myTileMap->LoadMapFromFile("../newChickenMap.csv");
		myTileMap->DrawMap();

		mySprite = gcnew Sprite(offScreenCanvas, SpriteImages, 8, rGen, Rectangle(0, 0, Width, Height), 0.2, myTileMap);

		mainCanvas->DrawImage(offScreenBitmap, 0, 0);
		timer1->Enabled = true;

		
	}

	private: TileMap^ generateTileMap()
	{
		Bitmap^ bookBitMap = gcnew Bitmap("../images/Book Tile.bmp");
		Bitmap^ candyBitMap = gcnew Bitmap("../images/Candy Tile.bmp");
		Bitmap^ critter1BitMap = gcnew Bitmap("../images/Critter1 Tile.bmp");
		Bitmap^ critter2BitMap = gcnew Bitmap("../images/Critter2 Tile.bmp");
		Bitmap^ critter4BitMap = gcnew Bitmap("../images/Critter4 Tile.bmp");
		Bitmap^ critter5BitMap = gcnew Bitmap("../images/Critter5 Tile.bmp");
		Bitmap^ flower1BitMap = gcnew Bitmap("../images/Flower1 Tile.bmp");
		Bitmap^ flower2BitMap = gcnew Bitmap("../images/Flower2 Tile.bmp");
		Bitmap^ flower3BitMap = gcnew Bitmap("../images/Flower3 Tile.bmp");
		Bitmap^ grassBitMap = gcnew Bitmap("../images/Grass Tile.jpg");
		Bitmap^ potionBitMap = gcnew Bitmap("../images/Potion Tile.bmp");
		Bitmap^ pumpkinBitMap = gcnew Bitmap("../images/Pumpkin Tile.bmp");
		Bitmap^ starBitMap = gcnew Bitmap("../images/Star Tile.bmp");
		
		Tile^ bookTile = gcnew Tile(bookBitMap, false);
		Tile^ candyTile = gcnew Tile(candyBitMap, false);
		Tile^ critter1Tile = gcnew Tile(critter1BitMap, false);
		Tile^ critter2Tile = gcnew Tile(critter2BitMap, false);
		Tile^ critter4Tile = gcnew Tile(critter4BitMap, false);
		Tile^ critter5Tile = gcnew Tile(critter5BitMap, false);
		Tile^ flower1Tile = gcnew Tile(flower1BitMap, false);
		Tile^ flower2Tile = gcnew Tile(flower2BitMap, false);
		Tile^ flower3Tile = gcnew Tile(flower3BitMap, false);
		Tile^ grassTile = gcnew Tile(grassBitMap, true);
		Tile^ potionTile = gcnew Tile(potionBitMap, false);
		Tile^ pumpkinTile = gcnew Tile(pumpkinBitMap, false);
		Tile^ starTile = gcnew Tile(starBitMap, false);

		mainTileList = gcnew TileList();
		mainTileList->SetTileArrayEntry(0, flower1Tile);
		mainTileList->SetTileArrayEntry(1, flower2Tile);
		mainTileList->SetTileArrayEntry(2, flower3Tile);
		mainTileList->SetTileArrayEntry(3, critter1Tile);
		mainTileList->SetTileArrayEntry(4, critter2Tile);
		mainTileList->SetTileArrayEntry(5, critter4Tile);
		mainTileList->SetTileArrayEntry(6, critter5Tile);
		mainTileList->SetTileArrayEntry(7, bookTile);
		mainTileList->SetTileArrayEntry(8, candyTile);
		mainTileList->SetTileArrayEntry(9, potionTile);
		mainTileList->SetTileArrayEntry(10, pumpkinTile);
		mainTileList->SetTileArrayEntry(11, starTile);
		mainTileList->SetTileArrayEntry(12, grassTile);

		TileMap^ preparedMap = gcnew TileMap(mainTileList, offScreenCanvas);
		return preparedMap;
	}


	private: System::Void Terrain_Collision_Form_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) 
	{
		switch (e->KeyData)
		{
		case Keys::Left:
			mySprite->SpriteDirection(WEST);
			break;
		case Keys::Up:
			mySprite->SpriteDirection(NORTH);
			break;
		case Keys::Down:
			mySprite->SpriteDirection(SOUTH);
			break;
		case Keys::Right:
			mySprite->SpriteDirection(EAST);
			break;
		}
	}

	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) 
	{
		offScreenCanvas->DrawImage(offScreenBitmap, 0, 0);
		mySprite->Move(3);
		mySprite->UpdateFrame();
		myTileMap->DrawMap();
		mySprite->Draw();
		mainCanvas->DrawImage(offScreenBitmap, 0, 0);
	}
};
}
