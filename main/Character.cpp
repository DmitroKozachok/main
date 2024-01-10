#include "Character.h"

Character::Character() : health{ 100 }, damage{ 5 }, is_alive{ true }, speed{ 15 }, diagonal_speed{ speed / 1.3f }, frame{0.f} {
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

Character::Character(int size_x, int size_y, std::string image_way, sf::Vector2f position, sf::Vector2f scale, float speed, float health, float damage) :character_health(character_sprite.getPosition(), health), health{ health }, damage{ damage }, is_alive{ true }, speed{ speed }, diagonal_speed{ speed / 1.3f }, frame{ 0.f }, size_texture_x{ size_x }, size_texture_y{ size_y }, is_attacking{ false }
{
	// ������������ ��������
	character_image.loadFromFile(image_way);
	
	// ������������ ��������
	character_texture.loadFromImage(character_image);

	// ������������ �������
	character_sprite.setTexture(character_texture);
	character_sprite.setTextureRect(sf::IntRect(0, 0, size_x, size_y));
	character_sprite.setScale(scale);
	character_sprite.setOrigin(sf::Vector2f(size_x / 2.f, size_y / 2.f));

	// ������������ �������
	character_sprite.setPosition(position);

	character_health.set_health_bar_position(character_sprite.getPosition());
}

void Character::move_left(float delta_time)
{
	// ���� �������
	character_sprite.move(-speed * delta_time, 0);

	// ���� ��������� �������
	move_status = LEFT;

	// ����������� �������
	move_animation_left(delta_time);
}

void Character::move_right(float delta_time)
{
	// ���� �������
	character_sprite.move(speed * delta_time, 0);

	// ���� ��������� �������
	move_status = RIGHT;

	// ����������� �������
	move_animation_right(delta_time);
}

void Character::move_up(float delta_time)
{
	// ���� �������
	character_sprite.move(0, -speed * delta_time);

	// ���� ��������� �������
	move_status = UP;

	// ����������� �������
	move_animation_up(delta_time);
}

void Character::move_down(float delta_time)
{
	// ���� �������
	character_sprite.move(0, speed * delta_time);

	// ���� ��������� �������
	move_status = DOWN;

	// ����������� �������
	move_animation_down(delta_time);
}

void Character::move_animation_left(float delta_time)
{
	// ����������� ����� �������
	if (speed == diagonal_speed)
	{
		frame += delta_time / 2;
	}
	else
	{
		frame += delta_time;
	}
	

	// �������� �� ����
	if (frame > 5)
	{
		frame -= 5;
	}

	// ������������ �����
	character_sprite.setTextureRect(sf::IntRect(size_texture_x * int(frame), size_texture_y * 4, size_texture_x, size_texture_y));
	// �������
	if (character_sprite.getScale().x > 0)
	{
		character_sprite.setScale(sf::Vector2f(-character_sprite.getScale().x, character_sprite.getScale().y));
	}
}

void Character::move_animation_right(float delta_time)
{
	// ����������� ����� �������
	if (speed == diagonal_speed)
	{
		frame += delta_time / 2;
	}
	else
	{
		frame += delta_time;
	}

	// �������� �� ����
	if (frame > 5)
	{
		frame -= 5;
	}

	// ������������ �����
	character_sprite.setTextureRect(sf::IntRect(size_texture_x * int(frame), size_texture_y * 4, size_texture_x, size_texture_y));

	// �������
	if (character_sprite.getScale().x < 0)
	{
		character_sprite.setScale(sf::Vector2f(-character_sprite.getScale().x, character_sprite.getScale().y));
	}
}

void Character::move_animation_up(float delta_time)
{
	// ����������� ����� �������
	if (speed == diagonal_speed)
	{
		frame += delta_time / 2;
	}
	else
	{
		frame += delta_time;
	}

	// �������� �� ����
	if (frame > 5)
	{
		frame -= 5;
	}

	// ������������ �����
	character_sprite.setTextureRect(sf::IntRect(size_texture_x * int(frame), size_texture_y * 5, size_texture_x, size_texture_y));
}

void Character::move_animation_down(float delta_time)
{
	// ����������� ����� �������
	if (speed == diagonal_speed)
	{
		frame += delta_time / 2;
	}
	else
	{
		frame += delta_time;
	}

	// �������� �� ����
	if (frame > 5)
	{
		frame -= 5;
	}

	// ������������ �����
	character_sprite.setTextureRect(sf::IntRect(size_texture_x * int(frame), size_texture_y * 3, size_texture_x, size_texture_y));
}

void Character::idle_animation(float delta_time)
{
	// ����������� ����� �������
	if (speed == diagonal_speed)
	{
		frame += delta_time / 2;
	}
	else
	{
		frame += delta_time;
	}

	// �������� �� ����
	if (frame > 5)
	{
		frame -= 5;
	}

	// ������������ �����
	character_sprite.setTextureRect(sf::IntRect(size_texture_x * int(frame), size_texture_y * 0, size_texture_x, size_texture_y));
}

void Character::set_health(float new_health) {
	// ������ � ��� ��'����� ��������
	if (new_health > 0)
	{
		gain_damage(health - new_health);
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
	// ������������ �������
	is_alive = status;
}

void Character::set_position(sf::Vector2f position)
{
	character_sprite.setPosition(position);
}

float Character::get_health() const { return health; }

float Character::get_damage() const { return damage; }

bool Character::is_character_attacking() const
{
	return is_attacking;
}

bool Character::get_can_move()
{
	return can_move;
}

void Character::move(float delta_time) {
	if (!is_attacking)
	{
		old_position = get_character_position();

		// ��������� ����� ���������� ����� ��� ���� �� �������
		bool is_key_pressed_a = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
		bool is_key_pressed_d = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
		bool is_key_pressed_w = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
		bool is_key_pressed_s = sf::Keyboard::isKeyPressed(sf::Keyboard::S);

		// ���
		if (is_key_pressed_a && is_key_pressed_w || is_key_pressed_a && is_key_pressed_s || is_key_pressed_d && is_key_pressed_s || is_key_pressed_d && is_key_pressed_w)
			speed = diagonal_speed;
		else
			speed = diagonal_speed * 1.3;

		if (is_key_pressed_a) move_left(delta_time); is_attacking = false;
		if (is_key_pressed_d) move_right(delta_time); is_attacking = false;
		if (is_key_pressed_w) move_up(delta_time); is_attacking = false;
		if (is_key_pressed_s) move_down(delta_time); is_attacking = false;
		can_move = true;
	}
	else
	{
		can_move = false;
	}

	if (get_character_position() == old_position && !is_attacking)
	{
		move_status = STAND;
		idle_animation(delta_time);
	}
}

void Character::gain_damage(float x)
{
	character_health.lose_health(x);
}

bool Character::get_live_status() const { return is_alive; }

sf::Vector2f Character::get_character_position() const { return character_sprite.getPosition(); }

sf::Sprite Character::get_character_sprite() const
{
	return character_sprite;
}

float Character::get_frame() const
{
	return frame;
}

void Character::detect_colision(Map& map_lvl, sf::FloatRect rect)
{
	// ��������� ������� ��� ������� ���糿
	std::vector<sf::Sprite> colision_sprite_arr = map_lvl.get_colision_sprite_arr();

	// ��������� ���������� ��������� ������
	sf::FloatRect character_bounds = sf::FloatRect{ rect };

	// ������� ���糿
	if (can_move)
	{
		for (int i = 0; i < colision_sprite_arr.size(); i++)
		{
			sf::FloatRect obj_bounds = colision_sprite_arr[i].getGlobalBounds();

			// �������� �� �����
			if (character_bounds.intersects(obj_bounds))
			{
				set_position(old_position);
			}
		}

		if (!(get_character_position().x - map_lvl.get_tile_size() > 0 && get_character_position().y - map_lvl.get_tile_size() > 0 && get_character_position().x + map_lvl.get_tile_size() < map_lvl.get_map_size().x && get_character_position().y + map_lvl.get_tile_size() < map_lvl.get_map_size().y))
		{
			set_position(old_position);
		}
	}

}

void Character::show(sf::RenderWindow& window) {
	// ���� ������� �� �����
	window.draw(character_sprite);

	character_health.set_health_bar_position(character_sprite.getPosition());
	window.draw(character_health.get_health_bar());
}