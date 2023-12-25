// ���� ��� ��������� ����
#pragma once

#include "StandartMenu.h"
#include "PlayerCamera.h"

class MainMenu : public StandartMenu
{
public:
	MainMenu(PlayerCamera& camera, sf::RenderWindow& window); // ��������� ����

	void set_position(PlayerCamera& camera); // ������������ ������� ��'����

	void show(sf::RenderWindow& window) override; // ���� �����
};