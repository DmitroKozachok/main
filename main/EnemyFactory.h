//Клас фабрики ворогів для фабричного методу
#pragma once
#include "Enemy.h"

class EnemyFactory {
public:
    virtual Enemy* create_enemy(sf::Vector2f spawn_position, std::string name) = 0;
};
