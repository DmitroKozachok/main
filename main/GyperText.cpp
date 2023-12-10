#include "GyperText.h"

GyperText::GyperText() : EditTxt() {}

GyperText::GyperText(std::string string) : EditTxt(string){}

void GyperText::hover(sf::RenderWindow& window)
{
    // �������� ������� ����� ������� ����
    sf::Vector2i mouse_position = sf::Mouse::getPosition(window);

    // �������� ������� ������
    sf::Vector2f text_position = get_position();

    // ����������, �� ����� ����������� ��� �������
    if (mouse_position.x >= text_position.x - (text_string.getGlobalBounds().width / 2) && mouse_position.x <= text_position.x + (text_string.getGlobalBounds().width / 2) && 
        mouse_position.y >= text_position.y - (text_string.getGlobalBounds().height / 2) && mouse_position.y <= text_position.y + (text_string.getGlobalBounds().height / 2))
    {
        // ������� ���� ������ ��� �������� �����
        text_string.setFillColor(sf::Color::Red); // ����� ���� �� �������
    }
    else
    {
        // ��������� ����������� ����, ���� ����� �� ��������
        text_string.setFillColor(sf::Color::White); // ����� �� ����������� ����
    }
}

bool GyperText::is_button_pressed(sf::Event event)
{
    if (event.type == sf::Event::MouseButtonPressed && event.key.code == sf::Mouse::Left) {
        if (text_string.getFillColor() == sf::Color::Red)
            return true;
        else
            return false;
    }
    else
        return false;
}