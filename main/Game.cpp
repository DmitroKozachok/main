#include "Game.h"

void Game::event_processing(sf::RenderWindow& window, Player& player, float delta_time, std::vector<Enemy>& enemies, MainMenu& main_menu, PlayerCamera& camera, Map& map, std::vector<NPC>& npcs, Game_Music& my_music, PauseMenu& pause_menu, SettingMenu& setting_menu, Transition transition_player)
{
    sf::Event event;

    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::KeyPressed) {
            // ������� �������� ����
            if (!main_menu.get_status() && !setting_menu.get_status())
            {
                if (event.key.code == sf::Keyboard::Escape && pause_menu.get_status()) {
                    pause_menu.set_status(false);
                }
                else if (event.key.code == sf::Keyboard::Escape && !pause_menu.get_status()) {
                    pause_menu.set_status(true);
                }
            }
            
            // ������� ��������� ������
            for (auto& npc : npcs)
            {
                // ����� ��������� � ��������� �� ������� ����
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

    // ��� �����
    int num_of_killed_enemy = 0;
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
                player.get_character_sprite().getGlobalBounds().height - 100 }, delta_time ,sound_player_get_damage);
        }
        else
        {
            num_of_killed_enemy++;
        }
    }
    
    //��� NPC
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

            // ������� ������, �� �������� �� ������� ������ �������
            if (npc.get_name() == "Inhabitant" && num_of_killed_enemy >= 10)
            {
                if (npc.get_dialog().get_dialog_name() == "inhabitant dialog 1 lvl1")
                {
                    npc.load_new_dialog("Code/Dialogs/Inhabitant/Dialog2.txt", "inhabitant dialog 2 lvl1");
                    npc.set_position(sf::Vector2f(400.f, 2700.f));
                }
            }
        }
    }

    // ����
    if (main_menu.get_status()) {

        // ������� ���������� ������ ����
        main_menu.click_processing(window, event, my_music, setting_menu, player, npcs, enemies, DialogSystem::all_complate_dialog, gamae_saver);

        // ������� ����
        main_menu.set_position(camera, map.get_map_size(), window);
    }
    else if (setting_menu.get_status())
    {
        // ������� ���������� ������ ����
        setting_menu.click_processing(window, event);

        // ������� ����
        setting_menu.set_position(camera, map.get_map_size(), window);
    }
    else
    {
        camera.set_size(sf::Vector2f(window.getSize().x / 1.5, window.getSize().y / 1.5));


        if (pause_menu.get_status())
        {
            // ������� ���������� ������ ����
            pause_menu.click_processing(event, main_menu, setting_menu, my_music);

            // ������� ����
            pause_menu.set_position(camera, map.get_map_size(), window);
        }
        else
        {
            bool is_dialog = false; //�� ��������� �����
            for (auto& npc : npcs)
            {
                if (npc.get_is_dialog())
                {
                    is_dialog = true;
                    break;
                }
            }
            // ��� ���������
            player.move(delta_time, sound_walk);
            if (!is_dialog)
            {
                player.move(delta_time, my_music);
            }
            else
            {
                player.idle_animation(ANIMATION_TIME);
            }
            
            //std::cout << "Pos x:" << player.get_character_position().x << ", Pos y:" << player.get_character_position().y << std::endl;
            // ������� ����� ���� � ��� 
            if ((player.get_character_position().x > 512 && player.get_character_position().x < 512 + 128) && (player.get_character_position().y > 2560 && player.get_character_position().y < 2560 + 32)) {    // �����
                transition_player.teleport_player_pos({ player.get_character_position().x,2200 }, player, window, camera, 1250);
            }
            if ((player.get_character_position().x > 512 && player.get_character_position().x < 512 + 128) && (player.get_character_position().y < 2432  && player.get_character_position().y > 2432 - 64)) {   //����
                transition_player.teleport_player_pos({ player.get_character_position().x,2700 }, player, window, camera, 1250);
            }
            //�������� u������ ������/���� � �����
            if ((player.get_character_position().x > 3000 && player.get_character_position().x < 3070) && (player.get_character_position().y < 440 && player.get_character_position().y > 420)) {   //����
                transition_player.teleport_player_pos({ 3195,1660 }, player, window, camera, 1250);
            }
            if ((player.get_character_position().x > 3122 && player.get_character_position().x < 3378) && (player.get_character_position().y < 1750 && player.get_character_position().y > 1690)) {   //�����
                transition_player.teleport_player_pos({ 3050,470 }, player, window, camera, 1250);
            }
            //�������� � ������� ������
            if ((player.get_character_position().x > 950 && player.get_character_position().x < 1020) && (player.get_character_position().y < 2950 && player.get_character_position().y > 2915)) {   //����
                transition_player.teleport_player_pos({ 448,4400 }, player, window, camera, 1250);
            }
            if ((player.get_character_position().x > 380 && player.get_character_position().x < 520) && (player.get_character_position().y < 4500 && player.get_character_position().y > 4438)) {   //�����
                transition_player.teleport_player_pos({ 960,2960 }, player, window, camera, 1250);
            }

            //�������� ��������� ������� ������� � �������
            if ((player.get_character_position().x > 500 && player.get_character_position().x < 580) && (player.get_character_position().y < 4225 && player.get_character_position().y > 4110)) {   //����
                
            }


            // ����� ������
            player.attack(event, delta_time, sound_player_attack);   ///////

            // ������� ���糿
            player.detect_colision(map, sf::FloatRect{ player.get_character_sprite().getGlobalBounds().left + 45, 
            player.get_character_sprite().getGlobalBounds().top + 80, player.get_character_sprite().getGlobalBounds().width - 95, 
            player.get_character_sprite().getGlobalBounds().height - 100});
            // ������� ���糿
            player.detect_colision(map, sf::FloatRect{ player.get_character_sprite().getGlobalBounds().left + 45, player.get_character_sprite().getGlobalBounds().top + 80, player.get_character_sprite().getGlobalBounds().width - 95, player.get_character_sprite().getGlobalBounds().height - 100 });
        }

    }
}

