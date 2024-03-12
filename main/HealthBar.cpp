#include "HealthBar.h"

HealthBar::HealthBar() {}

HealthBar::HealthBar(sf::Vector2f character_position, float character_health)
{
	health_bar.setFillColor(sf::Color::Red);
	health_bar.setSize(sf::Vector2f(health_bar_x, health_bar_y));
	health_bar.setOutlineColor(sf::Color::White);
	health_bar.setOutlineThickness(2.f);
	set_health_bar_position(character_position);

	c_for_damage = 1;
}

void HealthBar::set_health_bar_position(sf::Vector2f character_position)
{
	health_bar.setPosition(character_position.x - health_bar_x / 2, character_position.y - 40); /* тут ще потрібно підрівняти координати відносно персонажів щоб здоров'я відображалося над ними, а не в ньому*/
}

void HealthBar::set_health_bar_x(float x)
{
	health_bar_x = x;
	max_health_bar_x = health_bar_x;
}

void HealthBar::set_health_bar_y(float y)
{
	health_bar_y = y;
}

void HealthBar::set_health_bar()
{
	health_bar.setSize(sf::Vector2f(health_bar_x, health_bar_y));
}

sf::RectangleShape HealthBar::get_health_bar()
{
	return health_bar;
}

void HealthBar::set_c_for_damage(float x)
{
	c_for_damage = x;
}

void HealthBar::set_health_origin(sf::Vector2f x)
{
	health_bar.setOrigin(x);
}

float HealthBar::get_health_bar_x()
{
	return health_bar_x;
}

float HealthBar::get_health_bar_y()
{
	return health_bar_y;
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
	if (health_bar_x + x > max_health_bar_x)
	{
		health_bar_x = max_health_bar_x;
		return;
	}

	health_bar_x += x * c_for_damage;
	health_bar.setSize(sf::Vector2f(health_bar_x, health_bar_y));
}