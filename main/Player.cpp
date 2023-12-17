#include "Player.h"

void Player::attack_animation_down(float delta_time)
{
    // Якщо йде удар, програвайте анімацію
    if (is_attacking) {
        frame += delta_time;

        // Перевірте, чи анімація програла повністю
        if (frame > 3) {
            frame = 0;
            is_attacking = false; // Скидайте флаг удару після того, як анімація програлась
        }

        // Встановлення кадру
        character_sprite.setTextureRect(sf::IntRect(size_texture_x * int(frame), size_texture_y * 6, size_texture_x, size_texture_y));

    }

}

void Player::attack_animation_up(float delta_time)
{
    // Якщо йде удар, програвайте анімацію
    if (is_attacking) {
        frame += delta_time;

        // Перевірте, чи анімація програла повністю
        if (frame > 3) {
            frame = 0;
            is_attacking = false; // Скидайте флаг удару після того, як анімація програлась
        }

        // Встановлення кадру
        character_sprite.setTextureRect(sf::IntRect(size_texture_x * int(frame), size_texture_y * 8, size_texture_x, size_texture_y));

    }
}

void Player::attack_animation_left(float delta_time)
{
    // Якщо йде удар, програвайте анімацію
    if (is_attacking) {
        frame += delta_time;

        // Перевірте, чи анімація програла повністю
        if (frame > 3) {
            frame = 0;
            is_attacking = false; // Скидайте флаг удару після того, як анімація програлась
        }

        // Встановлення кадру
        character_sprite.setTextureRect(sf::IntRect(size_texture_x * int(frame), size_texture_y * 7, size_texture_x, size_texture_y));

        // Інверсія
        if (character_sprite.getScale().x > 0) {
            character_sprite.setScale(sf::Vector2f(-character_sprite.getScale().x, character_sprite.getScale().y));
        }

    }

}

void Player::attack_animation_right(float delta_time)
{
    // Якщо йде удар, програвайте анімацію
    if (is_attacking) {
        frame += delta_time;

        // Перевірте, чи анімація програла повністю
        if (frame > 3) {
            frame = 0;
            is_attacking = false; // Скидайте флаг удару після того, як анімація програлась
        }

        // Встановлення кадру
        character_sprite.setTextureRect(sf::IntRect(size_texture_x * int(frame), size_texture_y * 7, size_texture_x, size_texture_y));

        // Інверсія
        if (character_sprite.getScale().x < 0) {
            character_sprite.setScale(sf::Vector2f(-character_sprite.getScale().x, character_sprite.getScale().y));
        }

    }
}

Player::Player(int size_x, int size_y, std::string image_way, sf::Vector2f position, sf::Vector2f scale) : Character(size_x, size_y, image_way, position, scale) {}

void Player::attack(sf::Event event , float delta_time)
{
    // перевірка на атаку
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		is_attacking = true;
	}

    // визначення анімації

    if (move_status == LEFT) attack_animation_left(delta_time);
    if (move_status == RIGHT) attack_animation_right(delta_time);
    if (move_status == UP) attack_animation_up(delta_time);
    if (move_status == DOWN) attack_animation_down(delta_time);

}
