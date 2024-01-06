// ���� ��� ��������� ����
#pragma once

#include "StandartMenu.h"
#include "PlayerCamera.h"

class MainMenu : public StandartMenu
{
public:
	MainMenu(PlayerCamera& camera); // ��������� ����

	void set_position(PlayerCamera& camera, sf::Vector2f border_size, sf::RenderWindow& window); // ������������ ������� ��'����

	void show(sf::RenderWindow& window) override; // ���� �����

	void click_processing(sf::RenderWindow& window, sf::Event event); // ������� ���������� ������ ����

};