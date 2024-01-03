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

Character::Character(int size_x, int size_y, std::string image_way, sf::Vector2f position, sf::Vector2f scale) : health{ 100 }, damage{ 5 }, is_alive{ true }, speed{ 20 }, diagonal_speed{ speed / 1.3f }, frame{ 0.f }, size_texture_x{ size_x }, size_texture_y{ size_y }, is_attacking{ false }
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

void Character::move(sf::Event& event, float delta_time) {
	if (!is_attacking)
	{
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
		is_move = true;
	}
	else
	{
		is_move = false;
	}
}

bool Character::get_live_status() const { return is_alive; }

sf::Vector2f Character::get_character_position() const { return character_sprite.getPosition(); }

void Character::detect_colision(Map& map_lvl)
{
	// ���������� ���������
	int x = get_character_position().x / (map_lvl.get_tile_size() * map_lvl.get_scale());
	int y = get_character_position().y / (map_lvl.get_tile_size() * map_lvl.get_scale());

	// ������������ �����
	char** map_arr = map_lvl.get_map_arr();
	char_and_coords* cord_arr = map_lvl.get_cord_arr();

	// ������� ���糿
	if (is_move)
	{
		if (move_status == LEFT)
		{
			for (int i = 0; i < map_lvl.get_symbol_coord_arr_size(); i++)
			{
				if (x - 1 >= 0)
				{
					if (cord_arr[i].ch == map_arr[y][x - 1] && cord_arr[i].is_colision)
					{
						set_position(sf::Vector2f{ get_character_position().x + 1.7f, get_character_position().y });
					}
				}
				else {
					set_position(sf::Vector2f{ get_character_position().x + 0.1f, get_character_position().y });
				}
				
			}

		}
		if (move_status == RIGHT)
		{
			for (int i = 0; i < map_lvl.get_symbol_coord_arr_size(); i++)
			{
				if (x + 1 <= map_lvl.get_map_size().x / (map_lvl.get_tile_size() * map_lvl.get_scale()))
				{
					if (cord_arr[i].ch == map_arr[y][x + 1] && cord_arr[i].is_colision)
					{
						set_position(sf::Vector2f{ get_character_position().x - 1.7f, get_character_position().y });
					}
				}
				else {
					set_position(sf::Vector2f{ get_character_position().x - 0.1f, get_character_position().y });
				}

			}
		}
		if (move_status == DOWN)
		{
			for (int i = 0; i < map_lvl.get_symbol_coord_arr_size(); i++)
			{
				if (x - 1 >= 0)
				{
					if (cord_arr[i].ch == map_arr[y][x - 1] && cord_arr[i].is_colision)
					{
						set_position(sf::Vector2f{ get_character_position().x + 1.7f, get_character_position().y });
					}
				}
				else {
					set_position(sf::Vector2f{ get_character_position().x + 0.1f, get_character_position().y });
				}

			}

			for (int i = 0; i < map_lvl.get_symbol_coord_arr_size(); i++)
			{
				if (x + 1 <= map_lvl.get_map_size().x / (map_lvl.get_tile_size() * map_lvl.get_scale()))
				{
					if (cord_arr[i].ch == map_arr[y][x + 1] && cord_arr[i].is_colision)
					{
						set_position(sf::Vector2f{ get_character_position().x - 1.7f, get_character_position().y });
					}
				}
				else {
					set_position(sf::Vector2f{ get_character_position().x - 0.1f, get_character_position().y });
				}

			}

			for (int i = 0; i < map_lvl.get_symbol_coord_arr_size(); i++)
			{
				if (y + 1 < map_lvl.get_map_size().y / (map_lvl.get_tile_size() * map_lvl.get_scale()))
				{
					if (cord_arr[i].ch == map_arr[y + 1][x] && cord_arr[i].is_colision)
					{
						set_position(sf::Vector2f{ get_character_position().x, get_character_position().y - 1.7f });
					}
				}
				else {
					set_position(sf::Vector2f{ get_character_position().x, get_character_position().y - 0.1f });
				}

			}
		}
		if (move_status == UP)
		{
			for (int i = 0; i < map_lvl.get_symbol_coord_arr_size(); i++)
			{
				if (x - 1 >= 0)
				{
					if (cord_arr[i].ch == map_arr[y][x - 1] && cord_arr[i].is_colision)
					{
						set_position(sf::Vector2f{ get_character_position().x + 1.7f, get_character_position().y });
					}
				}
				else {
					set_position(sf::Vector2f{ get_character_position().x + 0.1f, get_character_position().y });
				}

			}

			for (int i = 0; i < map_lvl.get_symbol_coord_arr_size(); i++)
			{
				if (x + 1 <= map_lvl.get_map_size().x / (map_lvl.get_tile_size() * map_lvl.get_scale()))
				{
					if (cord_arr[i].ch == map_arr[y][x + 1] && cord_arr[i].is_colision)
					{
						set_position(sf::Vector2f{ get_character_position().x - 1.7f, get_character_position().y });
					}
				}
				else {
					set_position(sf::Vector2f{ get_character_position().x - 0.1f, get_character_position().y });
				}

			}

			for (int i = 0; i < map_lvl.get_symbol_coord_arr_size(); i++)
			{
				if (y - 1 >= 0)
				{
					if (cord_arr[i].ch == map_arr[y][x] && cord_arr[i].is_colision)
					{
						set_position(sf::Vector2f{ get_character_position().x, get_character_position().y + 1.7f });
					}
				}
				else{
					set_position(sf::Vector2f{ get_character_position().x, get_character_position().y + 0.1f });
				}

			}
		}
	}

}

void Character::show(sf::RenderWindow& window) {
	// ���� ������� �� �����
	window.draw(character_sprite);
}