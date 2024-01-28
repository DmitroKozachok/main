#include "NPC.h"

void NPC::move_animation_left(float delta_time)
{
	// ����������� ����� �������
	if (speed == diagonal_speed)
	{
		frame += delta_time / 2;
	}
	else
	{
		frame += delta_time;
	}


	// �������� �� ����
	if (frame > 5)
	{
		frame -= 5;
	}

	// ������������ �����
	character_sprite.setTextureRect(sf::IntRect(size_texture_x * int(frame), size_texture_y * 1, size_texture_x, size_texture_y));
}

void NPC::move_animation_right(float delta_time)
{
	// ����������� ����� �������
	if (speed == diagonal_speed)
	{
		frame += delta_time / 2;
	}
	else
	{
		frame += delta_time;
	}


	// �������� �� ����
	if (frame > 5)
	{
		frame -= 5;
	}

	// ������������ �����
	character_sprite.setTextureRect(sf::IntRect(size_texture_x * int(frame), size_texture_y * 2, size_texture_x, size_texture_y));
}

void NPC::move_animation_up(float delta_time)
{
	// ����������� ����� �������
	if (speed == diagonal_speed)
	{
		frame += delta_time / 2;
	}
	else
	{
		frame += delta_time;
	}


	// �������� �� ����
	if (frame > 5)
	{
		frame -= 5;
	}

	// ������������ �����
	character_sprite.setTextureRect(sf::IntRect(size_texture_x * int(frame), size_texture_y * 3, size_texture_x, size_texture_y));
}

void NPC::move_animation_down(float delta_time)
{
	// ����������� ����� �������
	if (speed == diagonal_speed)
	{
		frame += delta_time / 2;
	}
	else
	{
		frame += delta_time;
	}


	// �������� �� ����
	if (frame > 5)
	{
		frame -= 5;
	}

	// ������������ �����
	character_sprite.setTextureRect(sf::IntRect(size_texture_x * int(frame), size_texture_y * 0, size_texture_x, size_texture_y));
}

void NPC::idle_animation(float delta_time)
{
	// ������������ �����
	character_sprite.setTextureRect(sf::IntRect(size_texture_x * 1, size_texture_y * 0, size_texture_x, size_texture_y));
}

NPC::NPC(int size_x, int size_y, std::string image_way, sf::Vector2f position, sf::Vector2f scale, std::string font_path, std::string replik_file_path, std::string dialog_name, std::string name) : Character(size_x, size_y, image_way, position, scale, 5, 100, 1, name), dialog{ font_path, replik_file_path, dialog_name } {}

void NPC::detect_colision_with_player(Character& player, sf::FloatRect npc_rect, sf::FloatRect player_rect, float delta_time)
{
	// ��������� ���������� ��������� ������ �� ������
	sf::FloatRect npc_bounds = npc_rect;
	sf::FloatRect player_bounds = player_rect;

	// �������� �� �����
	if (npc_bounds.intersects(player_bounds))
	{
		is_dialog = true;
		player.set_position(player.get_old_position());
	}
}

void NPC::script_move(float delta_timer)
{
	// ���������
	move_status = STAND;
	idle_animation(delta_timer);
}

void NPC::dialog_processing(sf::Event event)
{
	if (is_dialog)
	{
		dialog.dialog_switch(event);
	}
}

void NPC::load_new_dialog(std::string path, std::string dialog_name)
{
	dialog.set_dialog_name(dialog_name);
	dialog.load_dialog_from_file(path);
}

void NPC::show(sf::RenderWindow& window, PlayerCamera& camera)
{
	// ���� ������� �� �����
	window.draw(character_sprite);

	if (is_dialog)
	{
		// ���� ������ �� �����
		dialog.show(window, camera, is_dialog);
	}

}

DialogSystem NPC::get_dialog() const
{
	return dialog;
}
