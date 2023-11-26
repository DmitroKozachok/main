#include "Game.h"

// коефіцієнт часу впливає на швидкість руху та програвання руху: чим менший, тим швидше
int time_c = 10000;

void Game::event_processing(sf::RenderWindow& window, Character& character, float delta_time, Enemy& enemy)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        // вікно закривається, коли ти натискаєш Escape
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            window.close();

        //рух персонажа
        character.move(event, delta_time);
        enemy.move(character.get_character_position(), delta_time);
    }
}

void Game::play_game()
{
    // створення персонажа
    Character character(48, 48, "Resources/sprite/2/mystic_woods_free_2.1/sprites/characters/player.png", sf::Vector2f(1000.f, 200.f), sf::Vector2f(3.f, 3.f));

    // створення злодія
    Enemy enemy(32, 32, "Resources/sprite/2/mystic_woods_free_2.1/sprites/characters/slime.png", sf::Vector2f(700.f, 200.f), sf::Vector2f(3.f, 3.f));

    // створення вікна на весь екран
    sf::RenderWindow window(sf::VideoMode::getFullscreenModes()[0], "SFML works!");

    // створення годинника гри
    sf::Clock clock;

    while (window.isOpen())
    {
        // створення різниці часу (потрібно для руху та анімацій)
        float delta_time = clock.getElapsedTime().asSeconds();
        clock.restart();

        delta_time /= time_c;

        // обробка подій
        event_processing(window, character, delta_time, enemy);

        window.clear();

        character.show(window);
        enemy.show(window);

        window.display();
    }
}
