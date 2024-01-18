#pragma once
#include "Character.h"

class Enemy : public Character
{
	void move_animation_left(float delta_time) override; // анімація руху вліво
	void move_animation_right(float delta_time) override; // анімація руху вправо
	void move_animation_up(float delta_time) override; // анімація руху вгору
	void move_animation_down(float delta_time) override; // анімація руху вниз
	void attack_animation(float delta_time); // атака ворога

public:
	Enemy(); // конструктор по замовчуванню
	Enemy(int size_x, int size_y, std::string image_way, sf::Vector2f position, sf::Vector2f scale); // конструктор з параметрами

	void detect_colision_with_player(Character& player, sf::FloatRect enemy_rect, sf::FloatRect player_rect, float delta_time); // колізія з гравцем
	void attack(float delta_time, Character& player); // атака ворога

	void move(sf::Vector2f player_position, float game_timer); // постійний рух ворога на персонажа
};