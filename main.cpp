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
            Move(0.0f, -5.0f);
        } if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
            Move(0.0f, 5.0f);
        } if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
            Move(-5.0f, 0.0f);
        } if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
            Move(5.0f, 0.0f);
        }

        window.clear();
        RenderPlayer(window);
        RenderGround(window);
        window.display();
    }
}