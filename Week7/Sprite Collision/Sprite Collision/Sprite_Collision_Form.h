#pragma once
#include "KnightSprite.h"
#include "Sprite.h"
#include "SpriteList.h"

namespace SpriteCollision {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Sprite_Collision_Form
	/// </summary>
	public ref class Sprite_Collision_Form : public System::Windows::Forms::Form
	{
	public:
		Sprite_Collision_Form(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	private:
		Random^ rGen;
		Graphics^ mainCanvas;

		
		Bitmap^ spritePic;
		Bitmap^ offScreenBitmap;
		Image^ backgroundImage = Image::FromFile(".. /images/houseBg.jpg");
		Graphics^ offScreenCanvas;

		Sprite^ myKnight;
		array<String^>^ KnightImages;

		Sprite^ mySprite;
		SpriteList^ mySpriteList;
		array<String^>^ SpriteImages;
		int spriteNum = 20;

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Sprite_Collision_Form()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^  timer1;
	protected:
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
			this->timer1->Tick += gcnew System::EventHandler(this, &Sprite_Collision_Form::timer1_Tick);
			// 
			// Sprite_Collision_Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(954, 713);
			this->Name = L"Sprite_Collision_Form";
			this->Text = L"Sprite_Collision_Form";
			this->Load += gcnew System::EventHandler(this, &Sprite_Collision_Form::Sprite_Collision_Form_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Sprite_Collision_Form::Sprite_Collision_Form_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Sprite_Collision_Form_Load(System::Object^  sender, System::EventArgs^  e) 
	{
		mainCanvas = CreateGraphics();
		rGen = gcnew Random();
		offScreenBitmap = gcnew Bitmap(1024, 768);
		offScreenCanvas = Graphics::FromImage(offScreenBitmap);
		mySpriteList = gcnew SpriteList();


		KnightImages = gcnew array < String^>(4);
		KnightImages[EAST] = "../images/Knight East.bmp";
		KnightImages[SOUTH] = "../images/Knight South.bmp";
		KnightImages[WEST] = "../images/Knight West.bmp";
		KnightImages[NORTH] = "../images/Knight North.bmp";
		myKnight = gcnew Sprite(offScreenCanvas, KnightImages, 8, rGen, Rectangle(0, 0, Width, Height), 0.2);
		
		SpriteImages = gcnew array<String^>(4);
		SpriteImages[SPRITE_EAST] = "../images/LittleChickenWalkEast.bmp";
		SpriteImages[SPRITE_SOUTH] = "../images/LittleChickenWalkSouth.bmp";
		SpriteImages[SPRITE_WEST] = "../images/LittleChickenWalkWest.bmp";
		SpriteImages[SPRITE_NORTH] = "../images/LittleChickenWalkNorth.bmp";

		for (int i = 0; i < spriteNum; i++)
		{
			mySprite = gcnew Sprite(offScreenCanvas, SpriteImages, 8, rGen, Rectangle(0,0, Width, Height), 0.2);
			mySpriteList->addSprite(mySprite);
		}

		timer1->Enabled = true;
	}

	private: System::Void Sprite_Collision_Form_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) 
	{
		switch (e->KeyData)
		{
		case Keys::Left:
			myKnight->SpriteDirection(WEST);
			myKnight->Move(3);
			myKnight->UpdateFrame();
			//myKnight->Draw();
			break;
		case Keys::Up:
			myKnight->SpriteDirection(NORTH);
			myKnight->Move(3);
			myKnight->UpdateFrame();
			//myKnight->Draw();
			break;
		case Keys::Down:
			myKnight->SpriteDirection(SOUTH);
			myKnight->Move(3);
			myKnight->UpdateFrame();
			//myKnight->Draw();
			break;
		case Keys::Right:
			myKnight->SpriteDirection(EAST);
			myKnight->Move(3);
			myKnight->UpdateFrame();
			
			break;
		}
	}

	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) 
	{
		offScreenCanvas->DrawImage(backgroundImage, Rectangle(0, 0, 1024, 768));
		mySpriteList->moveSprites(3);
		mySpriteList->deleteAllDeadSprites();
		mySpriteList->drawSprites();
		Sprite^ SpriteHolder = mySpriteList->checkCollisions(myKnight);
		if (SpriteHolder != nullptr){
			SpriteHolder->StopSprite();
		}

		myKnight->Draw();
		
		mainCanvas->DrawImage(offScreenBitmap, 0, 0);
	}
	};
}
