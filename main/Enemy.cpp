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

Enemy::Enemy(int size_x, int size_y, std::string image_way, sf::Vector2f position, sf::Vector2f scale) : Character(size_x, size_y, image_way, position, scale, 5, 100, 1) {} // делегування батьківського конструктора

void Enemy::detect_colision_with_player(Character& player, sf::FloatRect enemy_rect, sf::FloatRect player_rect, float delta_time)
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
			attack(delta_time, player);
		}
		
	}
	else
	{
		is_attacking = false;
	}
}

void Enemy::attack(float delta_time, Character& player)
{
	if (is_attacking != true)
	{
		is_attacking = true;
	}

	// зменшення здоров'я гравця
	player.set_health(player.get_health() - damage);

	// анімація атаки
	attack_animation(delta_time);

}

void Enemy::move(sf::Vector2f player_position, float game_timer)
{
	old_position = character_sprite.getPosition();
    sf::Vector2f enemy_position = character_sprite.getPosition(); // теперішня позиція ворога на екрані
    
    if (enemy_position.x > player_position.x + 22) {
        move_left(game_timer);
    }
	else if (enemy_position.x < player_position.x - 22)
	{
		move_right(game_timer);
	}
	if (enemy_position.y > player_position.y + 22) {
        move_up(game_timer);
    }
	else if (enemy_position.y < player_position.y + 22)
	{
		move_down(game_timer);
	}
}