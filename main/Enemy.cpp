#include "Enemy.h"

void Enemy::move_animation_left(float delta_time)
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
	character_sprite.setTextureRect(sf::IntRect(size_texture_x * int(frame), size_texture_y * 1, size_texture_x, size_texture_y));
	// інверсія
	if (character_sprite.getScale().x > 0)
	{
		character_sprite.setScale(sf::Vector2f(-character_sprite.getScale().x, character_sprite.getScale().y));
	}
}

void Enemy::move_animation_right(float delta_time)
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
	character_sprite.setTextureRect(sf::IntRect(size_texture_x * int(frame), size_texture_y * 1, size_texture_x, size_texture_y));

	// інверсія
	if (character_sprite.getScale().x < 0)
	{
		character_sprite.setScale(sf::Vector2f(-character_sprite.getScale().x, character_sprite.getScale().y));
	}
}

void Enemy::move_animation_up(float delta_time)
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
	character_sprite.setTextureRect(sf::IntRect(size_texture_x * int(frame), size_texture_y * 1, size_texture_x, size_texture_y));
}

void Enemy::move_animation_down(float delta_time)
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
	character_sprite.setTextureRect(sf::IntRect(size_texture_x * int(frame), size_texture_y * 1, size_texture_x, size_texture_y));
}

void Enemy::idle_animation(float delta_time)
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
	if (frame > 3)
	{
		frame -= 3;
	}

	// встановлення кадру
	character_sprite.setTextureRect(sf::IntRect(size_texture_x * int(frame), size_texture_y * 0, size_texture_x, size_texture_y));
}

void Enemy::attack_animation(float delta_time)
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
	if (frame > 3)
	{
		frame -= 3;
	}

	// встановлення кадру
	character_sprite.setTextureRect(sf::IntRect(size_texture_x * int(frame), size_texture_y * 3, size_texture_x, size_texture_y));
}

Enemy::Enemy() : Character() {}

Enemy::Enemy(int size_x, int size_y, std::string image_way, sf::Vector2f position, sf::Vector2f scale, std::string name) : Character(size_x, size_y, image_way, position, scale, 5, 100, 1, name) // делегування батьківського конструктора
{
	character_health.set_health_bar_position(character_sprite.getPosition());
	start_position = position;
}

void Enemy::detect_colision_with_player(Character& player, sf::FloatRect enemy_rect, sf::FloatRect player_rect, float delta_time , Game_Music& sound_player_get_damage)
{
	// отримання глобальних координат гравця та ворога
	sf::FloatRect enemy_bounds = enemy_rect;
	sf::FloatRect player_bounds = player_rect;

	// перевірка на колізію
	if (enemy_bounds.intersects(player_bounds))
	{
		// обробка атаки гравця
		if (player.is_character_attacking() && player.get_frame() < 1)
		{
			set_health(get_health() - player.get_damage());
		}

		if (frame < 1) // шоб не завжди знімалось здоров'я
		{
			// обробка ворога гравця
			attack(delta_time, player , sound_player_get_damage);
		}
		
	}
	else
	{
		is_attacking = false;
	}
}

void Enemy::attack(float delta_time, Character& player, Game_Music& sound_player_get_damage)
{
	if (is_attacking != true)
	{
		is_attacking = true;
	}

	// зменшення здоров'я гравця
	player.set_health(player.get_health() - damage);
	sound_player_get_damage.start_play_this_music();

	// анімація атаки
	attack_animation(delta_time);

}

bool Enemy::check_collision(Map& map_lvl, sf::Vector2f position)
{
	std::vector<sf::Sprite> colision_sprite_arr = map_lvl.get_colision_sprite_arr();
	sf::FloatRect enemy_bounds = character_sprite.getGlobalBounds();

	if (can_move)
	{
		for (int i = 0; i < colision_sprite_arr.size(); i++)
		{
			sf::FloatRect obj_bounds = colision_sprite_arr[i].getGlobalBounds();

			// Перевірка на колізію
			if (enemy_bounds.intersects(obj_bounds))
			{
				return true; // Колізія виявлена
			}
		}
	}

	return false; // Колізія не виявлена
}

bool Enemy::can_move_left(sf::Vector2f position, Map& map_lvl)
{
	sf::FloatRect next_position = character_sprite.getGlobalBounds();
	next_position.left -= speed; // Перемістимо ворога ліворуч

	if (!check_collision(map_lvl, next_position.getPosition()))
	{
		return true; // Ворог може рухатися ліворуч
	}

	return false; // Ворог не може рухатися ліворуч
}

