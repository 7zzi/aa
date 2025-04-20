#include "player.h"
#include "ground.h"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <unordered_map>

const sf::Texture texture("Player.png");
sf::Sprite player(texture);
sf::Vector2f Factors(2.0f, 2.0f);
float x = 320.0f;
float y = 40.0f;

sf::FloatRect Player::GetBounds() {
	sf::FloatRect localBounds = player.getGlobalBounds();
	return localBounds;
}

void Player::Move(float xf, float yf) {
	Player::x += xf;
	Player::y += yf;

	sf::Vector2f Position(x, y);

	player.setPosition(Position);
}

void Player::Jump() {
	/*sf::Rect<float> PlayerBounds = Player::GetBounds();
	sf::Rect<float> GroundBounds = Ground::GetBounds();*/
}

void RenderPlayer(sf::RenderWindow& w) { 

	player.setScale(Factors);
	w.draw(player); 
}