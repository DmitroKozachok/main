// ���� ��� ������ � ������ ���
#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <fstream>
#include <iostream>

struct char_and_coords // ���������, ��� ������ ������, ���� ������� �� ������ ����
{
	char ch;

	int x;
	int y;
};

class Map
{
private:

	int height; // ������ �����
	int width; // ������ �����
	int tile_size; // ����� ������ �����
	int scale;
	char** map_arr; // ����� ������� �����
	std::string path; // ���� �� �������� �����
	char_and_coords* symbol_coord_arr; // ����� ���������� �� ������� ��� ����������� �����
	int symbol_coord_arr_size; // ����� ������ ����������

	sf::Image map_image; // �������� ��������
	sf::Texture map_texture; // �������� ��������
	sf::Sprite map_sprite; // ������ �����

	void load_config(std::string file_config_path, std::string file_code_path); // ������������ ����������� �����
	void load_arr(std::string file_path); // �������� ������

public:
	Map(std::string file_config_path, std::string file_arr_path, std::string file_code_path); // �����������, �� ���������� ������������ �����

	void draw(sf::RenderWindow& window); // ���������� �����

};
