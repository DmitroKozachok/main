// ���� ��� ������� ��� ���� � ������ ���
#pragma once
#include <SFML/Graphics.hpp>
#include "Character.h"
#include "EditTxt.h"

class Game
{
private:
	void event_processing(sf::RenderWindow& window, Character& character); // ������� ����

public:
	void play_game();
};

