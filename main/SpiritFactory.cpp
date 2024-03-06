#include "SpiritFactory.h"

Enemy* SpiritFactory::create_enemy(sf::Vector2f spawn_position, std::string name)
{
    return new Enemy(32, 32, "Resources/sprite/2/mystic_woods_free_2.1/sprites/characters/spirit.png", spawn_position, sf::Vector2f(3.f, 3.f), name);
}
