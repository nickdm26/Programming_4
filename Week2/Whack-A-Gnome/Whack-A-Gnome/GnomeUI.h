#pragma once
#include "GnomeManager.h"

namespace WhackAGnome {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for GnomeUI
	/// </summary>
	public ref class GnomeUI : public System::Windows::Forms::Form
	{
	public:
		GnomeUI(void)
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
		~GnomeUI()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btnStart;
	private: System::Windows::Forms::Label^  lblGnomesText;

	private: System::Windows::Forms::Label^  lblGnomesWhacked;
	private: System::ComponentModel::IContainer^  components;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>

		Random^ rGen;
		Graphics^ mainCanvas;
		GnomeManager^ gnomeManager;
		int gnomeIndex;
		int gnomeCount;
		bool started;
	private: System::Windows::Forms::Label^  lblWinner;




	private: System::Windows::Forms::Timer^  timer;
			 

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->btnStart = (gcnew System::Windows::Forms::Button());
			this->lblGnomesText = (gcnew System::Windows::Forms::Label());
			this->lblGnomesWhacked = (gcnew System::Windows::Forms::Label());
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->lblWinner = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// btnStart
			// 
			this->btnStart->Location = System::Drawing::Point(12, 12);
			this->btnStart->Name = L"btnStart";
			this->btnStart->Size = System::Drawing::Size(75, 23);
			this->btnStart->TabIndex = 0;
			this->btnStart->Text = L"Start";
			this->btnStart->UseVisualStyleBackColor = true;
			this->btnStart->Click += gcnew System::EventHandler(this, &GnomeUI::btnStart_Click);
			// 
			// lblGnomesText
			// 
			this->lblGnomesText->AutoSize = true;
			this->lblGnomesText->Location = System::Drawing::Point(12, 38);
			this->lblGnomesText->Name = L"lblGnomesText";
			this->lblGnomesText->Size = System::Drawing::Size(99, 13);
			this->lblGnomesText->TabIndex = 1;
			this->lblGnomesText->Text = L"Gnomes Whacked:";
			// 
			// lblGnomesWhacked
			// 
			this->lblGnomesWhacked->AutoSize = true;
			this->lblGnomesWhacked->Location = System::Drawing::Point(107, 38);
			this->lblGnomesWhacked->Name = L"lblGnomesWhacked";
			this->lblGnomesWhacked->Size = System::Drawing::Size(44, 13);
			this->lblGnomesWhacked->TabIndex = 2;
			this->lblGnomesWhacked->Text = L"Number";
			// 
			// timer
			// 
			this->timer->Interval = 800;
			this->timer->Tick += gcnew System::EventHandler(this, &GnomeUI::timer_Tick);
			// 
			// lblWinner
			// 
			this->lblWinner->AutoSize = true;
			this->lblWinner->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 30, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblWinner->Location = System::Drawing::Point(394, 250);
			this->lblWinner->Name = L"lblWinner";
			this->lblWinner->Size = System::Drawing::Size(178, 46);
			this->lblWinner->TabIndex = 3;
			this->lblWinner->Text = L"You Win";
			this->lblWinner->Visible = false;
			// 
			// GnomeUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(984, 561);
			this->Controls->Add(this->lblWinner);
			this->Controls->Add(this->lblGnomesWhacked);
			this->Controls->Add(this->lblGnomesText);
			this->Controls->Add(this->btnStart);
			this->Name = L"GnomeUI";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"GnomeUI";
			this->Load += gcnew System::EventHandler(this, &GnomeUI::GnomeUI_Load);
			this->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &GnomeUI::GnomeUI_MouseClick);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void GnomeUI_Load(System::Object^  sender, System::EventArgs^  e) {		
		gnomeCount = 20;
		gnomeIndex = 0;
		rGen = gcnew Random();
		mainCanvas = CreateGraphics();
		gnomeManager = gcnew GnomeManager(rGen, mainCanvas, gnomeCount);
		started = true;
	}

			 /*
				When the start button is clicked the gnomes are all reset and the timer starts.
			 */
	private: System::Void btnStart_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		if (started){
			started = false;
		}
		else{
			gnomeManager->resetAll();
			started = true;
		}
		lblGnomesWhacked->Text = " 0";
		timer->Enabled = true;
		lblWinner->Visible = false;	
	}
			 /*
				Every 0.8 seconds all hamsters are drawn on the canvas then the random number generator  picks a random gnome to draw onto the canvas
				When all the Hamsters are drawn on the canvas then the timer stops and a message is displayed on the screen.
			 */
	private: System::Void timer_Tick(System::Object^  sender, System::EventArgs^  e) 
	{
		gnomeManager->eraseOne(gnomeIndex);
		gnomeManager->drawAllHamsters();
		gnomeIndex = rGen->Next(0, gnomeCount);
		while (gnomeManager->isAHamster(gnomeIndex))
		{
			gnomeIndex = rGen->Next(0, gnomeCount);
			if (gnomeManager->isAllHamster())
			{
				break;
			}
		}

		gnomeManager->drawOne(gnomeIndex);		
		lblGnomesWhacked->Text = " " + gnomeManager->hamstersHit();

		if (gnomeManager->isAllHamster())
		{
			timer->Enabled = false;
			lblWinner->Visible = true;
		}
	}

			 /*
				When the mouse clicks on the canvas it gets the X and Y location and sends it to the gnome to check if it was clicked on
			 */
private: System::Void GnomeUI_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	gnomeManager->gnomeClicked(gnomeIndex, e->X, e->Y);
}
};
}
