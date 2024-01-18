#include "Game.h"

void Game::event_processing(sf::RenderWindow& window, Player& player, float delta_time, std::vector<Enemy>& enemies, MainMenu& main_menu, PlayerCamera& camera, Map& map, std::vector<NPC>& npcs)
{
    sf::Event event;

    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Escape) { // вікно закривається, коли ти натискаєш Escape
                window.close();
            }

            // обробка відкриття меню
            if (event.key.code == sf::Keyboard::P && main_menu.get_status()) {
                main_menu.set_status(false);
            }
            else if (event.key.code == sf::Keyboard::P && !main_menu.get_status()) {
                main_menu.set_status(true);
            }

            // обробка можливого діалогу
            for (auto& npc : npcs)
            {
                npc.dialog_processing(event);
            }

        }
    }
    // рух злодія
    for (auto& enemy : enemies)
    {
        if (enemy.get_live_status())
        {
            enemy.move(player.get_character_position(), delta_time / 2);
            enemy.detect_colision(map, sf::FloatRect{ enemy.get_character_sprite().getGlobalBounds().left + 45, enemy.get_character_sprite().getGlobalBounds().top + 60, enemy.get_character_sprite().getGlobalBounds().width - 95, enemy.get_character_sprite().getGlobalBounds().height - 100 });
            enemy.detect_colision_with_player(player, sf::FloatRect{ enemy.get_character_sprite().getGlobalBounds().left + 25, enemy.get_character_sprite().getGlobalBounds().top + 40, enemy.get_character_sprite().getGlobalBounds().width - 45, enemy.get_character_sprite().getGlobalBounds().height - 80 }, sf::FloatRect{ player.get_character_sprite().getGlobalBounds().left + 45, player.get_character_sprite().getGlobalBounds().top + 80, player.get_character_sprite().getGlobalBounds().width - 95, player.get_character_sprite().getGlobalBounds().height - 100 }, delta_time);
        }
    }
    
    //рух NPC
    for (auto& npc : npcs)
    {
        if (npc.get_live_status())
        {
            npc.script_move(delta_time);
            npc.detect_colision(map, sf::FloatRect{ npc.get_character_sprite().getGlobalBounds().left + 45, npc.get_character_sprite().getGlobalBounds().top + 60, npc.get_character_sprite().getGlobalBounds().width - 95, npc.get_character_sprite().getGlobalBounds().height - 100 });
            npc.detect_colision_with_player(player, sf::FloatRect{ npc.get_character_sprite().getGlobalBounds().left, npc.get_character_sprite().getGlobalBounds().top, npc.get_character_sprite().getGlobalBounds().width, npc.get_character_sprite().getGlobalBounds().height }, sf::FloatRect{ player.get_character_sprite().getGlobalBounds().left + 45, player.get_character_sprite().getGlobalBounds().top + 80, player.get_character_sprite().getGlobalBounds().width - 95, player.get_character_sprite().getGlobalBounds().height - 100 }, delta_time);
        }
    }

    // меню
    if (main_menu.get_status()) {

        // обробка натискання кнопок меню
        main_menu.click_processing(window, event);

        // вивід меню
        main_menu.set_position(camera, map.get_map_size(), window);
    }
    else
    {
        camera.set_size(sf::Vector2f(window.getSize().x / 1.5, window.getSize().y / 1.5));

        // рух персонажа
        player.move(delta_time);

        // атака гравця
        player.attack(event, delta_time);

        // обробка колізії
        player.detect_colision(map, sf::FloatRect{ player.get_character_sprite().getGlobalBounds().left + 45, player.get_character_sprite().getGlobalBounds().top + 80, player.get_character_sprite().getGlobalBounds().width - 95, player.get_character_sprite().getGlobalBounds().height - 100});
    }
}

void Game::draw(Map map_lvl, Player player, std::vector<Enemy> enemies, PlayerCamera& camera, sf::RenderWindow& window, MainMenu main_menu, std::vector<NPC>& npcs)
{
    // вивід гри, або меню

    if (main_menu.get_status())
    {
        main_menu.show(window);
        camera.draw(sf::Vector2f{0.f, 0.f}, window, map_lvl.get_map_size());
    }
    else
    {
        map_lvl.draw(window);
        for (auto& npc : npcs)
        {
            npc.show(window, camera);
        }
        player.show(window);

        for (auto& enemy : enemies)
        {
            if (enemy.get_live_status())
            {
                enemy.show(window);
            }
        }

        camera.draw(player.get_character_position(), window, map_lvl.get_map_size());
    }

    window.display();
    
}

void Game::play_game()
{
    // створення мапи
    Map map_lvl_1("Code/Maps/lvl_1/lvl_1_config.txt", "Code/Maps/lvl_1/lvl_1_map.txt", "Code/Maps/lvl_1/lvl_1_Codet.txt");

    // створення персонажа
    Player player(48, 48, "Resources/sprite/2/mystic_woods_free_2.1/sprites/characters/player.png", sf::Vector2f(400.f, 3000.f), sf::Vector2f(2.3f, 2.3f));

    // створення злодіїв
    std::vector<Enemy> enemies;
    Enemy enemy(32, 32, "Resources/sprite/2/mystic_woods_free_2.1/sprites/characters/slime.png", sf::Vector2f(700.f, 600.f), sf::Vector2f(3.f, 3.f));

    enemies.push_back(enemy);

    // створення NPC
    std::vector<NPC> npcs;
    NPC warlock(32, 32, "Resources/TailSet/Male/Male 12-2.png", sf::Vector2f(1000.f, 2950.f), sf::Vector2f(1.7f, 1.7f), "Resources/Fonts/NAMU-1750.ttf", "Code/Dialogs/Warlock/Dialog.txt");
    NPC brother(32, 32, "Resources/TailSet/Male/Male 02-2.png", sf::Vector2f(900.f, 2950.f), sf::Vector2f(1.7f, 1.7f), "Resources/Fonts/NAMU-1750.ttf", "Code/Dialogs/Brother/Dialog1.txt");

    npcs.push_back(warlock);
    npcs.push_back(brother);

    // створення вікна на весь екран
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!", sf::Style::Fullscreen);

    // створення музики для гри 
    Game_Music music;

    // створення камери
    PlayerCamera camera(player.get_character_position(), sf::Vector2f(window.getSize().x / 1.5, window.getSize().y / 1.5), window, map_lvl_1.get_map_size());

    // створення меню
    MainMenu main_menu(camera);
    main_menu.set_status(true);

    // запуск стартової бг музики
    music.start_background_music_in_Menu();

    while (window.isOpen())
    {

        // обробка подій
        event_processing(window, player, ANIMATION_TIME, enemies, main_menu, camera, map_lvl_1, npcs);

        window.clear();
        
        // вивід
        draw(map_lvl_1, player, enemies, camera, window, main_menu, npcs);

    }
}
