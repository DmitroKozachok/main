#include <SFML/Graphics.hpp>
#include "Character.h"

// ������� ����
void event_processing(sf::RenderWindow& window, Character& character);

int main()
{
    Character character;
    // ��������� ���� �� ���� �����
    sf::RenderWindow window(sf::VideoMode::getFullscreenModes()[0], "SFML works!");

    // ˳�� �����
    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        // ������� ����
        event_processing(window, character);

        window.clear();

        character.show(window);

        window.display();
    }

    return 0;
}

void event_processing(sf::RenderWindow& window, Character& character)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        // ���� �����������, ���� �� �������� Escape
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            window.close();

        //��� ���������
        character.move(event);
    }
}
