// Клас для обробки усіх подій в процесі гри
#pragma once
#include <SFML/Graphics.hpp>
#include "Character.h"
#include "EditTxt.h"

sf::Clock clock; // створення годинника гри

class Game
{
private:

	float game_timer; // створення ігрового часу

	void event_processing(sf::RenderWindow& window, Character& character); // обробка подій

public:
	void play_game(); // запуск гри
};

