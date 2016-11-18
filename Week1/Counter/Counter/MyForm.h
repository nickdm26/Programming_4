#pragma once

namespace Counter {

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
	private: System::Windows::Forms::Button^  ButtonCount;
	protected:

	private: System::Windows::Forms::ListBox^  listBox1;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->ButtonCount = (gcnew System::Windows::Forms::Button());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->SuspendLayout();
			// 
			// ButtonCount
			// 
			this->ButtonCount->Location = System::Drawing::Point(13, 13);
			this->ButtonCount->Name = L"ButtonCount";
			this->ButtonCount->Size = System::Drawing::Size(75, 23);
			this->ButtonCount->TabIndex = 0;
			this->ButtonCount->Text = L"Count";
			this->ButtonCount->UseVisualStyleBackColor = true;
			this->ButtonCount->Click += gcnew System::EventHandler(this, &MyForm::ButtonCount_Click);
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(13, 43);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(117, 186);
			this->listBox1->TabIndex = 1;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->ButtonCount);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void ButtonCount_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		for (int i = 0; i <= 10; i++)
		{
			listBox1->Items->Add(i*2);

		}
	}
	};
}
