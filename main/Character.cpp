#include "Character.h"

Character::Character() : health{ 100 }, damage{ 5 }, is_alive{ true }, speed{ 10 } {
	// створення текстури зеленого квадрату
	sf::Texture character_texture;
	character_texture.create(100, 100);

	// створення тичасового спрайту для налаштувань
	sf::Sprite new_sprite(character_texture);
	new_sprite.setColor(sf::Color::Green);

	// перенесення тимчасового спрайту на постійний
	character_sprite = new_sprite;
	character_sprite.setPosition(sf::Vector2f(1000, 200));
}

void Character::set_sprite(sf::Sprite& new_sprite) {
	// зміна спрайту
	character_sprite = new_sprite;
}

void Character::move_left()
{
	float now_x = character_sprite.getPosition().x; // початкове значення x
	float now_y = character_sprite.getPosition().y; // початкове значення y

	// зміна позиції
	character_sprite.setPosition(sf::Vector2f((now_x - speed), now_y));
}

void Character::move_right()
{
	float now_x = character_sprite.getPosition().x; // початкове значення x
	float now_y = character_sprite.getPosition().y; // початкове значення y

	// зміна позиції
	character_sprite.setPosition(sf::Vector2f((now_x + speed), now_y));

}

void Character::move_up()
{
	float now_x = character_sprite.getPosition().x; // початкове значення x
	float now_y = character_sprite.getPosition().y; // початкове значення y

	// зміна позиції
	character_sprite.setPosition(sf::Vector2f(now_x, (now_y - speed)));

}

void Character::move_down()
{
	float now_x = character_sprite.getPosition().x; // початкове значення x
	float now_y = character_sprite.getPosition().y; // початкове значення y

	// зміна позиції
	character_sprite.setPosition(sf::Vector2f(now_x, (now_y + speed)));
}

void Character::set_health(float new_health) {
	// смерть в разі відє'много значення
	if (new_health > 0)
	{
		health = new_health;
		set_live_status(true);
	}
	else {
		health = 0;
		set_live_status(false);
	}
}

void Character::set_damage(float new_damage) {
	// встановлення урону
	if (new_damage > 0)
	{
		damage = new_damage;
	}
}

void Character::set_live_status(bool status) {
	// перевірка на смерть
	if (!status)
	{
		death();
	}

	is_alive = status;
}

sf::Sprite Character::get_sprite() const { return character_sprite; }

float Character::get_health() const { return health; }

float Character::get_damage() const { return damage; }

void Character::move(sf::Event event) {
	// перевірка чи нажата клавіша
	if (event.type == sf::Event::KeyPressed) {
		// отримання стану натиснутих клавіш для руху по діагоналі
		bool is_key_pressed_a = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
		bool is_key_pressed_d = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
		bool is_key_pressed_w = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
		bool is_key_pressed_s = sf::Keyboard::isKeyPressed(sf::Keyboard::S);

		if (is_key_pressed_a)
		{
			move_left();
		}
		if (is_key_pressed_d)
		{
			move_right();
		}
		if (is_key_pressed_w)
		{
			move_up();
		}
		if (is_key_pressed_s)
		{
			move_down();
		}
	}
}

void Character::death()
{
	// анімація смерті...
}

bool Character::get_live_status() const { return is_alive; }

void Character::show(sf::RenderWindow& window) {
	// вивід спрайту на екран
	window.draw(character_sprite);
}