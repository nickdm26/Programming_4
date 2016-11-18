#pragma once

namespace Triathlon {

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
	private: System::Windows::Forms::Button^  btnStart;
	protected:
	private: System::Windows::Forms::ListBox^  listBox1;

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
			this->btnStart = (gcnew System::Windows::Forms::Button());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->SuspendLayout();
			// 
			// btnStart
			// 
			this->btnStart->Location = System::Drawing::Point(13, 13);
			this->btnStart->Name = L"btnStart";
			this->btnStart->Size = System::Drawing::Size(75, 23);
			this->btnStart->TabIndex = 0;
			this->btnStart->Text = L"Start";
			this->btnStart->UseVisualStyleBackColor = true;
			this->btnStart->Click += gcnew System::EventHandler(this, &MyForm::btnStart_Click);
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(13, 43);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(287, 368);
			this->listBox1->TabIndex = 1;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1163, 630);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->btnStart);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btnStart_Click(System::Object^  sender, System::EventArgs^  e) {
		array<String^>^ Swimmer = gcnew array<String^>(3);
		array<String^>^ Cyclist = gcnew array<String^>(3);
		array<String^>^ Runner = gcnew array<String^>(3);

		Swimmer[0] = "Anne";
		Swimmer[1] = "David";
		Swimmer[2] = "Ellen";

		Cyclist[0] = "Anne";
		Cyclist[1] = "Bob";
		Cyclist[2] = "Carl";

		Runner[0] = "Bob";
		Runner[1] = "Ellen";
		Runner[2] = "Fred";

		listBox1->Items->Add(Swimmer[0]);



	}
	};
}
