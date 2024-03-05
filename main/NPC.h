#pragma once
#include "Character.h"
#include "DialogSystem.h"
#include "PlayerCamera.h"

class NPC : public Character
{
private:
	bool is_dialog; // чи йде діалог
	DialogSystem dialog; // діалогова система

	void move_animation_left(float delta_time) override; // анімація руху вліво
	void move_animation_right(float delta_time) override; // анімація руху вправо
	void move_animation_up(float delta_time) override; // анімація руху вгору
	void move_animation_down(float delta_time) override; // анімація руху вниз
	void idle_animation(float delta_time) override; // анімація стояння

public:
	NPC(int size_x, int size_y, std::string image_way, sf::Vector2f position, sf::Vector2f scale, std::string font_path, std::string replik_file_path, std::string dialog_name, std::string name); // конструктор з параметрами

	void detect_colision_with_player(Character& player, sf::FloatRect npc_rect, sf::FloatRect player_rect, float delta_time); // колізія з гравцем
	void script_move(float delta_timer); // заскриптований рух (при потребі)

	void dialog_processing(sf::Event event); // обробка діалогу
	void load_new_dialog(std::string path, std::string dialog_name);

	void show(sf::RenderWindow& window, PlayerCamera& camera); // вивід

	DialogSystem get_dialog() const; // отримання діалогу

	bool get_is_dialog() const; // повертає чи є зараз діалог
};

