#pragma once
#include "Pellet.h"
#include "PelletList.h"

namespace RainbowChicken {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ChickenForm
	/// </summary>
	public ref class ChickenForm : public System::Windows::Forms::Form
	{
	public:
		ChickenForm(void)
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
		~ChickenForm()
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

		Random^ rGen;
		Graphics^ mainCanvas;
		Pellet^ test;
		PelletList^ pellets;



	private: System::Windows::Forms::PictureBox^  picChicken;
	private: System::Windows::Forms::Label^  lblCount;


	private: System::Windows::Forms::Timer^  timer1;


			 

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->picChicken = (gcnew System::Windows::Forms::PictureBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->lblCount = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picChicken))->BeginInit();
			this->SuspendLayout();
			// 
			// picChicken
			// 
			this->picChicken->Location = System::Drawing::Point(368, 485);
			this->picChicken->Name = L"picChicken";
			this->picChicken->Size = System::Drawing::Size(64, 64);
			this->picChicken->TabIndex = 1;
			this->picChicken->TabStop = false;
			// 
			// timer1
			// 
			this->timer1->Interval = 20;
			this->timer1->Tick += gcnew System::EventHandler(this, &ChickenForm::timer1_Tick);
			// 
			// lblCount
			// 
			this->lblCount->AutoSize = true;
			this->lblCount->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->lblCount->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->lblCount->Location = System::Drawing::Point(13, 42);
			this->lblCount->Name = L"lblCount";
			this->lblCount->Size = System::Drawing::Size(35, 13);
			this->lblCount->TabIndex = 2;
			this->lblCount->Text = L"Count";
			// 
			// ChickenForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->ClientSize = System::Drawing::Size(784, 561);
			this->Controls->Add(this->lblCount);
			this->Controls->Add(this->picChicken);
			this->Name = L"ChickenForm";
			this->Text = L"ChickenForm";
			this->Load += gcnew System::EventHandler(this, &ChickenForm::ChickenForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &ChickenForm::ChickenForm_KeyDown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picChicken))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		/*
			On Load form load the timer is turned on and the Random generator, Graphics Canvas, PelletsList and chicken picture are initialised.
		*/
#pragma endregion
	private: System::Void ChickenForm_Load(System::Object^  sender, System::EventArgs^  e) 
	{
		timer1->Enabled = true;
		rGen = gcnew Random;
		mainCanvas = CreateGraphics();
		pellets = gcnew PelletList();
		picChicken->Image = Image::FromFile(".. /Pictures/chicken.gif");
	}



		 /*
			ChickenForm_KeyDown is used to perform a task when a key is pressed.
			When the left key is pressed move the picturebox containing the chicken picture left 10 pixels.
			When the right key is pressed move the picturebox containing the chicken picture right 10 pixels.
			When space bar is pressed create a new Pellet at the center top of the picture box, then it adds the Pellet to the PelletList.
		 */
	private: System::Void ChickenForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) 
	{
		if (e->KeyData == Keys::Left)
		{
			if (picChicken->Left > 0)
			{
				picChicken->Left -= 10;
			}
			
		}	
		if (e->KeyData == Keys::Right)
		{
			if (picChicken->Left < 720)
			{
				picChicken->Left += 10;
			}
		}

		if (e->KeyData == Keys::Space)
		{
			int num1 = picChicken->Left + (picChicken->Width / 2);
			int num2 = picChicken->Top - PELLET_DIAMETER;
			test = gcnew Pellet(num1, num2, mainCanvas, rGen);
			pellets->addPellet(test);
		}
	}

		 /*
			timer1_Tick is used to tell all the Pellets to draw themselves, display how many Pellets are currently in the PelletList and Then tell all the dead Pellets in PelletList to delete themselves.
			Updates every 20 milliseconds.
		*/
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) 
	{
		pellets->drawPellets();
		lblCount->Text = " " + pellets->countPellets();
		pellets->deleteAllDeadPellets();
		
	}
};
}
