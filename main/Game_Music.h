#pragma once
#include <SFML/Audio.hpp>
#include <string>

#define SOUND_TIME 0.25f

class Game_Music
{
public:
	
	//
	class settings_music {
	public:
		int lvl_this_music = 0;	// ����� ����
		sf::Music this_music;	// ���� ������
		std::string path_to_music;	// ���� �� ������
		settings_music(int song_lvl, std::string Amusik);  //�����������
		void set_Lvl_this_music(int new_lvl_song);	// ���� ������� ������
		void set_This_music(std::string another_path);	// ���� ���� ������
		int get_Lvl_this_music();	// ��������� ������� ������ 
		std::string get_This_music();	// ��������� ���� ������
		void start_play_this_music();
		void stop_play_this_music();
	};

	class settings_sound {
	public:
		float sound_timer_for_move = 0;
		//
		int lvl_this_sound = 0;	// ����� ����
		sf::Sound this_sound;	// ���� ����
		sf::SoundBuffer this_sound_buffer; 
		std::string path_to_sound;	// ���� �� ����
		settings_sound(int song_lvl, std::string Asong);  //�����������
		void set_Lvl_this_sound(int new_lvl_song);	// ���� ������� ����
		void set_This_sound(std::string another_path);	// ���� ���� ����
		int get_Lvl_this_sound();	// ��������� ������� ���� 
		std::string get_This_sound();	// ��������� ���� ����
		void start_play_this_sound();
		void stop_play_this_sound();
	};

	settings_music background_Music_in_Menu;

	settings_music background_music_in_world;

	settings_sound song_walking_playear;

	Game_Music();	// �����������
};
	//�� ������ �������� vector � ������� ���� �� ��� ��� �� ���� ���������