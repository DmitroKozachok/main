#include "Game.h"

void Game::event_processing(sf::RenderWindow& window, Player& player, float delta_time, std::vector<Enemy>& enemies, MainMenu& main_menu, PlayerCamera& camera, Map& map, std::vector<NPC>& npcs, Game_Music& my_music, PauseMenu& pause_menu, SettingMenu& setting_menu, Transition transition_player)
{
    sf::Event event;

    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::KeyPressed) {
            // обробка відкриття меню
            if (!main_menu.get_status() && !setting_menu.get_status())
            {
                if (event.key.code == sf::Keyboard::Escape && pause_menu.get_status()) {
                    pause_menu.set_status(false);
                }
                else if (event.key.code == sf::Keyboard::Escape && !pause_menu.get_status()) {
                    pause_menu.set_status(true);
                }
            }
            
            // обробка можливого діалогу
            for (auto& npc : npcs)
            {
                // діалог змінюється в залежності від минулих подій
                if (std::find(DialogSystem::all_complate_dialog.begin(), DialogSystem::all_complate_dialog.end(), "warlock dialog 1 lvl1") != DialogSystem::all_complate_dialog.end() && npc.get_name() == "Brother" && npc.get_dialog().get_dialog_name() != "brother dialog 2 lvl1")
                {
                    npc.load_new_dialog("Code/Dialogs/Brother/Dialog2.txt", "brother dialog 2 lvl1");
                }
                if (npc.get_dialog().get_dialog_name() == "brother dialog 1 lvl1" && std::find(DialogSystem::all_complate_dialog.begin(), DialogSystem::all_complate_dialog.end(), "brother dialog 1 lvl1") != DialogSystem::all_complate_dialog.end())
                {
                    npc.load_new_dialog("Code/Dialogs/Brother/Dialog_hint.txt", "brother dialog hint lvl1");
                }
                if (npc.get_name() == "Warlock" && std::find(DialogSystem::all_complate_dialog.begin(), DialogSystem::all_complate_dialog.end(), "warlock dialog 1 lvl1") != DialogSystem::all_complate_dialog.end())
                {
                    npc.load_new_dialog("Code/Dialogs/Warlock/Dialog2.txt", "warlock dialog 2 lvl1");
                }
                npc.dialog_processing(event);
            }

        }
    }
    // рух злодія
    for (auto& enemy : enemies)
    {
        if (enemy.get_live_status())
        {
            enemy.move(player.get_character_position(), delta_time / 2, map);
            enemy.detect_colision(map, sf::FloatRect{ enemy.get_character_sprite().getGlobalBounds().left + 45,
                enemy.get_character_sprite().getGlobalBounds().top + 60, enemy.get_character_sprite().getGlobalBounds().width - 95,
                enemy.get_character_sprite().getGlobalBounds().height - 100 });

            enemy.detect_colision_with_player(player, sf::FloatRect{ enemy.get_character_sprite().getGlobalBounds().left + 25,
                enemy.get_character_sprite().getGlobalBounds().top + 40, enemy.get_character_sprite().getGlobalBounds().width - 45,
                enemy.get_character_sprite().getGlobalBounds().height - 80 }, sf::FloatRect{ player.get_character_sprite().getGlobalBounds().left + 45,
                player.get_character_sprite().getGlobalBounds().top + 80, player.get_character_sprite().getGlobalBounds().width - 95, 
                player.get_character_sprite().getGlobalBounds().height - 100 }, delta_time);
        }
        else
        {
            if (num_of_killed_lvl_enemy < 25)
            {
                //переродження ворога
                srand(time(NULL));
                std::vector<sf::Sprite> enemy_spawn_sprite_arr = map.get_enemy_spawn_sprite_arr();
                sf::Sprite spawn_sprite = enemy_spawn_sprite_arr[rand() % enemy_spawn_sprite_arr.size()];
                sf::Vector2f spawn_position{ (spawn_sprite.getPosition().x + 32) + (rand() % 65 - 32), spawn_sprite.getPosition().y + 46 };

                enemy.set_position(spawn_position);
                enemy.set_health(50);
                enemy.set_live_status(true);

                num_of_killed_lvl_enemy++;
            }
        }
    }
    
    //рух NPC
    for (auto& npc : npcs)
    {
        if (npc.get_live_status())
        {
            npc.script_move(delta_time);
            npc.detect_colision(map, sf::FloatRect{ npc.get_character_sprite().getGlobalBounds().left + 45, 
                npc.get_character_sprite().getGlobalBounds().top + 60, npc.get_character_sprite().getGlobalBounds().width - 95, 
                npc.get_character_sprite().getGlobalBounds().height - 100 });

            npc.detect_colision_with_player(player, sf::FloatRect{ npc.get_character_sprite().getGlobalBounds().left, 
                npc.get_character_sprite().getGlobalBounds().top, npc.get_character_sprite().getGlobalBounds().width, 
                npc.get_character_sprite().getGlobalBounds().height }, sf::FloatRect{ player.get_character_sprite().getGlobalBounds().left + 45, 
                player.get_character_sprite().getGlobalBounds().top + 80, player.get_character_sprite().getGlobalBounds().width - 95, 
                player.get_character_sprite().getGlobalBounds().height - 100 }, delta_time);
        }
    }

    // меню
    if (main_menu.get_status()) {

        // обробка натискання кнопок меню
        main_menu.click_processing(window, event, my_music, setting_menu);

        // позиція меню
        main_menu.set_position(camera, map.get_map_size(), window);
    }
    else if (setting_menu.get_status())
    {
        // обробка натискання кнопок меню
        setting_menu.click_processing(window, event);

        // позиція меню
        setting_menu.set_position(camera, map.get_map_size(), window);
    }
    else
    {
        camera.set_size(sf::Vector2f(window.getSize().x / 1.5, window.getSize().y / 1.5));


        if (pause_menu.get_status())
        {
            // обробка натискання кнопок меню
            pause_menu.click_processing(event, main_menu, setting_menu);

            // позиція меню
            pause_menu.set_position(camera, map.get_map_size(), window);
        }
        else
        {
            // рух персонажа
            player.move(delta_time, my_music);
            
            std::cout << "Pos x:" << player.get_character_position().x << ", Pos y:" << player.get_character_position().y << std::endl;
            // Перехід через двері в селі 
            if ((player.get_character_position().x > 512 && player.get_character_position().x < 512 + 128) && (player.get_character_position().y > 2560 && player.get_character_position().y < 2560 + 32)) {    // вихід
                transition_player.teleport_player_pos({ player.get_character_position().x,2200 }, player, window, camera, 1250);
            }
            if ((player.get_character_position().x > 512 && player.get_character_position().x < 512 + 128) && (player.get_character_position().y < 2432  && player.get_character_position().y > 2432 - 64)) {   //вхід
                transition_player.teleport_player_pos({ player.get_character_position().x,2700 }, player, window, camera, 1250);
            }

            //телепорт в магазин гравця
            if ((player.get_character_position().x > 950 && player.get_character_position().x < 1020) && (player.get_character_position().y < 2950 && player.get_character_position().y > 2915)) {   //вхід
                transition_player.teleport_player_pos({ 448,4400 }, player, window, camera, 1250);
            }
            if ((player.get_character_position().x > 380 && player.get_character_position().x < 520) && (player.get_character_position().y < 4500 && player.get_character_position().y > 4438)) {   //вхід
                transition_player.teleport_player_pos({ 960,2960 }, player, window, camera, 1250);
            }

            //перевірка підбирання бутилки гравцем в магазині
            if ((player.get_character_position().x > 500 && player.get_character_position().x < 580) && (player.get_character_position().y < 4225 && player.get_character_position().y > 4110)) {   //вхід
                //дописати
            }


            // атака гравця
            player.attack(event, delta_time);

            // обробка колізії
            player.detect_colision(map, sf::FloatRect{ player.get_character_sprite().getGlobalBounds().left + 45, 
            player.get_character_sprite().getGlobalBounds().top + 80, player.get_character_sprite().getGlobalBounds().width - 95, 
            player.get_character_sprite().getGlobalBounds().height - 100});
            // обробка колізії
            player.detect_colision(map, sf::FloatRect{ player.get_character_sprite().getGlobalBounds().left + 45, player.get_character_sprite().getGlobalBounds().top + 80, player.get_character_sprite().getGlobalBounds().width - 95, player.get_character_sprite().getGlobalBounds().height - 100 });
        }

    }
}