bool Enemy::can_move_right(sf::Vector2f position, Map& map_lvl)
{
	sf::FloatRect next_position = character_sprite.getGlobalBounds();
	next_position.left += speed; // Перемістимо ворога праворуч

	if (!check_collision(map_lvl, next_position.getPosition()))
	{
		return true; // Ворог може рухатися праворуч
	}

	return false; // Ворог не може рухатися праворуч
}

bool Enemy::can_move_up(sf::Vector2f position, Map& map_lvl)
{
	sf::FloatRect next_position = character_sprite.getGlobalBounds();
	next_position.top -= speed; // Перемістимо ворога вверх

	if (!check_collision(map_lvl, next_position.getPosition()))
	{
		return true; // Ворог може рухатися вверх
	}

	return false; // Ворог не може рухатися вверх
}

bool Enemy::can_move_down(sf::Vector2f position, Map& map_lvl)
{
	sf::FloatRect next_position = character_sprite.getGlobalBounds();
	next_position.top += speed; // Перемістимо ворога вниз

	if (!check_collision(map_lvl, next_position.getPosition()))
	{
		return true; // Ворог може рухатися вниз
	}

	return false; // Ворог не може рухатися вниз
}

void Enemy::move(sf::Vector2f player_position, float game_timer, Map& map)
{
	old_position = character_sprite.getPosition();
    sf::Vector2f enemy_position = character_sprite.getPosition(); // теперішня позиція ворога на екрані
    
	if (check_collision(map, enemy_position)) {		
		if (move_status == LEFT) {
			can_move = true;
			if (enemy_position.y > player_position.y + 22 && abs(enemy_position.y - player_position.y) < 170 && abs(enemy_position.x - player_position.x) < 300) {
				move_up(game_timer);
			}
			else if (enemy_position.y < player_position.y + 22 && abs(enemy_position.y - player_position.y) < 170 && abs(enemy_position.x - player_position.x) < 300) {
				move_down(game_timer);
			}
		}
		else if (move_status == RIGHT) {
			can_move = true;
			if (enemy_position.y > player_position.y + 22 && abs(enemy_position.y - player_position.y) < 170 && abs(enemy_position.x - player_position.x) < 300) {
				move_up(game_timer);
			}
			else if (enemy_position.y < player_position.y + 22 && abs(enemy_position.y - player_position.y) < 170 && abs(enemy_position.x - player_position.x) < 300) {
				move_down(game_timer);
			}
		}
		else if (move_status == UP) {
			can_move = true;
			if (enemy_position.x > player_position.x + 22 && abs(enemy_position.x - player_position.x) < 300 && abs(enemy_position.y - player_position.y) < 170) {
				move_left(game_timer);
			}
			else if (enemy_position.x < player_position.x - 22 && abs(enemy_position.x - player_position.x) < 300 && abs(enemy_position.y - player_position.y) < 170) {
				move_right(game_timer);
			}
		}
		else if (move_status == DOWN) {
			can_move = true;
			if (enemy_position.x > player_position.x + 22 && abs(enemy_position.x - player_position.x) < 300 && abs(enemy_position.y - player_position.y) < 170) {
				move_left(game_timer);
			}
			else if (enemy_position.x < player_position.x - 22 && abs(enemy_position.x - player_position.x) < 300 && abs(enemy_position.y - player_position.y) < 170) {
				move_right(game_timer);
			}
		}
		else
		{
			can_move = false;
			idle_animation(game_timer);
		}
	}
	else {
		if (enemy_position.x > player_position.x + 22 && abs(enemy_position.x - player_position.x) < 300 && abs(enemy_position.y - player_position.y) < 170) {
			can_move = true;
			move_left(game_timer);
		}
		else if (enemy_position.x < player_position.x - 22 && abs(enemy_position.x - player_position.x) < 300 && abs(enemy_position.y - player_position.y) < 170)
		{
			can_move = true;
			move_right(game_timer);
		}
		else
		{
			can_move = false;
			idle_animation(game_timer);
		}
		if (enemy_position.y > player_position.y + 22 && abs(enemy_position.y - player_position.y) < 170 && abs(enemy_position.x - player_position.x) < 300) {
			can_move = true;
			move_up(game_timer);
		}
		else if (enemy_position.y < player_position.y + 22 && abs(enemy_position.y - player_position.y) < 170 && abs(enemy_position.x - player_position.x) < 300)
		{
			can_move = true;
			move_down(game_timer);
		}
		else
		{
			can_move = false;
			idle_animation(game_timer);
		}
	}
}

sf::Vector2f Enemy::get_start_position()
{
	return start_position;
}
