// клас для роботи з камерою
#include <SFML/Graphics.hpp>
#include "Character.h"
#pragma once

class PlayerCamera
{
private:
	sf::View camera; // камера
	sf::Vector2f position; // позиція камери
	sf::Vector2f size; // розмір камери

public:
	PlayerCamera(Character& character, sf::Vector2f size, sf::RenderWindow& window);

	void set_position(sf::Vector2f new_size, sf::RenderWindow& window);

	void draw(Character& character, sf::RenderWindow& window);
};

