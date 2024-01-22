// Клас для роботи з гравцем

#pragma once
#include "Character.h"
#include "Game_Music.h"

class Player : public Character
{
private:
	void attack_animation_down(float delta_time); // анімація нижньої атаки
	void attack_animation_up(float delta_time); // анімація верхньої атаки
	void attack_animation_left(float delta_time); // анімація лівої атаки
	void attack_animation_right(float delta_time); // анімація правої атаки

public:

	Player(int size_x, int size_y, std::string image_way, sf::Vector2f position, sf::Vector2f scale); // конструктор гравця

	void move(float delta_time, Game_Music& my_music);

	void attack(sf::Event event, float delta_time); // обробка атаки
	
};

