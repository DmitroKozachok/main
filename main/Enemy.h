#pragma once
#include "Character.h"

class Enemy : public Character
{
public:
	Enemy(); // ����������� �� ������������

	void move(sf::Vector2f player_position, float game_timer); // �������� ��� ������ �� ���������
};