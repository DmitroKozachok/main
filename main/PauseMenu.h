// клас для ігрового меню
#pragma once

#include "StandartMenu.h"
#include "PlayerCamera.h"

class PauseMenu : public StandartMenu
{
public:
	PauseMenu(PlayerCamera& camera); // створення меню

	void set_position(PlayerCamera& camera, sf::Vector2f border_size, sf::RenderWindow& window); // встановлення позицій об'єктів

	void show(sf::RenderWindow& window); // вивід карти

	void click_processing(sf::RenderWindow& window, sf::Event event); // обробка натискання на кнопки меню

};

