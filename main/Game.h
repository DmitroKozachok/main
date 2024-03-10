// Клас для обробки усіх подій в процесі гри
#pragma once
#include <SFML/Graphics.hpp>
#include <chrono>
#include <thread>
#include <vector>
#include <algorithm>
#include "EditTxt.h"
#include "Enemy.h"
#include "Game_Music.h"
#include "GyperText.h"
#include "Map.h"
#include "MainMenu.h"
#include "PlayerCamera.h"
#include "Player.h"
#include "NPC.h"
#include "DialogSystem.h"
#include "PauseMenu.h"
#include "SettingMenu.h"
#include "Transition.h"
#include "SlimeFactory.h"
#include "MiniMap.h"
#include "GameOverMenu.h"
#define ANIMATION_TIME 0.25f

class Game
{
private:
	void event_processing(sf::RenderWindow& window, Player& player, float delta_time, std::vector<Enemy>& enemies, MainMenu& main_menu, PlayerCamera& camera, Map& map, std::vector<NPC>& npcs, Game_Music& my_music, PauseMenu& pause_menu, SettingMenu& setting_menu, Transition transition_player, GameOverMenu& game_over_menu); // обробка подій
	void draw(Map map_lvl, Player player, std::vector<Enemy> enemies, PlayerCamera& camera, sf::RenderWindow& window, MainMenu main_menu, std::vector<NPC>& npcs, PauseMenu& pause_menu, SettingMenu& setting_menu, MiniMap& mini_map, GameOverMenu& game_over_menu); // промальовка об'єктів
	void enemy_spawn(std::vector<Enemy>& enemies, Map& map); // спавн ворогів

public:
	void play_game(); // запуск гри
};

