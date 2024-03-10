/*���� ��� ��������� ��������� ���������*/

#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>
#include "Map.h"
#include "HealthBar.h"
#include "PlayerCamera.h"

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
	DOWN,
	STAND
};

class Character
{
protected:

	CordAnimation cord_for_animation; // ��������� �������

	float health; // ������'�
	float damage; // ����
	bool is_alive; // �� �����
	bool is_attacking; // �� �����
	bool can_move; // �� ���� ��������
	float speed; // ��������
	float diagonal_speed; // �������� �� ��� ���� �� �������
	sf::Vector2f old_position; // ����� ������� (��� ���糿)
	std::string name; // ��'� ������

	sf::Sprite character_sprite; // ������ ���������
	sf::Image character_image; // �������� ���������
	sf::Texture character_texture; // �������� ���������
	
	HealthBar character_health; // ������'� ���������
	
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

public:

	virtual void idle_animation(float delta_time); // ������� �������

	Character(); // ����������� �� ��������������, ������� ��������� �������
	Character(int size_x, int size_y, std::string image_way, sf::Vector2f position, sf::Vector2f scale, float speed, float health, float damage, std::string name); // �����������, �� ���������� ������ ���������

	void set_health(float new_health); // ������������ �����
	void set_damage(float new_damage); // ������������ �����
	void set_live_status(bool status); // ������������ �� ����� �����, true - �����, false - �������
	void set_position(sf::Vector2f position); // ������������ �������

	float get_health() const; // ������� ������'� ���������
	float get_damage() const; // ������� ���� ���������
	bool is_character_attacking() const; // �� �����
	bool get_can_move(); // �� ���� ��������
	bool get_live_status() const; // ������� ������ ����� �����, true - �����, false - �������
	sf::Vector2f get_character_position() const; // ������� ������� ������
	sf::Sprite get_character_sprite() const; // ������� ������ ������
	sf::Image get_character_image() const; // ������� �������� ������
	sf::Texture get_character_texture() const; // ������� �������� ������
	float get_frame() const; // ������� �������� ���� �������
	sf::Vector2f get_old_position() const; // ������� ������� ������� ������
	std::string get_name() const; // ������� ��'�
	MoveStatus get_move_status() const;

	void detect_colision(Map& map_lvl, sf::FloatRect rect); // ������� ���糿

	virtual void show(sf::RenderWindow& window); // ����������� ���������

	virtual void move(float delta_time); // ��� ���������

	void gain_damage(float x);
};