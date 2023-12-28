#include "PlayerCamera.h"

PlayerCamera::PlayerCamera(Character& character, sf::Vector2f size, sf::RenderWindow& window) : size{ size }
{
	set_position(character.get_character_position(), window); // ������������ ������ ������
	camera.setSize(size); //������������ ������
	window.setView(camera);
}

void PlayerCamera::set_position(sf::Vector2f new_position, sf::RenderWindow& window)
{
	// �������� �� ������ �� �������� �� ��� ������
	/*if (new_position.x < (size.x / 2))
		new_position.x = (size.x / 2);				// ��� ����� �������� �������� , ��� ������ ����� �����
	if (new_position.y < (size.y / 2))
		new_position.y = (size.y / 2);
	if (new_position.x > (window.getSize().x - size.x / 2))
		new_position.x = (window.getSize().x - size.x / 2);
	if (new_position.y > (window.getSize().y - size.y / 2))
		new_position.y = (window.getSize().y - size.y / 2);*/
	camera.setCenter(new_position);
}

void PlayerCamera::draw(Character& character, sf::RenderWindow& window)
{
	set_position(character.get_character_position(), window); // ������������ �������
	
	window.setView(camera); // ������������ ������

}
