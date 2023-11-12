#include "Character.h"

Character::Character() : health{ 100 }, damage{ 5 }, is_alive{ true }, speed{ 10 } {
	// ��������� �������� �������� ��������
	sf::Texture character_texture;
	character_texture.create(100, 100);

	// ��������� ���������� ������� ��� �����������
	sf::Sprite new_sprite(character_texture);
	new_sprite.setColor(sf::Color::Green);

	// ����������� ����������� ������� �� ��������
	character_sprite = new_sprite;
	character_sprite.setPosition(sf::Vector2f(1000, 200));
}

void Character::set_sprite(sf::Sprite& new_sprite) {
	// ���� �������
	character_sprite = new_sprite;
}

void Character::move_left()
{
	float now_x = character_sprite.getPosition().x; // ��������� �������� x
	float now_y = character_sprite.getPosition().y; // ��������� �������� y

	// ���� �������
	character_sprite.setPosition(sf::Vector2f((now_x - speed), now_y));
}

void Character::move_right()
{
	float now_x = character_sprite.getPosition().x; // ��������� �������� x
	float now_y = character_sprite.getPosition().y; // ��������� �������� y

	// ���� �������
	character_sprite.setPosition(sf::Vector2f((now_x + speed), now_y));

}

void Character::move_up()
{
	float now_x = character_sprite.getPosition().x; // ��������� �������� x
	float now_y = character_sprite.getPosition().y; // ��������� �������� y

	// ���� �������
	character_sprite.setPosition(sf::Vector2f(now_x, (now_y - speed)));

}

void Character::move_down()
{
	float now_x = character_sprite.getPosition().x; // ��������� �������� x
	float now_y = character_sprite.getPosition().y; // ��������� �������� y

	// ���� �������
	character_sprite.setPosition(sf::Vector2f(now_x, (now_y + speed)));
}

void Character::set_health(float new_health) {
	// ������ � ��� ��'����� ��������
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
	// ������������ �����
	if (new_damage > 0)
	{
		damage = new_damage;
	}
}

void Character::set_live_status(bool status) {
	// �������� �� ������
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
	// �������� �� ������ ������
	if (event.type == sf::Event::KeyPressed) {
		// ��������� ����� ���������� ����� ��� ���� �� �������
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
	// ������� �����...
}

bool Character::get_live_status() const { return is_alive; }

void Character::show(sf::RenderWindow& window) {
	// ���� ������� �� �����
	window.draw(character_sprite);
}