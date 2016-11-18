/*
	Nicholas Muldrew
*/


#pragma once
#include "KnightSprite.h"
#include "Chicken.h"
#include "ChickenList.h"

namespace Knight_Project {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private:
		Random^ rGen;
		Graphics^ mainCanvas;

		Chicken^ myChicken;
		ChickenList^ myChickenList;
		array<String^>^ ChickenImages;
		int chickens = 40;

		KnightSprite^ myKnight;		
		array<String^>^ KnightImages;
		Bitmap^ spritePic;
		Bitmap^ offScreenBitmap;
		Image^ backgroundImage = Image::FromFile(".. /images/background.jpg");
		Graphics^ offScreenCanvas;

	private: System::Windows::Forms::Timer^  timer1;
	public:
		

		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^  components;
	protected:

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
			this->timer1->Interval = 50;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1008, 729);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) 
	{
		mainCanvas = CreateGraphics();
		rGen = gcnew Random();
		offScreenBitmap = gcnew Bitmap(1024, 768);
		offScreenCanvas = Graphics::FromImage(offScreenBitmap);
		myChickenList = gcnew ChickenList();

		KnightImages = gcnew array < String^> (4);
		KnightImages[EAST] = "../images/KnightWalkEast.bmp";
		KnightImages[SOUTH] = "../images/KnightWalkSouth.bmp";
		KnightImages[WEST] = "../images/KnightWalkWest.bmp";
		KnightImages[NORTH] = "../images/KnightWalkNorth.bmp";
		myKnight = gcnew KnightSprite(offScreenCanvas, KnightImages, 8, rGen);

		ChickenImages = gcnew array<String^>(4);
		ChickenImages[CHICKEN_EAST] = "../images/LittleChickenWalkEast.bmp";
		ChickenImages[CHICKEN_SOUTH] = "../images/LittleChickenWalkSouth.bmp";
		ChickenImages[CHICKEN_WEST] = "../images/LittleChickenWalkWest.bmp";
		ChickenImages[CHICKEN_NORTH] = "../images/LittleChickenWalkNorth.bmp";

		for (int i = 0; i < chickens; i++)
		{
			myChicken = gcnew Chicken(offScreenCanvas, ChickenImages, 8, rGen);
			myChickenList->addChicken(myChicken);
		}
		
		timer1->Enabled = true;


	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) 
	{
		offScreenCanvas->DrawImage(backgroundImage, Rectangle(0, 0, 1024, 768));
		myKnight->Move();
		myKnight->UpdateFrame();
		myKnight->Draw();

		myChickenList->moveChickens();
		myChickenList->drawChickens();
		mainCanvas->DrawImage(offScreenBitmap, 0, 0);
	}
	private: System::Void MyForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) 
	{
		switch (e->KeyData)
		{
		case Keys::Left:
			myKnight->SpriteDirection(WEST);
			break;
		case Keys::Up:
			myKnight->SpriteDirection(NORTH);
			break;
		case Keys::Down:
			myKnight->SpriteDirection(SOUTH);
			break;
		case Keys::Right:
			myKnight->SpriteDirection(EAST);
			break;
		}
	}
	};
}
