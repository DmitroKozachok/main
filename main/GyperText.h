/*���� ��� ������ � �����������*/

#pragma once
#include <SFML/Graphics.hpp>
#include "EditTxt.h"
#include "PlayerCamera.h"

class GyperText : public EditTxt
{
public:
	GyperText();
	GyperText(std::string string); // ��������� ����������

	void hover(sf::RenderWindow& window, PlayerCamera& camera); // ���� ������� ��� �������
	bool is_button_pressed(sf::Event event); // ������� ���������� �� ������
};

