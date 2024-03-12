//Фабрика слайму
#pragma once
#include "EnemyFactory.h"
#include "Enemy.h"

class SlimeFactory : public EnemyFactory
{
public:
    Enemy* create_enemy(sf::Vector2f spawn_position, std::string name) override;
};

