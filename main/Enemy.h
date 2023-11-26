#pragma once
#include "Character.h"

class Enemy : public Character
{
public:
	Enemy(); // конструктор по замовчуванню
	Enemy(int size_x, int size_y, std::string image_way, sf::Vector2f position, sf::Vector2f scale); // конструктор з параметрами

	void move(sf::Vector2f player_position, float game_timer); // постійний рух ворога на персонажа
};