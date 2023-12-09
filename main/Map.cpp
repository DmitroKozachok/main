#include "Map.h"

void Map::load_config(std::string file_path)
{
    std::ifstream file(file_path);

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

				std::cout << width << "  " << height << std::endl;
			}
			else if (line == 2)
			{
				tile_size = std::stoi(string);
			}

			line++;
		}
	}
	
}
void Map::load_arr(std::string file_path)
{
	std::ifstream file(file_path);
	
	map_arr = new char* [height / tile_size];
	for (int i = 0; i < height / tile_size; i++)
	{
		map_arr[i] = new char[width / tile_size];
	}

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
	
	for (int i = 0; i < height / tile_size; i++)
	{
		for (int j = 0; j < width / tile_size; j++)
		{
			std::cout << map_arr[i][j] << " ";
		}
		std::cout << std::endl;
	}

}
Map::Map(std::string file_config_path, std::string file_arr_path)
{
	load_config(file_config_path);
	load_arr(file_arr_path);

	map_image.loadFromFile(path);
	map_texture.loadFromImage(map_image);
	map_sprite.setTexture(map_texture);

	map_sprite.setPosition(0, 0);
	map_sprite.setScale(10, 10);
}

void Map::draw(sf::RenderWindow& window, std::string file_code_path)
{
	for (int i = 0; i < height / tile_size; i++)
	{
		for (int j = 0; j < width / tile_size; j++)
		{
			std::ifstream file(file_code_path);
			std::string string;
			if (!file)
			{
				std::cout << "ERROR!!!" << std::endl;
			}
			else 
			{
				while (std::getline(file, string))
				{
					if (string[0] == map_arr[i][j])
					{
						int x = std::stoi(string.substr(string.find_first_of(' ') + 1, string.find_last_of(' ')));
						int y = std::stoi(string.substr(string.find_last_of(' ') + 1));

						//std::cout << x << " " << y << std::endl;

						map_sprite.setTextureRect(sf::IntRect(tile_size * x, tile_size * y, tile_size, tile_size));
						window.draw(map_sprite);
					}
				}
			}

			map_sprite.setPosition(tile_size * j, tile_size * i);
			std::cout << map_sprite.getPosition().x << " " << map_sprite.getPosition().y << std::endl;
		}

	}
}
