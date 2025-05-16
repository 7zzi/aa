#pragma once

#ifndef LUCKY_H
#define LUCKY_H

#include <SFML/Graphics.hpp>
#include <iostream>

class luckyblock {
private:
	sf::Texture texture;
	sf::FloatRect b_Baba;
	std::vector<sf::Vector2f> positions;
	/*float velocityY = 0;
	float accelerationY = 0;

	float gravity = 2;*/
	bool checkPlayerCollision(sf::FloatRect p_Baba);
public:
	sf::Sprite sprite;
	luckyblock();
	void update();
};

#endif#pragma once
