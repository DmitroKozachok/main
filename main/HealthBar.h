#pragma once
#include <SFML/Graphics.hpp>

/* клас для здоров'я персонажів */

#define HEALTH_BAR_Y 7.f

class HealthBar
{
	sf::RectangleShape health_bar; // прямокутник (здоров'я)
	float health_bar_x = 50.f; // розмір прямокутника по x (змінна (для зміни здоров'я персонажів) )
	float health_bar_y = HEALTH_BAR_Y; // розмір прямокутника по y

	float max_health_bar_x;

	float c_for_damage; // коефіцієнт, що відповідає за відношення життя до розміру HealthBar

public:
	HealthBar();
	HealthBar(sf::Vector2f character_position, float character_health); // конструктор

	void set_health_bar_position(sf::Vector2f character_position); // метод для встановлення розташування здоров'я відносно гравця
	void set_health_bar_x(float x);
	void set_health_bar_y(float y);
	void set_health_bar();
	void set_c_for_damage(float x);

	sf::RectangleShape get_health_bar(); // гетер для "health_bar"
	float get_health_bar_x();
	float get_health_bar_y();

	void lose_health(float x); // втрата здоров'я

	void gain_health(float x); // получення здоров'я
};