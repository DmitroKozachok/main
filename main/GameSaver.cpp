#include "GameSaver.h"

void GameSaver::save_game(Player& player, std::vector<NPC>& npcs, std::vector<Enemy>& enemies)
{
    // ���������� ������
    std::ofstream player_file(PLAYER_PATH, std::ios::binary);
    CharacterToSave player_c_t_v(player);
    player_file.write(reinterpret_cast<char*>(&player_c_t_v), sizeof(CharacterToSave));

    player_file.close();

    // ���������� ������
    std::ofstream enemies_file(ENEMIES_PATH, std::ios::binary);
    for (auto& enemy : enemies) {
        CharacterToSave enemy_c_t_v(enemy);
        enemies_file.write(reinterpret_cast<char*>(&enemy_c_t_v), sizeof(CharacterToSave));
    }

    enemies_file.close();

    // ���������� NPC
    std::ofstream npc_file(NPC_PATH, std::ios::binary);
    for (auto& n : npcs) {
        CharacterToSave npc_c_t_v(n);
        npc_file.write(reinterpret_cast<char*>(&npc_c_t_v), sizeof(CharacterToSave));
    }

    npc_file.close();

}

void GameSaver::load_game(Player& player, std::vector<NPC>& npcs, std::vector<Enemy>& enemies)
{
	//������������ ������
    std::ifstream player_file(PLAYER_PATH, std::ios::binary);
    CharacterToSave player_c_t_v;
    
    player_file.read(reinterpret_cast<char*>(&player_c_t_v), sizeof(CharacterToSave));
    player.load_character_to_save(player_c_t_v);
    player_file.close();

	//������������ ������
    std::ifstream enemies_file(ENEMIES_PATH, std::ios::binary);
    for (auto& enemy : enemies) {
        CharacterToSave enemy_c_t_v;
        enemies_file.read(reinterpret_cast<char*>(&enemy_c_t_v), sizeof(CharacterToSave));
        enemy.load_character_to_save(enemy_c_t_v);
    }
    enemies_file.close();

	//������������ NPC
    std::ifstream npc_file(NPC_PATH, std::ios::binary);
    for (auto& n : npcs) {
        CharacterToSave npc_c_t_v;
        npc_file.read(reinterpret_cast<char*>(&npc_c_t_v), sizeof(CharacterToSave));
        n.load_character_to_save(npc_c_t_v);
    }

    npc_file.close();
}
