// ���� ��� ������� ��� ���� � ������ ���
#pragma once
#include <SFML/Graphics.hpp>
#include "Character.h"
#include "EditTxt.h"
#include "Enemy.h"

class Game
{
private:
	void event_processing(sf::RenderWindow& window, Character& character, float delta_time, Enemy& enemy); // ������� ����

public:
	void play_game(); // ������ ���
};

