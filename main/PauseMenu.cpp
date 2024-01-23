#include "PauseMenu.h"

PauseMenu::PauseMenu(PlayerCamera& camera) : StandartMenu("Resources/menu/Main_Menu_BG.jpg", 1, 3) {
	// створення тексту
	text_arr[0].set_size(60);
	text_arr[0].set_string("Main Menu");

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
	camera.set_position(sf::Vector2f{ 0.f, 0.f }, sf::Vector2f{ window.getSize() });
	camera.set_size(sf::Vector2f{ window.getSize().x * 0.5f,  window.getSize().y * 0.5f });

	text_arr[0].set_position({ camera.get_size().x * 0.5f, camera.get_size().y * 0.35f });
	gyper_text_arr[0].set_position({ camera.get_size().x * 0.15f, camera.get_size().y * 0.6f });
	gyper_text_arr[1].set_position({ camera.get_size().x * 0.15f, camera.get_size().y * 0.7f });
	gyper_text_arr[2].set_position({ camera.get_size().x * 0.15f, camera.get_size().y * 0.8f });

	// редагування зображення
	background_sprite.setPosition(sf::Vector2f(400.f, 3000.f));
	background_sprite.setScale(camera.get_size().x / background_image.getSize().x, camera.get_size().y / background_image.getSize().y);
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
