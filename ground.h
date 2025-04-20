#pragma once

#ifndef GROUND_H
#define GROUND_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Ground {
	public:
		sf::FloatRect GetBounds();
		void Render(sf::RenderWindow& w);
};

#endif