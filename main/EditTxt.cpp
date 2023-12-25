#include "EditTxt.h"
#include <iostream>

EditTxt::EditTxt()
{
    text_font.loadFromFile("Resources/Fonts/Pixel_Font-7 (1).ttf"); // ���������� ������
    text_string.setFillColor(sf::Color::White); // ���� �������
    text_string.setFont(text_font); // ���� ������
    text_string.setString("---"); // ���� ������

    // ������������ ������ ������
    sf::FloatRect text_bounds = text_string.getLocalBounds();
    text_string.setOrigin(text_bounds.left + text_bounds.width / 2.0f, text_bounds.top + text_bounds.height / 2.0f);

}

EditTxt::EditTxt(std::string string) : EditTxt() // ����������� ������������
{
    text_string.setString(string); // ���� ������
}

void EditTxt::set_string(std::string string)
{
    text_string.setString(string); // ���� ������
}

void EditTxt::set_position(sf::Vector2f position)
{
    sf::FloatRect text_bounds = text_string.getLocalBounds();
    text_string.setOrigin(text_bounds.width / 2.0f, text_bounds.height / 2.0f);
    text_position = position;
    text_string.setPosition(text_position);
}

void EditTxt::set_size(float size)
{
    text_string.setCharacterSize(size);
}

sf::Text EditTxt::get_txt()
{
    return text_string;
}

sf::Vector2f EditTxt::get_position() const { return text_position; }

void EditTxt::show(sf::RenderWindow& window)
{
    window.draw(text_string); // ����
}
