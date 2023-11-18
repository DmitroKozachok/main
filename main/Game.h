// Клас для обробки усіх подій в процесі гри
#pragma once
#include <SFML/Graphics.hpp>
#include "Character.h"
#include "EditTxt.h"

class Game
{
private:
	void event_processing(sf::RenderWindow& window, Character& character); // обробка подій

public:
	void play_game(); // зауск гри
};

