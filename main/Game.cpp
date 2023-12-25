#include "Game.h"

void Game::event_processing(sf::RenderWindow& window, Player& player, float delta_time, Enemy& enemy, MainMenu& main_menu, PlayerCamera& camera)
{
    sf::Event event;

    while (window.pollEvent(event))
    {
        // ���� �����������, ���� �� �������� Escape
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        }

        // ��� �����
        enemy.move(player.get_character_position(), delta_time);
    }

    // ��� ���������
    player.move(event, delta_time);

    // ����� ������
    player.attack(event, delta_time);

    // ���� ����
    main_menu.set_position(camera);

}

void Game::draw(Map map_lvl, Player player, Enemy enemy, PlayerCamera camera, sf::RenderWindow& window, MainMenu main_menu)
{
    main_menu.show(window);
    /*map_lvl.draw(window);
    player.show(window);
    enemy.show(window);*/
    window.display();
    //camera.draw(player, window);
}

void Game::play_game()
{
    // ��������� ����
    //Map map("Code/Maps/Test/Test config.txt", "Code/Maps/Test/Test map.txt", "Code/Maps/Test/Code for test.txt");
    Map map_lvl_1("Code/Maps/lvl_1/lvl_1_config.txt", "Code/Maps/lvl_1/lvl_1_map.txt", "Code/Maps/lvl_1/lvl_1_Codet.txt");

    // ��������� ���������
    Player player(48, 48, "Resources/sprite/2/mystic_woods_free_2.1/sprites/characters/player.png", sf::Vector2f(1000.f, 200.f), sf::Vector2f(3.f, 3.f));

    // ��������� �����
    Enemy enemy(32, 32, "Resources/sprite/2/mystic_woods_free_2.1/sprites/characters/slime.png", sf::Vector2f(700.f, 200.f), sf::Vector2f(3.f, 3.f));

    // ��������� ���� �� ���� �����
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!", sf::Style::Fullscreen);

    // ��������� ������ ��� ��� 
    Game_Music music;

    // ��������� ������
    PlayerCamera camera(player, sf::Vector2f(window.getSize().x, window.getSize().y), window);

    // ��������� ����
    MainMenu main_menu(camera, window);

    // ������ �������� �� ������
    music.start_background_music_in_Menu();

    while (window.isOpen())
    {

        // ������� ����
        event_processing(window, player, ANIMATION_TIME, enemy, main_menu, camera);

        window.clear();
        
        // ����
        draw(map_lvl_1, player, enemy, camera, window, main_menu);

    }
}
