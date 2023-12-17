// ���� ��� ������ � �������
#include <SFML/Graphics.hpp>
#include "Character.h"
#pragma once

class PlayerCamera
{
private:
	sf::View camera; // ������
	sf::Vector2f position; // ������� ������
	sf::Vector2f size; // ����� ������

public:
	PlayerCamera(Character& character, sf::Vector2f size, sf::RenderWindow& window);

	void set_position(sf::Vector2f new_size, sf::RenderWindow& window);

	void draw(Character& character, sf::RenderWindow& window);
};

