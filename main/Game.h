// ���� ��� ������� ��� ���� � ������ ���
#pragma once
#include <SFML/Graphics.hpp>
#include "Character.h"
#include "EditTxt.h"

sf::Clock clock; // ��������� ��������� ���

class Game
{
private:

	float game_timer; // ��������� �������� ����

	void event_processing(sf::RenderWindow& window, Character& character); // ������� ����

public:
	void play_game(); // ������ ���
};

