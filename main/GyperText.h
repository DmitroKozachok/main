/*���� ��� ������ � �����������*/

#pragma once
#include <SFML/Graphics.hpp>
#include "EditTxt.h"
#include <iostream>

class GyperText : public EditTxt
{
public:
	GyperText();
	GyperText(std::string string); // ��������� ����������

	void hover(sf::RenderWindow& window); // ���� ������� ��� �������
	bool is_button_pressed(sf::Event event); // ������� ���������� �� ������
};

