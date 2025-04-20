#include <SFML/Graphics.hpp>
#include "player.h"
#include "ground.h"
int main()
{
    sf::RenderWindow window(sf::VideoMode({ 640, 480 }), "a");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
            Player::Move(0.0f, -5.0f);
        } if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
            Player::Move(0.0f, 5.0f);
        } if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
            Player::Move(-5.0f, 0.0f);
        } if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
            Player::Move(5.0f, 0.0f);
        }

        window.clear();
        Player::Render(window);
        Ground::Render(window);
        window.display();
    }
}