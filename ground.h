#pragma once

#ifndef GROUND_H
#define GROUND_H

#include <SFML/Graphics.hpp>
#include <iostream>

sf::FloatRect GetGroundBounds();
void RenderGround(sf::RenderWindow& w);

#endif