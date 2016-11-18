/*
Nick Muldrew
RougeLike Assignment
04/10/2016
*/

/*
	Press any arrow key to start.
	If stuck you may press spacebar to make a new Dungeon.
*/

#pragma once
#include "Tile.h"
#include "TileList.h"
#include "TileMap.h"
#include "Dungeon.h"
#include "Game_Manager.h"

namespace RogueLike {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Nicks_RougeLike
	/// </summary>
	public ref class Nicks_RougeLike : public System::Windows::Forms::Form
	{
	public:
		Nicks_RougeLike(void)
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
		~Nicks_RougeLike()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		TileList^ MainTileList;
		TileMap^ MainTileMap;
		Graphics^ mainCanvas;
		Graphics^ offScreenCanvas;
		Bitmap^ offScreenBitmap;
		Dungeon^ MYDungeon;
		Game_Manager^ Manager;

	private: System::Windows::Forms::Timer^  timer;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Label^  lblScore;
	private: System::Windows::Forms::Label^  lblPlayerHealth;
	private: System::Windows::Forms::Label^  lblPlayerDamage;
	private: System::Windows::Forms::Label^  lblPlayer;
	private: System::Windows::Forms::Label^  lblEnemy;
	private: System::Windows::Forms::Label^  lblEnemyHealth;
	private: System::Windows::Forms::Label^  lblEnemyDamage;
	private: System::Windows::Forms::Label^  lblDisplayPlayerHealth;
	private: System::Windows::Forms::Label^  lblDisplayPlayerDamage;
	private: System::Windows::Forms::Label^  lblDisplayEnemyHealth;
	private: System::Windows::Forms::Label^  lblDisplayEnemyDamage;
	private: System::Windows::Forms::Label^  lblDisplayScore;
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
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->lblScore = (gcnew System::Windows::Forms::Label());
			this->lblPlayerHealth = (gcnew System::Windows::Forms::Label());
			this->lblPlayerDamage = (gcnew System::Windows::Forms::Label());
			this->lblPlayer = (gcnew System::Windows::Forms::Label());
			this->lblEnemy = (gcnew System::Windows::Forms::Label());
			this->lblEnemyHealth = (gcnew System::Windows::Forms::Label());
			this->lblEnemyDamage = (gcnew System::Windows::Forms::Label());
			this->lblDisplayPlayerHealth = (gcnew System::Windows::Forms::Label());
			this->lblDisplayPlayerDamage = (gcnew System::Windows::Forms::Label());
			this->lblDisplayEnemyHealth = (gcnew System::Windows::Forms::Label());
			this->lblDisplayEnemyDamage = (gcnew System::Windows::Forms::Label());
			this->lblDisplayScore = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// timer
			// 
			this->timer->Interval = 50;
			this->timer->Tick += gcnew System::EventHandler(this, &Nicks_RougeLike::timer_Tick);
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(220, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1040, 680);
			this->panel1->TabIndex = 1;
			// 
			// lblScore
			// 
			this->lblScore->AutoSize = true;
			this->lblScore->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblScore->Location = System::Drawing::Point(12, 9);
			this->lblScore->Name = L"lblScore";
			this->lblScore->Size = System::Drawing::Size(71, 24);
			this->lblScore->TabIndex = 2;
			this->lblScore->Text = L"Score:";
			// 
			// lblPlayerHealth
			// 
			this->lblPlayerHealth->AutoSize = true;
			this->lblPlayerHealth->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblPlayerHealth->Location = System::Drawing::Point(23, 73);
			this->lblPlayerHealth->Name = L"lblPlayerHealth";
			this->lblPlayerHealth->Size = System::Drawing::Size(57, 16);
			this->lblPlayerHealth->TabIndex = 3;
			this->lblPlayerHealth->Text = L"Health:";
			// 
			// lblPlayerDamage
			// 
			this->lblPlayerDamage->AutoSize = true;
			this->lblPlayerDamage->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblPlayerDamage->Location = System::Drawing::Point(9, 89);
			this->lblPlayerDamage->Name = L"lblPlayerDamage";
			this->lblPlayerDamage->Size = System::Drawing::Size(71, 16);
			this->lblPlayerDamage->TabIndex = 4;
			this->lblPlayerDamage->Text = L"Damage:";
			// 
			// lblPlayer
			// 
			this->lblPlayer->AutoSize = true;
			this->lblPlayer->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblPlayer->Location = System::Drawing::Point(22, 53);
			this->lblPlayer->Name = L"lblPlayer";
			this->lblPlayer->Size = System::Drawing::Size(58, 20);
			this->lblPlayer->TabIndex = 5;
			this->lblPlayer->Text = L"Player";
			// 
			// lblEnemy
			// 
			this->lblEnemy->AutoSize = true;
			this->lblEnemy->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblEnemy->Location = System::Drawing::Point(17, 126);
			this->lblEnemy->Name = L"lblEnemy";
			this->lblEnemy->Size = System::Drawing::Size(63, 20);
			this->lblEnemy->TabIndex = 6;
			this->lblEnemy->Text = L"Enemy";
			// 
			// lblEnemyHealth
			// 
			this->lblEnemyHealth->AutoSize = true;
			this->lblEnemyHealth->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblEnemyHealth->Location = System::Drawing::Point(23, 146);
			this->lblEnemyHealth->Name = L"lblEnemyHealth";
			this->lblEnemyHealth->Size = System::Drawing::Size(57, 16);
			this->lblEnemyHealth->TabIndex = 8;
			this->lblEnemyHealth->Text = L"Health:";
			// 
			// lblEnemyDamage
			// 
			this->lblEnemyDamage->AutoSize = true;
			this->lblEnemyDamage->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblEnemyDamage->Location = System::Drawing::Point(9, 162);
			this->lblEnemyDamage->Name = L"lblEnemyDamage";
			this->lblEnemyDamage->Size = System::Drawing::Size(71, 16);
			this->lblEnemyDamage->TabIndex = 9;
			this->lblEnemyDamage->Text = L"Damage:";
			// 
			// lblDisplayPlayerHealth
			// 
			this->lblDisplayPlayerHealth->AutoSize = true;
			this->lblDisplayPlayerHealth->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblDisplayPlayerHealth->Location = System::Drawing::Point(86, 73);
			this->lblDisplayPlayerHealth->Name = L"lblDisplayPlayerHealth";
			this->lblDisplayPlayerHealth->Size = System::Drawing::Size(38, 16);
			this->lblDisplayPlayerHealth->TabIndex = 10;
			this->lblDisplayPlayerHealth->Text = L"temp";
			// 
			// lblDisplayPlayerDamage
			// 
			this->lblDisplayPlayerDamage->AutoSize = true;
			this->lblDisplayPlayerDamage->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblDisplayPlayerDamage->Location = System::Drawing::Point(86, 89);
			this->lblDisplayPlayerDamage->Name = L"lblDisplayPlayerDamage";
			this->lblDisplayPlayerDamage->Size = System::Drawing::Size(38, 16);
			this->lblDisplayPlayerDamage->TabIndex = 11;
			this->lblDisplayPlayerDamage->Text = L"temp";
			// 
			// lblDisplayEnemyHealth
			// 
			this->lblDisplayEnemyHealth->AutoSize = true;
			this->lblDisplayEnemyHealth->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblDisplayEnemyHealth->Location = System::Drawing::Point(86, 146);
			this->lblDisplayEnemyHealth->Name = L"lblDisplayEnemyHealth";
			this->lblDisplayEnemyHealth->Size = System::Drawing::Size(38, 16);
			this->lblDisplayEnemyHealth->TabIndex = 12;
			this->lblDisplayEnemyHealth->Text = L"temp";
			// 
			// lblDisplayEnemyDamage
			// 
			this->lblDisplayEnemyDamage->AutoSize = true;
			this->lblDisplayEnemyDamage->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblDisplayEnemyDamage->Location = System::Drawing::Point(86, 165);
			this->lblDisplayEnemyDamage->Name = L"lblDisplayEnemyDamage";
			this->lblDisplayEnemyDamage->Size = System::Drawing::Size(38, 16);
			this->lblDisplayEnemyDamage->TabIndex = 13;
			this->lblDisplayEnemyDamage->Text = L"temp";
			// 
			// lblDisplayScore
			// 
			this->lblDisplayScore->AutoSize = true;
			this->lblDisplayScore->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblDisplayScore->Location = System::Drawing::Point(89, 15);
			this->lblDisplayScore->Name = L"lblDisplayScore";
			this->lblDisplayScore->Size = System::Drawing::Size(80, 16);
			this->lblDisplayScore->TabIndex = 14;
			this->lblDisplayScore->Text = L"TempScore";
			// 
			// Nicks_RougeLike
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1264, 681);
			this->Controls->Add(this->lblDisplayScore);
			this->Controls->Add(this->lblDisplayEnemyDamage);
			this->Controls->Add(this->lblDisplayEnemyHealth);
			this->Controls->Add(this->lblDisplayPlayerDamage);
			this->Controls->Add(this->lblDisplayPlayerHealth);
			this->Controls->Add(this->lblEnemyDamage);
			this->Controls->Add(this->lblEnemyHealth);
			this->Controls->Add(this->lblEnemy);
			this->Controls->Add(this->lblPlayer);
			this->Controls->Add(this->lblPlayerDamage);
			this->Controls->Add(this->lblPlayerHealth);
			this->Controls->Add(this->lblScore);
			this->Controls->Add(this->panel1);
			this->Name = L"Nicks_RougeLike";
			this->Text = L"Nicks_RougeLike";
			this->Load += gcnew System::EventHandler(this, &Nicks_RougeLike::Nicks_RougeLike_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Nicks_RougeLike::Nicks_RougeLike_KeyDown);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	/*
		Nicks_RougeLike_Load Is called when the form first loads.
		It Creates the Graphics Canvas and the OffScreen Canvas which will be used to double buffer the animation.
		It also creates a instance of Game_Manager which provide the core logic of the program.
	*/
	private: System::Void Nicks_RougeLike_Load(System::Object^  sender, System::EventArgs^  e)
	{
		mainCanvas = panel1->CreateGraphics();
		offScreenBitmap = gcnew Bitmap(Width, Height);
		offScreenCanvas = Graphics::FromImage(offScreenBitmap);
		Manager = gcnew Game_Manager(offScreenCanvas);
		mainCanvas->DrawImage(offScreenBitmap, 0, 0);
		timer->Enabled = true;
	}

