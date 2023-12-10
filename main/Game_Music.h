#pragma once
#include  <SFML/Audio.hpp>
#include <string>

class Game_Music
{
public:
	class settings_music {
	public:
		int lvl_this_song = 0;	// ����� ����
		sf::Music this_music;	// ���� ������
		std::string path_to_music;	// ���� �� ������
		settings_music(int song_lvl, std::string Amusik);  //�����������
		void set_Lvl_this_song(int new_lvl_song);	// ���� ������� ������
		void set_This_music(std::string another_path);	// ���� ���� ������
		int get_Lvl_this_song();	// ��������� ������� ������ 
		std::string get_This_music();	// ��������� ���� ������
	};

	settings_music background_Music_in_Menu;
	Game_Music();	// �����������
	void start_background_music_in_Menu();	//������ �� ������
	void stop_background_music_in_Menu();	//������� �� ������
	void up_tone_on_10();		//�������� ���� �� 10
	void down_tone_on_10();	//�������� ���� �� 10
};
