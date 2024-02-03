// ���� ��� ������ � ������ ���
#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>

struct char_and_coords // ���������, ��� ������ ������, ���� ������� �� ������ ����
{
	char ch;

	int x;
	int y;
	int x_under;
	int y_under;

	bool is_colision;
	bool is_enemy_spawn;
};

class Map
{
private:

	int height; // ������ �����
	int width; // ������ �����
	int tile_size; // ����� ������ �����
	int scale; // ��������� �������� �����
	char** map_arr; // ����� ������� �����
	std::string path; // ���� �� �������� �����
	char_and_coords* symbol_coord_arr; // ����� ���������� �� ������� ��� ����������� �����
	int symbol_coord_arr_size; // ����� ������ ����������
	std::vector<sf::Sprite> colision_sprite_arr; // ����� �������� ��'����
	std::vector<sf::Sprite> enemy_spawn_sprite_arr; // ����� ��'���� ������

	sf::Image map_image; // �������� ��������
	sf::Texture map_texture; // �������� ��������
	sf::Sprite map_sprite; // ������ �����

	void load_config(std::string file_config_path, std::string file_code_path); // ������������ ����������� �����
	void load_arr(std::string file_path); // �������� ������

public:
	Map(std::string file_config_path, std::string file_arr_path, std::string file_code_path); // �����������, �� ���������� ������������ �����

	void draw(sf::RenderWindow& window); // ���������� �����

	sf::Vector2f get_map_size() const;
	int get_tile_size() const;
	int get_scale() const;
	char_and_coords* get_cord_arr() const;
	char** get_map_arr() const;
	int get_symbol_coord_arr_size() const;
	std::vector<sf::Sprite> get_colision_sprite_arr() const;
	std::vector<sf::Sprite> get_enemy_spawn_sprite_arr() const;
};

