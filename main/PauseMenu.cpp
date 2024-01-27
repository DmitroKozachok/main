#include "PauseMenu.h"

PauseMenu::PauseMenu(PlayerCamera& camera) : StandartMenu("Resources/menu/Main_Menu_BG.jpg", 1, 3) {
	// створення тексту
	text_arr[0].set_size(60);
	text_arr[0].set_string("Pause Menu");

	// створення кнопок
	gyper_text_arr[0].set_size(30);
	gyper_text_arr[0].set_string("Start");

	gyper_text_arr[1].set_size(30);
	gyper_text_arr[1].set_string("Settings");

	gyper_text_arr[2].set_size(30);
	gyper_text_arr[2].set_string("Exit");
}

void PauseMenu::set_position(PlayerCamera& camera, sf::Vector2f border_size, sf::RenderWindow& window)
{
	// встановлення позиції об'єктів в залежності від вікна
	text_arr[0].set_position({ camera.get_position().x, camera.get_position().y - 150.f });
	gyper_text_arr[0].set_position({ camera.get_position().x, camera.get_position().y - 50.f });
	gyper_text_arr[1].set_position({ camera.get_position().x, camera.get_position().y + 25.f });
	gyper_text_arr[2].set_position({ camera.get_position().x, camera.get_position().y + 100.f });

	// редагування зображення
	background_sprite.setPosition(camera.get_position().x, camera.get_position().y);
	background_sprite.setScale((camera.get_size().x / background_image.getSize().x) / 2, (camera.get_size().y / background_image.getSize().y) / 1.2f);
}

void PauseMenu::show(sf::RenderWindow& window)
{
	// вивід усіх елементів
	for (int i = 0; i < gyper_text_amount; i++)
	{
		gyper_text_arr[i].hover(window);
	}

	window.draw(background_sprite);

	for (int i = 0; i < text_amount; i++) {
		text_arr[i].show(window);
	}

	for (int i = 0; i < gyper_text_amount; i++) {
		gyper_text_arr[i].show(window);
	}
}

void PauseMenu::click_processing(sf::RenderWindow& window, sf::Event event)
{
	if (gyper_text_arr[0].is_button_pressed(event))
	{
		is_open = false; // кнопка виходу
	}
	else if (gyper_text_arr[2].is_button_pressed(event))
	{
		window.close(); // кнопка старту
	}
}
