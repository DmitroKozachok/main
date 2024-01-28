#pragma once
#include <SFML/Audio.hpp>
#include <string>
#include <vector>

#define SOUND_TIME 0.25f

class Game_Music
{
public:
	
	//
	class settings_music {
	public:
		int lvl_this_music = 0;	// рівень звук
		sf::Music this_music;	// сама музика
		std::string path_to_music;	// шлях до музики
		settings_music(int song_lvl, std::string Amusik);  //конструктор
		void set_Lvl_this_music(int new_lvl_song);	// Зміна гучності музики
		void set_This_music(std::string another_path);	// Зміна самої музики
		int get_Lvl_this_music();	// отримання гучності музики 
		std::string get_This_music();	// отримання самої музики
		void start_play_this_music();
		void stop_play_this_music();
	};

	class settings_sound {
	public:
		float sound_timer_for_move = 0;
		//
		int lvl_this_sound = 0;	// рівень звук
		sf::Sound this_sound;	// сама звук
		sf::SoundBuffer this_sound_buffer; 
		std::string path_to_sound;	// шлях до звук
		settings_sound(int song_lvl, std::string Asong);  //конструктор
		void set_Lvl_this_sound(int new_lvl_song);	// Зміна гучності звук
		void set_This_sound(std::string another_path);	// Зміна самої звук
		int get_Lvl_this_sound();	// отримання гучності звук 
		std::string get_This_sound();	// отримання самої звук
		void start_play_this_sound();
		void stop_play_this_sound();
	};

	settings_music background_Music_in_Menu;
	settings_music background_music_in_world;
	std::vector<settings_music> vector_music;
	//
	settings_sound song_walking_playear;

	Game_Music();	// Конструктор
};
	//як варіант дописати vector і запхати туди всі пісні щоб по колу крутилися