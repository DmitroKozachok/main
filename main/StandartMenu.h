#pragma once
#include <SFML/Graphics.hpp>
#include "EditTxt.h"
#include "GyperText.h"

class StandartMenu
{
protected:
	sf::Image background_image; // задній фон
	sf::Texture background_texture; // задній фон
	sf::Sprite background_sprite; // задній фон
	EditTxt* text_arr; // текст без взаємодії
	GyperText* gyper_text_arr; // текст із взаємодією

	int text_amount; // кількість звичайного тексту
	int gyper_text_amount; // кількість гіпер-тексту

	bool is_open; // чи відкрите вікно

public:
	StandartMenu(std::string path, int new_text_amount, int new_gyper_text_amount); // переназвав аргументи

	virtual void show(sf::RenderWindow& window) = 0; // стандартний вивід

	void set_background_image(std::string path);
	void set_text_amount(int new_text_amount);
	void set_gyper_text_amount(int new_gyper_text_amount);
	void set_status(bool status);

	int get_text_amount() const;
	int get_gyper_text_amount() const;
	int get_status() const;

};

