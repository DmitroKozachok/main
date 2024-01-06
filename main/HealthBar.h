#pragma once
#include <SFML/Graphics.hpp>

/* ���� ��� ������'� ��������� */

#define HEALTH_BAR_Y 7.f

class HealthBar
{
	sf::RectangleShape health_bar; // ����������� (������'�)
	float health_bar_x = 50.f; // ����� ������������ �� x (����� (��� ���� ������'� ���������) )
	const float health_bar_y = HEALTH_BAR_Y; // ����� ������������ �� y (��������a)

public:
	HealthBar();
	HealthBar(sf::Vector2f character_position); // �����������

	void set_health_bar_position(sf::Vector2f character_position); // ����� ��� ������������ ������������ ������'� ������� ������

	sf::RectangleShape get_health_bar(); // ����� ��� "health_bar"

	void lose_health(float x); // ������ ������'�

	void gain_health(float x); // ��������� ������'�
};