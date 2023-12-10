// клас для роботи з картою гри
#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <fstream>
#include <iostream>

struct char_and_coords
{
	char ch;

	int x;
	int y;
};

class Map
{
private:

	int height; // висота карти
	int width; // ширина карти
	int tile_size; // розмір одного тайлу
	int scale;
	char** map_arr; // масив символів карти
	std::string path; // шлях до тайлсету карти
	char_and_coords* symbol_coord_arr;
	int symbol_coord_arr_size;

	sf::Image map_image; // картинка тайлсету
	sf::Texture map_texture; // текстура тайлсету
	sf::Sprite map_sprite; // спрайт карти

	void load_config(std::string file_config_path, std::string file_code_path); // встановлення налаштувань карти
	void load_arr(std::string file_path); // загрузка масиву

public:
	Map(std::string file_config_path, std::string file_arr_path, std::string file_code_path);

	void draw(sf::RenderWindow& window);

};

