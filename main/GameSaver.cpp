#include "GameSaver.h"

void GameSaver::delete_all_file()
{
    std::ifstream player_file(PLAYER_PATH, std::ios::binary);
    if (!player_file.is_open())
        std::remove(PLAYER_PATH);
    
    std::ifstream enemy_file(ENEMIES_PATH, std::ios::binary);
    if (!enemy_file.is_open())
        std::remove(ENEMIES_PATH);
    
    std::ifstream npc_file(NPC_PATH, std::ios::binary);
    if (!npc_file.is_open())
        std::remove(NPC_PATH);
    
    std::ifstream dialog_file(DIALOGS_PATH, std::ios::binary);
    if (!dialog_file.is_open())
        std::remove(DIALOGS_PATH);
}

void GameSaver::save_game(Player& player, std::vector<NPC>& npcs, std::vector<Enemy>& enemies, std::vector<std::string>& dialogs)
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

    // ���������� ������
    std::ofstream dialogs_file(DIALOGS_PATH, std::ios::binary);

    size_t size = dialogs.size();

    dialogs_file.write(reinterpret_cast<const char*>(&size), sizeof(size));

    // �������� ����� ����� ������� � ����
    for (const std::string& str : dialogs) {
        size_t strSize = str.size();
        dialogs_file.write(reinterpret_cast<const char*>(&strSize), sizeof(strSize));
        dialogs_file.write(str.data(), strSize);
    }

    dialogs_file.close();

}

void GameSaver::load_game(Player& player, std::vector<NPC>& npcs, std::vector<Enemy>& enemies, std::vector<std::string>& dialogs)
{
    // �������� �������� ����� ���������� ������
    std::ifstream player_file(PLAYER_PATH, std::ios::binary);
    if (!player_file.is_open()) {
        return; // ����������, ���� ���� �� ��������
    }

    // ������������ ������
    CharacterToSave player_c_t_v(player);
    player_file.read(reinterpret_cast<char*>(&player_c_t_v), sizeof(CharacterToSave));
    player_c_t_v.load_character_to_save(player);
    player_file.close();

    // �������� �������� ����� ���������� ������
    std::ifstream enemies_file(ENEMIES_PATH, std::ios::binary);
    if (!enemies_file.is_open()) {
        return; // ����������, ���� ���� �� ��������
    }

    // ������������ ������
    for (auto& enemy : enemies) {
        CharacterToSave enemy_c_t_v(enemy);
        enemies_file.read(reinterpret_cast<char*>(&enemy_c_t_v), sizeof(CharacterToSave));
        enemy_c_t_v.load_character_to_save(enemy);
    }
    enemies_file.close();

    // �������� �������� ����� ���������� NPC
    std::ifstream npc_file(NPC_PATH, std::ios::binary);
    if (!npc_file.is_open()) {
        return; // ����������, ���� ���� �� ��������
    }

    // ������������ NPC
    for (auto& n : npcs) {
        CharacterToSave npc_c_t_v(n);
        npc_file.read(reinterpret_cast<char*>(&npc_c_t_v), sizeof(CharacterToSave));
        npc_c_t_v.load_character_to_save(n);
    }
    npc_file.close();

    // �������� �������� ����� ���������� ������
    std::ifstream dialogs_file(DIALOGS_PATH, std::ios::binary);
    if (!dialogs_file.is_open()) {
        return; // ����������, ���� ���� �� ��������
    }

    // ������� ������ ����� ����������� ������ ������
    dialogs.clear();

    // ������� ����� �������
    size_t size;
    dialogs_file.read(reinterpret_cast<char*>(&size), sizeof(size));

    // ������� ����� ����� � ������ ���� �� �������
    for (size_t i = 0; i < size; ++i) {
        size_t strSize;
        dialogs_file.read(reinterpret_cast<char*>(&strSize), sizeof(strSize));
        std::string str(strSize, '\0');
        dialogs_file.read(&str[0], strSize);
        dialogs.push_back(str);
    }

    dialogs_file.close();

}
