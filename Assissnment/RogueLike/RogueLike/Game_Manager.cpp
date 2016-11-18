/*
Nick Muldrew
RougeLike Assignment
04/10/2016
*/

#include "Game_Manager.h"

/*
	The GameManager Constructer Is used to Instalise all the variables and start the Dungeon, Player, Enemies and Items.
*/
Game_Manager::Game_Manager(Graphics^ StartCanvas)
{
	canvas = StartCanvas;
	rGen = gcnew Random();
	GameDungeon = gcnew Dungeon(canvas, rGen, 65, 43);
	GameDungeon->CreateDungeon();			//vvv
	GameDungeon->DrawDungeon();				//The Dungeon is created and drawn to the screen.

	DungeonTileMap = GameDungeon->GetDungeonTileMap();
	DungeonRooms = GameDungeon->getRooms();

	EnemiesList = gcnew SpriteList();
	ItemList = gcnew SpriteList();

	PlayerSpriteImages = gcnew array<String^>(4);			//The Player Images are saved into a array to be passed into the Sprite class to be created.
	PlayerSpriteImages[SPRITE_EAST] = "../images/Hero_Right.bmp";
	PlayerSpriteImages[SPRITE_SOUTH] = "../images/Hero_Down.bmp";
	PlayerSpriteImages[SPRITE_WEST] = "../images/Hero_Left.bmp";
	PlayerSpriteImages[SPRITE_NORTH] = "../images/Hero_Up.bmp";

	EnemySpriteImages = gcnew array<String^>(3);			//The Enemy Images are saved into a array to be passed into the Sprite class to be created.
	EnemySpriteImages[0] = "../images/BlueEnemy.bmp";
	EnemySpriteImages[1] = "../images/GreenEnemy.bmp";
	EnemySpriteImages[2] = "../images/PinkEnemy.bmp";

	ItemSpriteImages = gcnew array<String^>(3);				//The Item Images are saved into a array to be passed into the Sprite class to be created.
	ItemSpriteImages[0] = "../images/CyanBall.bmp";
	ItemSpriteImages[1] = "../images/RedBall.bmp";
	ItemSpriteImages[2] = "../images/Star.bmp";

	BattleCounter = 0;
	PlayerDead = false;
	LavaSpeed = 0;

	SetSprites();			//Instalises the Sprites	
}

/*
	DrawGame is used to Draw the Dungeon, Player, Enemies and Items to the Canvas
*/
void Game_Manager::DrawGame()
{
	GameDungeon->DrawDungeon();
	PlayerSprite->Draw();
	EnemiesList->drawSprites();
	ItemList->drawSprites();	
}

/*
	NewDungeon is used to create a new Dungeon and reset all the sprites.
*/
void Game_Manager::NewDungeon()
{
	EnemiesList->deleteSprites();		//vvv	
	ItemList->deleteSprites();			//The Eneimes and Item List delete Sprites from them so there is room for new ones to be created.

	GameDungeon->CreateDungeon();
	DungeonTileMap = GameDungeon->GetDungeonTileMap();
	DungeonRooms = GameDungeon->getRooms();			//Stores the amount of rooms so a enemy or player can be assigend to each room
	
	SetSprites();
	array<int>^ postion = DungeonTileMap->CalculatePostion(PlayerSprite->GetXPos(), PlayerSprite->GetYPos());
	GameDungeon->PlayerSight(postion[0], postion[1]);

	if (!PlayerDead)			//If the Player is not dead pass their information over into the new Dungeon.
	{
		PlayerSprite->SetHealth(PlayerHealth);
		PlayerSprite->SetCurrentHealth(PlayerHealth);
		PlayerSprite->SetAttackDamage(PlayerDamage);		
	}
	PlayerDead = false;
}

