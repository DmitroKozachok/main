/*���� ��� ������ � �����������*/

#pragma once
#include <SFML/Graphics.hpp>
#include "EditTxt.h"

class GyperText : public EditTxt
{
public:

	GyperText(std::string string); // ��������� ����������

	void hover(sf::RenderWindow& window); // ���� ������� ��� �������
	void click(); // ������� ���������� �� ������

};

