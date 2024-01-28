/*Клас для роботи з гіпертекстом*/

#pragma once
#include <SFML/Graphics.hpp>
#include "EditTxt.h"
#include "PlayerCamera.h"

class GyperText : public EditTxt
{
public:
	GyperText();
	GyperText(std::string string); // створення гіпертексту

	void hover(sf::RenderWindow& window, PlayerCamera& camera); // зміна кольору при наведені
	bool is_button_pressed(sf::Event event); // обробка натискання на клавішу
};

