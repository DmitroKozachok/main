// клас для ігрового меню
#pragma once

#include "StandartMenu.h"
#include "PlayerCamera.h"
#include "MainMenu.h"
#include "SettingMenu.h"
#include "Game_Music.h"

class PauseMenu : public StandartMenu
{
public:
	PauseMenu(PlayerCamera& camera); // створення меню

	void set_position(PlayerCamera& camera, sf::Vector2f border_size, sf::RenderWindow& window); // встановлення позицій об'єктів

	void show(sf::RenderWindow& window, PlayerCamera& camera) override; // вивід карти

	void click_processing(sf::Event event, MainMenu& main_menu, SettingMenu& setting_menu, std::vector<Game_Music>& music); // обробка натискання на кнопки меню

};

