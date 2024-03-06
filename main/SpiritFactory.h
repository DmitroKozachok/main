//Фабрика орка
#pragma once
#include "EnemyFactory.h"
#include "Enemy.h"

class SpiritFactory : public EnemyFactory
{
public:
    Enemy* create_enemy(sf::Vector2f spawn_position, std::string name) override;
};

