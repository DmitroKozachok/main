/*клас для створення шаблоного персонажа*/

#pragma once
#include <SFML/Graphics.hpp>
#include "Map.h"
#include "HealthBar.h"

// структура координат анімації
struct CordAnimation
{
	int cord_left_anim;
	int cord_right_anim;
	int cord_up_anim;
	int cord_down_anim;
};

// положення анімації персонажа
enum MoveStatus
{
	LEFT,
	RIGHT,
	UP,
	DOWN,
	STAND
};

class Character
{
protected:

	CordAnimation cord_for_animation; // кординати анімації

	float health; // здоров'я
	float damage; // урон
	bool is_alive; // чи живий
	bool is_attacking; // чи атакує
	bool can_move; // чи може рухаєтись
	float speed; // швидкість
	float diagonal_speed; // швидкість під час руху по діагоналі
	sf::Vector2f old_position; // стара позиція (для колізії)
	std::string name; // ім'я гравця

	sf::Sprite character_sprite; // спрайт персонажа
	sf::Image character_image; // картинка персонажа
	sf::Texture character_texture; // текстура персонажа
	
	HealthBar character_health; // здоров'я персонажа
	
	int size_texture_x; // розмір тайлу по Х
	int size_texture_y; // розмір тайлу по У

	float frame; // теперішній кадр

	MoveStatus move_status; // положення анімації персонажа

	void move_left(float delta_time); // рух вліво
	void move_right(float delta_time); // рух вправо
	void move_up(float delta_time); // рух вгору
	void move_down(float delta_time); // рух вниз

	virtual void move_animation_left(float delta_time); // анімація руху вліво
	virtual void move_animation_right(float delta_time); // анімація руху вправо
	virtual void move_animation_up(float delta_time); // анімація руху вгору
	virtual void move_animation_down(float delta_time); // анімація руху вниз

	virtual void idle_animation(float delta_time); // анімація стояння

public:

	Character(); // конструктор за завмовчуванням, створює звичайний квадрат
	Character(int size_x, int size_y, std::string image_way, sf::Vector2f position, sf::Vector2f scale, float speed, float health, float damage, std::string name); // конструктор, що встановлює спрайт персонажа

	void set_health(float new_health); // встановлення життя
	void set_damage(float new_damage); // встановлення урону
	void set_live_status(bool status); // встановлення чи герой живий, true - живий, false - мертвий
	void set_position(sf::Vector2f position); // встановлення позиції

	float get_health() const; // повертає здоров'я персонажа
	float get_damage() const; // повертає урон персонажа
	bool is_character_attacking() const; // чи атакує
	bool get_can_move(); // чи може рухатись
	bool get_live_status() const; // повертає статус життя героя, true - живий, false - мертвий
	sf::Vector2f get_character_position() const; // повертає позицію гравця
	sf::Sprite get_character_sprite() const; // повертає спрайт гравця
	float get_frame() const; // повертає теперішній кадр анімації
	sf::Vector2f get_old_position() const; // повертає колишню позицію гравця
	std::string get_name() const; // повертає ім'я

	void detect_colision(Map& map_lvl, sf::FloatRect rect); // обробка колізії

	void show(sf::RenderWindow& window); // промальовка персонажа

	void move(float delta_time); // рух персонажа

	void gain_damage(float x);
};