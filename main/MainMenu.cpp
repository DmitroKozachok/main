#include "MainMenu.h"
#include <iostream>

MainMenu::MainMenu(PlayerCamera& camera) : StandartMenu("Resources/menu/Main_Menu_BG.jpg", 1, 5)
{
	// ��������� ������
	text_arr[0].set_size(60);
	text_arr[0].set_string("Main Menu");

	// ��������� ������
	gyper_text_arr[0].set_size(30);
	gyper_text_arr[0].set_string("Start");

	gyper_text_arr[1].set_size(30);
	gyper_text_arr[1].set_string("Settings");

	gyper_text_arr[2].set_size(30);
	gyper_text_arr[2].set_string("Load");

	gyper_text_arr[3].set_size(30);
	gyper_text_arr[3].set_string("Save");

	gyper_text_arr[4].set_size(30);
	gyper_text_arr[4].set_string("Exit");

}

void MainMenu::set_position(PlayerCamera& camera, sf::Vector2f border_size, sf::RenderWindow& window)
{
	// ������������ ������� ��'���� � ��������� �� ����
	camera.set_position(sf::Vector2f{ 0.f, 0.f }, sf::Vector2f{ window.getSize() });
	camera.set_size(sf::Vector2f{ (float)window.getSize().x, (float)window.getSize().y });

	text_arr[0].set_position({ camera.get_size().x * 0.5f, camera.get_size().y * 0.15f });
	gyper_text_arr[0].set_position({ camera.get_size().x * 0.15f, camera.get_size().y * 0.4f });
	gyper_text_arr[1].set_position({ camera.get_size().x * 0.15f, camera.get_size().y * 0.5f });
	gyper_text_arr[2].set_position({ camera.get_size().x * 0.15f, camera.get_size().y * 0.6f });
	gyper_text_arr[3].set_position({ camera.get_size().x * 0.15f, camera.get_size().y * 0.7f });
	gyper_text_arr[4].set_position({ camera.get_size().x * 0.15f, camera.get_size().y * 0.8f });

	// ����������� ����������
	background_sprite.setPosition(camera.get_size().x * 0.5f, camera.get_size().y * 0.5f);
	background_sprite.setScale(camera.get_size().x / background_image.getSize().x, camera.get_size().y / background_image.getSize().y);
}

void MainMenu::show(sf::RenderWindow& window, PlayerCamera& camera)
{
	// ���� ��� ��������
	for (int i = 0; i < gyper_text_amount; i++)
	{
		gyper_text_arr[i].hover(window, camera);
	}
	
	window.draw(background_sprite);
	
	for (int i = 0; i < text_amount; i++) {
		text_arr[i].show(window);
	}

	for (int i = 0; i < gyper_text_amount; i++) {
		gyper_text_arr[i].show(window);
	}
}

void MainMenu::click_processing(sf::RenderWindow& window, sf::Event event, Game_Music &music, SettingMenu& setting_menu)
{
	if (gyper_text_arr[0].is_button_pressed(event))
	{
		is_open = false; // ������ ������
		music.background_Music_in_Menu.stop_play_this_music();
		music.background_music_in_world.start_play_this_music();
	}
	else if (gyper_text_arr[1].is_button_pressed(event))
	{
		//������ �������� �����������
		setting_menu.set_status(true);
		set_status(false);
	}
	else if (gyper_text_arr[2].is_button_pressed(event))
	{
		//������ Load
		std::cout << "Load" << std::endl;
	}
	else if (gyper_text_arr[3].is_button_pressed(event))
	{
		//������ Save
		std::cout << "Save" << std::endl;
	}
	else if (gyper_text_arr[4].is_button_pressed(event))
	{
		window.close(); // ������ ������
	}

}
