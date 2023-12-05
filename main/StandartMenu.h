#pragma once
#include <SFML/Graphics.hpp>
#include "EditTxt.h"
#include "GyperText.h"

class StandartMenu
{
protected:
	sf::Image background_image; // ����� ���
	EditTxt* text_arr; // ����� ��� �����䳿
	GyperText* gyper_text_arr; // ����� �� �����䳺�

	int text_amount; // ������� ���������� ������
	int gyper_text_amount; // ������� ����-������

public:
	StandartMenu(std::string path, int text_amount, int gyper_text_amount);

	virtual void show(sf::RenderWindow& window) = 0; // ����������� ����

	void set_background_image(std::string path);
	void set_text_amount(int new_text_amount);
	void set_gyper_text_amount(int new_gyper_text_amount);

	int get_text_amount() const;
	int get_gyper_text_amount() const;

};

