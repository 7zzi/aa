#include "player.h"
#include "ground.h"

#include <SFML/Graphics.hpp>
#include <iostream>

player::player():
	texture("Player.png"),
	sprite(texture)
{
	texture.loadFromFile("player.png");
	sprite.setTexture(texture);

	m_Position.x = 320;
	m_Position.y = 380;

	m_Speed = 400;

	sf::FloatRect bounds = sprite.getGlobalBounds();
}

sf::Sprite player::getSprite() {
	return sprite;
}

void player::moveLeft() {
	m_LeftPressed = true;
}

void player::moveRight() {
	m_RightPressed = true;
}

void player::stopLeft() {
	m_LeftPressed = false;
}

void player::stopRight() {
	m_RightPressed = false;
}

void player::jump() {
	velocityY -= 15;
} 

void player::update(float elapsedTime) {
	if (m_Position.y < 380.0f)                  //If you are above ground
		velocityY += gravity;    //Add gravity
	//That's not supposed to happen, put him back up

	velocityX += accelerationX;
	velocityY += accelerationY;

	m_Position.x += velocityX;
	m_Position.y += velocityY;

	if (m_Position.y > 379.0f)             //If you are below ground
		m_Position.y = 380.0f;
	/*if (player::check(g_Bounds)) { std::cout << "1" << std::endl; }
	if (!player::check(g_Bounds)) { m_Position.y += 5; }*/

	if (m_RightPressed) {
		m_Position.x += m_Speed * elapsedTime;
	}

	if (m_LeftPressed) {
		m_Position.x -= m_Speed * elapsedTime;
	}
	sprite.setPosition(m_Position);
}