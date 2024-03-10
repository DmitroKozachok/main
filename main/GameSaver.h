// Клас для збереження
#pragma once

#include "Player.h"
#include "NPC.h"
#include "Enemy.h"
#include <vector>
#include <fstream>
#include "CharacterToSave.h"
#include "Character.h"

#define PLAYER_PATH "Code/Save/Player/player.bin"
#define ENEMIES_PATH "Code/Save/Enemies/enemies.bin"
#define NPC_PATH "Code/Save/NPC/npcs.bin"
#define DIALOGS_PATH "Code/Save/Dialogs/dialogs.bin"

class GameSaver
{
public:
	//GameSaver(Player& player, std::vector<NPC>& npc, std::vector<Enemy>& enemies);
	
	void save_game(Player& player, std::vector<NPC>& npcs, std::vector<Enemy>& enemies, std::vector<std::string>& dialogs);
	void load_game(Player& player, std::vector<NPC>& npcs, std::vector<Enemy>& enemies, std::vector<std::string>& dialogs);

};

