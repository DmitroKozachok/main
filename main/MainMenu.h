#pragma once

#include "StandartMenu.h"

class MainMenu : public StandartMenu
{
public:
	MainMenu();

	void show(sf::RenderWindow& window) override;
};