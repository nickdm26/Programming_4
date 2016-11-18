#pragma once

namespace Prac2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
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
	private: System::Windows::Forms::Button^  buttonBigger;
	private: System::Windows::Forms::Button^  buttonTextBox;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  buttonAddLine;

	private: System::Windows::Forms::ListBox^  listBox1;
	private: System::Windows::Forms::Button^  buttonOnOff;
	private: System::Windows::Forms::Button^  buttonMove;

	private: System::Windows::Forms::TextBox^  textBoxMove;

	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::Button^  btnChangePic;

	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Button^  buttonGraphics;
	private: System::Windows::Forms::Button^  buttonStopStart;
	private: System::ComponentModel::IContainer^  components;

	protected:

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
			this->buttonBigger = (gcnew System::Windows::Forms::Button());
			this->buttonTextBox = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->buttonAddLine = (gcnew System::Windows::Forms::Button());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->buttonOnOff = (gcnew System::Windows::Forms::Button());
			this->buttonMove = (gcnew System::Windows::Forms::Button());
			this->textBoxMove = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->btnChangePic = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->buttonGraphics = (gcnew System::Windows::Forms::Button());
			this->buttonStopStart = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// buttonBigger
			// 
			this->buttonBigger->Location = System::Drawing::Point(33, 28);
			this->buttonBigger->Name = L"buttonBigger";
			this->buttonBigger->Size = System::Drawing::Size(75, 23);
			this->buttonBigger->TabIndex = 0;
			this->buttonBigger->Text = L"Change size";
			this->buttonBigger->UseVisualStyleBackColor = true;
			this->buttonBigger->Click += gcnew System::EventHandler(this, &MyForm::buttonBigger_Click);
			// 
			// buttonTextBox
			// 
			this->buttonTextBox->Location = System::Drawing::Point(33, 75);
			this->buttonTextBox->Name = L"buttonTextBox";
			this->buttonTextBox->Size = System::Drawing::Size(140, 26);
			this->buttonTextBox->TabIndex = 1;
			this->buttonTextBox->Text = L"Button = textbox";
			this->buttonTextBox->UseVisualStyleBackColor = true;
			this->buttonTextBox->Click += gcnew System::EventHandler(this, &MyForm::buttonTextBox_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(33, 117);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(140, 20);
			this->textBox1->TabIndex = 2;
			// 
			// buttonAddLine
			// 
			this->buttonAddLine->Location = System::Drawing::Point(33, 164);
			this->buttonAddLine->Name = L"buttonAddLine";
			this->buttonAddLine->Size = System::Drawing::Size(120, 23);
			this->buttonAddLine->TabIndex = 3;
			this->buttonAddLine->Text = L"Add Line";
			this->buttonAddLine->UseVisualStyleBackColor = true;
			this->buttonAddLine->Click += gcnew System::EventHandler(this, &MyForm::buttonAddLine_Click);
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(33, 194);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(120, 95);
			this->listBox1->TabIndex = 4;
			// 
			// buttonOnOff
			// 
			this->buttonOnOff->Location = System::Drawing::Point(33, 307);
			this->buttonOnOff->Name = L"buttonOnOff";
			this->buttonOnOff->Size = System::Drawing::Size(120, 23);
			this->buttonOnOff->TabIndex = 5;
			this->buttonOnOff->Text = L"Button On/Off";
			this->buttonOnOff->UseVisualStyleBackColor = true;
			this->buttonOnOff->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// buttonMove
			// 
			this->buttonMove->Location = System::Drawing::Point(210, 28);
			this->buttonMove->Name = L"buttonMove";
			this->buttonMove->Size = System::Drawing::Size(75, 23);
			this->buttonMove->TabIndex = 6;
			this->buttonMove->Text = L"Move box";
			this->buttonMove->UseVisualStyleBackColor = true;
			this->buttonMove->Click += gcnew System::EventHandler(this, &MyForm::button1_Click_1);
			// 
			// textBoxMove
			// 
			this->textBoxMove->Location = System::Drawing::Point(210, 58);
			this->textBoxMove->Name = L"textBoxMove";
			this->textBoxMove->Size = System::Drawing::Size(100, 20);
			this->textBoxMove->TabIndex = 7;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::HotTrack;
			this->pictureBox1->Location = System::Drawing::Point(210, 87);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(100, 50);
			this->pictureBox1->TabIndex = 8;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->pictureBox2->Location = System::Drawing::Point(210, 211);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(128, 128);
			this->pictureBox2->TabIndex = 9;
			this->pictureBox2->TabStop = false;
			// 
			// btnChangePic
			// 
			this->btnChangePic->Location = System::Drawing::Point(210, 163);
			this->btnChangePic->Name = L"btnChangePic";
			this->btnChangePic->Size = System::Drawing::Size(75, 23);
			this->btnChangePic->TabIndex = 10;
			this->btnChangePic->Text = L"Change pic";
			this->btnChangePic->UseVisualStyleBackColor = true;
			this->btnChangePic->Click += gcnew System::EventHandler(this, &MyForm::btnChangePic_Click);
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// buttonGraphics
			// 
			this->buttonGraphics->Location = System::Drawing::Point(361, 58);
			this->buttonGraphics->Name = L"buttonGraphics";
			this->buttonGraphics->Size = System::Drawing::Size(75, 23);
			this->buttonGraphics->TabIndex = 11;
			this->buttonGraphics->Text = L"Graphics";
			this->buttonGraphics->UseVisualStyleBackColor = true;
			this->buttonGraphics->Click += gcnew System::EventHandler(this, &MyForm::buttonGraphics_Click);
			// 
			// buttonStopStart
			// 
			this->buttonStopStart->Location = System::Drawing::Point(361, 87);
			this->buttonStopStart->Name = L"buttonStopStart";
			this->buttonStopStart->Size = System::Drawing::Size(75, 23);
			this->buttonStopStart->TabIndex = 12;
			this->buttonStopStart->Text = L"Stop/Start";
			this->buttonStopStart->UseVisualStyleBackColor = true;
			this->buttonStopStart->Click += gcnew System::EventHandler(this, &MyForm::buttonStopStart_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(584, 462);
			this->Controls->Add(this->buttonStopStart);
			this->Controls->Add(this->buttonGraphics);
			this->Controls->Add(this->btnChangePic);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->textBoxMove);
			this->Controls->Add(this->buttonMove);
			this->Controls->Add(this->buttonOnOff);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->buttonAddLine);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->buttonTextBox);
			this->Controls->Add(this->buttonBigger);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void buttonBigger_Click(System::Object^  sender, System::EventArgs^  e) {
		buttonBigger->Width += 10;
		if (buttonBigger->Right >= Width)
		{
			buttonBigger->Text = "Too Big";
		}
	}
	private: System::Void buttonTextBox_Click(System::Object^  sender, System::EventArgs^  e) {
		buttonTextBox->Text = textBox1->Text;
	}

			 int i = 0;

	private: System::Void buttonAddLine_Click(System::Object^  sender, System::EventArgs^  e) {
		
		listBox1->Items->Add("This is line " + i);
		i++;
	}

			 
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	if (buttonOnOff->Text == "Button On/Off"){
		buttonOnOff->Text = "";
	}
	else{
		buttonOnOff->Text = "Button On/Off";
	}

}
private: System::Void button1_Click_1(System::Object^  sender, System::EventArgs^  e) {
	int a = 0;
	while (a < 50){
		int i;
		i = Convert::ToInt32(textBoxMove->Text->ToString());
		pictureBox1->Left += i;
		System::Threading::Thread::Sleep(100);
		a++;
	}
}
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {

	
}
private: System::Void btnChangePic_Click(System::Object^  sender, System::EventArgs^  e) {
	for (int i = 1; i < 10; i++){
		pictureBox2->Image = Image::FromFile("../dragons/Dragon" + i + ".bmp");
		System::Threading::Thread::Sleep(100);
		Application::DoEvents();
	}
	

}
		 bool graphicsGOStop = false;

