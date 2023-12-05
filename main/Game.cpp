#include "Game.h"

void Game::event_processing(sf::RenderWindow& window, Character& character, float delta_time, Enemy& enemy, GyperText& gt)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        // вікно закривається, коли ти натискаєш Escape
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            window.close();

        //рух персонажа
        character.move(event, delta_time);

        // наведення на текст
        gt.hover(window);

        //рух злодія
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

    // створення гіпертексту
    GyperText gt("TEST");

    while (window.isOpen())
    {

        // обробка подій
        event_processing(window, character, ANIMATION_TIME, enemy, gt);

        window.clear();
        
        // вивід
        gt.show(window);
        character.show(window);
        enemy.show(window);
        window.display();
    }
}
