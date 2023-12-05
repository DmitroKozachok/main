#pragma once
#include <SFML/Graphics.hpp>
#include "EditTxt.h"
#include "GyperText.h"

class StandartMenu
{
protected:
	sf::Image background_image; // задній фон
	EditTxt* text_arr; // текст без взаємодії
	GyperText* gyper_text_arr; // текст із взаємодією

	int text_amount; // кількість звичайного тексту
	int gyper_text_amount; // кількість гіпер-тексту

public:
	StandartMenu(std::string path, int text_amount, int gyper_text_amount);

	virtual void show(sf::RenderWindow& window) = 0; // стандартний вивід

	void set_background_image(std::string path);
	void set_text_amount(int new_text_amount);
	void set_gyper_text_amount(int new_gyper_text_amount);

	int get_text_amount() const;
	int get_gyper_text_amount() const;

};

