#include "EditTxt.h"
#include <iostream>

EditTxt::EditTxt() :EditTxt ("Resources/Fonts/Pixel_Font-7 (1).ttf", true) {}

EditTxt::EditTxt(std::string font_path, bool is_center) : is_center{ is_center }
{
    text_font.loadFromFile(font_path); // підключення шрифта
    text_string.setFillColor(sf::Color::White); // зміна кольору
    text_string.setFont(text_font); // зміна шрифта
    text_string.setString("---"); // зміна стрічки

    // встановлення центру стрічки
    if (is_center)
    {
        sf::FloatRect text_bounds = text_string.getLocalBounds();
        text_string.setOrigin(text_bounds.left + text_bounds.width / 2.0f, text_bounds.top + text_bounds.height / 2.0f);
    }
}

void EditTxt::set_string(std::string string)
{
    text_string.setString(string); // зміна стрічки
}

void EditTxt::set_position(sf::Vector2f position)
{
    if (is_center)
    {
        sf::FloatRect text_bounds = text_string.getLocalBounds();
        text_string.setOrigin(text_bounds.width / 2.0f, text_bounds.height / 2.0f);
    }
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
    window.draw(text_string); // вивід
}
