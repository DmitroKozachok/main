#pragma once
#include <SFML/Graphics.hpp>
#include "EditTxt.h"
#include "GyperText.h"
#include "PlayerCamera.h"

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

	virtual void show(sf::RenderWindow& window, PlayerCamera& camera) = 0; // стандартний вивід

	void set_background_image(std::string path); // встановлення зображення
	void set_text_amount(int new_text_amount); // встановлення кількості тексту
	void set_gyper_text_amount(int new_gyper_text_amount); // встановлення кількості кнопок
	void set_status(bool status); // встановлення статусу (відкрите/закрите)

	int get_text_amount() const; // отримання кількості тексту
	int get_gyper_text_amount() const; // отримання кількості кнопок
	int get_status() const; // отримання статусу (відкрите/закрите)

};

