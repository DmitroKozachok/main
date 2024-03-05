/*
Це клас для створення мінікарти
*/

#pragma once

#include "Map.h"
#include "Player.h"
#include "PlayerCamera.h"

#define LEVEL_RECTANGLES_SIZE 2
#define LINK_RECTANGLES_SIZE 1

class MiniMap
{
	sf::RectangleShape miniMap_background; // задній фон мінікарти
	sf::Vector2f miniMap_background_size;
	sf::Vector2f miniMap_background_position;

	sf::RectangleShape level_rectangles[LEVEL_RECTANGLES_SIZE];
	sf::RectangleShape link_rectangles[LINK_RECTANGLES_SIZE];
	sf::Vector2f level_rectangles_size;

public:
	MiniMap(Map map);

	void draw(sf::RenderWindow& window, Map& map, Player& player, PlayerCamera& camera);
};