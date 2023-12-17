#include "Game.h"

void Game::event_processing(sf::RenderWindow& window, Player& player, float delta_time, Enemy& enemy, GyperText& gt)
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
        
        //рух персонажа
        player.move(event, delta_time);

        // наведення на текст
        gt.hover(window);

        //рух злодія
        enemy.move(player.get_character_position(), delta_time);
    }

    // атака гравця
    player.attack(event, delta_time);

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
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!");

    // створення гіпертексту
    GyperText gt("TEST");

    MainMenu main_menu;

    // створення музики для гри 
    Game_Music music;

    // створення камери
    PlayerCamera camera(player, sf::Vector2f(window.getSize().x / 1.5, window.getSize().y / 1.5), window);

    // запуск стартової бг музики
    music.start_background_music_in_Menu();

    while (window.isOpen())
    {

        // обробка подій
        event_processing(window, player, ANIMATION_TIME, enemy, gt);

        window.clear();
        
        // вивід
        map_lvl_1.draw(window);
        gt.show(window);
        player.show(window);
        enemy.show(window);
        window.display();
        camera.draw(player, window);
    }
}
