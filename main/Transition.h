#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "PlayerCamera.h"
class Transition
{
    sf::RectangleShape overlay;
public:
    void darken_screen_lighten_screen(sf::RenderWindow& window, PlayerCamera camera, int duration_ms, sf::Vector2f position, Player& hero) {
        overlay.setSize(sf::Vector2f(camera.get_size().x + 128, camera.get_size().y + 128));
        overlay.setPosition(sf::Vector2f(camera.get_position().x - 448, camera.get_position().y - 256));
        for (int i = 0; i <= 255; i++) {
            overlay.setFillColor(sf::Color((0, 0, 0, i)));
            window.draw(overlay); 
            window.display();
            sf::sleep(sf::milliseconds(duration_ms / 255));
        }     
        hero.set_position(position); 
    }


    void teleport_player_pos(sf::Vector2f position, Player& hero, sf::RenderWindow& window, PlayerCamera& camera ,int transition_duration_ms) {
        darken_screen_lighten_screen(window, camera,transition_duration_ms, position, hero);
    }
};
