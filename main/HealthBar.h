#pragma once
#include <SFML/Graphics.hpp>

/* клас для здоров'я персонажів */

#define HEALTH_BAR_Y 7.f

class HealthBar
{
	sf::RectangleShape health_bar; // прямокутник (здоров'я)
	float health_bar_x = 50.f; // розмір прямокутника по x (змінна (для зміни здоров'я персонажів) )
	const float health_bar_y = HEALTH_BAR_Y; // розмір прямокутника по y (константa)

public:
	HealthBar();
	HealthBar(sf::Vector2f character_position); // конструктор

	void set_health_bar_position(sf::Vector2f character_position); // метод для встановлення розташування здоров'я відносно гравця

	sf::RectangleShape get_health_bar(); // гетер для "health_bar"

	void lose_health(float x); // втрата здоров'я

	void gain_health(float x); // получення здоров'я
};