#pragma once
#include "Character.h"

class NPC : public Character
{
private:
	bool is_dialog;

	void move_animation_left(float delta_time) override; // ������� ���� ����
	void move_animation_right(float delta_time) override; // ������� ���� ������
	void move_animation_up(float delta_time) override; // ������� ���� �����
	void move_animation_down(float delta_time) override; // ������� ���� ����
	void idle_animation(float delta_time) override; // ������� �������

public:
	NPC(int size_x, int size_y, std::string image_way, sf::Vector2f position, sf::Vector2f scale); // ����������� � �����������

	void detect_colision_with_player(Character& player, sf::FloatRect npc_rect, sf::FloatRect player_rect, float delta_time); // ����� � �������

	void script_move(float delta_timer); // �������������� ��� (��� ������)
};

