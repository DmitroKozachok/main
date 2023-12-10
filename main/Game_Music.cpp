#include "Game_Music.h"
#include <iostream>

Game_Music::Game_Music():
	background_Music_in_Menu(15, "Resources/Music/Ambient 3.wav")
{

}

void Game_Music::start_background_music_in_Menu() {
	//background_Music_in_Menu.set_Lvl_this_song(50);
	background_Music_in_Menu.this_music.setVolume(background_Music_in_Menu.get_Lvl_this_song());
	background_Music_in_Menu.this_music.setLoop(true);
	background_Music_in_Menu.this_music.play();

}

void Game_Music::stop_background_music_in_Menu() {
	background_Music_in_Menu.this_music.stop();
}

void Game_Music::up_tone_on_10() {
	if (background_Music_in_Menu.get_Lvl_this_song() + 10 < 100) {
		background_Music_in_Menu.set_Lvl_this_song(background_Music_in_Menu.get_Lvl_this_song() + 10);
	}
	else {
		background_Music_in_Menu.set_Lvl_this_song(100);
	}
}

void Game_Music::down_tone_on_10() {
	if (background_Music_in_Menu.get_Lvl_this_song() - 10 > 0) {
		background_Music_in_Menu.set_Lvl_this_song(background_Music_in_Menu.get_Lvl_this_song() - 10);
	}
	else {
		background_Music_in_Menu.set_Lvl_this_song(0);
	}
}

// далі йде конструктор по класу settings_music
Game_Music::settings_music::settings_music(int song_lvl, std::string Amusik)
{
	if (!this_music.openFromFile(Amusik)) {
		std::cout << "Error adding music in settings_music class" << std::endl;
	}
	else {
		song_lvl = 50;
		path_to_music = Amusik;
		this_music.setVolume(song_lvl);
	}
}

void Game_Music::settings_music::set_Lvl_this_song(int new_lvl_song)
{
	lvl_this_song = new_lvl_song;
}

void Game_Music::settings_music::set_This_music(std::string another_path)
{
	if (!this_music.openFromFile(another_path)) {
		std::cout << "Error adding music in settings_music class" << std::endl;
	}
	else {
		path_to_music = another_path;
	}
}

int Game_Music::settings_music::get_Lvl_this_song()
{
	return lvl_this_song;
}

std::string Game_Music::settings_music::get_This_music()
{
	return path_to_music;
}

// кінець конструктора по класу settings_music