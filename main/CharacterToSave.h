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

	CharacterToSave();
	CharacterToSave(Character& character);

};

