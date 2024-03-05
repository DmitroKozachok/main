#include "OrcFactory.h"

Enemy* OrcFactory::create_enemy(sf::Vector2f spawn_position, std::string name)
{
    return new Enemy(32, 32, "Resources/sprite/Pixel Crawler - FREE - 1.8/Pixel Crawler - FREE - 1.8/Enemy/Orc Crew/Orc.png", spawn_position, sf::Vector2f(3.f, 3.f), name);
}
