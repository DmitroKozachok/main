#pragma once
#include  <SFML/Audio.hpp>


class Music
{
private:
	int lvl_song_background_Music = 0;	// ����� ����� ������ ������
public:
	sf::Music background_Music_in_Menu; // ����� ��� �� ������
	Music();	// �����������
	void start_background_music_in_Menu();	//������ �� ������
	void stop_background_music_in_Menu();	//������� �� ������
	void up_tone_on_10();		//�������� ���� �� 10
	void down_tone_on_10();	//�������� ���� �� 10
	int get_Lvl_song_background_Music();	// ������ ����� �����
	void set_Lvl_song_background_Music(int user_nam);	// ������ ����� �����

};

