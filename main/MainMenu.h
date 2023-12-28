// клас для головного меню
#pragma once

#include "StandartMenu.h"
#include "PlayerCamera.h"

class MainMenu : public StandartMenu
{
public:
	MainMenu(PlayerCamera& camera); // створення меню

	void set_position(PlayerCamera& camera, sf::RenderWindow& window); // встановлення позицій об'єктів

	void show(sf::RenderWindow& window) override; // вивід карти

	void click_processing(sf::RenderWindow& window, sf::Event event); // обробка натискання кнопок меню

};