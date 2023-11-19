/*���� ��� ��������� ��������� ���������*/

#pragma once
#include <SFML/Graphics.hpp>

class Character
{
protected:
	sf::Sprite character_sprite; // ������ ���������
	float health; // ������'�
	float damage; // ����
	bool is_alive; // �� �����
	float speed; // ��������

	void move_left(float delta_time); // ��� ����
	void move_right(float delta_time); // ��� ������
	void move_up(float delta_time); // ��� �����
	void move_down(float delta_time); // ��� ����


public:
	Character(); // ����������� �� ��������������, ������� ��������� �������

	void set_sprite(sf::Sprite& new_sprite); // ������������ ������ �������
	void set_health(float new_health); // ������������ �����
	void set_damage(float new_damage); // ������������ �����
	void set_live_status(bool status); // ������������ �� ����� �����, true - �����, false - �������

	sf::Sprite get_sprite() const; // ������� ������ ���������
	float get_health() const; // ������� ������'� ���������
	float get_damage() const; // ������� ���� ���������
	bool get_live_status() const; // ������� ������ ����� �����, true - �����, false - �������
	
	void show(sf::RenderWindow& window); // ����������� ���������

	void move(sf::Event event, float delta_time); // ��� ���������

	void death(); // ������ ���������

};

