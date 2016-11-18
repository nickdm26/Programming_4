#pragma once
#include "Thing.h"
#include "Creature.h"

namespace FSM_Creature {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FSM_Creature_Form
	/// </summary>
	public ref class FSM_Creature_Form : public System::Windows::Forms::Form
	{
	public:
		FSM_Creature_Form(void)
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
		~FSM_Creature_Form()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		Graphics^ mainCanvas;
		Graphics^ offScreenCanvas;
		Bitmap^ offScreenBitmap;
		Random^ rGen;
		Thing^ cookie;
		array<Thing^>^ cookieArray;
		Thing^ gem;
		array<Thing^>^ gemArray;
		Creature^ bug1;
		array<Creature^>^ bug1Array;
		Creature^ bug2;
		array<Creature^>^ bug2Array;
		String^ cookiepath;
		String^ gemPath;
		String^ bug1Path;
		String^ bug2Path;
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
			this->timer1->Interval = 25;
			this->timer1->Tick += gcnew System::EventHandler(this, &FSM_Creature_Form::timer1_Tick);
			// 
			// FSM_Creature_Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(984, 661);
			this->Name = L"FSM_Creature_Form";
			this->Text = L"FSM_Creature_Form";
			this->Load += gcnew System::EventHandler(this, &FSM_Creature_Form::FSM_Creature_Form_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void FSM_Creature_Form_Load(System::Object^  sender, System::EventArgs^  e) {
		mainCanvas = CreateGraphics();
		offScreenBitmap = gcnew Bitmap(Width, Height);
		offScreenCanvas = Graphics::FromImage(offScreenBitmap);

		rGen = gcnew Random();

		cookieArray = gcnew array<Thing^> (10);
		gemArray = gcnew array<Thing^>(10);
		bug1Array = gcnew array<Creature^>(10);
		bug2Array = gcnew array<Creature^>(10);

		cookiepath = "../Images/cookie.jpg";
		gemPath = "../Images/gemstone.jpg";
		bug1Path = "../Images/littleBug1.png";
		bug2Path = "../Images/littleBug2.png";

		

		for (int i = 0; i < 10; i++){
			cookie = gcnew Thing(mainCanvas, rGen, Width, Height, cookiepath);
			gem = gcnew Thing(mainCanvas, rGen, Width, Height, gemPath);
			bug1 = gcnew Creature(mainCanvas, rGen, Width, Height, bug1Path);
			bug2 = gcnew Creature(mainCanvas, rGen, Width, Height, bug2Path);
			cookieArray[i] = cookie;
			gemArray[i] = gem;
			bug1Array[i] = bug1;
			bug2Array[i] = bug2;
		}
		
		//mainCanvas->DrawImage(offScreenBitmap, Rectangle(0, 0, Width, Height));
		timer1->Enabled = true;


	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) 
	{
		Refresh();
		//offScreenCanvas->DrawImage(offScreenBitmap, Rectangle(0,0,Width,Height));

		for (int i = 0; i < 10; i++){
			cookieArray[i]->Draw();
			gemArray[i]->Draw();
		}
		
		for (int j = 0; j < 10; j++){
			bug1Array[j]->UpdateState(cookieArray, gemArray);
			bug1Array[j]->PerformAction(cookieArray, gemArray);
			bug2Array[j]->UpdateState(cookieArray, gemArray);
			bug2Array[j]->PerformAction(cookieArray, gemArray);
		}
		/*bug1->UpdateState(cookieArray, gemArray);
		bug1->PerformAction(cookieArray, gemArray);*/

		//mainCanvas->DrawImage(offScreenBitmap, 0, 0);
	}
};
}
