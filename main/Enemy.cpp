#include "Enemy.h"

void Enemy::move_animation_left(float delta_time)
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
	character_sprite.setTextureRect(sf::IntRect(size_texture_x * int(frame), size_texture_y * 1, size_texture_x, size_texture_y));
	// �������
	if (character_sprite.getScale().x > 0)
	{
		character_sprite.setScale(sf::Vector2f(-character_sprite.getScale().x, character_sprite.getScale().y));
	}
}

void Enemy::move_animation_right(float delta_time)
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
	character_sprite.setTextureRect(sf::IntRect(size_texture_x * int(frame), size_texture_y * 1, size_texture_x, size_texture_y));

	// �������
	if (character_sprite.getScale().x < 0)
	{
		character_sprite.setScale(sf::Vector2f(-character_sprite.getScale().x, character_sprite.getScale().y));
	}
}

void Enemy::move_animation_up(float delta_time)
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
	character_sprite.setTextureRect(sf::IntRect(size_texture_x * int(frame), size_texture_y * 1, size_texture_x, size_texture_y));
}

void Enemy::move_animation_down(float delta_time)
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
	character_sprite.setTextureRect(sf::IntRect(size_texture_x * int(frame), size_texture_y * 1, size_texture_x, size_texture_y));
}

void Enemy::idle_animation(float delta_time)
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
	if (frame > 3)
	{
		frame -= 3;
	}

	// ������������ �����
	character_sprite.setTextureRect(sf::IntRect(size_texture_x * int(frame), size_texture_y * 0, size_texture_x, size_texture_y));
}

void Enemy::attack_animation(float delta_time)
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
	if (frame > 3)
	{
		frame -= 3;
	}

	// ������������ �����
	character_sprite.setTextureRect(sf::IntRect(size_texture_x * int(frame), size_texture_y * 3, size_texture_x, size_texture_y));
}

Enemy::Enemy() : Character() {}

Enemy::Enemy(int size_x, int size_y, std::string image_way, sf::Vector2f position, sf::Vector2f scale, std::string name) : Character(size_x, size_y, image_way, position, scale, 5, 100, 1, name) // ����������� ������������ ������������
{
	character_health.set_health_bar_position(character_sprite.getPosition());
}