		/*
			timer_tick Is called every x milliseconds.
			It calls the GameCycle method from within the GameManager class and then draws to the canvas.
			After drawing to the canvas it Gets all the Player and Enemy stats from the GameManager and displays that information using labels.
		*/
	private: System::Void timer_Tick(System::Object^  sender, System::EventArgs^  e)
	{
		Manager->GameCycle();
		mainCanvas->DrawImage(offScreenBitmap, 0, 0);

		int gameScore = Manager->GetGameScore();
		int playerHealth = Manager->GetPlayerHealth();
		int playerCurrentHealth = Manager->GetPlayerCurrentHealth();
		int playerDamage = Manager->GetPlayerDamage();
		int enemyHealth = Manager->GetEnemyHealth();
		int enemyCurrentHealth = Manager->GetEnemyCurrentHealth();
		int enemyDamage = Manager->GetEnemyDamage();

		lblDisplayScore->Text = " " + gameScore;
		lblDisplayPlayerHealth->Text = " " + playerCurrentHealth + "/" + playerHealth;
		lblDisplayPlayerDamage->Text = " " + playerDamage;
		lblDisplayEnemyHealth->Text = " " + enemyCurrentHealth + "/" + enemyHealth;
		lblDisplayEnemyDamage->Text = " " + enemyDamage;
	}

		/*
			Nicks_RougeLike_KeyDown Is called whenever a key is pressed.
			When the correct key is pressed it performs a method call from within the switch.
			These calls will range from telling the Manager what direction the sprite should be facing.
			If spacebar is pressed it will create a new dungeon.
		*/
	private: System::Void Nicks_RougeLike_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) 
	{
		switch (e->KeyData)
		{
		case Keys::Left:
			Manager->PlayerDirection(WEST);
			break;
		case Keys::Up:
			Manager->PlayerDirection(NORTH);
			break;
		case Keys::Down:
			Manager->PlayerDirection(SOUTH);
			break;
		case Keys::Right:
			Manager->PlayerDirection(EAST);
			break;
		case Keys::Space:
			Manager->NewDungeon();
			break;
		}
	}
}
;}

