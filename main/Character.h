/*���� ��� ��������� ��������� ���������*/

#pragma once
#include <SFML/Graphics.hpp>

class Character
{
private:
	sf::Sprite character_sprite; // ������ ���������
	float health; // ������'�
	float damage; // ����
	bool is_alive; // �� �����
	float speed; // ��������

	void move_left(); // ��� ����
	void move_right(); // ��� ������
	void move_up(); // ��� �����
	void move_down(); // ��� ����


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

	void move(sf::Event event); // ��� ���������

	void death(); // ������ ���������

};

