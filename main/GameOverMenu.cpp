#include "GameOverMenu.h"

GameOverMenu::GameOverMenu(PlayerCamera& camera) : StandartMenu("Resources/menu/Main_Menu_BG.jpg", 1, 4)
{
	text_arr[0].set_size(60);
	text_arr[0].set_string("Game Over!");

	gyper_text_arr[0].set_size(30);
	gyper_text_arr[0].set_string("Continue");

	gyper_text_arr[1].set_size(30);
	gyper_text_arr[1].set_string("Settings");

	gyper_text_arr[2].set_size(30);
	gyper_text_arr[2].set_string("To MainMenu");

	gyper_text_arr[3].set_size(30);
	gyper_text_arr[3].set_string("Exit");
}

void GameOverMenu::set_position(PlayerCamera& camera, sf::Vector2f border_size, sf::RenderWindow& window)
{
	// ������������ ������� ��'���� � ��������� �� ����
	text_arr[0].set_position({ camera.get_position().x, camera.get_position().y - 150.f });
	gyper_text_arr[0].set_position({ camera.get_position().x, camera.get_position().y - 50.f });
	gyper_text_arr[1].set_position({ camera.get_position().x, camera.get_position().y + 0.f });
	gyper_text_arr[2].set_position({ camera.get_position().x, camera.get_position().y + 50.f });
	gyper_text_arr[3].set_position({ camera.get_position().x, camera.get_position().y + 100.f });

	// ����������� ����������
	background_sprite.setPosition(camera.get_position().x, camera.get_position().y);
	background_sprite.setScale((camera.get_size().x / background_image.getSize().x) / 2, (camera.get_size().y / background_image.getSize().y) / 1.2f);
}

void GameOverMenu::show(sf::RenderWindow& window, PlayerCamera& camera)
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

void GameOverMenu::click_processing(sf::RenderWindow& window, sf::Event event, MainMenu& main_menu, SettingMenu& setting_menu, Player& player)
{
	if (gyper_text_arr[0].is_button_pressed(event))
	{
		is_open = false; // ������ ����������� ���
		player.set_health(100.f);
	}
	else if (gyper_text_arr[1].is_button_pressed(event))
	{
		//������ �������� �����������
		setting_menu.set_status(true);
		set_status(false);
	}
	else if (gyper_text_arr[2].is_button_pressed(event))
	{
		// ������ ������ � ������� ����
		main_menu.set_status(true);
		set_status(false);
	}
	else if (gyper_text_arr[3].is_button_pressed(event))
	{
		window.close();
	}
}