#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <iostream>

//sf::Sprite LOAD();
sf::FloatRect GetPlayerBounds();
void Kill(int REASON);
void Move(float xf, float yf);
void Jump();
void RenderPlayer(sf::RenderWindow& w);

#endif