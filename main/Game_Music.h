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
	int lvl_this_music = 0;	// рівень звук
	sf::Music this_music;	// сама музика
	//
	sf::Sound this_sound;	// самий звук
	sf::SoundBuffer this_sound_buffer;
	//
	std::string path_to_music_song;	// шлях до музики
	sf::Time current_time_for_pause;
public:
	//Game_Music();	// Конструктор
	Game_Music(const Game_Music& other);
	Game_Music(int song_lvl, std::string Amusik, bool iMusic, int prioretet);	// Конструктор
	Game_Music(int song_lvl, std::string Amusik, bool iMusic) : Game_Music(song_lvl, Amusik, iMusic, -1) {}
	void set_lvl_this_music(int new_lvl_song);	// Зміна гучності музики
	void set_this_music(std::string another_path);	// Зміна самої музики
	int get_lvl_this_music();	// отримання гучності музики 
	std::string get_path_this_music();	// отримання самої музики
	//
	void start_play_this_music();
	void stop_play_this_music();
	int getPrioretet_vect_music();

};