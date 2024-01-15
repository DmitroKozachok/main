#include "DialogSystem.h"

DialogSystem::DialogSystem(std::string font_path, std::string replik_file_path) : dialog_text(font_path), current_line{0}
{
    // ������������ ���� ������
    dialog_box.setSize(sf::Vector2f(600, 200));
    dialog_box.setPosition(2000, 500);
    dialog_box.setFillColor(sf::Color::Black);
    dialog_box.setOutlineColor(sf::Color::White);
    dialog_box.setOutlineThickness(2.0f);

    // ������������ ������ ������
    dialog_text.set_position(sf::Vector2f{ dialog_box.getPosition().x + 10, dialog_box.getPosition().y + 10 });

    // ������������ ����� � �����
    load_dialog_from_file(replik_file_path);
}

void DialogSystem::load_dialog_from_file(std::string filename)
{
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        // ���������� ������� ����� ����� Enter
        while (std::getline(file, line)) {
            dialog_replik.push_back(line);
        }
        file.close();
    }
}

void DialogSystem::dialog_switch(sf::Event event)
{
    // ������� �������� : ������ �� ���������� Enter
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
        waiting_for_input = false;
        if (current_line < dialog_replik.size()) {
            current_line++;
        }
    }
}

void DialogSystem::show(sf::RenderWindow& window)
{
    // ��������� ���������� ����
    window.draw(dialog_box);

    // ��������� ������� ������
    if (current_line < dialog_replik.size()) {
        dialog_text.set_string(dialog_replik[current_line]);
        dialog_text.show(window);
    }
    else {
        // ���������� �������� ��� �����������
        if (!waiting_for_input) {
            waiting_for_input = true;
            // �������� ���� ���� ���������� ������
            current_line = 0;
        }
    }
}
