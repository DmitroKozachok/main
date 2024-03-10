#include "GameSaver.h"

void GameSaver::save_game(Player& player, std::vector<NPC>& npcs, std::vector<Enemy>& enemies, std::vector<std::string>& dialogs)
{
    // Збереження гравця
    std::ofstream player_file(PLAYER_PATH, std::ios::binary);
    CharacterToSave player_c_t_v(player);
    player_file.write(reinterpret_cast<char*>(&player_c_t_v), sizeof(CharacterToSave));

    player_file.close();

    // Збереження ворогів
    std::ofstream enemies_file(ENEMIES_PATH, std::ios::binary);
    for (auto& enemy : enemies) {
        CharacterToSave enemy_c_t_v(enemy);
        enemies_file.write(reinterpret_cast<char*>(&enemy_c_t_v), sizeof(CharacterToSave));
    }

    enemies_file.close();

    // Збереження NPC
    std::ofstream npc_file(NPC_PATH, std::ios::binary);
    for (auto& n : npcs) {
        CharacterToSave npc_c_t_v(n);
        npc_file.write(reinterpret_cast<char*>(&npc_c_t_v), sizeof(CharacterToSave));
    }

    npc_file.close();

    // Збереження діалогів
    std::ofstream dialogs_file(DIALOGS_PATH, std::ios::binary);

    for (auto& d : dialogs) {
        dialogs_file.write(reinterpret_cast<char*>(&d), sizeof(std::string));
    }

    dialogs_file.close();

}

void GameSaver::load_game(Player& player, std::vector<NPC>& npcs, std::vector<Enemy>& enemies, std::vector<std::string>& dialogs)
{
	//завантаження гравця
    std::ifstream player_file(PLAYER_PATH, std::ios::binary);
    CharacterToSave player_c_t_v(player);
    
    player_file.read(reinterpret_cast<char*>(&player_c_t_v), sizeof(CharacterToSave));
    player_c_t_v.load_character_to_save(player);
    player_file.close();

	//завантаження ворогів
    std::ifstream enemies_file(ENEMIES_PATH, std::ios::binary);
    for (auto& enemy : enemies) {
        CharacterToSave enemy_c_t_v(enemy);
        enemies_file.read(reinterpret_cast<char*>(&enemy_c_t_v), sizeof(CharacterToSave));
        enemy_c_t_v.load_character_to_save(enemy);
    }
    enemies_file.close();

	//завантаження NPC
    std::ifstream npc_file(NPC_PATH, std::ios::binary);
    for (auto& n : npcs) {
        CharacterToSave npc_c_t_v(n);
        npc_file.read(reinterpret_cast<char*>(&npc_c_t_v), sizeof(CharacterToSave));
        npc_c_t_v.load_character_to_save(n);
    }

    npc_file.close();

    //Завантаження діалогів

    std::ifstream dialogs_file(DIALOGS_PATH, std::ios::binary);

    for (auto& d : dialogs) {
        dialogs_file.read(reinterpret_cast<char*>(&d), sizeof(std::string));
    }

    dialogs_file.close();

}
