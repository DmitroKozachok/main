#include "PlayerCamera.h"

PlayerCamera::PlayerCamera(sf::Vector2f center, sf::Vector2f size, sf::RenderWindow& window, sf::Vector2f border_size) : size{ size }
{
	set_position(center, border_size); // встановлення центру камери
	camera.setSize(size); //встановлення розміру
	window.setView(camera);
}

void PlayerCamera::set_position(sf::Vector2f new_position, sf::Vector2f border_size)
{
	// перевірка чи камера не виходить за межі екрану
	if (new_position.x < (size.x / 2))
		new_position.x = (size.x / 2);
	if (new_position.y < (size.y / 2))
		new_position.y = (size.y / 2);
	if (new_position.x > (border_size.x - size.x / 2))
		new_position.x = (border_size.x - size.x / 2);
	if (new_position.y > (border_size.y - size.y / 2))
		new_position.y = (border_size.y - size.y / 2);
	camera.setCenter(new_position);
	position = new_position;
}

void PlayerCamera::set_size(sf::Vector2f new_size)
{
	size = new_size;
}

sf::Vector2f PlayerCamera::get_size() const
{
	return size;
}

sf::Vector2f PlayerCamera::get_position() const
{
	return position;
}

void PlayerCamera::draw(sf::Vector2f center, sf::RenderWindow& window, sf::Vector2f border_size)
{
	set_position(center, border_size); // встановлення позиції
	camera.setSize(size); // встановлення розміру
	window.setView(camera); // встановлення камери

}
