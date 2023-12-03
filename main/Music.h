#pragma once
#include  <SFML/Audio.hpp>


class Music
{
private:
	int lvl_song_background_Music = 0;	// рівень звуку задньої музики
public:
	sf::Music background_Music_in_Menu; // змінна для бг музики
	Music();	// Конструктор
	void start_background_music_in_Menu();	//запуск бг музики
	void stop_background_music_in_Menu();	//зупинка бг музики
	void up_tone_on_10();		//збільшити звук на 10
	void down_tone_on_10();	//збільшити звук на 10
	int get_Lvl_song_background_Music();	// дістати рівень звуку
	void set_Lvl_song_background_Music(int user_nam);	// змінити рівень звуку

};

