// ���� ��� ��������� ������ ������������� ��������� ��� ���������

#pragma once

#include "Character.h"

class CharacterToSave
{	
public:
	float health; // ������'�
	bool is_alive; // �� �����
	float x_pos; // ������� �� x
	float y_pos; // ������� �� y

	CharacterToSave(Character& character);

	void load_character_to_save(Character& character);

};

