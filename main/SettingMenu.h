// клас для меню налаштувань
#pragma once

#include "StandartMenu.h"
#include "PlayerCamera.h"

class SettingMenu : public StandartMenu
{
public:
	SettingMenu(PlayerCamera& camera); // створення меню

	void set_position(PlayerCamera& camera, sf::Vector2f border_size, sf::RenderWindow& window); // встановлення позицій об'єктів

	void show(sf::RenderWindow& window, PlayerCamera& camera) override; // вивід карти

	bool is_continue_pressed(sf::RenderWindow& window, sf::Event event);

	void click_processing(sf::RenderWindow& window, sf::Event event); // обробка натискання кнопок меню

};