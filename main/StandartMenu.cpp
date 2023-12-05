#include "StandartMenu.h"

StandartMenu::StandartMenu(std::string path, int text_amount, int gyper_text_amount)
{
	set_background_image(path);
	set_text_amount(text_amount);
	set_gyper_text_amount(gyper_text_amount);
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

int StandartMenu::get_text_amount() const { return text_amount; }

int StandartMenu::get_gyper_text_amount() const { return gyper_text_amount; }
