#include "MainMenu.h"
#include <iostream>

MainMenu::MainMenu(PlayerCamera& camera) : StandartMenu("Resources/menu/Main_Menu_BG.jpg", 1, 5)
{
	// створення тексту
	text_arr[0].set_size(60);
	text_arr[0].set_string("Main Menu");

	// створення кнопок
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
	// встановлення позиції об'єктів в залежності від вікна
	camera.set_position(sf::Vector2f{ 0.f, 0.f }, sf::Vector2f{ window.getSize() });
	camera.set_size(sf::Vector2f{ (float)window.getSize().x, (float)window.getSize().y });

	text_arr[0].set_position({ camera.get_size().x * 0.5f, camera.get_size().y * 0.15f });
	gyper_text_arr[0].set_position({ camera.get_size().x * 0.15f, camera.get_size().y * 0.4f });
	gyper_text_arr[1].set_position({ camera.get_size().x * 0.15f, camera.get_size().y * 0.5f });
	gyper_text_arr[2].set_position({ camera.get_size().x * 0.15f, camera.get_size().y * 0.6f });
	gyper_text_arr[3].set_position({ camera.get_size().x * 0.15f, camera.get_size().y * 0.7f });
	gyper_text_arr[4].set_position({ camera.get_size().x * 0.15f, camera.get_size().y * 0.8f });

	// редагування зображення
	background_sprite.setPosition(camera.get_size().x * 0.5f, camera.get_size().y * 0.5f);
	background_sprite.setScale(camera.get_size().x / background_image.getSize().x, camera.get_size().y / background_image.getSize().y);
}

void MainMenu::show(sf::RenderWindow& window, PlayerCamera& camera)
{
	// вивід усіх елементів
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

void MainMenu::click_processing(sf::RenderWindow& window, sf::Event event, std::vector<Game_Music>& music, SettingMenu& setting_menu, Player& player, std::vector<NPC>& npcs, std::vector<Enemy>& enemies, std::vector<std::string>& dialogs, GameSaver game_saver)
{
	if (gyper_text_arr[0].is_button_pressed(event))
	{
		//is_open = false; // кнопка старту

		// створення персонажу заново
		game_saver.delete_all_file();
		player.set_position(sf::Vector2f(2900.f, 460.f));
		player.set_health(100.f);

		// створення ворогів заново
		for (auto& enemy : enemies)
		{
			enemy.set_live_status(true);
			enemy.set_health(100.f);
			enemy.set_position(enemy.get_start_position());
		}

		// скидання діалогів
		for (auto& dialog : dialogs)
		{
			dialog = "";
		}

		bool bg_menu_chek = false;
		bool bg_world_1_chek = false;
		for (auto& it : music) {
			if (it.get_path_this_music() == "Resources/Music/bg_menu.wav") {
				it.stop_play_this_music();
				bg_menu_chek = true;
			}
			if (it.get_path_this_music() == "Resources/Music/bg_world_1.wav") {
				it.start_play_this_music();
				bg_world_1_chek = true;
			}
			if (bg_world_1_chek && bg_menu_chek) {
				break;
			}
		}
	}
	else if (gyper_text_arr[1].is_button_pressed(event))
	{
		//кнопка відкриття налаштувань
		setting_menu.set_status(true);
		set_status(false);
	}
	else if (gyper_text_arr[2].is_button_pressed(event))
	{
		//кнопка Load
		game_saver.load_game(player, npcs, enemies, DialogSystem::all_complate_dialog);
		set_status(false);
	}
	else if (gyper_text_arr[3].is_button_pressed(event))
	{
		//кнопка Save
		game_saver.save_game(player, npcs, enemies, DialogSystem::all_complate_dialog);
	}
	else if (gyper_text_arr[4].is_button_pressed(event))
	{
		window.close(); // кнопка виходу
	}

}
