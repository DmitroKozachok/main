// ���� ��� ��������� ����
#pragma once
#include "Game_Music.h"
#include "StandartMenu.h"
#include "PlayerCamera.h"
#include "SettingMenu.h"

class MainMenu : public StandartMenu
{
public:
	MainMenu(PlayerCamera& camera); // ��������� ����

	void set_position(PlayerCamera& camera, sf::Vector2f border_size, sf::RenderWindow& window); // ������������ ������� ��'����

	void show(sf::RenderWindow& window, PlayerCamera& camera) override; // ���� �����

	void click_processing(sf::RenderWindow& window, sf::Event event, SettingMenu& setting_menu); // ������� ���������� ������ ����
	void click_processing(sf::RenderWindow& window, sf::Event event, Game_Music &music); // ������� ���������� ������ ����

};