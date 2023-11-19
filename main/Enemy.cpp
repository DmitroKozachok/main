#include "Enemy.h"

Enemy::Enemy() : Character() {}

void Enemy::move(sf::Vector2f player_position, float game_timer)
{
    sf::Vector2f enemy_position = character_sprite.getPosition(); // теперішня позиція ворога на екрані
    sf::Vector2f new_enemy_position = enemy_position; // нова позиція ворога на екрані
    if (enemy_position.x < player_position.x) {
        new_enemy_position.x = enemy_position.x + speed * game_timer;
    }
    if (enemy_position.x > player_position.x) {
        new_enemy_position.x = enemy_position.x - speed * game_timer;
    }
    if (enemy_position.y < player_position.y) {
        new_enemy_position.y = enemy_position.y + speed * game_timer;
    }
    if (enemy_position.y > player_position.y) {
        new_enemy_position.y = enemy_position.y - speed * game_timer;
    }
    character_sprite.setPosition(new_enemy_position); // зміна позиції ворога на екрані
}