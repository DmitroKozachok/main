// клас для показу діалогу за допомогою вікна діалогу
#pragma once
#include <SFML/Graphics.hpp>
#include <fstream>
#include <vector>
#include <string>
#include "EditTxt.h"
#include "PlayerCamera.h"

class DialogSystem {
private:
    std::string dialog_name; // назва діалогу
    sf::RectangleShape dialog_box; // вікно діалогу
    EditTxt dialog_text; // текст діалогу
    std::vector<std::string> dialog_replik; // усі репліки діалогу
    int current_line; // номер теперішньої репліки
    bool waiting_for_input; // чи чекаємо на ввід Enter чи ні
    std::string font_path; // шлях до шрифта
public:

    static std::vector<std::string> all_complate_dialog; // глобальний вектор в якому є всі програні діалоги

    DialogSystem(std::string font_path, std::string replik_file_path, std::string dialog_name); // конструктор

    void set_dialog_name(std::string name);
    void load_dialog_from_file(std::string filename); // завантаження реплік з файлу

    void dialog_switch(sf::Event event); // обробка прогортання діалогу

    void show(sf::RenderWindow& window, PlayerCamera& camera, bool& is_dialog); // вивід діалогу

    std::string get_dialog_name() const; // повертає ім'я діалогу
    std::string get_font_path() const; // повертає шрифт
    bool get_waiting_for_input() const; // повертає чи діалог чекає на ввід
};


