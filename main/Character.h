/*клас для створення шаблоного персонажа*/

#pragma once
#include <SFML/Graphics.hpp>

// структура координат анімації
struct CordAnimation
{
	int cord_left_anim;
	int cord_right_anim;
	int cord_up_anim;
	int cord_down_anim;
};

class Character
{
protected:

	CordAnimation cord_for_animation; // кординати анімації

	float health; // здоров'я
	float damage; // урон
	bool is_alive; // чи живий
	float speed; // швидкість
	
	sf::Sprite character_sprite; // спрайт персонажа
	sf::Image character_image; // картинка персонажа
	sf::Texture character_texture; // текстура персонажа

	int size_texture_x; // розмір тайлу по Х
	int size_texture_y; // розмір тайлу по У

	float frame; // теперішній кадр

	void move_left(float delta_time); // рух вліво
	void move_right(float delta_time); // рух вправо
	void move_up(float delta_time); // рух вгору
	void move_down(float delta_time); // рух вниз

	void move_animation_left(float delta_time); // анімація руху вліво
	void move_animation_right(float delta_time); // анімація руху вправо
	void move_animation_up(float delta_time); // анімація руху вгору
	void move_animation_down(float delta_time); // анімація руху вниз

	void idle_animation(float delta_time); // анімація стояння

public:

	Character(); // конструктор за завмовчуванням, створює звичайний квадрат
	Character(int size_x, int size_y, std::string image_way, sf::Vector2f position, sf::Vector2f scale); // конструктор, що встановлює спрайт персонажа

	void set_health(float new_health); // встановлення життя
	void set_damage(float new_damage); // встановлення урону
	void set_live_status(bool status); // встановлення чи герой живий, true - живий, false - мертвий

	float get_health() const; // повертає здоров'я персонажа
	float get_damage() const; // повертає урон персонажа
	bool get_live_status() const; // повертає статус життя героя, true - живий, false - мертвий
	
	void show(sf::RenderWindow& window); // промальовка персонажа

	void move(sf::Event event, float delta_time); // рух персонажа

};

