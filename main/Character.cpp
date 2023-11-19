#include "Character.h"

// коефіцієнт анімації впливає на швидкість показу анімації: чим більший, тим швидше
int animation_c = 5000000;

Character::Character() : health{ 100 }, damage{ 5 }, is_alive{ true }, speed{ 2 }, frame{ 0.f } {
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

Character::Character(int size_x, int size_y, std::string image_way, sf::Vector2f position, sf::Vector2f scale) : size_texture_x{ size_x }, size_texture_y{ size_y }, frame{ 0.f }
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

	//встановлення координат анімації
	

}

void Character::move_left(float delta_time)
{
	// зміна позиції
	character_sprite.move(speed * delta_time, 0);

	// програвання анімації
	move_animation_left(delta_time);
}

void Character::move_right(float delta_time)
{
	// зміна позиції
	character_sprite.move(-speed * delta_time, 0);

	// програвання анімації
	move_animation_right(delta_time);
}

void Character::move_up(float delta_time)
{
	// зміна позиції
	character_sprite.move(0, speed * delta_time);

	// програвання анімації
	move_animation_up(delta_time);
}

void Character::move_down(float delta_time)
{
	// зміна позиції
	character_sprite.move(0, -speed * delta_time);

	// програвання анімації
	move_animation_down(delta_time);
}

void Character::move_animation_left(float delta_time)
{
	frame += animation_c * delta_time; // прогортання кадру анімації

	// перевірка на кадр
	if (frame > 6)
	{
		frame -= 6;
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
	frame += animation_c * delta_time; // прогортання кадру анімації

	// перевірка на кадр
	if (frame > 6)
	{
		frame -= 6;
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
	frame += animation_c * delta_time; // прогортання кадру анімації

	// перевірка на кадр
	if (frame > 6)
	{
		frame -= 6;
	}

	// встановлення кадру
	character_sprite.setTextureRect(sf::IntRect(size_texture_x * int(frame), size_texture_y * 5, size_texture_x, size_texture_y));
}

void Character::move_animation_down(float delta_time)
{
	frame += animation_c * delta_time; // прогортання кадру анімації

	// перевірка на кадр
	if (frame > 6)
	{
		frame -= 6;
	}

	// встановлення кадру
	character_sprite.setTextureRect(sf::IntRect(size_texture_x * int(frame), size_texture_y * 3, size_texture_x, size_texture_y));
}

void Character::idle_animation(float delta_time)
{
	frame += animation_c * delta_time; // прогортання кадру анімації

	// перевірка на кадр
	if (frame > 6)
	{
		frame -= 6;
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
	// перевірка на смерть
	is_alive = status;
}

float Character::get_health() const { return health; }

float Character::get_damage() const { return damage; }

void Character::move(sf::Event event, float delta_time) {
	// перевірка чи нажата клавіша
	if (event.type == sf::Event::KeyPressed) {
		// отримання стану натиснутих клавіш для руху по діагоналі
		bool is_key_pressed_a = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
		bool is_key_pressed_d = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
		bool is_key_pressed_w = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
		bool is_key_pressed_s = sf::Keyboard::isKeyPressed(sf::Keyboard::S);

		// рух
		if (is_key_pressed_a) move_left(delta_time);
		if (is_key_pressed_d) move_right(delta_time);
		if (is_key_pressed_w) move_up(delta_time);
		if (is_key_pressed_s) move_down(delta_time);

	}
}

bool Character::get_live_status() const { return is_alive; }

void Character::show(sf::RenderWindow& window) {
	// вивід спрайту на екран
	window.draw(character_sprite);
}