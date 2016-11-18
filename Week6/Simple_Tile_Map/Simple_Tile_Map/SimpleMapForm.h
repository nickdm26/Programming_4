#pragma once
#include "TileMap.h"

namespace Simple_Tile_Map {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for SimpleMapForm
	/// </summary>
	public ref class SimpleMapForm : public System::Windows::Forms::Form
	{
	public:
		SimpleMapForm(void)
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
		~SimpleMapForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  panel1;
	protected:
	private: System::Windows::Forms::Button^  btnDrawRandomMap;
	private: System::Windows::Forms::Button^  btnLoadMap;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

	private:
		TileList^ mainTileList;
		TileMap^ myTileMap;
		Graphics^ mainCanvas;
		Graphics^ offScreenCanvas;
		Bitmap^ offScreenBitmap;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->btnDrawRandomMap = (gcnew System::Windows::Forms::Button());
			this->btnLoadMap = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(13, 55);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(958, 583);
			this->panel1->TabIndex = 0;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &SimpleMapForm::panel1_Paint);
			// 
			// btnDrawRandomMap
			// 
			this->btnDrawRandomMap->Location = System::Drawing::Point(13, 13);
			this->btnDrawRandomMap->Name = L"btnDrawRandomMap";
			this->btnDrawRandomMap->Size = System::Drawing::Size(120, 30);
			this->btnDrawRandomMap->TabIndex = 1;
			this->btnDrawRandomMap->Text = L"Draw Random Map";
			this->btnDrawRandomMap->UseVisualStyleBackColor = true;
			this->btnDrawRandomMap->Click += gcnew System::EventHandler(this, &SimpleMapForm::btnDrawRandomMap_Click);
			// 
			// btnLoadMap
			// 
			this->btnLoadMap->Location = System::Drawing::Point(139, 13);
			this->btnLoadMap->Name = L"btnLoadMap";
			this->btnLoadMap->Size = System::Drawing::Size(120, 30);
			this->btnLoadMap->TabIndex = 2;
			this->btnLoadMap->Text = L"Load Map from File";
			this->btnLoadMap->UseVisualStyleBackColor = true;
			this->btnLoadMap->Click += gcnew System::EventHandler(this, &SimpleMapForm::btnLoadMap_Click);
			// 
			// SimpleMapForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(983, 650);
			this->Controls->Add(this->btnLoadMap);
			this->Controls->Add(this->btnDrawRandomMap);
			this->Controls->Add(this->panel1);
			this->Name = L"SimpleMapForm";
			this->Text = L"SimpleMapForm";
			this->Load += gcnew System::EventHandler(this, &SimpleMapForm::SimpleMapForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion


	private: System::Void btnDrawRandomMap_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		/*myTileMap = generateTileMap();
		myTileMap->FillMap();


		myTileMap->DrawMap();
		mainCanvas->DrawImage(offScreenBitmap, 0, 0);*/


	}

	private: System::Void btnLoadMap_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		myTileMap = generateTileMap(); 
		myTileMap->LoadMapFromFile("../mazeMap_30_20.csv");
		myTileMap->DrawMap();
		mainCanvas->DrawImage(offScreenBitmap, 0, 0);
	}

	private: System::Void panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) 
	{
		

	}
	
	private: System::Void SimpleMapForm_Load(System::Object^  sender, System::EventArgs^  e) 
	{
		mainCanvas = panel1->CreateGraphics();
		offScreenBitmap = gcnew Bitmap(950, 570);
		offScreenCanvas = Graphics::FromImage(offScreenBitmap);
		
		
	}

	private: TileMap^ generateTileMap()
	{
		Bitmap^ cobbleStoneBitMap = gcnew Bitmap("../Pics/Cobblestones Tile 32.bmp");
		Bitmap^ dryGrassBitMap = gcnew Bitmap("../Pics/Dry Grass Tile 32.bmp");
		Bitmap^ flowerBitMap = gcnew Bitmap("../Pics/Flower Tile 32.bmp");

		Tile^ cobbleStoneTile = gcnew Tile(cobbleStoneBitMap);
		Tile^ dryGrassTile = gcnew Tile(dryGrassBitMap);
		Tile^ flowerTile = gcnew Tile(flowerBitMap);

		mainTileList = gcnew TileList();
		mainTileList->SetTileArrayEntry(0, cobbleStoneTile);
		mainTileList->SetTileArrayEntry(1, dryGrassTile);
		mainTileList->SetTileArrayEntry(2, flowerTile);

		TileMap^ preparedMap = gcnew TileMap(mainTileList, offScreenCanvas);
		return preparedMap;
	}

	
	
};
}
