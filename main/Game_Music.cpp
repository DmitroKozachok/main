#include "Game_Music.h"
#include <iostream>

Game_Music::Game_Music() :
	background_Music_in_Menu(10, "Resources/Music/bg_menu.wav"),
	background_music_in_world(5,"Resources/Music/bg_world_1.wav"),
	song_walking_playear(10,"Resources/Music/StepOnTheGrass.wav")
{

};

// далі йде конструктор по класу settings_music
Game_Music::settings_music::settings_music(int song_lvl, std::string Amusik)
{
	if (!this_music.openFromFile(Amusik)) {
		std::cout << "Error adding music in settings_music class" << std::endl;
	}
	else {
		lvl_this_music = song_lvl;
		path_to_music = Amusik;
		this_music.setVolume(lvl_this_music);
	}
}

void Game_Music::settings_music::set_Lvl_this_music(int new_lvl_song)
{
	lvl_this_music = new_lvl_song;
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

int Game_Music::settings_music::get_Lvl_this_music()
{
	return lvl_this_music;
}

std::string Game_Music::settings_music::get_This_music()
{
	return path_to_music;
}

void Game_Music::settings_music::start_play_this_music()
{
	this_music.play();
}

void Game_Music::settings_music::stop_play_this_music()
{
	this_music.stop();
}

// кінець конструктора по класу settings_music

//start settings_song

Game_Music::settings_sound::settings_sound(int song_lvl, std::string Asong)
{
	if (!this_sound_buffer.loadFromFile(Asong)) {
		std::cout << "Error adding song in settings_music class" << std::endl;
	}
	else {
		lvl_this_sound = song_lvl;
		path_to_sound = Asong;
		this_sound.setBuffer(this_sound_buffer);
		this_sound.setVolume(lvl_this_sound);
	}
}

void Game_Music::settings_sound::set_Lvl_this_sound(int new_lvl_song)
{
	lvl_this_sound = new_lvl_song;
}

void Game_Music::settings_sound::set_This_sound(std::string another_path)
{
	path_to_sound = another_path;
}

int Game_Music::settings_sound::get_Lvl_this_sound()
{
	return lvl_this_sound;
}

std::string Game_Music::settings_sound::get_This_sound()
{
	return path_to_sound;
}

void Game_Music::settings_sound::start_play_this_sound()
{
	sound_timer_for_move += SOUND_TIME;
	//std::cout << sound_timer_for_move << std::endl;
	if (sound_timer_for_move > 9) {
		sound_timer_for_move = 0;
		this_sound.play();
	}
}

void Game_Music::settings_sound::stop_play_this_sound()
{
	this_sound.stop();
}


//end settings_song