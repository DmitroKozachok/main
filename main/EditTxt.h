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
	EditTxt(std::string font_path); // створення тексту із певним шрифтом

	void set_string(std::string string); // зміна стрічки
	void set_position(sf::Vector2f position); // зміна розиції
	void set_size(float size);

	sf::Text get_txt(); // повертає текст
	sf::Vector2f get_position() const; // повертає позицію

	void show(sf::RenderWindow& window); // вивід

};

