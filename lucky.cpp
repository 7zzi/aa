#include "lucky.h"

#include <SFML/Graphics.hpp>
#include <iostream>
luckyblock::luckyblock() :
	texture("LuckyBlock.png"),
	sprite(texture)
{
	//sf::Vector2f b_Baba = sprite.getGlobalBounds();
}

sf::Sprite luckyblock::getSprite() {
	return sprite;
}

bool luckyblock::checkPlayerCollision(sf::FloatRect p_Baba) {
	if (p_Baba.contains(positions)) {

	}
}

void luckyblock::update() {

}