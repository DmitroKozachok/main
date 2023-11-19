#include "Game.h"

void Game::event_processing(sf::RenderWindow& window, Character& character, float delta_time)
{
    sf::Event event;
    while (window.waitEvent(event))
    {
        // ���� �����������, ���� �� �������� Escape
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            window.close();

        //��� ���������
        character.move(event, delta_time);
    }
}

void Game::play_game()
{
    // ��������� ������
    EditTxt tmp_text("Hello");
    
    // ��������� ���������
    Character character; 

    // ��������� ���� �� ���� �����
    sf::RenderWindow window(sf::VideoMode::getFullscreenModes()[0], "SFML works!");

    // ��������� ��������� ���
    sf::Clock clock;

    while (window.isOpen())
    {
        // ��������� ������ ���� (������� ��� ���� �� �������)
        float delta_time = clock.getElapsedTime().asMicroseconds();
        clock.restart();

        delta_time /= 50;

        // ������� ����
        event_processing(window, character, delta_time);

        window.clear();

        character.show(window);
        tmp_text.show(window);

        window.display();
    }
}
