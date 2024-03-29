#include "Player.h"

void Player::attack_animation_down(float delta_time)
{
    // ���� ��� ����, ����������� ��������
    if (is_attacking) {
        frame += delta_time;

        // ��������, �� �������� �������� ��������
        if (frame > 3) {
            frame = 0;
            is_attacking = false; // �������� ���� ����� ���� ����, �� �������� ����������
        }

        // ������������ �����
        character_sprite.setTextureRect(sf::IntRect(size_texture_x * int(frame), size_texture_y * 6, size_texture_x, size_texture_y));

    }

}

void Player::attack_animation_up(float delta_time)
{
    // ���� ��� ����, ����������� ��������
    if (is_attacking) {
        frame += delta_time;

        // ��������, �� �������� �������� ��������
        if (frame > 3) {
            frame = 0;
            is_attacking = false; // �������� ���� ����� ���� ����, �� �������� ����������
        }

        // ������������ �����
        character_sprite.setTextureRect(sf::IntRect(size_texture_x * int(frame), size_texture_y * 8, size_texture_x, size_texture_y));

    }
}

void Player::attack_animation_left(float delta_time)
{
    // ���� ��� ����, ����������� ��������
    if (is_attacking) {
        frame += delta_time;

        // ��������, �� �������� �������� ��������
        if (frame > 3) {
            frame = 0;
            is_attacking = false; // �������� ���� ����� ���� ����, �� �������� ����������
        }

        // ������������ �����
        character_sprite.setTextureRect(sf::IntRect(size_texture_x * int(frame), size_texture_y * 7, size_texture_x, size_texture_y));

        // �������
        if (character_sprite.getScale().x > 0) {
            character_sprite.setScale(sf::Vector2f(-character_sprite.getScale().x, character_sprite.getScale().y));
        }

    }

}

void Player::attack_animation_right(float delta_time)
{
    // ���� ��� ����, ����������� ��������
    if (is_attacking) {
        frame += delta_time;

        // ��������, �� �������� �������� ��������
        if (frame > 3) {
            frame = 0;
            is_attacking = false; // �������� ���� ����� ���� ����, �� �������� ����������
        }

        // ������������ �����
        character_sprite.setTextureRect(sf::IntRect(size_texture_x * int(frame), size_texture_y * 7, size_texture_x, size_texture_y));

        // �������
        if (character_sprite.getScale().x < 0) {
            character_sprite.setScale(sf::Vector2f(-character_sprite.getScale().x, character_sprite.getScale().y));
        }

    }
}

Player::Player(int size_x, int size_y, std::string image_way, sf::Vector2f position, sf::Vector2f scale, std::string name) : Character(size_x, size_y, image_way, position, scale, 10, 100, 7, name)
{
    character_health.set_health_bar_x(200.f);
    character_health.set_health_bar_y(16.f);
    character_health.set_health_bar();
    character_health.set_c_for_damage(2.f);
    character_health.set_health_bar_position({ character_sprite.getPosition().x - 320.f, character_sprite.getPosition().y - 170.f });
}

void Player::move(float delta_time, Game_Music& sound_walk)
{
    Character::move(delta_time);    // ������ ���
    if (move_status == UP || move_status == LEFT || move_status == RIGHT || move_status == DOWN) { // �������� ����
        sound_walk.start_play_this_music();  // ������ ���� �� ���� (�����)
        
    }
}

void Player::attack(sf::Event event , float delta_time, Game_Music& sound_player_attack)
{
    // �������� �� �����
	if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
		is_attacking = true;
        sound_player_attack.start_play_this_music();
	}

    // ���������� ��������

    if (move_status == LEFT) attack_animation_left(delta_time);
    if (move_status == RIGHT) attack_animation_right(delta_time);
    if (move_status == UP) attack_animation_up(delta_time);
    if (move_status == DOWN) attack_animation_down(delta_time);
    if (move_status == STAND) attack_animation_down(delta_time);

}

void Player::show_p(sf::RenderWindow& window, PlayerCamera camera) {
    // ���� ������� �� �����
    window.draw(character_sprite);

    character_health.set_health_origin(sf::Vector2f(-(character_health.get_health_bar_x() / 2), 0.f));
    character_health.set_health_bar_position({ camera.get_position().x - 390.f, camera.get_position().y - 180.f });
    window.draw(character_health.get_health_bar());
}