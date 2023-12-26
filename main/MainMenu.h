// ���� ��� ��������� ����
#pragma once

#include "StandartMenu.h"
#include "PlayerCamera.h"

class MainMenu : public StandartMenu
{
public:
	MainMenu(PlayerCamera& camera); // ��������� ����

	void set_position(PlayerCamera& camera, sf::RenderWindow& window); // ������������ ������� ��'����

	void show(sf::RenderWindow& window) override; // ���� �����
};