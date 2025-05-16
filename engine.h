#pragma once
#include <SFML/Graphics.hpp>
#include "player.h"
#include "ground.h"
using namespace sf;

class Engine
{
private:
	player Player;
	ground Ground;
	Clock jumpclock;

	RenderWindow m_Window;

	void update(float dtAsSeconds);

	void input();
	void draw(player Player);

	float jumpCountdownAsSeconds = 1.5f;
public:
	Engine();
	int start();
	bool isJumpCooldownOver();
};