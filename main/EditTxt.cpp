#include "EditTxt.h"

EditTxt::EditTxt()
{
    text_font.loadFromFile("Resources/Fonts/Pixel_Font-7 (1).ttf"); // підключення шрифта
    text_string.setCharacterSize(25); // зміна розміру
    text_string.setFillColor(sf::Color::White); // зміна кольору
    text_string.setFont(text_font); // зміна шрифта
    text_string.setString("Test!"); // зміна стрічки

    text_position = sf::Vector2f(600.f, 600.f); // встановлення позиції

    text_string.setPosition(text_position); // зміна позиції

}

EditTxt::EditTxt(std::string string) : EditTxt() // делигування конструкторів
{
    text_string.setString(string); // зміна стрічки
}

void EditTxt::set_string(std::string string)
{
    text_string.setString(string); // зміна стрічки
}

sf::Vector2f EditTxt::get_position() const{return text_position;}

void EditTxt::show(sf::RenderWindow& window)
{
    window.draw(text_string); // вивід
}
