#include "MainMenu.h"
#include <iostream>

MainMenu::MainMenu(PlayerCamera& camera) : StandartMenu("---", 1, 3)
{
	text_arr[0].set_size(60);
	text_arr[0].set_string("Main Menu");

	gyper_text_arr[0].set_size(30);
	gyper_text_arr[0].set_string("Start");

	gyper_text_arr[1].set_size(30);
	gyper_text_arr[1].set_string("Settings");

	gyper_text_arr[2].set_size(30);
	gyper_text_arr[2].set_string("Exit");
}

void MainMenu::set_position(PlayerCamera& camera, sf::RenderWindow& window)
{
	camera.set_position(sf::Vector2f{ 0.f, 0.f }, window);
	camera.set_size(sf::Vector2f{ (float)window.getSize().x, (float)window.getSize().y });

	text_arr[0].set_position({ camera.get_size().x * 0.5f, camera.get_size().y * 0.35f });
	gyper_text_arr[0].set_position({ camera.get_size().x * 0.15f, camera.get_size().y * 0.6f });
	gyper_text_arr[1].set_position({ camera.get_size().x * 0.15f, camera.get_size().y * 0.7f });
	gyper_text_arr[2].set_position({ camera.get_size().x * 0.15f, camera.get_size().y * 0.8f });
}

void MainMenu::show(sf::RenderWindow& window)
{
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
