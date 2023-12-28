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
	PlayerCamera(Character& character, sf::Vector2f size, sf::RenderWindow& window); // конструктор камери

	void set_position(sf::Vector2f new_position, sf::RenderWindow& window); // встановлення позиції
	void set_size(sf::Vector2f new_size);

	sf::Vector2f get_size() const; // отримання розміру
	sf::Vector2f get_position() const; // отримання позиції

	void draw(Character& character, sf::RenderWindow& window); // промальовка камери
};

