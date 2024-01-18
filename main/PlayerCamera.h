// ���� ��� ������ � �������
#pragma once
#include <SFML/Graphics.hpp>
#include "Character.h"
#include <iostream>

class PlayerCamera
{
private:
	sf::View camera; // ������
	sf::Vector2f position; // ������� ������
	sf::Vector2f size; // ����� ������

public:
	PlayerCamera(sf::Vector2f center, sf::Vector2f size, sf::RenderWindow& window, sf::Vector2f border_size); // ����������� ������

	void set_position(sf::Vector2f new_position, sf::Vector2f border_size); // ������������ �������
	void set_size(sf::Vector2f new_size);

	sf::Vector2f get_size() const; // ��������� ������
	sf::Vector2f get_position() const; // ��������� �������

	void draw(sf::Vector2f center, sf::RenderWindow& window, sf::Vector2f border_size); // ����������� ������
};

