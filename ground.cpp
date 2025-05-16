#include "ground.h"

#include <SFML/Graphics.hpp>
#include <iostream>
ground::ground():
	texture("Block.png"),
	sprite(texture)
{
	sf::FloatRect bounds = sprite.getGlobalBounds();
}
void ground::draw(sf::RenderWindow& w) {

	positions.push_back({0, 400 });

	// Repeat
	// positions.push_back(); 
	// until desired amount is reached, 
	// redrawing the texture in many positions.
	for (int i = 1; i <= 48; i++) {
		positions.push_back({ static_cast<float>(16 * i), static_cast<float>(400) });
	}

	for (const auto& position : positions) {
		sprite.setPosition(position); // Set the sprite's position
		w.draw(sprite); // Draw the sprite at the current position
	}
}
/*void hit() {
	velocityY -= 10;
}*/
void ground::update() {
	/*sprite.setPosition(g_Position.x, g_Position.y);

	if (g_Position.y < 400)                  //If you are above ground
		velocityY += gravity;    //Add gravity
	else if (g_Position.y > 400)             //If you are below ground
		g_Position.y = 400;                 //That's not supposed to happen, put him back up
	velocityY += accelerationY;
	g_Position.y += velocityY;*/
}