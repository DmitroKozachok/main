#include "SettingMenu.h"
#include <iostream>

SettingMenu::SettingMenu(PlayerCamera& camera) : StandartMenu("Resources/menu/Main_Menu_BG.jpg", 2, 4)
{
	// створення тексту
	text_arr[0].set_size(60);
	text_arr[0].set_string("Setting Menu");

	text_arr[1].set_size(30);
	text_arr[1].set_string("Window mode:");

	// створення кнопок
	gyper_text_arr[0].set_size(30);
	gyper_text_arr[0].set_string("1280X720");

	gyper_text_arr[1].set_size(30);
	gyper_text_arr[1].set_string("1024X768");

	gyper_text_arr[2].set_size(30);
	gyper_text_arr[2].set_string("720X360");

	gyper_text_arr[3].set_size(30);
	gyper_text_arr[3].set_string("Continue");

}

void SettingMenu::set_position(PlayerCamera& camera, sf::Vector2f border_size, sf::RenderWindow& window)
{
	// встановлення позиції об'єктів в залежності від вікна
	camera.set_position(sf::Vector2f{ 0.f, 0.f }, sf::Vector2f{ window.getSize() });
	camera.set_size(sf::Vector2f{ (float)window.getSize().x, (float)window.getSize().y });

	text_arr[0].set_position({ camera.get_size().x * 0.5f, camera.get_size().y * 0.2f });
	text_arr[1].set_position({ camera.get_size().x * 0.5f, camera.get_size().y * 0.4f });

	gyper_text_arr[0].set_position({ camera.get_size().x * 0.15f, camera.get_size().y * 0.6f });
	gyper_text_arr[1].set_position({ camera.get_size().x * 0.5f, camera.get_size().y * 0.6f });
	gyper_text_arr[2].set_position({ camera.get_size().x * 0.85f, camera.get_size().y * 0.6f });
	gyper_text_arr[3].set_position({ camera.get_size().x * 0.15f, camera.get_size().y * 0.8f });

	// редагування зображення
	background_sprite.setPosition(camera.get_size().x * 0.5f, camera.get_size().y * 0.5f);
	background_sprite.setScale(camera.get_size().x / background_image.getSize().x, camera.get_size().y / background_image.getSize().y);
}

void SettingMenu::show(sf::RenderWindow& window, PlayerCamera& camera)
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

void SettingMenu::click_processing(sf::RenderWindow& window, sf::Event event)
{
	if (gyper_text_arr[0].is_button_pressed(event))
	{
		window.setSize(sf::Vector2u{ 1280, 720 }); // кнопка 1280X720
	}
	else if (gyper_text_arr[1].is_button_pressed(event))
	{
		window.setSize(sf::Vector2u{ 1024, 768 }); // кнопка 1024X768
	}
	else if (gyper_text_arr[2].is_button_pressed(event))
	{
		window.setSize(sf::Vector2u{ 720, 360 }); // кнопка 720X360
	}
	else if (gyper_text_arr[3].is_button_pressed(event))
	{
		set_status(false); // кнопка продовжити гру
	}

}
