#include "Game.h"

// ���������� ���� ������ �� �������� ���� �� ����������� ����: ��� ������, ��� ������
//int time_c = 10000;

void Game::event_processing(sf::RenderWindow& window, Character& character, float delta_time, Enemy& enemy)
{
    sf::Event event;
    while (window.pollEvent(event))
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
    // ��������� ���������
    Character character(48, 48, "Resources/sprite/2/mystic_woods_free_2.1/sprites/characters/player.png", sf::Vector2f(1000.f, 200.f), sf::Vector2f(3.f, 3.f));

    // ��������� �����
    Enemy enemy(32, 32, "Resources/sprite/2/mystic_woods_free_2.1/sprites/characters/slime.png", sf::Vector2f(700.f, 200.f), sf::Vector2f(3.f, 3.f));

    // ��������� ���� �� ���� �����
    sf::RenderWindow window(sf::VideoMode::getFullscreenModes()[0], "SFML works!");

    // ��������� ��������� ���
    //sf::Clock clock;

    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        // ��������� ������ ���� (������� ��� ���� �� �������)
        //float delta_time = clock.getElapsedTime().asSeconds();
        //clock.restart();

        //delta_time /= time_c;

        enemy.move(character.get_character_position(), ANIMATION_TIME);

        // ������� ����
        event_processing(window, character, ANIMATION_TIME, enemy);

        window.clear();

        character.show(window);
        enemy.show(window);

        window.display();
        std::cout << character.get_character_position().x << ", " << character.get_character_position().y << '\n';
    }
}
