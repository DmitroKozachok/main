#include "Enemy.h"

Enemy::Enemy() : Character() {}

Enemy::Enemy(int size_x, int size_y, std::string image_way, sf::Vector2f position, sf::Vector2f scale) : Character(size_x, size_y, image_way, position, scale){} // делегування батьківського конструктора

void Enemy::move(sf::Vector2f player_position, float game_timer)
{
    sf::Vector2f enemy_position = character_sprite.getPosition(); // теперішня позиція ворога на екрані
    sf::Vector2f new_enemy_position = enemy_position; // нова позиція ворога на екрані
    if (enemy_position.x < player_position.x) {
        move_right(game_timer);
    }
    if (enemy_position.x > player_position.x) {
        move_left(game_timer);
    }
    if (enemy_position.y < player_position.y) {
        move_down(game_timer);
    }
    if (enemy_position.y > player_position.y) {
        move_up(game_timer);
    }
    character_sprite.setPosition(new_enemy_position); // зміна позиції ворога на екрані
}