void Game::draw(Map map_lvl, Player player, std::vector<Enemy> enemies, PlayerCamera& camera, sf::RenderWindow& window, MainMenu main_menu, std::vector<NPC>& npcs, PauseMenu& pause_menu, SettingMenu& setting_menu, MiniMap& mini_map)
{
    // вивід гри, або меню

    if (main_menu.get_status())
    {
        main_menu.show(window, camera);
        camera.draw(sf::Vector2f{0.f, 0.f}, window, map_lvl.get_map_size());
    }
    else if (setting_menu.get_status())
    {
        setting_menu.show(window, camera);
        camera.draw(sf::Vector2f{ 0.f, 0.f }, window, map_lvl.get_map_size());
    }
    else
    {
        map_lvl.draw(window);
        for (auto& npc : npcs)
        {
            npc.show(window, camera);
        }
        player.show_p(window, camera);

        // якщо ворог помирає, то вектор змінюється
        for (auto& enemy : enemies)
        {
            if (enemy.get_live_status())
            {
                enemy.show(window);
            }
        }

        if (pause_menu.get_status())
        {
            pause_menu.show(window, camera);
        }
        
        camera.draw(player.get_character_position(), window, map_lvl.get_map_size());
        
        mini_map.change_level_rectangle_color(player.get_character_position());
        mini_map.draw(window, map_lvl, player, camera);
    }

    window.display();
    
}

