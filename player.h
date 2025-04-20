#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <iostream>

//sf::Sprite LOAD();
class Player {
	private:
		sf::Sprite player;
		void Kill(int REASON);
		float x;
		float y;
	public:
		sf::FloatRect GetBounds();
		void Move();
		void Jump();
		void Render();
};

#endif