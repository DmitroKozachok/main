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
    std::string dialog_name; // ����� ������
    sf::RectangleShape dialog_box; // ���� ������
    EditTxt dialog_text; // ����� ������
    std::vector<std::string> dialog_replik; // �� ������ ������
    int current_line; // ����� ��������� ������
    bool waiting_for_input; // �� ������ �� ��� Enter �� �
    std::string font_path; // ���� �� ������
public:

    static std::vector<std::string> all_complate_dialog; // ���������� ������ � ����� � �� ������� ������

    DialogSystem(std::string font_path, std::string replik_file_path, std::string dialog_name); // �����������

    void set_dialog_name(std::string name);
    void load_dialog_from_file(std::string filename); // ������������ ����� � �����

    void dialog_switch(sf::Event event); // ������� ����������� ������

    void show(sf::RenderWindow& window, PlayerCamera& camera, bool& is_dialog); // ���� ������

    std::string get_dialog_name() const; // ������� ��'� ������
    std::string get_font_path() const; // ������� �����
    bool get_waiting_for_input() const; // ������� �� ����� ���� �� ���
};


