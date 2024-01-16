#include "DialogSystem.h"

DialogSystem::DialogSystem(std::string font_path, std::string replik_file_path) : dialog_text(font_path, false), current_line{0}
{
    // Налаштування вікна діалогу
    dialog_box.setSize(sf::Vector2f(500, 125));
    dialog_box.setOrigin(sf::Vector2f(dialog_box.getSize().x / 2, dialog_box.getSize().y / 2));
    dialog_box.setPosition(2000, 500);
    dialog_box.setFillColor(sf::Color::Black);
    dialog_box.setOutlineColor(sf::Color::White);
    dialog_box.setOutlineThickness(2.0f);

    // Налаштування тексту діалогу
    dialog_text.set_position(sf::Vector2f{ dialog_box.getPosition().x + 10, dialog_box.getPosition().y + 10 });

    // Завантаження реплік з файлу
    load_dialog_from_file(replik_file_path);
}

void DialogSystem::load_dialog_from_file(std::string filename)
{
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        // зчитування окремих реплік через Enter
        while (std::getline(file, line)) {
            dialog_replik.push_back(line);
        }
        file.close();
    }
}

void DialogSystem::dialog_switch(sf::Event event)
{
    // Обробка введення : чекаємо на натискання Enter
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
        waiting_for_input = false;
        if (current_line < dialog_replik.size()) {
            current_line++;
        }
    }
}

void DialogSystem::show(sf::RenderWindow& window, PlayerCamera& camera, bool& is_dialog)
{
    dialog_box.setPosition(camera.get_position().x, camera.get_position().y + 150);

    // Виведення діалогового вікна
    window.draw(dialog_box);

    // Виведення поточної репліки
    if (current_line < dialog_replik.size()) {
        dialog_text.set_string(dialog_replik[current_line]);
        dialog_text.set_position(sf::Vector2f{ dialog_box.getPosition().x - 230, dialog_box.getPosition().y - 60 });
        dialog_text.show(window);
    }
    else {
        // Очікування введення для продовження
        if (!waiting_for_input) {
            waiting_for_input = true;
            // Очищення вікна після завершення діалогу
            current_line = 0;
            is_dialog = false;
        }
    }
}
