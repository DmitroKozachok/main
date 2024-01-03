/*���� ��� ��������� ��������� ���������*/

#pragma once
#include <SFML/Graphics.hpp>
#include "Map.h"

// ��������� ��������� �������
struct CordAnimation
{
	int cord_left_anim;
	int cord_right_anim;
	int cord_up_anim;
	int cord_down_anim;
};

// ��������� ������� ���������
enum MoveStatus
{
	LEFT,
	RIGHT,
	UP,
	DOWN
};

class Character
{
protected:

	CordAnimation cord_for_animation; // ��������� �������

	float health; // ������'�
	float damage; // ����
	bool is_alive; // �� �����
	bool is_attacking; // �� �����
	bool is_move; // �� ��������
	float speed; // ��������
	float diagonal_speed; // �������� �� ��� ���� �� �������
	
	sf::Sprite character_sprite; // ������ ���������
	sf::Image character_image; // �������� ���������
	sf::Texture character_texture; // �������� ���������

	int size_texture_x; // ����� ����� �� �
	int size_texture_y; // ����� ����� �� �

	float frame; // �������� ����

	MoveStatus move_status; // ��������� ������� ���������

	void move_left(float delta_time); // ��� ����
	void move_right(float delta_time); // ��� ������
	void move_up(float delta_time); // ��� �����
	void move_down(float delta_time); // ��� ����

	virtual void move_animation_left(float delta_time); // ������� ���� ����
	virtual void move_animation_right(float delta_time); // ������� ���� ������
	virtual void move_animation_up(float delta_time); // ������� ���� �����
	virtual void move_animation_down(float delta_time); // ������� ���� ����

	void idle_animation(float delta_time); // ������� �������

public:

	Character(); // ����������� �� ��������������, ������� ��������� �������
	Character(int size_x, int size_y, std::string image_way, sf::Vector2f position, sf::Vector2f scale); // �����������, �� ���������� ������ ���������

	void set_health(float new_health); // ������������ �����
	void set_damage(float new_damage); // ������������ �����
	void set_live_status(bool status); // ������������ �� ����� �����, true - �����, false - �������
	void set_position(sf::Vector2f position); // ������������ �������

	float get_health() const; // ������� ������'� ���������
	float get_damage() const; // ������� ���� ���������
	bool get_live_status() const; // ������� ������ ����� �����, true - �����, false - �������
	sf::Vector2f get_character_position() const; // ������� ������� ������
	
	void detect_colision(Map& map_lvl); // ������� ���糿

	void show(sf::RenderWindow& window); // ����������� ���������

	void move(sf::Event& event, float delta_time); // ��� ���������

};

