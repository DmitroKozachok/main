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
#include "NPC.h"

#define ANIMATION_TIME 0.25f

class Game
{
private:
	void event_processing(sf::RenderWindow& window, Player& player, float delta_time, Enemy& enemy, MainMenu& main_menu, PlayerCamera& camera, Map& map, NPC& npc); // обробка подій
	void draw(Map map_lvl, Player player, Enemy enemy, PlayerCamera& camera, sf::RenderWindow& window, MainMenu main_menu, NPC& npc); // промальовка об'єктів

public:
	void play_game(); // запуск гри
};

