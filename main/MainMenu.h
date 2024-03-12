// клас для головного меню
#pragma once
#include "Game_Music.h"
#include "StandartMenu.h"
#include "PlayerCamera.h"
#include "SettingMenu.h"
#include "Player.h"
#include "NPC.h"
#include "Enemy.h"
#include <vector>
#include "GameSaver.h"

class MainMenu : public StandartMenu
{
public:
	MainMenu(PlayerCamera& camera); // створення меню

	void set_position(PlayerCamera& camera, sf::Vector2f border_size, sf::RenderWindow& window); // встановлення позицій об'єктів

	void show(sf::RenderWindow& window, PlayerCamera& camera) override; // вивід карти

	void click_processing(sf::RenderWindow& window, sf::Event event, std::vector<Game_Music>&music, SettingMenu& setting_menu); // обробка натискання кнопок меню
	void click_processing(sf::RenderWindow& window, sf::Event event, Game_Music &music, SettingMenu& setting_menu, Player& player, std::vector<NPC>& npcs, std::vector<Enemy>& enemies, std::vector<std::string>& dialogs, GameSaver game_saver); // обробка натискання кнопок меню

};