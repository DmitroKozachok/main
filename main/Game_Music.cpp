#include "Game_Music.h"
#include <iostream>

Game_Music::Game_Music(int song_lvl, std::string Amusik, bool iMusic, int prioretet = -1)
{
	lvl_this_music = song_lvl;
	path_to_music_song = Amusik;
	prioretet_counter_to_vector_start_music = prioretet;
	if (iMusic) {
		if (!this_music.openFromFile(Amusik)) {
			std::cout << "Error adding music in settings_music class" << std::endl;
		}
		this_music.setVolume(lvl_this_music);
		isMusic = true;
	}
	else {
		if (!this_sound_buffer.loadFromFile(Amusik)) {
			std::cout << "Error adding song in settings_music class" << std::endl;
		}
		else {
			this_sound.setBuffer(this_sound_buffer);
			this_sound.setVolume(lvl_this_music);
			isMusic = false;
		}
	}
}

void Game_Music::set_lvl_this_music(int new_lvl_song)
{
	if (new_lvl_song > 100)
		lvl_this_music = 100;
	else if (new_lvl_song < 0)
		lvl_this_music = 0;
	else
		lvl_this_music = new_lvl_song;
}

void Game_Music::set_this_music(std::string another_path)
{
	if (isMusic) {
		if (!this_music.openFromFile(another_path)) {
			std::cout << "Error adding music in settings_music class" << std::endl;
		}
		else {
			path_to_music_song = another_path;
		}
	}
	else {
		if (!this_sound_buffer.loadFromFile(another_path)) {
			std::cout << "Error adding song in settings_music class" << std::endl;
		}
		else {
			path_to_music_song = another_path;
		}
	}
}

int Game_Music::get_lvl_this_music()
{
	return lvl_this_music;
}

std::string Game_Music::get_path_this_music()
{
	return path_to_music_song;
}

void Game_Music::start_play_this_music()
{
	if (isMusic) {
		this_music.setPlayingOffset(current_time_for_pause);
		this_music.play();
	}
	else {
		if (prioretet_counter_to_vector_start_music == 1 && isStartOnce) {
			this_sound.play();
			isStartOnce = false;
		}
		else if (prioretet_counter_to_vector_start_music == 1 && isStartOnce == false) {

		}
		else if (prioretet_counter_to_vector_start_music == -1) {
			sound_timer_for_move += SOUND_TIME;
			if (sound_timer_for_move > 9) {
				sound_timer_for_move = 0;
				this_sound.play();
			}
		}
		else {
			sound_timer_for_move += SOUND_TIME;
			if (sound_timer_for_move > 1.25) {
				sound_timer_for_move = 0;
				this_sound.play();
			}
		}
	}
}

void Game_Music::stop_play_this_music()
{
	if (isMusic) {
		this_music.stop();
		current_time_for_pause = this_music.getPlayingOffset();
	}
	else {
		this_sound.stop();
	}
}

int Game_Music::getPrioretet_vect_music()
{
	return prioretet_counter_to_vector_start_music;
}

Game_Music::Game_Music(const Game_Music& other) {
	prioretet_counter_to_vector_start_music = other.prioretet_counter_to_vector_start_music;
	isMusic = other.isMusic;
	sound_timer_for_move = other.sound_timer_for_move;
	lvl_this_music = other.lvl_this_music;
	path_to_music_song = other.path_to_music_song;
	isMusic = other.isMusic;
	if (isMusic) {
		//this_music = other.this_music;
		if (!this_music.openFromFile(path_to_music_song)) {
			std::cout << "Error adding music in constructor copy " << std::endl;
		}
		this_music.setVolume(lvl_this_music);
	}
	else {
		if (!this_sound_buffer.loadFromFile(path_to_music_song)) {
			std::cout << "Error adding song in settings_music class" << std::endl;
		}
		this_sound.setBuffer(this_sound_buffer);
		this_sound.setVolume(lvl_this_music);
	}



}

