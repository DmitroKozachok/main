#include "MainMenu.h"

MainMenu::MainMenu() : StandartMenu("---", 1, 3)
{
	text_arr[0].set_size(120);
	text_arr[0].set_string("Main Menu");
	text_arr[0].set_position({ 1000.f, 200.f });

	gyper_text_arr[0].set_size(60);
	gyper_text_arr[0].set_string("Start");
	gyper_text_arr[0].set_position({ 340.f, 600.f });

	gyper_text_arr[1].set_size(60);
	gyper_text_arr[1].set_string("Settings");
	gyper_text_arr[1].set_position({ 340.f, 700.f });

	gyper_text_arr[2].set_size(60);
	gyper_text_arr[2].set_string("Exit");
	gyper_text_arr[2].set_position({ 340.f, 800.f });
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
