#include "GyperText.h"

GyperText::GyperText() : EditTxt() {}

GyperText::GyperText(std::string string) : EditTxt(string){}

void GyperText::hover(sf::RenderWindow& window)
{
    // Отримуємо позицію мишки відносно вікна
    sf::Vector2i mouse_position = sf::Mouse::getPosition(window);

    // Отримуємо границі тексту
    sf::Vector2f text_position = get_position();

    std::cout << "M: " << mouse_position.x << " " << mouse_position.y << std::endl;
    std::cout << "T: " << text_position.x << " " << text_position.y << std::endl;

    // Перевіряємо, чи мишка знаходиться над текстом
    if (mouse_position.x >= text_position.x - (text_string.getGlobalBounds().width / 2) && mouse_position.x <= text_position.x + (text_string.getGlobalBounds().width / 2) && 
        mouse_position.y >= text_position.y - (text_string.getGlobalBounds().height / 2) && mouse_position.y <= text_position.y + (text_string.getGlobalBounds().height / 2))
    {
        // Змінюємо колір тексту при наведенні мишки
        text_string.setFillColor(sf::Color::Red); // Змініть колір на бажаний
    }
    else
    {
        // Повертаємо оригінальний колір, якщо мишка не наведена
        text_string.setFillColor(sf::Color::White); // Змініть на оригінальний колір
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