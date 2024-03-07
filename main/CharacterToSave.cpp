#include "CharacterToSave.h"

CharacterToSave::CharacterToSave()
{

}

CharacterToSave::CharacterToSave(Character& character)
{
	health = character.get_health();
	is_alive = character.get_live_status();

	x_pos = character.get_character_position().x;
	y_pos = character.get_character_position().y;
}
