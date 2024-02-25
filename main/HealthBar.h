#pragma once
#include <SFML/Graphics.hpp>

/* ���� ��� ������'� ��������� */

#define HEALTH_BAR_Y 7.f

class HealthBar
{
	sf::RectangleShape health_bar; // ����������� (������'�)
	float health_bar_x = 50.f; // ����� ������������ �� x (����� (��� ���� ������'� ���������) )
	float health_bar_y = HEALTH_BAR_Y; // ����� ������������ �� y

	float max_health_bar_x;

	float c_for_damage; // ����������, �� ������� �� ��������� ����� �� ������ HealthBar

public:
	HealthBar();
	HealthBar(sf::Vector2f character_position, float character_health); // �����������

	void set_health_bar_position(sf::Vector2f character_position); // ����� ��� ������������ ������������ ������'� ������� ������
	void set_health_bar_x(float x);
	void set_health_bar_y(float y);
	void set_health_bar();
	void set_c_for_damage(float x);
	void set_health_origin(sf::Vector2f pos);

	sf::RectangleShape get_health_bar(); // ����� ��� "health_bar"
	float get_health_bar_x();
	float get_health_bar_y();

	void lose_health(float x); // ������ ������'�

	void gain_health(float x); // ��������� ������'�
};