private: System::Void buttonGraphics_Click(System::Object^  sender, System::EventArgs^  e) {
	if (graphicsGOStop){
		graphicsGOStop = false;
	}
	else {
		graphicsGOStop = true;
	}
	Graphics^ mainCanvas = CreateGraphics();
	Brush^ greenBrush = gcnew SolidBrush(Color::Green);
	Brush^ redBrush = gcnew SolidBrush(Color::Red);
	Brush^ blueBrush = gcnew SolidBrush(Color::Blue);
	Brush^ yellowBrush = gcnew SolidBrush(Color::Yellow);
	mainCanvas->FillEllipse(greenBrush, 100, 100, 10, 10);
	Random^ randnum = gcnew Random();
	do {
		mainCanvas->FillEllipse(greenBrush, randnum->Next(0, 600), randnum->Next(0, 500), randnum->Next(0, 100), randnum->Next(0, 100));
		mainCanvas->FillEllipse(redBrush, randnum->Next(0, 600), randnum->Next(0, 500), randnum->Next(0, 100), randnum->Next(0, 100));
		mainCanvas->FillEllipse(blueBrush, randnum->Next(0, 600), randnum->Next(0, 500), randnum->Next(0, 100), randnum->Next(0, 100));
		mainCanvas->FillEllipse(yellowBrush, randnum->Next(0, 600), randnum->Next(0, 500), randnum->Next(0, 100), randnum->Next(0, 100));
		System::Threading::Thread::Sleep(50);
	} while ((graphicsGOStop));
	

	
}
private: System::Void buttonStopStart_Click(System::Object^  sender, System::EventArgs^  e) {
	
}
};
}
