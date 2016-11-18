#pragma once
#include "SpriteList.h"

namespace SpriteProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Gooey
	/// </summary>
	public ref class Gooey : public System::Windows::Forms::Form
	{
	public:
		
		Gooey(void)
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
		~Gooey()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btnOne;
	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		Random^ rGen;
		Graphics^ mainCanvas;
		Sprite^ mySprite;
		Sprite^ mySprite2;
		SpriteList^ mySprites;
		SpriteList^ mySprites2;
		Bitmap^ spritePic;
		Bitmap^ offScreenBitmap;
		Graphics^ offScreenCanvas;
		Image^ backgroundImage = Image::FromFile(".. /Pics/outerSpace.jpg");
		int blobbos = 30;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Timer^  timer2;
	private: System::Windows::Forms::Button^  btnMulti;

	private: System::ComponentModel::IContainer^  components;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->btnOne = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->btnMulti = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btnOne
			// 
			this->btnOne->Location = System::Drawing::Point(13, 13);
			this->btnOne->Name = L"btnOne";
			this->btnOne->Size = System::Drawing::Size(98, 23);
			this->btnOne->TabIndex = 0;
			this->btnOne->Text = L"One Blobbo";
			this->btnOne->UseVisualStyleBackColor = true;
			this->btnOne->Click += gcnew System::EventHandler(this, &Gooey::button1_Click);
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &Gooey::timer1_Tick);
			// 
			// timer2
			// 
			this->timer2->Tick += gcnew System::EventHandler(this, &Gooey::timer2_Tick);
			// 
			// btnMulti
			// 
			this->btnMulti->Location = System::Drawing::Point(13, 43);
			this->btnMulti->Name = L"btnMulti";
			this->btnMulti->Size = System::Drawing::Size(98, 23);
			this->btnMulti->TabIndex = 1;
			this->btnMulti->Text = L"Multiple Blobbo\'s";
			this->btnMulti->UseVisualStyleBackColor = true;
			this->btnMulti->Click += gcnew System::EventHandler(this, &Gooey::btnMulti_Click);
			// 
			// Gooey
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(1008, 730);
			this->Controls->Add(this->btnMulti);
			this->Controls->Add(this->btnOne);
			this->Name = L"Gooey";
			this->Text = L"Gooey";
			this->Load += gcnew System::EventHandler(this, &Gooey::Gooey_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		timer1->Enabled = true;
		mySprites->drawSprites();
		mySprites2->hideSprites();
		timer2->Enabled = false;
	}

	private: System::Void Gooey_Load(System::Object^  sender, System::EventArgs^  e) 
	{
		mySprites = gcnew SpriteList();
		mySprites2 = gcnew SpriteList();
		rGen = gcnew Random;
		mainCanvas = CreateGraphics();
		spritePic = gcnew Bitmap(".. /Pics/BlobboMulti.bmp");

		offScreenBitmap = gcnew Bitmap(1024, 768);
		offScreenCanvas = Graphics::FromImage(offScreenBitmap);





		mySprite = gcnew Sprite(offScreenCanvas, spritePic, 8, rGen);
		mySprites->addSprite(mySprite);

		for (int i = 0; i < blobbos; i++)
		{

			mySprite2 = gcnew Sprite(offScreenCanvas, spritePic, 8, rGen, rGen->Next(0, 8));

			mySprites2->addSprite(mySprite2);
		}		
	}

	private: System::Void btnMulti_Click(System::Object^  sender, System::EventArgs^  e)
	{
		timer1->Enabled = false;
		mySprites->hideSprites();
		mySprites2->drawSprites();
		timer2->Enabled = true;		
	}

	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) 
	{
		offScreenCanvas->DrawImage(backgroundImage, Rectangle(0, 0, 1024, 768));
		//Refresh();
		mySprites->moveSprites();
		mySprites->drawSprites();
		mainCanvas->DrawImage(offScreenBitmap, 0, 0);
	}

private: System::Void timer2_Tick(System::Object^  sender, System::EventArgs^  e) 
{
	offScreenCanvas->DrawImage(backgroundImage, Rectangle(0, 0, 1024, 768));
	//Refresh();
	mySprites2->moveSprites();
	mySprites2->drawSprites();
	mainCanvas->DrawImage(offScreenBitmap, 0, 0);
	
}
};
}
