// Клас для обробки усіх подій в процесі гри
#pragma once
#include <SFML/Graphics.hpp>
#include "EditTxt.h"
#include "Enemy.h"
#include "Game_Music.h"
#include "GyperText.h"
#include "Map.h"
#include "MainMenu.h"
#include "PlayerCamera.h"
#include "Player.h"

#define ANIMATION_TIME 0.3f

class Game
{
private:
	void event_processing(sf::RenderWindow& window, Player& player, float delta_time, Enemy& enemy, GyperText& gt); // обробка подій

public:
	void play_game(); // запуск гри
};

