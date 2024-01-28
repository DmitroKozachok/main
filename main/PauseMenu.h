// ���� ��� �������� ����
#pragma once

#include "StandartMenu.h"
#include "PlayerCamera.h"
#include "MainMenu.h"

class PauseMenu : public StandartMenu
{
public:
	PauseMenu(PlayerCamera& camera); // ��������� ����

	void set_position(PlayerCamera& camera, sf::Vector2f border_size, sf::RenderWindow& window); // ������������ ������� ��'����

	void show(sf::RenderWindow& window, PlayerCamera& camera) override; // ���� �����

	void click_processing(sf::Event event, MainMenu& main_menu); // ������� ���������� �� ������ ����

};