/*
	SetSprites is used to Instalise all the diffrent sprites like the Player, Enemy and item sprites.
	Uses a for loop to place a Player and Enemy Sprite into each of the rooms.
	This means that there can only be 1 enemy in a room while Items may spawn in a room with enemies or the player.
	Also calculates the bounds which the enemyies may move in and sets the X and Y postion which the sprites spawn at.
*/
void Game_Manager::SetSprites()
{
	array<int>^ TileDimensions = GameDungeon->getTileDimensions();
	int TileWidth = TileDimensions[0];
	int TileHeight = TileDimensions[1];
	int RectXPos;
	int RectYPos;
	int RectWidth;
	int RectHeight;
	Rectangle rect;
	int spawnX;
	int spawnY;
	int EnemyType;
	int RanRoom;

	RectXPos = DungeonRooms[0]->getXPos() * TileWidth;
	RectYPos = DungeonRooms[0]->getYPos() * TileHeight;
	RectWidth = DungeonRooms[0]->getWidth() * TileWidth;
	RectHeight = DungeonRooms[0]->getHeight() * TileHeight;
	rect = Rectangle(RectXPos, RectYPos, RectWidth, RectHeight);			
	spawnX = rGen->Next(RectXPos + TileWidth, (RectXPos + RectWidth) - TileWidth * 2);			//Calculates the X location to spawn at
	spawnY = rGen->Next(RectYPos + TileHeight, (RectYPos + RectHeight) - TileHeight*2);			//Calculate the Y location to spawn at

	PlayerSprite = gcnew Player(canvas, PlayerSpriteImages, 4, rGen, rect, 0.2, DungeonTileMap, spawnX, spawnY);			//Sets the player to spawn within the first room.

	for (int i = 1; i < DungeonRooms->Length; i++)
	{
		RectXPos = (DungeonRooms[i]->getXPos()) * TileWidth;
		RectYPos = (DungeonRooms[i]->getYPos()) * TileHeight;
		RectWidth = (DungeonRooms[i]->getWidth()) * TileWidth;
		RectHeight = (DungeonRooms[i]->getHeight()) * TileHeight;
		rect = Rectangle(RectXPos, RectYPos, RectWidth, RectHeight);								//The Bounds the Enemies may move within
		spawnX = rGen->Next(RectXPos + TileWidth, (RectXPos + RectWidth) - TileWidth * 2);			//Calculates the X location to spawn at
		spawnY = rGen->Next(RectYPos + TileHeight, (RectYPos + RectHeight) - TileHeight * 2);		//Calculate the Y location to spawn at

		EnemyType = rGen->Next(ENEMYTYPES);															//Randomly chooses a Enemy Type
		EnemySprite = gcnew Enemy(canvas, EnemySpriteImages, 6, rGen, rect, 0.2, DungeonTileMap, spawnX, spawnY, EnemyType);
		EnemiesList->addSprite(EnemySprite);														//Adds the Enemy to the Enemy SpriteList
	}

	for (int i = 0; i < ITEMNUM; i++)
	{
		RanRoom = rGen->Next(DungeonRooms->Length);
		RectXPos = (DungeonRooms[i + 1]->getXPos()) * TileWidth;
		RectYPos = (DungeonRooms[i + 1]->getYPos()) * TileHeight;
		RectWidth = (DungeonRooms[i + 1]->getWidth()) * TileWidth;
		RectHeight = (DungeonRooms[i + 1]->getHeight()) * TileHeight;
		rect = Rectangle(RectXPos, RectYPos, RectWidth, RectHeight);								//The Bounds the Items may move within
		spawnX = rGen->Next(RectXPos + TileWidth, (RectXPos + RectWidth) - TileWidth * 2);			//Calculates the X location to spawn at
		spawnY = rGen->Next(RectYPos + TileHeight, (RectYPos + RectHeight) - TileHeight * 2);		//Calculate the Y location to spawn at

		ItemSprite = gcnew Item(canvas, ItemSpriteImages, 6, rGen, rect, 0.2, DungeonTileMap, spawnX, spawnY, i);
		ItemList->addSprite(ItemSprite);															//Adds the Item to the Item SpriteList
	}
}

