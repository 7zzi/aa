#pragma once
#define PLAYER_H
#include <SDL3/SDL.h>


class player
{
private:
	float velocityX = 0;
	float velocityY = 0;
	float accelerationX = 0;
	float accelerationY = 0;

	float gravity = 2;
public:
	player();
	SDL_Texture* load(SDL_Renderer* ren);
	SDL_FRect rect{ 100, 100, 16, 16 };
	void move(float x, float y);
	void setsize(float w, float h);
	void setpos(float x, float y);

	void update(int COLLISION_OUTPUT);
};