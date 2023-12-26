#include "StandartMenu.h"

StandartMenu::StandartMenu(std::string path, int new_text_amount, int new_gyper_text_amount) // переназвав аргументи
{
	set_background_image(path);
	background_texture.loadFromImage(background_image);
	background_sprite.setTexture(background_texture);
	set_text_amount(new_text_amount); // переназвав аргументи
	set_gyper_text_amount(new_gyper_text_amount); // переназвав аргументи
	text_arr = new EditTxt[text_amount]; // добавл€ю текст
	gyper_text_arr = new GyperText[gyper_text_amount]; // добавл€ю текст
	is_open = false; // в≥кно не в≥дкрите
}

void StandartMenu::set_background_image(std::string path)
{
	if (path != "")
	{
		background_image.loadFromFile(path);
	}
}

void StandartMenu::set_text_amount(int new_text_amount)
{
	if (new_text_amount > 0)
	{
		text_amount = new_text_amount;
	}
}

void StandartMenu::set_gyper_text_amount(int new_gyper_text_amount)
{
	if (new_gyper_text_amount > 0)
	{
		gyper_text_amount = new_gyper_text_amount;
	}
}

void StandartMenu::set_status(bool status)
{
	is_open = status;
}

int StandartMenu::get_text_amount() const { return text_amount; }

int StandartMenu::get_gyper_text_amount() const { return gyper_text_amount; }

int StandartMenu::get_status() const
{
	return is_open;
}
