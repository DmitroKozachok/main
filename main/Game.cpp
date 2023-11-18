#include "Game.h"

void Game::event_processing(sf::RenderWindow& window, Character& character)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        // вікно закривається, коли ти натискаєш Escape
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            window.close();

        //рух персонажа
        character.move(event);
    }
}

void Game::play_game()
{
    EditTxt tmp_text("Hello");
    Character character;
    // створення вікна на весь екран
    sf::RenderWindow window(sf::VideoMode::getFullscreenModes()[0], "SFML works!");

    // Ліміт кадрів
    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        // обробка подій
        event_processing(window, character);

        window.clear();

        character.show(window);
        tmp_text.show(window);

        window.display();
    }
}
