#include "Music.h"
#include <iostream>

Music::Music() {
	if (!background_Music_in_Menu.openFromFile("Resources/Music/Ambient 3.wav")) {	// перевірка на добавлення музики 
		std::cout << "Error background_Music_in_Menu" << std::endl;
	}
	else {
		lvl_song_background_Music = 50;
	}
}
void Music::start_background_music_in_Menu() {
	background_Music_in_Menu.setVolume(90);
	background_Music_in_Menu.setLoop(true);
	background_Music_in_Menu.play();

}
void Music::stop_background_music_in_Menu() {
	background_Music_in_Menu.stop();
}

void Music::up_tone_on_10()
{
	lvl_song_background_Music += 10;
	if (lvl_song_background_Music > 100) {
		lvl_song_background_Music = 100;
	}
}

void Music::down_tone_on_10()
{
	lvl_song_background_Music -= 10;
	if (lvl_song_background_Music < 0) {
		lvl_song_background_Music = 0;
	}
}

int Music::get_Lvl_song_background_Music()
{
	return lvl_song_background_Music;
}

void Music::set_Lvl_song_background_Music(int user_nam)
{
	if (user_nam > 100) 
		lvl_song_background_Music = 100;
	else if (user_nam < 0)
		lvl_song_background_Music = 0;
	lvl_song_background_Music = user_nam;
}
