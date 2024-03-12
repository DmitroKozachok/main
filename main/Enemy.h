#pragma once
#include "Character.h"
#include "Game_Music.h"
#define SECONDS 

class Enemy : public Character
{
	void move_animation_left(float delta_time) override; // анімація руху вліво
	void move_animation_right(float delta_time) override; // анімація руху вправо
	void move_animation_up(float delta_time) override; // анімація руху вгору
	void move_animation_down(float delta_time) override; // анімація руху вниз
	void idle_animation(float delta_time) override;
	void attack_animation(float delta_time); // атака ворога

	sf::Vector2f start_position; // стартова позиція

public:
	Enemy(); // конструктор по замовчуванню
	Enemy(int size_x, int size_y, std::string image_way, sf::Vector2f position, sf::Vector2f scale, std::string name); // конструктор з параметрами

	void detect_colision_with_player(Character& player, sf::FloatRect enemy_rect, sf::FloatRect player_rect, float delta_time, Game_Music& sound_player_get_damage); // колізія з гравцем
	void attack(float delta_time, Character& player, Game_Music& sound_player_get_damage); // атака ворога

	bool check_collision(Map& map_lvl, sf::Vector2f position);

	bool can_move_left(sf::Vector2f position, Map& map_lvl);
	bool can_move_right(sf::Vector2f position, Map& map_lvl);
	bool can_move_up(sf::Vector2f position, Map& map_lvl);
	bool can_move_down(sf::Vector2f position, Map& map_lvl);

	void move(sf::Vector2f player_position, float game_timer, Map& map); // постійний рух ворога на персонажа

	sf::Vector2f get_start_position(); // отримання стартової позиції
};