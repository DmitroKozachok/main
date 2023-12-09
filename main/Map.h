// ���� ��� ������ � ������ ���
#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <fstream>
#include <iostream>

class Map
{
private:
	int height; // ������ �����
	int width; // ������ �����
	int tile_size; // ����� ������ �����
	char** map_arr; // ����� ������� �����
	std::string path; // ���� �� �������� �����


	sf::Image map_image; // �������� ��������
	sf::Texture map_texture; // �������� ��������
	sf::Sprite map_sprite; // ������ �����

	void load_config(std::string file_path); // ������������ ����������� �����
	void load_arr(std::string file_path); // �������� ������

public:
	Map(std::string file_config_path, std::string file_arr_path);

	void draw(sf::RenderWindow& window, std::string file_code_path);

};

