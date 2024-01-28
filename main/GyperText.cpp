#include "GyperText.h"

GyperText::GyperText() : EditTxt() {}

GyperText::GyperText(std::string string) : EditTxt(string, true){}

void GyperText::hover(sf::RenderWindow& window, PlayerCamera& camera)
{
    // Отримуємо позицію мишки відносно вікна
    sf::Vector2i mouse_position = sf::Mouse::getPosition(window);

    // Враховуємо зсув камери
    sf::Vector2f world_mouse_position = window.mapPixelToCoords(mouse_position, camera.get_view());

    // Отримуємо границі тексту
    sf::Vector2f text_position = get_position();

    // Перевіряємо, чи мишка знаходиться над текстом
    if (world_mouse_position.x >= text_position.x - (text_string.getGlobalBounds().width) && world_mouse_position.x <= text_position.x + (text_string.getGlobalBounds().width) &&
        world_mouse_position.y >= text_position.y - (text_string.getGlobalBounds().height) && world_mouse_position.y <= text_position.y + (text_string.getGlobalBounds().height))
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
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (text_string.getFillColor() == sf::Color::Red)
            return true;
        else
            return false;
    }
    else
        return false;
}