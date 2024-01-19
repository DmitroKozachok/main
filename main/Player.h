// ���� ��� ������ � �������

#pragma once
#include "Character.h"

class Player : public Character
{
private:
	void attack_animation_down(float delta_time); // ������� ������ �����
	void attack_animation_up(float delta_time); // ������� ������� �����
	void attack_animation_left(float delta_time); // ������� ��� �����
	void attack_animation_right(float delta_time); // ������� ����� �����

public:

	Player(int size_x, int size_y, std::string image_way, sf::Vector2f position, sf::Vector2f scale, std::string name); // ����������� ������

	void attack(sf::Event event, float delta_time); // ������� �����

};

