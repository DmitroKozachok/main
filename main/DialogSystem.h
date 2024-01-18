// ���� ��� ������ ������ �� ��������� ���� ������
#pragma once
#include <SFML/Graphics.hpp>
#include <fstream>
#include <vector>
#include <string>
#include "EditTxt.h"
#include "PlayerCamera.h"

class DialogSystem {
private:
    sf::RectangleShape dialog_box; // ���� ������
    EditTxt dialog_text; // ����� ������
    std::vector<std::string> dialog_replik; // �� ������ ������
    int current_line; // ����� ��������� ������
    bool waiting_for_input; // �� ������ �� ��� Enter �� �
public:
    DialogSystem(std::string font_path, std::string replik_file_path); // �����������

    void load_dialog_from_file(std::string filename); // ������������ ����� � �����

    void dialog_switch(sf::Event event); // ������� ����������� ������

    void show(sf::RenderWindow& window, PlayerCamera& camera, bool& is_dialog); // ���� ������
};


