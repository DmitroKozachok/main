/*Клас для роботи з текстом*/

#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class EditTxt
{
protected:
	sf::Text text_string; // стрічка
	sf::Font text_font; // шрифт тексту
	sf::Vector2f text_position; // позиція тексту

public:
	EditTxt(); // створення стандартного тексту
	EditTxt(std::string string); // створення введеного тексту

	void set_string(std::string string); // зміна стрічки
	
	sf::Vector2f get_position() const; // повертає позицію

	void show(sf::RenderWindow& window); // вивід

};

