#pragma once

#include "Pond.h"

namespace OrientationBugs2016 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
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
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 20;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"label1";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(13, 30);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(35, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"label2";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(984, 761);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"Form1";
			this->Text = L"Orientation Baby Bugs";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->Shown += gcnew System::EventHandler(this, &Form1::Form1_Shown);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		Pond^ mainPond;
		Graphics^ mainCanvas;
		Graphics^ offScreenCanvas;
		Bitmap^ offScreenBuffer;
		Random^ rGen;
		Brush^ backgroundBrush;
		Rectangle canvasRectangle;

	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) 
	{
		mainCanvas = CreateGraphics();
		offScreenBuffer = gcnew Bitmap(Width, Height);
		offScreenCanvas = Graphics::FromImage(offScreenBuffer);
		rGen = gcnew Random();
		backgroundBrush = gcnew SolidBrush(Color::Black);
		canvasRectangle = Rectangle(0, 0, Width, Height);
		mainPond = gcnew Pond(10, offScreenCanvas, rGen, Width, Height);
	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) 
	{
		offScreenCanvas->FillRectangle(backgroundBrush, canvasRectangle);

		// move, draw and update state of all bugs in pond
		mainPond->cyclePond();
		int num = mainPond->getTeamCount(0);
		int num2 = mainPond->getTeamCount(1);
		label1->Text = "Red" + num;
		label2->Text = "Blue" + num2;
		mainCanvas->DrawImage(offScreenBuffer, 0, 0);
		
	}
	private: System::Void Form1_Shown(System::Object^  sender, System::EventArgs^  e) 
	{
		mainCanvas->FillRectangle(backgroundBrush, canvasRectangle);
	}
	};
}
