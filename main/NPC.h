#pragma once
#include "Character.h"
#include "DialogSystem.h"
#include "PlayerCamera.h"

class NPC : public Character
{
private:
	bool is_dialog; // �� ��� �����
	DialogSystem dialog; // �������� �������

	void move_animation_left(float delta_time) override; // ������� ���� ����
	void move_animation_right(float delta_time) override; // ������� ���� ������
	void move_animation_up(float delta_time) override; // ������� ���� �����
	void move_animation_down(float delta_time) override; // ������� ���� ����
	void idle_animation(float delta_time) override; // ������� �������

public:
	NPC(int size_x, int size_y, std::string image_way, sf::Vector2f position, sf::Vector2f scale, std::string font_path, std::string replik_file_path, std::string dialog_name, std::string name); // ����������� � �����������

	void detect_colision_with_player(Character& player, sf::FloatRect npc_rect, sf::FloatRect player_rect, float delta_time); // ����� � �������
	void script_move(float delta_timer); // �������������� ��� (��� ������)

	void dialog_processing(sf::Event event); // ������� ������
	void load_new_dialog(std::string path, std::string dialog_name);

	void show(sf::RenderWindow& window, PlayerCamera& camera); // ����

	DialogSystem get_dialog() const; //��������� ������
};

