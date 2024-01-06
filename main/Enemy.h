#pragma once
#include "Character.h"

class Enemy : public Character
{
	void move_animation_left(float delta_time) override; // ������� ���� ����
	void move_animation_right(float delta_time) override; // ������� ���� ������
	void move_animation_up(float delta_time) override; // ������� ���� �����
	void move_animation_down(float delta_time) override; // ������� ���� ����

public:
	Enemy(); // ����������� �� ������������
	Enemy(int size_x, int size_y, std::string image_way, sf::Vector2f position, sf::Vector2f scale); // ����������� � �����������

	void detect_colision_with_player(Character player, sf::FloatRect enemy_rect, sf::FloatRect player_rect);

	void move(sf::Vector2f player_position, float game_timer); // �������� ��� ������ �� ���������
};