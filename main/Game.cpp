#include "Game.h"

void Game::event_processing(sf::RenderWindow& window, Character& character, float delta_time, Enemy& enemy, GyperText& gt)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        // ���� �����������, ���� �� �������� Escape
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            window.close();

        //��� ���������
        character.move(event, delta_time);

        // ��������� �� �����
        gt.hover(window);

        //��� �����
        enemy.move(character.get_character_position(), delta_time);
    }
}

void Game::play_game()
{
    // ��������� ����
    Map map("Code/Maps/Test/Test config.txt", "Code/Maps/Test/Test map.txt", "Code/Maps/Test/Code for test.txt");

    // ��������� ���������
    Character character(48, 48, "Resources/sprite/2/mystic_woods_free_2.1/sprites/characters/player.png", sf::Vector2f(1000.f, 200.f), sf::Vector2f(3.f, 3.f));

    // ��������� �����
    Enemy enemy(32, 32, "Resources/sprite/2/mystic_woods_free_2.1/sprites/characters/slime.png", sf::Vector2f(700.f, 200.f), sf::Vector2f(3.f, 3.f));

    // ��������� ���� �� ���� �����
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!", sf::Style::Fullscreen);

    // ��������� ����������
    GyperText gt("TEST");

    while (window.isOpen())
    {

        // ������� ����
        event_processing(window, character, ANIMATION_TIME, enemy, gt);

        window.clear();
        
        // ����
        map.draw(window);
        gt.show(window);
        character.show(window);
        enemy.show(window);
        window.display();
    }
}
