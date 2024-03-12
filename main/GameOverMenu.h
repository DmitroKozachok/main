/*
клас для виводу меню після смерті головного героя
*/

#pragma once

#include "StandartMenu.h"
#include "PlayerCamera.h"
#include "MainMenu.h"
#include "SettingMenu.h"
#include "Player.h"
#include "NPC.h"
#include "Enemy.h"
#include <vector>
#include "GameSaver.h"

class GameOverMenu : public StandartMenu
{
public:
	GameOverMenu(PlayerCamera& camera);

	void set_position(PlayerCamera& camera, sf::Vector2f border_size, sf::RenderWindow& window);

	void show(sf::RenderWindow& window, PlayerCamera& camera);

	void click_processing(sf::RenderWindow& window, sf::Event event, MainMenu& main_menu, SettingMenu& setting_menu, Player& player, std::vector<NPC>& npcs, std::vector<Enemy>& enemies, std::vector<std::string>& dialogs, GameSaver game_saver, std::vector<Game_Music>& my_music);
};