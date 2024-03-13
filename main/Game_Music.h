#pragma once
#include <SFML/Audio.hpp>
#include <string>
#include <vector>

#define SOUND_TIME 0.25f


class Game_Music
{
public:
	int prioretet_counter_to_vector_start_music;
	bool isStartOnce = true;
	bool isMusic;
	float sound_timer_for_move = 0;
	int lvl_this_music = 0;	// ����� ����
	sf::Music this_music;	// ���� ������
	//
	sf::Sound this_sound;	// ����� ����
	sf::SoundBuffer this_sound_buffer;
	//
	std::string path_to_music_song;	// ���� �� ������
	sf::Time current_time_for_pause;
public:
	//Game_Music();	// �����������
	Game_Music(const Game_Music& other);
	Game_Music(int song_lvl, std::string Amusik, bool iMusic, int prioretet);	// �����������
	Game_Music(int song_lvl, std::string Amusik, bool iMusic) : Game_Music(song_lvl, Amusik, iMusic, -1) {}
	void set_lvl_this_music(int new_lvl_song);	// ���� ������� ������
	void set_this_music(std::string another_path);	// ���� ���� ������
	int get_lvl_this_music();	// ��������� ������� ������ 
	std::string get_path_this_music();	// ��������� ���� ������
	//
	void start_play_this_music();
	void stop_play_this_music();
	int getPrioretet_vect_music();

};