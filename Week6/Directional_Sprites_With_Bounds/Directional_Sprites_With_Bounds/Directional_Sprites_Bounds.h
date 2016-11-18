#pragma once
#include "Chicken.h"
#include "ChickenList.h"

namespace Directional_Sprites_With_Bounds {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Directional_Sprites_Bounds
	/// </summary>
	public ref class Directional_Sprites_Bounds : public System::Windows::Forms::Form
	{
	public:
		Directional_Sprites_Bounds(void)
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
		~Directional_Sprites_Bounds()
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

	private:
		Random^ rGen;
		Graphics^ mainCanvas;

		Chicken^ myChicken;
		ChickenList^ myChickenList;
		array<String^>^ ChickenImages;
		int chickens = 20;

		
		Bitmap^ spritePic;
		Bitmap^ offScreenBitmap;
		Image^ backgroundImage = Image::FromFile(".. /images/background.jpg");
		int state;

	private: System::Windows::Forms::Button^  btnStop;


	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  btnWrap;
	private: System::Windows::Forms::Button^  btnBounce;


			 Graphics^ offScreenCanvas;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->btnStop = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->btnWrap = (gcnew System::Windows::Forms::Button());
			this->btnBounce = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &Directional_Sprites_Bounds::timer1_Tick);
			// 
			// btnStop
			// 
			this->btnStop->Location = System::Drawing::Point(13, 13);
			this->btnStop->Name = L"btnStop";
			this->btnStop->Size = System::Drawing::Size(75, 23);
			this->btnStop->TabIndex = 0;
			this->btnStop->Text = L"Stop";
			this->btnStop->UseVisualStyleBackColor = true;
			this->btnStop->Click += gcnew System::EventHandler(this, &Directional_Sprites_Bounds::btnStop_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(13, 43);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Die";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Directional_Sprites_Bounds::button2_Click);
			// 
			// btnWrap
			// 
			this->btnWrap->Location = System::Drawing::Point(13, 73);
			this->btnWrap->Name = L"btnWrap";
			this->btnWrap->Size = System::Drawing::Size(75, 23);
			this->btnWrap->TabIndex = 2;
			this->btnWrap->Text = L"Wrap";
			this->btnWrap->UseVisualStyleBackColor = true;
			this->btnWrap->Click += gcnew System::EventHandler(this, &Directional_Sprites_Bounds::btnWrap_Click);
			// 
			// btnBounce
			// 
			this->btnBounce->Location = System::Drawing::Point(13, 103);
			this->btnBounce->Name = L"btnBounce";
			this->btnBounce->Size = System::Drawing::Size(75, 23);
			this->btnBounce->TabIndex = 3;
			this->btnBounce->Text = L"Bounce";
			this->btnBounce->UseVisualStyleBackColor = true;
			this->btnBounce->Click += gcnew System::EventHandler(this, &Directional_Sprites_Bounds::btnBounce_Click);
			// 
			// Directional_Sprites_Bounds
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(984, 661);
			this->Controls->Add(this->btnBounce);
			this->Controls->Add(this->btnWrap);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->btnStop);
			this->Name = L"Directional_Sprites_Bounds";
			this->Text = L"Directional_Sprites_Bounds";
			this->Load += gcnew System::EventHandler(this, &Directional_Sprites_Bounds::Directional_Sprites_Bounds_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Directional_Sprites_Bounds_Load(System::Object^  sender, System::EventArgs^  e) 
	{
		mainCanvas = CreateGraphics();
		rGen = gcnew Random();
		offScreenBitmap = gcnew Bitmap(1000, 700);
		offScreenCanvas = Graphics::FromImage(offScreenBitmap);
		myChickenList = gcnew ChickenList();


		ChickenImages = gcnew array<String^>(4);
		ChickenImages[CHICKEN_EAST] = "../images/LittleChickenWalkEast.bmp";
		ChickenImages[CHICKEN_SOUTH] = "../images/LittleChickenWalkSouth.bmp";
		ChickenImages[CHICKEN_WEST] = "../images/LittleChickenWalkWest.bmp";
		ChickenImages[CHICKEN_NORTH] = "../images/LittleChickenWalkNorth.bmp";

		for (int i = 0; i < chickens; i++)
		{

			myChicken = gcnew Chicken(offScreenCanvas, ChickenImages, 8, rGen, Rectangle(0,0, Width, Height));
			myChickenList->addChicken(myChicken);
		}
		state = 0;
		timer1->Enabled = true;
	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) 
	{
		offScreenCanvas->DrawImage(backgroundImage, Rectangle(0, 0, Width, Height));
		
		myChickenList->moveChickens(state);
		myChickenList->deleteAllDeadChickens();
		myChickenList->drawChickens();
		mainCanvas->DrawImage(offScreenBitmap, 0, 0);
	}


	private: System::Void btnStop_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		state = STOP;	
		resetChickens();
	}

	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		state = DIE;	
		resetChickens();
	}

	private: System::Void btnWrap_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		state = WRAP;	
		resetChickens();
	}

	private: System::Void btnBounce_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		state = BOUNCE;	
		resetChickens();
	}

	private: System::Void resetChickens()
	{
		myChickenList->deleteChickens();
		for (int i = 0; i < chickens; i++)
		{
			int startX = rGen->Next(0, Width-200);
			int startY = rGen->Next(0, Height-200);
			int rectWidth = rGen->Next(100, 200);
			int rectHeight = rGen->Next(100, 200);
			myChicken = gcnew Chicken(offScreenCanvas, ChickenImages, 8, rGen, Rectangle(startX, startY, rectWidth, rectHeight));
			myChickenList->addChicken(myChicken);
		}
	}
};
}
