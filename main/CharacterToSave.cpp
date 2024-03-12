#include "CharacterToSave.h"

CharacterToSave::CharacterToSave(Character& character)
{
	health = character.get_health();
	is_alive = character.get_live_status();

	x_pos = character.get_character_position().x;
	y_pos = character.get_character_position().y;
}

void CharacterToSave::load_character_to_save(Character& character)
{
	character.set_health(health);
	character.set_live_status(is_alive);
	character.set_position(sf::Vector2f(x_pos, y_pos));
}
