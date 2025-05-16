#pragma once

#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <iostream>

class player {
	private:		
		sf::Texture texture;

		bool m_LeftPressed;
		bool m_RightPressed;

		float m_Speed;
		
		sf::FloatRect bounds;

		float velocityX = 0;
		float velocityY = 0;
		float accelerationX = 0;
		float accelerationY = 0;

		float gravity = 2;
	public:
		player();
		sf::Sprite sprite;
		sf::Vector2f m_Position;
		void moveLeft();
		void moveRight();
		void stopLeft();
		void stopRight();
		void jump();
		void update(float elapsedTime);
};