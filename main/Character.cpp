#include "Character.h"

Character::Character() : health{ 100 }, damage{ 5 }, is_alive{ true }, speed{ 15 }, diagonal_speed{ speed / 1.3f }, frame{0.f} {
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

Character::Character(int size_x, int size_y, std::string image_way, sf::Vector2f position, sf::Vector2f scale, float speed, float health, float damage) : health{ health }, damage{ damage }, is_alive{ true }, speed{ speed }, diagonal_speed{ speed / 1.3f }, frame{ 0.f }, size_texture_x{ size_x }, size_texture_y{ size_y }, is_attacking{ false }
{
	// встановлення картинки
	character_image.loadFromFile(image_way);
	
	// встановлення текстури
	character_texture.loadFromImage(character_image);

	// встановлення спрайту
	character_sprite.setTexture(character_texture);
	character_sprite.setTextureRect(sf::IntRect(0, 0, size_x, size_y));
	character_sprite.setScale(scale);
	character_sprite.setOrigin(sf::Vector2f(size_x / 2.f, size_y / 2.f));

	// встановлення позиції
	character_sprite.setPosition(position);

}

void Character::move_left(float delta_time)
{
	// зміна позиції
	character_sprite.move(-speed * delta_time, 0);

	// зміна положення анімації
	move_status = LEFT;

	// програвання анімації
	move_animation_left(delta_time);
}

void Character::move_right(float delta_time)
{
	// зміна позиції
	character_sprite.move(speed * delta_time, 0);

	// зміна положення анімації
	move_status = RIGHT;

	// програвання анімації
	move_animation_right(delta_time);
}

void Character::move_up(float delta_time)
{
	// зміна позиції
	character_sprite.move(0, -speed * delta_time);

	// зміна положення анімації
	move_status = UP;

	// програвання анімації
	move_animation_up(delta_time);
}

void Character::move_down(float delta_time)
{
	// зміна позиції
	character_sprite.move(0, speed * delta_time);

	// зміна положення анімації
	move_status = DOWN;

	// програвання анімації
	move_animation_down(delta_time);
}

void Character::move_animation_left(float delta_time)
{
	// прогортання кадру анімації
	if (speed == diagonal_speed)
	{
		frame += delta_time / 2;
	}
	else
	{
		frame += delta_time;
	}
	

	// перевірка на кадр
	if (frame > 5)
	{
		frame -= 5;
	}

	// встановлення кадру
	character_sprite.setTextureRect(sf::IntRect(size_texture_x * int(frame), size_texture_y * 4, size_texture_x, size_texture_y));
	// інверсія
	if (character_sprite.getScale().x > 0)
	{
		character_sprite.setScale(sf::Vector2f(-character_sprite.getScale().x, character_sprite.getScale().y));
	}
}

void Character::move_animation_right(float delta_time)
{
	// прогортання кадру анімації
	if (speed == diagonal_speed)
	{
		frame += delta_time / 2;
	}
	else
	{
		frame += delta_time;
	}

	// перевірка на кадр
	if (frame > 5)
	{
		frame -= 5;
	}

	// встановлення кадру
	character_sprite.setTextureRect(sf::IntRect(size_texture_x * int(frame), size_texture_y * 4, size_texture_x, size_texture_y));

	// інверсія
	if (character_sprite.getScale().x < 0)
	{
		character_sprite.setScale(sf::Vector2f(-character_sprite.getScale().x, character_sprite.getScale().y));
	}
}

void Character::move_animation_up(float delta_time)
{
	// прогортання кадру анімації
	if (speed == diagonal_speed)
	{
		frame += delta_time / 2;
	}
	else
	{
		frame += delta_time;
	}

	// перевірка на кадр
	if (frame > 5)
	{
		frame -= 5;
	}

	// встановлення кадру
	character_sprite.setTextureRect(sf::IntRect(size_texture_x * int(frame), size_texture_y * 5, size_texture_x, size_texture_y));
}

void Character::move_animation_down(float delta_time)
{
	// прогортання кадру анімації
	if (speed == diagonal_speed)
	{
		frame += delta_time / 2;
	}
	else
	{
		frame += delta_time;
	}

	// перевірка на кадр
	if (frame > 5)
	{
		frame -= 5;
	}

	// встановлення кадру
	character_sprite.setTextureRect(sf::IntRect(size_texture_x * int(frame), size_texture_y * 3, size_texture_x, size_texture_y));
}

void Character::idle_animation(float delta_time)
{
	// прогортання кадру анімації
	if (speed == diagonal_speed)
	{
		frame += delta_time / 2;
	}
	else
	{
		frame += delta_time;
	}

	// перевірка на кадр
	if (frame > 5)
	{
		frame -= 5;
	}

	// встановлення кадру
	character_sprite.setTextureRect(sf::IntRect(size_texture_x * int(frame), size_texture_y * 0, size_texture_x, size_texture_y));
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
	// встановлення статусу
	is_alive = status;
}

void Character::set_position(sf::Vector2f position)
{
	character_sprite.setPosition(position);
}

float Character::get_health() const { return health; }

float Character::get_damage() const { return damage; }

bool Character::get_can_move()
{
	return can_move;
}

void Character::move(float delta_time) {
	if (!is_attacking)
	{
		old_position = get_character_position();

		// отримання стану натиснутих клавіш для руху по діагоналі
		bool is_key_pressed_a = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
		bool is_key_pressed_d = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
		bool is_key_pressed_w = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
		bool is_key_pressed_s = sf::Keyboard::isKeyPressed(sf::Keyboard::S);

		// рух
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

bool Character::get_live_status() const { return is_alive; }

sf::Vector2f Character::get_character_position() const { return character_sprite.getPosition(); }

sf::Sprite Character::get_character_sprite() const
{
	return character_sprite;
}

void Character::detect_colision(Map& map_lvl, sf::FloatRect rect)
{
	// створення вектора для обробки колізії
	std::vector<sf::Sprite> colision_sprite_arr = map_lvl.get_colision_sprite_arr();

	// отримання глобальних координат гравця
	sf::FloatRect character_bounds = sf::FloatRect{ rect };

	// обробка колізії
	if (can_move)
	{
		for (int i = 0; i < colision_sprite_arr.size(); i++)
		{
			sf::FloatRect obj_bounds = colision_sprite_arr[i].getGlobalBounds();

			// перевірка на колізію
			if (character_bounds.intersects(obj_bounds) || !(get_character_position().x - map_lvl.get_tile_size() > 0 && get_character_position().y - map_lvl.get_tile_size() > 0 && get_character_position().x + map_lvl.get_tile_size() < map_lvl.get_map_size().x && get_character_position().y + map_lvl.get_tile_size() < map_lvl.get_map_size().y))
			{
				set_position(old_position);
			}
		}

	}

}

void Character::show(sf::RenderWindow& window) {
	// вивід спрайту на екран
	window.draw(character_sprite);
}