#include "MiniMap.h"

MiniMap::MiniMap(Map map) : miniMap_background_size{map.get_map_size().x / 40 / (map.get_map_size().x / map.get_map_size().y), map.get_map_size().y / 40 }, level_rectangles_size{ miniMap_background_size.x / 6, miniMap_background_size.y / 6 }
{
	miniMap_background.setSize(miniMap_background_size);
	miniMap_background.setFillColor(sf::Color(255,255,255,127));
	miniMap_background.setOutlineThickness(2.f);
	miniMap_background.setOutlineColor(sf::Color(255, 255, 255, 180));

	for (int i = 0; i < LEVEL_RECTANGLES_SIZE; i++)
	{
		level_rectangles[i].setSize(level_rectangles_size);
		level_rectangles[i].setFillColor(sf::Color::White);
	}

	for (int i = 0; i < LINK_RECTANGLES_SIZE; i++)
	{
		link_rectangles[i].setSize({ level_rectangles_size.x / 3, level_rectangles_size.y / 1.5f });
		link_rectangles[i].setFillColor(sf::Color::White);
		//link_rectangles[i].setOutlineThickness(0.75f);
		//link_rectangles[i].setOutlineColor(sf::Color(0, 0, 0, 180));
	}
}

void MiniMap::draw(sf::RenderWindow& window, Map& map, Player& player, PlayerCamera& camera)
{
	miniMap_background.setPosition({ camera.get_position().x + 290.f, camera.get_position().y - 220.f });
	miniMap_background_position = miniMap_background.getPosition();

	level_rectangles[0].setPosition({ miniMap_background_position.x + (miniMap_background_size.x / 2) - (level_rectangles_size.x / 2), (miniMap_background_position.y + (miniMap_background_size.y / 2) - (level_rectangles_size.y / 2)) - (level_rectangles_size.y * 0.75f) });
	level_rectangles[1].setPosition({ level_rectangles[0].getPosition().x, (level_rectangles[0].getPosition().y + (level_rectangles_size.y * 1.5f)) });

	link_rectangles[0].setPosition({ level_rectangles[0].getPosition().x + (level_rectangles_size.x / 3), (level_rectangles[0].getPosition().y + level_rectangles_size.y) });
	
	window.draw(miniMap_background);
	window.draw(level_rectangles[0]);
	window.draw(level_rectangles[1]);
	window.draw(link_rectangles[0]);
}