#include "Game.h"

void Game::event_processing(sf::RenderWindow& window, Player& player, float delta_time, Enemy& enemy, MainMenu& main_menu, PlayerCamera& camera, Map& map)
{
    sf::Event event;

    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Escape) { // ���� �����������, ���� �� �������� Escape
                window.close();
            }

            // ������� �������� ����

            if (event.key.code == sf::Keyboard::P && main_menu.get_status()) {
                main_menu.set_status(false);
            }
            else if (event.key.code == sf::Keyboard::P && !main_menu.get_status()) {
                main_menu.set_status(true);
            }
        }
    }
    // ��� �����
    enemy.move(player.get_character_position(), delta_time);
    enemy.detect_colision(map, sf::FloatRect{ enemy.get_character_sprite().getGlobalBounds().left + 45, enemy.get_character_sprite().getGlobalBounds().top + 60, enemy.get_character_sprite().getGlobalBounds().width - 95, enemy.get_character_sprite().getGlobalBounds().height - 100 });
    enemy.detect_colision_with_player(player, sf::FloatRect{ enemy.get_character_sprite().getGlobalBounds().left + 45, enemy.get_character_sprite().getGlobalBounds().top + 60, enemy.get_character_sprite().getGlobalBounds().width - 95, enemy.get_character_sprite().getGlobalBounds().height - 100 }, sf::FloatRect{ player.get_character_sprite().getGlobalBounds().left + 45, player.get_character_sprite().getGlobalBounds().top + 80, player.get_character_sprite().getGlobalBounds().width - 95, player.get_character_sprite().getGlobalBounds().height - 100 });

    if (main_menu.get_status()) {

        // ������� ���������� ������ ����
        main_menu.click_processing(window, event);

        // ���� ����
        main_menu.set_position(camera, map.get_map_size(), window);
    }
    else
    {
        camera.set_size(sf::Vector2f(window.getSize().x / 1.5, window.getSize().y / 1.5));

        // ��� ���������
        player.move(delta_time);

        // ����� ������
        player.attack(event, delta_time);

        // ������� ���糿
        player.detect_colision(map, sf::FloatRect{ player.get_character_sprite().getGlobalBounds().left + 45, player.get_character_sprite().getGlobalBounds().top + 80, player.get_character_sprite().getGlobalBounds().width - 95, player.get_character_sprite().getGlobalBounds().height - 100});
    }
}

void Game::draw(Map map_lvl, Player player, Enemy enemy, PlayerCamera camera, sf::RenderWindow& window, MainMenu main_menu)
{
    // ���� ���, ��� ����

    if (main_menu.get_status())
    {
        main_menu.show(window);
        camera.draw(sf::Vector2f{0.f, 0.f}, window, map_lvl.get_map_size());
    }
    else
    {
        map_lvl.draw(window);
        enemy.show(window);
        player.show(window); 
        camera.draw(player.get_character_position(), window, map_lvl.get_map_size());
    }

    window.display();
    
}

void Game::play_game()
{
    // ��������� ����
    //Map map("Code/Maps/Test/Test config.txt", "Code/Maps/Test/Test map.txt", "Code/Maps/Test/Code for test.txt");
    Map map_lvl_1("Code/Maps/lvl_1/lvl_1_config.txt", "Code/Maps/lvl_1/lvl_1_map.txt", "Code/Maps/lvl_1/lvl_1_Codet.txt");

    // ��������� ���������
    Player player(48, 48, "Resources/sprite/2/mystic_woods_free_2.1/sprites/characters/player.png", sf::Vector2f(50.f, 600.f), sf::Vector2f(2.3f, 2.3f));

    // ��������� �����
    Enemy enemy(32, 32, "Resources/sprite/2/mystic_woods_free_2.1/sprites/characters/slime.png", sf::Vector2f(700.f, 600.f), sf::Vector2f(3.f, 3.f));

    // ��������� ���� �� ���� �����
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!", sf::Style::Fullscreen);

    // ��������� ������ ��� ��� 
    Game_Music music;

    // ��������� ������
    PlayerCamera camera(player.get_character_position(), sf::Vector2f(window.getSize().x / 1.5, window.getSize().y / 1.5), window, map_lvl_1.get_map_size());

    // ��������� ����
    MainMenu main_menu(camera);
    main_menu.set_status(true);

    // ������ �������� �� ������
    music.start_background_music_in_Menu();

    while (window.isOpen())
    {

        // ������� ����
        event_processing(window, player, ANIMATION_TIME, enemy, main_menu, camera, map_lvl_1);

        window.clear();
        
        // ����
        draw(map_lvl_1, player, enemy, camera, window, main_menu);

    }
}
