// клас для роботи з камерою
#pragma once
#include <SFML/Graphics.hpp>
#include "Character.h"
#include <iostream>

class PlayerCamera
{
private:
	sf::View camera; // камера
	sf::Vector2f position; // позиція камери
	sf::Vector2f size; // розмір камери

public:
	PlayerCamera(sf::Vector2f center, sf::Vector2f size, sf::RenderWindow& window, sf::Vector2f border_size); // конструктор камери

	void set_position(sf::Vector2f new_position, sf::Vector2f border_size); // встановлення позиції
	void set_size(sf::Vector2f new_size);

	sf::Vector2f get_size() const; // отримання розміру
	sf::Vector2f get_position() const; // отримання позиції
	sf::View get_view() const;

	void draw(sf::Vector2f center, sf::RenderWindow& window, sf::Vector2f border_size); // промальовка камери
};

