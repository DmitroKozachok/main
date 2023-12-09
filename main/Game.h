// ���� ��� ������� ��� ���� � ������ ���
#pragma once
#include <SFML/Graphics.hpp>
#include "Character.h"
#include "EditTxt.h"
#include "Enemy.h"
#include "GyperText.h"
#include "Map.h"

#define ANIMATION_TIME 0.3f

class Game
{
private:
	void event_processing(sf::RenderWindow& window, Character& character, float delta_time, Enemy& enemy, GyperText& gt); // ������� ����

public:
	void play_game(); // ������ ���
};

