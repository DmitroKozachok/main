#include "Game.h"

void Game::event_processing(sf::RenderWindow& window, Player& player, float delta_time, Enemy& enemy, MainMenu& main_menu, PlayerCamera& camera)
{
    sf::Event event;

    while (window.pollEvent(event))
    {
        // вікно закривається, коли ти натискаєш Escape
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        }

        // рух злодія
        enemy.move(player.get_character_position(), delta_time);
    }

    // рух персонажа
    player.move(event, delta_time);

    // атака гравця
    player.attack(event, delta_time);

    // вивід меню
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
    // створення мапи
    //Map map("Code/Maps/Test/Test config.txt", "Code/Maps/Test/Test map.txt", "Code/Maps/Test/Code for test.txt");
    Map map_lvl_1("Code/Maps/lvl_1/lvl_1_config.txt", "Code/Maps/lvl_1/lvl_1_map.txt", "Code/Maps/lvl_1/lvl_1_Codet.txt");

    // створення персонажа
    Player player(48, 48, "Resources/sprite/2/mystic_woods_free_2.1/sprites/characters/player.png", sf::Vector2f(1000.f, 200.f), sf::Vector2f(3.f, 3.f));

    // створення злодія
    Enemy enemy(32, 32, "Resources/sprite/2/mystic_woods_free_2.1/sprites/characters/slime.png", sf::Vector2f(700.f, 200.f), sf::Vector2f(3.f, 3.f));

    // створення вікна на весь екран
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!", sf::Style::Fullscreen);

    // створення музики для гри 
    Game_Music music;

    // створення камери
    PlayerCamera camera(player, sf::Vector2f(window.getSize().x, window.getSize().y), window);

    // створення меню
    MainMenu main_menu(camera, window);

    // запуск стартової бг музики
    music.start_background_music_in_Menu();

    while (window.isOpen())
    {

        // обробка подій
        event_processing(window, player, ANIMATION_TIME, enemy, main_menu, camera);

        window.clear();
        
        // вивід
        draw(map_lvl_1, player, enemy, camera, window, main_menu);

    }
}
