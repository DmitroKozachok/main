// клас для показу діалогу за допомогою вікна діалогу
#pragma once
#include <SFML/Graphics.hpp>
#include <fstream>
#include <vector>
#include <string>
#include "EditTxt.h"

class DialogSystem {
private:
    sf::RectangleShape dialog_box; // вікно діалогу
    EditTxt dialog_text; // текст діалогу
    std::vector<std::string> dialog_replik; // усі репліки діалогу
    int current_line; // номер теперішньої репліки
    bool waiting_for_input; // чи чекаємо на ввід Enter чи ні
public:
    DialogSystem(std::string font_path, std::string replik_file_path); // конструктор

    void load_dialog_from_file(std::string filename); // завантаження реплік з файлу

    void dialog_switch(sf::Event event); // обробка прогортання діалогу

    void show(sf::RenderWindow& window); // вивід діалогу
};


