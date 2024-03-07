// клас для короткого запису характеристик персонажа для зберігання

#pragma once

#include "Character.h"

class CharacterToSave
{	
public:
	float health; // здоров'я
	bool is_alive; // чи живий
	float x_pos; // позиція по x
	float y_pos; // позиція по y

	CharacterToSave();
	CharacterToSave(Character& character);

};

