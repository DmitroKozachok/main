#pragma once
#include "Character.h"

class Enemy : public Character
{
public:
	Enemy(); // конструктор по замовчуванню

	void move(sf::Vector2f player_position, float game_timer); // постійний рух ворога на персонажа
};