void Game::enemy_spawn(std::vector<Enemy>& enemies, int num_of_enemies, Map& map)
{
    srand(time(NULL));
    std::vector<sf::Sprite> enemy_spawn_sprite_arr = map.get_enemy_spawn_sprite_arr();
    for (int i = 0; i < num_of_enemies; i++)
    {
        sf::Sprite spawn_sprite = enemy_spawn_sprite_arr[rand() % enemy_spawn_sprite_arr.size()];
        sf::Vector2f spawn_position{ (spawn_sprite.getPosition().x + 32) + (rand() % 65 - 32), spawn_sprite.getPosition().y + 46 };

        Enemy* enemy = new Enemy(32, 32, "Resources/sprite/2/mystic_woods_free_2.1/sprites/characters/slime.png", spawn_position, sf::Vector2f(3.f, 3.f), "enemy" + std::to_string(i));
        enemies.push_back(*enemy);
    }
}


void Game::play_game()
{
    // створення мапи
    Map map_lvl_1("Code/Maps/lvl_1 - map/lvl_1_config.txt", "Code/Maps/lvl_1 - map/lvl_1_map.txt", "Code/Maps/lvl_1 - map/lvl_1_Codet.txt");

    // створення персонажа
    Player player(48, 48, "Resources/sprite/2/mystic_woods_free_2.1/sprites/characters/player.png", sf::Vector2f(400.f, 500.f), sf::Vector2f(2.3f, 2.3f), "Player");

    // створення злодіїв
    num_of_killed_lvl_enemy = 0;
    std::vector<Enemy> enemies;
    enemy_spawn(enemies, 5, map_lvl_1);

    // створення NPC
    std::vector<NPC> npcs;
    NPC warlock(32, 32, "Resources/TailSet/Male/Male 12-2.png", sf::Vector2f(1100.f, 2950.f), sf::Vector2f(1.7f, 1.7f), "Resources/Fonts/NAMU-1750.ttf", "Code/Dialogs/Warlock/Dialog1.txt", "warlock dialog 1 lvl1", "Warlock");
    NPC brother(32, 32, "Resources/TailSet/Male/Male 02-2.png", sf::Vector2f(800.f, 2950.f), sf::Vector2f(1.7f, 1.7f), "Resources/Fonts/NAMU-1750.ttf", "Code/Dialogs/Brother/Dialog1.txt", "brother dialog 1 lvl1", "Brother");

    npcs.push_back(warlock);
    npcs.push_back(brother);

    // створення вікна на весь екран
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!", sf::Style::Fullscreen); //, sf::Style::Fullscreen

    // створення музики для гри 
    Game_Music music;

    // створення камери
    PlayerCamera camera(player.get_character_position(), sf::Vector2f(window.getSize().x / 1.5, window.getSize().y / 1.5), window, map_lvl_1.get_map_size());

    //створення мінікарти
    MiniMap mini_map(map_lvl_1);

    // створення меню
    MainMenu main_menu(camera);
    main_menu.set_status(true);

    PauseMenu pause_menu(camera);

    SettingMenu setting_menu(camera);

    // запуск стартової бг музики
    // music.background_Music_in_Menu.start_play_this_music();                  /////////////

    //
    Transition transition_player;

    while (window.isOpen())
    {

        // обробка подій
        event_processing(window, player, ANIMATION_TIME, enemies, main_menu, camera, map_lvl_1, npcs, music, pause_menu, setting_menu, transition_player);

        window.clear();
        
        // вивід
        draw(map_lvl_1, player, enemies, camera, window, main_menu, npcs, pause_menu, setting_menu, mini_map);

    }
}
