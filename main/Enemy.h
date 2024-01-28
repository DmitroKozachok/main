#pragma once
#include "Character.h"

#define SECONDS 

class Enemy : public Character
{
	void move_animation_left(float delta_time) override; // ������� ���� ����
	void move_animation_right(float delta_time) override; // ������� ���� ������
	void move_animation_up(float delta_time) override; // ������� ���� �����
	void move_animation_down(float delta_time) override; // ������� ���� ����
	void attack_animation(float delta_time); // ����� ������

public:
	Enemy(); // ����������� �� ������������
	Enemy(int size_x, int size_y, std::string image_way, sf::Vector2f position, sf::Vector2f scale); // ����������� � �����������

	void detect_colision_with_player(Character& player, sf::FloatRect enemy_rect, sf::FloatRect player_rect, float delta_time); // ����� � �������
	void attack(float delta_time, Character& player); // ����� ������

	bool check_collision(Map& map_lvl, sf::Vector2f position);

	bool can_move_left(sf::Vector2f position, Map& map_lvl);
	bool can_move_right(sf::Vector2f position, Map& map_lvl);
	bool can_move_up(sf::Vector2f position, Map& map_lvl);
	bool can_move_down(sf::Vector2f position, Map& map_lvl);

	void move(sf::Vector2f player_position, float game_timer, Map& map); // �������� ��� ������ �� ���������
};