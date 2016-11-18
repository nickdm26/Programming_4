#pragma once
#include "Dungeon.h"
#include "Tile.h"
#include "TileList.h"
#include "TileMap.h"
#include "Sprite.h"
#include "Player.h"
#include "Enemy.h"
#include "SpriteList.h"
#include "Item.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO;

#define ENEMYTYPES 3
#define ITEMNUM 3
#define BATTLESPEED 5

ref class Game_Manager
{
private:
	Graphics^ canvas;
	Random^ rGen;
	Dungeon^ GameDungeon;
	TileMap^ DungeonTileMap;
	Player^ PlayerSprite;
	array<String^>^ PlayerSpriteImages;
	Enemy^ EnemySprite;
	SpriteList^ EnemiesList;
	array<String^>^ EnemySpriteImages;
	Item^ ItemSprite;
	SpriteList^ ItemList;
	array<String^>^ ItemSpriteImages;		
	array<Room^>^ DungeonRooms;

	int LavaSpeed;
	int GameScore;
	int PlayerHealth;
	int PlayerCurrentHealth;
	int PlayerDamage;
	int EnemyHealth;
	int EnemyCurrentHealth;
	int EnemyDamage;
	int BattleCounter;
	bool PlayerDead;

public:
	Game_Manager(Graphics^ StartCanvas);

	void DrawGame();
	void NewDungeon();
	void GameCycle();
	void PlayerDirection(int newSpriteDirection);
	void SetSprites();
	void CheckCollisions();
	void Battle(Sprite^ SpriteInBattle);

	int GetGameScore() { return GameScore; }
	int GetPlayerHealth() { return PlayerHealth; }
	int GetPlayerCurrentHealth() { return PlayerCurrentHealth; }
	int GetPlayerDamage() { return PlayerDamage; }
	int GetEnemyHealth() { return EnemyHealth; }
	int GetEnemyCurrentHealth() { return EnemyCurrentHealth; }
	int GetEnemyDamage() { return EnemyDamage; }
};

