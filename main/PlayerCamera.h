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
	PlayerCamera(Character& character, sf::Vector2f size, sf::RenderWindow& window); // ����������� ������

	void set_position(sf::Vector2f new_position, sf::RenderWindow& window); // ������������ �������
	void set_size(sf::Vector2f new_size);

	sf::Vector2f get_size() const; // ��������� ������
	sf::Vector2f get_position() const; // ��������� �������

	void draw(Character& character, sf::RenderWindow& window); // ����������� ������
};

