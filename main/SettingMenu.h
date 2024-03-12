// ���� ��� ���� �����������
#pragma once

#include "StandartMenu.h"
#include "PlayerCamera.h"

class SettingMenu : public StandartMenu
{
public:
	SettingMenu(PlayerCamera& camera); // ��������� ����

	void set_position(PlayerCamera& camera, sf::Vector2f border_size, sf::RenderWindow& window); // ������������ ������� ��'����

	void show(sf::RenderWindow& window, PlayerCamera& camera) override; // ���� �����

	bool is_continue_pressed(sf::RenderWindow& window, sf::Event event);

	void click_processing(sf::RenderWindow& window, sf::Event event); // ������� ���������� ������ ����

};