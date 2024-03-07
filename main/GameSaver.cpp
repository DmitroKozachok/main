#include "GameSaver.h"

void GameSaver::save_game(Player& player, std::vector<NPC>& npcs, std::vector<Enemy>& enemies)
{
    // ���������� ������
    std::ofstream player_file(PLAYER_PATH, std::ios::binary);
    player_file.write(reinterpret_cast<char*>(&player), sizeof(Player));

    player_file.close();

    // ���������� ������
    std::ofstream enemies_file(ENEMIES_PATH, std::ios::binary);
    for (auto& enemy : enemies) {
        enemies_file.write(reinterpret_cast<char*>(&enemy), sizeof(Enemy));
    }

    enemies_file.close();

    // ���������� NPC
    std::ofstream npc_file(NPC_PATH, std::ios::binary);
    for (auto& n : npcs) {
        npc_file.write(reinterpret_cast<char*>(&n), sizeof(NPC));
    }

    npc_file.close();

}

void GameSaver::load_game(Player& player, std::vector<NPC>& npcs, std::vector<Enemy>& enemies)
{
	//������������ ������
    std::ifstream player_file(PLAYER_PATH, std::ios::binary);
    player_file.read(reinterpret_cast<char*>(&player), sizeof(Player));

    player_file.close();

	//������������ ������
    std::ifstream enemies_file(ENEMIES_PATH, std::ios::binary);
    for (auto& enemy : enemies) {
        enemies_file.read(reinterpret_cast<char*>(&enemy), sizeof(Enemy));
    }

	//������������ NPC
    std::ifstream npc_file(NPC_PATH, std::ios::binary);
    for (auto& n : npcs) {
        npc_file.read(reinterpret_cast<char*>(&n), sizeof(NPC));
    }

    npc_file.close();
}
