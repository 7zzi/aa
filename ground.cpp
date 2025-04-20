#include "ground.h"

#include <SFML/Graphics.hpp>
#include <iostream>

const sf::Texture texture("Block.png");
sf::Sprite ground(texture);

sf::Vector2f ScaleFactors(1.0f, 1.0f);
std::vector<sf::Vector2f> positions;

sf::FloatRect Ground::GetBounds() {
	sf::FloatRect localBounds = ground.getGlobalBounds();
	return localBounds;
}

void Jump() {}

void Ground::Render(sf::RenderWindow& w) {
	ground.setScale(ScaleFactors);
	positions.push_back({0, 400 });

	// Repeat
	// positions.push_back(); 
	// until desired amount is reached, 
	// redrawing the texture in many positions.
	for (int i = 1; i <= 48; i++) {
		positions.push_back({ static_cast<float>(16 * i), static_cast<float>(400) });
	}

	for (const auto& position : positions) {
		ground.setPosition(position); // Set the sprite's position
		w.draw(ground); // Draw the sprite at the current position
	}
}