void Game::draw(Map map_lvl, Player player, std::vector<Enemy> enemies, PlayerCamera& camera, sf::RenderWindow& window, MainMenu main_menu, std::vector<NPC>& npcs, PauseMenu& pause_menu, SettingMenu& setting_menu)
{
    // ���� ���, ��� ����

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

        // ���� ����� ������, �� ������ ���������
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
        
    }

    window.display();
    
}

void Game::enemy_spawn(std::vector<Enemy>& enemies, Map& map)
{
    srand(time(NULL));
    std::vector<sf::Sprite> enemy_spawn_sprite_arr = map.get_enemy_spawn_sprite_arr();
    for (int i = 0; i < enemy_spawn_sprite_arr.size(); i++)
    {
        for (int j = 0; j < 2; j++)
        {
            sf::Sprite spawn_sprite = enemy_spawn_sprite_arr[i];
            sf::Vector2f spawn_position{ (spawn_sprite.getPosition().x + 32) + (rand() % 65 - 32), spawn_sprite.getPosition().y + 46 };

            // ������������ ������� ��� ��������� ������
            SlimeFactory slime_factory;
            SpiritFactory orc_factory;

            if (j == 0)
            {
                Enemy* enemy = slime_factory.create_enemy(spawn_position, "enemy" + std::to_string(i));
                enemies.push_back(*enemy);
            }
            else
            {
                Enemy* enemy = orc_factory.create_enemy(spawn_position, "enemy" + std::to_string(i));
                enemies.push_back(*enemy);
            }
        }

    }
}

