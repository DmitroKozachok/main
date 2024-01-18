#include "HealthBar.h"

HealthBar::HealthBar() {}

HealthBar::HealthBar(sf::Vector2f character_position, float character_health)
{
	health_bar.setFillColor(sf::Color::Red);
	health_bar.setSize(sf::Vector2f(health_bar_x, health_bar_y));
	health_bar.setOutlineColor(sf::Color::White);
	health_bar.setOutlineThickness(2.f);
	set_health_bar_position(character_position);

	c_for_damage = health_bar.getSize().x / character_health;
}

void HealthBar::set_health_bar_position(sf::Vector2f character_position)
{
	health_bar.setPosition(character_position.x - health_bar_x / 2, character_position.y - 40); /* ��� �� ������� �������� ���������� ������� ��������� ��� ������'� ������������ ��� ����, � �� � �����*/
}

sf::RectangleShape HealthBar::get_health_bar()
{
	return health_bar;
}

void HealthBar::lose_health(float x)
{
	if (health_bar_x - x < 0)
	{
		health_bar_x = 0;
		return;
	}

	health_bar_x -= x * c_for_damage;
	health_bar.setSize(sf::Vector2f(health_bar_x, health_bar_y));
}

void HealthBar::gain_health(float x)
{
	if (health_bar_x - x > 50)
	{
		health_bar_x = 50;
		return;
	}

	health_bar_x += x;
	health_bar.setSize(sf::Vector2f(health_bar_x, health_bar_y));
}