void Enemy::detect_colision_with_player(Character& player, sf::FloatRect enemy_rect, sf::FloatRect player_rect, float delta_time)
{
	// ��������� ���������� ��������� ������ �� ������
	sf::FloatRect enemy_bounds = enemy_rect;
	sf::FloatRect player_bounds = player_rect;

	// �������� �� �����
	if (enemy_bounds.intersects(player_bounds))
	{
		// ������� ����� ������
		if (player.is_character_attacking() && player.get_frame() < 1)
		{
			set_health(get_health() - player.get_damage());
		}

		if (frame < 1) // ��� �� ������ �������� ������'�
		{
			// ������� ������ ������
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

	// ��������� ������'� ������
	player.set_health(player.get_health() - damage);

	// ������� �����
	attack_animation(delta_time);

}

bool Enemy::check_collision(Map& map_lvl, sf::Vector2f position)
{
	std::vector<sf::Sprite> colision_sprite_arr = map_lvl.get_colision_sprite_arr();
	sf::FloatRect enemy_bounds = character_sprite.getGlobalBounds();

	for (int i = 0; i < colision_sprite_arr.size(); i++)
	{
		sf::FloatRect obj_bounds = colision_sprite_arr[i].getGlobalBounds();

		// �������� �� �����
		if (enemy_bounds.intersects(obj_bounds))
		{
			return true; // ����� ��������
		}
	}

	return false; // ����� �� ��������
}

bool Enemy::can_move_left(sf::Vector2f position, Map& map_lvl)
{
	sf::FloatRect next_position = character_sprite.getGlobalBounds();
	next_position.left -= speed; // ���������� ������ ������

	if (!check_collision(map_lvl, next_position.getPosition()))
	{
		return true; // ����� ���� �������� ������
	}

	return false; // ����� �� ���� �������� ������
}

bool Enemy::can_move_right(sf::Vector2f position, Map& map_lvl)
{
	sf::FloatRect next_position = character_sprite.getGlobalBounds();
	next_position.left += speed; // ���������� ������ ��������

	if (!check_collision(map_lvl, next_position.getPosition()))
	{
		return true; // ����� ���� �������� ��������
	}

	return false; // ����� �� ���� �������� ��������
}

bool Enemy::can_move_up(sf::Vector2f position, Map& map_lvl)
{
	sf::FloatRect next_position = character_sprite.getGlobalBounds();
	next_position.top -= speed; // ���������� ������ �����

	if (!check_collision(map_lvl, next_position.getPosition()))
	{
		return true; // ����� ���� �������� �����
	}

	return false; // ����� �� ���� �������� �����
}

bool Enemy::can_move_down(sf::Vector2f position, Map& map_lvl)
{
	sf::FloatRect next_position = character_sprite.getGlobalBounds();
	next_position.top += speed; // ���������� ������ ����

	if (!check_collision(map_lvl, next_position.getPosition()))
	{
		return true; // ����� ���� �������� ����
	}

	return false; // ����� �� ���� �������� ����
}

void Enemy::move(sf::Vector2f player_position, float game_timer, Map& map)
{
	old_position = character_sprite.getPosition();
    sf::Vector2f enemy_position = character_sprite.getPosition(); // �������� ������� ������ �� �����
    
	if (check_collision(map, enemy_position)) {		
		if (move_status == LEFT) {
			if (enemy_position.y > player_position.y + 22 && abs(enemy_position.y - player_position.y) < 170 && abs(enemy_position.x - player_position.x) < 300) {
				move_up(game_timer);
			}
			else if (enemy_position.y < player_position.y + 22 && abs(enemy_position.y - player_position.y) < 170 && abs(enemy_position.x - player_position.x) < 300) {
				move_down(game_timer);
			}
		}
		else if (move_status == RIGHT) {
			if (enemy_position.y > player_position.y + 22 && abs(enemy_position.y - player_position.y) < 170 && abs(enemy_position.x - player_position.x) < 300) {
				move_up(game_timer);
			}
			else if (enemy_position.y < player_position.y + 22 && abs(enemy_position.y - player_position.y) < 170 && abs(enemy_position.x - player_position.x) < 300) {
				move_down(game_timer);
			}
		}
		else if (move_status == UP) {
			if (enemy_position.x > player_position.x + 22 && abs(enemy_position.x - player_position.x) < 300 && abs(enemy_position.y - player_position.y) < 170) {
				move_left(game_timer);
			}
			else if (enemy_position.x < player_position.x - 22 && abs(enemy_position.x - player_position.x) < 300 && abs(enemy_position.y - player_position.y) < 170) {
				move_right(game_timer);
			}
		}
		else if (move_status == DOWN) {
			if (enemy_position.x > player_position.x + 22 && abs(enemy_position.x - player_position.x) < 300 && abs(enemy_position.y - player_position.y) < 170) {
				move_left(game_timer);
			}
			else if (enemy_position.x < player_position.x - 22 && abs(enemy_position.x - player_position.x) < 300 && abs(enemy_position.y - player_position.y) < 170) {
				move_right(game_timer);
			}
		}
		else
		{
			idle_animation(game_timer);
		}
	}
	else {
		if (enemy_position.x > player_position.x + 22 && abs(enemy_position.x - player_position.x) < 300 && abs(enemy_position.y - player_position.y) < 170) {
			move_left(game_timer);
		}
		else if (enemy_position.x < player_position.x - 22 && abs(enemy_position.x - player_position.x) < 300 && abs(enemy_position.y - player_position.y) < 170)
		{
			move_right(game_timer);
		}
		else
		{
			idle_animation(game_timer);
		}
		if (enemy_position.y > player_position.y + 22 && abs(enemy_position.y - player_position.y) < 170 && abs(enemy_position.x - player_position.x) < 300) {
			move_up(game_timer);
		}
		else if (enemy_position.y < player_position.y + 22 && abs(enemy_position.y - player_position.y) < 170 && abs(enemy_position.x - player_position.x) < 300)
		{
			move_down(game_timer);
		}
		else
		{
			idle_animation(game_timer);
		}
	}
}