/*���� ��� ������ � �������*/

#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class EditTxt
{
protected:
	sf::Text text_string; // ������
	sf::Font text_font; // ����� ������
	sf::Vector2f text_position; // ������� ������

	bool is_center; // �� �����

public:
	EditTxt(); // ��������� ������������ ������
	EditTxt(std::string font_path, bool is_center); // ��������� ������ �� ������ �������

	void set_string(std::string string); // ���� ������
	void set_position(sf::Vector2f position); // ���� �������
	void set_size(float size);

	sf::Text get_txt(); // ������� �����
	sf::Vector2f get_position() const; // ������� �������

	void show(sf::RenderWindow& window); // ����

};

