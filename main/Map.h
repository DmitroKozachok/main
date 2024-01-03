// клас для роботи з картою гри
#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>

struct char_and_coords // структура, яка містить символ, який відповідає за певний тайл
{
	char ch;

	int x;
	int y;
	int x_under;
	int y_under;

	bool is_colision;
};

class Map
{
private:

	int height; // висота карти
	int width; // ширина карти
	int tile_size; // розмір одного тайлу
	int scale; // збільшення окремого тайлу
	char** map_arr; // масив символів карти
	std::string path; // шлях до тайлсету карти
	char_and_coords* symbol_coord_arr; // масив координатів та символів для відображення карти
	int symbol_coord_arr_size; // розмір масиву координатів

	sf::Image map_image; // картинка тайлсету
	sf::Texture map_texture; // текстура тайлсету
	sf::Sprite map_sprite; // спрайт карти

	void load_config(std::string file_config_path, std::string file_code_path); // встановлення налаштувань карти
	void load_arr(std::string file_path); // загрузка масиву

public:
	Map(std::string file_config_path, std::string file_arr_path, std::string file_code_path); // конструктор, що встановлює налаштування карти

	void draw(sf::RenderWindow& window); // промальова карти

	sf::Vector2f get_map_size() const;
	int get_tile_size() const;
	int get_scale() const;
	char_and_coords* get_cord_arr() const;
	char** get_map_arr() const;
	int get_symbol_coord_arr_size() const;

};

