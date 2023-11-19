#include "HealthBar.h"

HealthBar::HealthBar(sf::Vector2f character_position)
{
	health_bar.setFillColor(sf::Color::Red);
	health_bar.setSize(sf::Vector2f(health_bar_x, health_bar_y));
	health_bar.setOutlineColor(sf::Color::White);
	health_bar.setOutlineThickness(2.f);
	set_health_bar_position(character_position);
}

void HealthBar::set_health_bar_position(sf::Vector2f character_position)
{
	health_bar.setPosition(character_position.x, character_position.y - 10); /* тут ще потрібно підрівняти координати відносно персонажів щоб здоров'я відображалося над ними, а не в ньому*/
}

sf::RectangleShape HealthBar::get_health_bar()
{
	return health_bar;
}

void HealthBar::lose_health(float x)
{
	health_bar_x -= x;
}

void HealthBar::gain_health(float x)
{
	health_bar_x += x;
}