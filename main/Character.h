#pragma once
#include <SFML/Graphics.hpp>

class Character
{
private:
	sf::Sprite character_sprite; // спрайт персонажа
	float health; // здоров'я
	float damage; // урон
	bool is_alive; // чи живий
	float speed; // швидкість

	void move_left(); // рух вліво
	void move_right(); // рух вправо
	void move_up(); // рух вгору
	void move_down(); // рух вниз


public:
	Character(); // конструктор за завмовчуванням, створює звичайний квадрат

	void set_sprite(sf::Sprite& new_sprite); // встановлення нового спрайту
	void set_health(float new_health); // встановлення життя
	void set_damage(float new_damage); // встановлення урону
	void set_live_status(bool status); // встановлення чи герой живий, true - живий, false - мертвий

	sf::Sprite get_sprite() const; // повертає спрайт персонажа
	float get_health() const; // повертає здоров'я персонажа
	float get_damage() const; // повертає урон персонажа
	bool get_live_status() const; // повертає статус життя героя, true - живий, false - мертвий

	void show(sf::RenderWindow& window); // промальовка персонажа

	void move(sf::Event event); // рух персонажа

	void death(); // смерть персонажа

};