/*
	GameCycle Is used to perform all the operations at each timer tick and then draw the game.
*/
void Game_Manager::GameCycle()
{
	ItemList->deleteAllDeadSprites();			//Deletes all the Dead Sprites from the Enemey and Item SpriteLists.
	EnemiesList->deleteAllDeadSprites();		//^^^

	PlayerHealth = PlayerSprite->GetHealth();					//vvv
	PlayerCurrentHealth = PlayerSprite->GetCurrentHealth();		//Grabs the PlayerSprites current stats and stores them.
	PlayerDamage = PlayerSprite->GetAttackDamage();				//^^^

	CheckCollisions();

	EnemiesList->wanderSprites();			//vvv
	EnemiesList->UpdateSprites();			//Tells the Enemies to Wander and then updates the Enemy and Items Current frame.
	ItemList->UpdateSprites();				//^^^

	if (PlayerSprite->OnPortal)				//If the Player steps on the Portal then a new Dungeon is created.
	{
		NewDungeon();
	}	

	DrawGame();								//Calls the DrawGame method to draw the game at each timer tick.
}

/*
	PlayerDirection is used to pass the Direction to the playersprite which the user wants it to face and then moves and updates it.
*/
void Game_Manager::PlayerDirection(int newSpriteDirection)
{
	PlayerSprite->SpriteDirection(newSpriteDirection);
	PlayerSprite->Move();
	PlayerSprite->UpdateFrame();
	array<int>^ postion = DungeonTileMap->CalculatePostion(PlayerSprite->GetXPos(), PlayerSprite->GetYPos());
	GameDungeon->PlayerSight(postion[0], postion[1]);
}

/*
	CheckCollisions is used to check through the Enemy and Item SpriteLists to see if they are overlapping with the player.
	If they overlap with the player then the Item or Enemys stats are grabbed and stored so they can be displayed in the labels
*/
void Game_Manager::CheckCollisions()
{
	Sprite^ EnemyHolder = EnemiesList->checkCollisions(PlayerSprite);
	Sprite^ ItemHolder = ItemList->checkCollisions(PlayerSprite);	

	if (EnemyHolder != nullptr)
	{
		EnemyHealth = EnemyHolder->GetHealth();
		EnemyCurrentHealth = EnemyHolder->GetCurrentHealth();
		EnemyDamage = EnemyHolder->GetAttackDamage();
		Battle(EnemyHolder);					//The Battle method is called when the player overlaps with a enemy.
	}
	else
	{
		EnemyHealth = 0;
		EnemyCurrentHealth = 0;
		EnemyDamage = 0;
	}

	if (ItemHolder != nullptr)
	{
		int updatePlayerHealth = ItemHolder->GetHealth() + PlayerSprite->GetHealth();
		int updatePlayerCurrentHealth = ItemHolder->GetCurrentHealth() + PlayerSprite->GetCurrentHealth();
		int updatePlayerDamage = ItemHolder->GetAttackDamage() + PlayerSprite->GetAttackDamage();

		GameScore += ItemHolder->GetScore();							//vvv
																		//vvv
		PlayerSprite->SetHealth(updatePlayerHealth);					//Grabs the Health, AttackDamage and CurrentHealth from the item and adds it to the Players
		PlayerSprite->SetCurrentHealth(updatePlayerCurrentHealth);		//May also grab the Score from the item and add it to the GameScore.
		PlayerSprite->SetAttackDamage(updatePlayerDamage);				//The Item is then told to stop and that it is dead.
		ItemHolder->StopSprite();										//^^^
	}
}

/*
	Battle is called when a Enemy overlaps a Player
	The Player and Enemy then damage each other every X time they are in contact
	If the Enemy health gets to 0 then it is deleated and the GameScore increases.
	If the Player health gets to 0 then a new Dungeon is made and the player is set to Dead so their stats will not carry over like normal.
	X is BATTLESPEED
*/
void Game_Manager::Battle(Sprite^ SpriteInBattle)
{
	if (BattleCounter > BATTLESPEED)
	{
		SpriteInBattle->SetCurrentHealth(EnemyCurrentHealth - PlayerDamage);
		PlayerSprite->SetCurrentHealth(PlayerCurrentHealth - EnemyDamage);
		if (EnemyCurrentHealth <= 0)
		{
			GameScore += SpriteInBattle->GetScore();
			SpriteInBattle->IsAlive = false;
		}
		if (PlayerCurrentHealth <= 0)
		{
			GameScore = 0;
			PlayerDead = true;
			NewDungeon();
		}
		BattleCounter = 0;
	}
	BattleCounter++;	
}
