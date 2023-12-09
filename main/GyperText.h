/*Клас для роботи з гіпертекстом*/

#pragma once
#include <SFML/Graphics.hpp>
#include "EditTxt.h"

class GyperText : public EditTxt
{
public:

	GyperText(std::string string); // створення гіпертексту

	void hover(sf::RenderWindow& window); // зміна кольору при наведені
	void click(); // обробка натискання на клавішу

};

