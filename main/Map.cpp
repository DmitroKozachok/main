#include "Map.h"

void Map::load_config(std::string file_config_path, std::string file_code_path)
{
	// ������������ ����� ������������
    std::ifstream file(file_config_path);

	// ������������ ������ � ����� ������������
	if (!file)
	{
		std::cout << "ERROR!!!" << std::endl;
	}
	else
	{
		std::string string;
		int line = 0;

		while (std::getline(file, string))
		{
			if (line == 0)
			{
				path = string;
			}
			else if (line == 1)
			{
				width = std::stoi(string.substr(0, string.find_first_of('X')));
				height = std::stoi(string.substr(string.find_first_of('X') + 1, string.length()));
			}
			else if (line == 2)
			{
				tile_size = std::stoi(string);
			}
			else if (line == 3)
			{
				scale = std::stoi(string);
			}

			line++;
		}
	}

	// ������������ ����� ��� ������������ ������ ������ ����������
	std::ifstream file_code1(file_code_path);

	symbol_coord_arr_size = 0;

	// ������������ ������
	if (!file_code1)
	{
		std::cout << "ERROR!!!" << std::endl;
	}
	else
	{
		std::string string;

		while (std::getline(file_code1, string))
		{
			symbol_coord_arr_size++;
		}

		symbol_coord_arr = new char_and_coords[symbol_coord_arr_size];
	}


	// ������������ ����� ��� ������������ ���������� �������� ������
	std::ifstream file_code2(file_code_path);

	std::string string2;
	int line2 = 0;

	// ������������ ���������
	if (!file_code2)
	{
		std::cout << "ERROR!!!" << std::endl;
	}
	else
	{
		while (std::getline(file_code2, string2))
		{
			/*symbol_coord_arr[line2].ch = string2[0];
			symbol_coord_arr[line2].x = std::stoi(string2.substr(string2.find_first_of(' ') + 1, string2.find_last_of(' ')));
			symbol_coord_arr[line2].y = std::stoi(string2.substr(string2.find_last_of(' ') + 1));
			symbol_coord_arr[line2].lvl_layers = std::stoi(string2.substr(string2.find_first_of(lvl_find_char)+1));*/
			/////////////////
			char lvl_find_char = '#';
			char lvl_under_pos = ',';
			symbol_coord_arr[line2].ch = string2[0];
			if (string2.find_first_of(lvl_find_char) != std::string::npos) {
				symbol_coord_arr[line2].x = std::stoi(string2.substr(string2.find_first_of(' ') + 1, string2.find_last_of(' ')));

				symbol_coord_arr[line2].y = std::stoi(string2.substr(string2.find_last_of(' ') + 1));

				symbol_coord_arr[line2].x_under = std::stoi(string2.substr(string2.find_last_of(lvl_find_char)+1, string2.find_first_of(lvl_under_pos)));

				symbol_coord_arr[line2].y_under = std::stoi(string2.substr(string2.find_last_of(lvl_under_pos) + 1));


			}
			else {
				symbol_coord_arr[line2].x = std::stoi(string2.substr(string2.find_first_of(' ') + 1, string2.find_last_of(' ')));
				symbol_coord_arr[line2].y = std::stoi(string2.substr(string2.find_last_of(' ') + 1));
				symbol_coord_arr[line2].x_under = -1;
				symbol_coord_arr[line2].y_under = -1;
			}


			/////////////////
			line2++;
		}
	}
	
}

void Map::load_arr(std::string file_path)
{
	// �������� ����� �����
	std::ifstream file(file_path);
	
	// ��������� ������ ����� ������� width X height
	map_arr = new char* [height];
	for (int i = 0; i < height; i++)
	{
		map_arr[i] = new char[width];
	}

	// ������������ ������
	if (!file)
	{
		std::cout << "ERROR!!!" << std::endl;
	}
	else
	{
		char ch;
		int i = 0, j = 0;
		while (file.get(ch)) {
			if (ch == '\n')
			{
				i++;
				j = 0;
			}
			else
			{
				map_arr[i][j] = ch;
				j++;
			}
		}
	}

}

Map::Map(std::string file_config_path, std::string file_arr_path, std::string file_code_path)
{
	// ������������ ������ ��� ������ � ������
	load_config(file_config_path, file_code_path);
	load_arr(file_arr_path);

	// ������������ ������� �����
	map_image.loadFromFile(path);
	map_texture.loadFromImage(map_image);

	map_sprite.setTexture(map_texture);
	map_sprite.setScale(scale, scale);
}

void Map::draw(sf::RenderWindow& window)
{
	// ����������� ����� �� ��������� ������ �������� � ����� ���������
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			map_sprite.setPosition((tile_size * j * scale), (tile_size * i * scale));

			for (int k = 0; k < symbol_coord_arr_size; k++)
			{
				if (map_arr[i][j] == symbol_coord_arr[k].ch)
				{
					if (symbol_coord_arr[k].x_under == -1) {
						map_sprite.setTextureRect(sf::IntRect(tile_size * symbol_coord_arr[k].x, tile_size * symbol_coord_arr[k].y, tile_size, tile_size));
						window.draw(map_sprite);
					}
					else {
						map_sprite.setTextureRect(sf::IntRect(tile_size * symbol_coord_arr[k].x_under, tile_size * symbol_coord_arr[k].y_under, tile_size, tile_size));
						window.draw(map_sprite);
						map_sprite.setTextureRect(sf::IntRect(tile_size * symbol_coord_arr[k].x, tile_size * symbol_coord_arr[k].y, tile_size, tile_size));
						window.draw(map_sprite);
					}
				}

			}

		}

	}
}



