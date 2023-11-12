#include "EditTxt.h"

EditTxt::EditTxt()
{
    text_font.loadFromFile("Resources/Fonts/Pixel_Font-7 (1).ttf"); // ���������� ������
    text_string.setCharacterSize(25); // ���� ������
    text_string.setFillColor(sf::Color::White); // ���� �������
    text_string.setFont(text_font); // ���� ������
    text_string.setString("Test!"); // ���� ������

    text_position = sf::Vector2f(600.f, 600.f); // ������������ �������

    text_string.setPosition(text_position); // ���� �������

}

EditTxt::EditTxt(std::string string) : EditTxt() // ����������� ������������
{
    text_string.setString(string); // ���� ������
}

void EditTxt::set_string(std::string string)
{
    text_string.setString(string); // ���� ������
}

sf::Vector2f EditTxt::get_position() const{return text_position;}

void EditTxt::show(sf::RenderWindow& window)
{
    window.draw(text_string); // ����
}
