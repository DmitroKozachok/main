#include "Game.h"

void Game::event_processing(sf::RenderWindow& window, Character& character, float delta_time)
{
    sf::Event event;
    while (window.waitEvent(event))
    {
        // вікно закривається, коли ти натискаєш Escape
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            window.close();

        //рух персонажа
        character.move(event, delta_time);
    }
}

void Game::play_game()
{
    // створення тексту
    EditTxt tmp_text("Hello");
    
    // створення персонажа
    Character character; 

    // створення вікна на весь екран
    sf::RenderWindow window(sf::VideoMode::getFullscreenModes()[0], "SFML works!");

    // створення годинника гри
    sf::Clock clock;

    while (window.isOpen())
    {
        // створення різниці часу (потрібно для руху та анімацій)
        float delta_time = clock.getElapsedTime().asMicroseconds();
        clock.restart();

        delta_time /= 50;

        // обробка подій
        event_processing(window, character, delta_time);

        window.clear();

        character.show(window);
        tmp_text.show(window);

        window.display();
    }
}
