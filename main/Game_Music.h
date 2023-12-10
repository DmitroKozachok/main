#pragma once
#include  <SFML/Audio.hpp>
#include <string>

class Game_Music
{
public:
	class settings_music {
	public:
		int lvl_this_song = 0;	// рівень звук
		sf::Music this_music;	// сама музика
		std::string path_to_music;	// шлях до музики
		settings_music(int song_lvl, std::string Amusik);  //конструктор
		void set_Lvl_this_song(int new_lvl_song);	// Зміна гучності музики
		void set_This_music(std::string another_path);	// Зміна самої музики
		int get_Lvl_this_song();	// отримання гучності музики 
		std::string get_This_music();	// отримання самої музики
	};

	settings_music background_Music_in_Menu;
	Game_Music();	// Конструктор
	void start_background_music_in_Menu();	//запуск бг музики
	void stop_background_music_in_Menu();	//зупинка бг музики
	void up_tone_on_10();		//збільшити звук на 10
	void down_tone_on_10();	//збільшити звук на 10
};