void Game::play_game()
{
    // ��������� ����
    Map map_lvl_1("Code/Maps/lvl_1 - map/lvl_1_config.txt", "Code/Maps/lvl_1 - map/lvl_1_map.txt", "Code/Maps/lvl_1 - map/lvl_1_Codet.txt");

    // ��������� ���������
    Player player(48, 48, "Resources/sprite/2/mystic_woods_free_2.1/sprites/characters/player.png", sf::Vector2f(2900.f, 460.f), sf::Vector2f(2.3f, 2.3f), "Player");

    // ��������� ���䳿�
    std::vector<Enemy> enemies;
    enemy_spawn(enemies, map_lvl_1);

    // ��������� NPC
    std::vector<NPC> npcs;
    NPC warlock(32, 32, "Resources/TailSet/Male/Male 12-2.png", sf::Vector2f(1100.f, 2950.f), sf::Vector2f(1.7f, 1.7f), "Resources/Fonts/NAMU-1750.ttf", "Code/Dialogs/Warlock/Dialog1.txt", "warlock dialog 1 lvl1", "Warlock");
    NPC brother(32, 32, "Resources/TailSet/Male/Male 02-2.png", sf::Vector2f(800.f, 2950.f), sf::Vector2f(1.7f, 1.7f), "Resources/Fonts/NAMU-1750.ttf", "Code/Dialogs/Brother/Dialog1.txt", "brother dialog 1 lvl1", "Brother");
    NPC guider(32, 32, "Resources/TailSet/Male/Male 04-2.png", sf::Vector2f(570.f, 410.f), sf::Vector2f(1.7f, 1.7f), "Resources/Fonts/NAMU-1750.ttf", "Code/Dialogs/Guider/Dialog1.txt", "guider dialog 1 lvl1", "Guider");
    NPC inhabitant(32, 32, "Resources/TailSet/Male/Male 17-1.png", sf::Vector2f(670.f, 1800.f), sf::Vector2f(1.7f, 1.7f), "Resources/Fonts/NAMU-1750.ttf", "Code/Dialogs/Inhabitant/Dialog1.txt", "inhabitant dialog 1 lvl1", "Inhabitant");

    npcs.push_back(warlock);
    npcs.push_back(brother);
    npcs.push_back(guider);
    npcs.push_back(inhabitant);

    // ��������� ���� �� ���� �����
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!"); //, sf::Style::Fullscreen

    // ��������� ������ ��� ��� 

    Game_Music sound_walk_player(7, "Resources/Music/StepOnTheGrass.wav", false);
    Game_Music sound_player_attack(15, "Resources/Music/player_attack.wav", false, 88);
    Game_Music sound_player_get_damage(13, "Resources/Music/player_get_damage.wav", false , 88);
    std::vector<Game_Music> vect_music;
    Game_Music music_bg_wordl_1(5, "Resources/Music/bg_world_1.wav", true);
    Game_Music music_bg_wordl_2(5, "Resources/Music/bg_world_2.wav", true);
    Game_Music music_bg_wordl_3(5, "Resources/Music/bg_world_3.wav", true);
    Game_Music music_bg_menu(5, "Resources/Music/bg_menu.wav", true);

    vect_music.push_back(music_bg_wordl_1);
    vect_music.push_back(music_bg_wordl_2);
    vect_music.push_back(music_bg_wordl_3);
    vect_music.push_back(music_bg_menu);


    // ������ �������� �� ������
    std::vector<Game_Music>::iterator iter = std::find_if(
            vect_music.begin(), vect_music.end(),
            [music_bg_menu](const Game_Music& music) { return music.path_to_music_song == music_bg_menu.path_to_music_song; }
    );

    if (iter != vect_music.end()) {
        iter->start_play_this_music();
    }

    // ��������� ������
    PlayerCamera camera(player.get_character_position(), sf::Vector2f(window.getSize().x / 1.5, window.getSize().y / 1.5), window, map_lvl_1.get_map_size());

    // ��������� ����
    MainMenu main_menu(camera);
    main_menu.set_status(true);

    PauseMenu pause_menu(camera);
    SettingMenu setting_menu(camera);

    // ������ �������� �� ������
    // music.background_Music_in_Menu.start_play_this_music();                  /////////////

    //
    //
    Transition transition_player;

    GameSaver game_saver;

    while (window.isOpen())
    {
        event_processing(window, player, ANIMATION_TIME, enemies, main_menu, camera, map_lvl_1, npcs, music, pause_menu, setting_menu, transition_player, game_saver);
        event_processing(window, player, ANIMATION_TIME, enemies, main_menu, camera, map_lvl_1, npcs, vect_music, pause_menu, setting_menu, transition_player, sound_walk_player, sound_player_attack , sound_player_get_damage);
        // ������� ����
        event_processing(window, player, ANIMATION_TIME, enemies, main_menu, camera, map_lvl_1, npcs, music, pause_menu, setting_menu, transition_player);

        window.clear();
        
        // ����
        draw(map_lvl_1, player, enemies, camera, window, main_menu, npcs, pause_menu, setting_menu);

    }

    game_saver.save_game(player, npcs, enemies, DialogSystem::all_complate_dialog);
}
