// клас для головного меню
#pragma once

#include "StandartMenu.h"
#include "PlayerCamera.h"

class MainMenu : public StandartMenu
{
public:
	MainMenu(PlayerCamera& camera, sf::RenderWindow& window); // створення меню

	void set_position(PlayerCamera& camera); // встановлення позицій об'єктів

	void show(sf::RenderWindow& window) override; // вивід карти
};