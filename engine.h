#pragma once

#define ENGINE_H
#include <SDL3/SDL.h>
#include "player.h"
#include "loader.h"
class engine
{
	private:
		player playerInstance;
		loader loaderInstance;
		SDL_Texture* pT;

		SDL_Window* w;
		SDL_Renderer* r;
		SDL_Event e;

		bool quit = false;

		void update(float dtAsSeconds);

		void input();
		void draw();
		void update();
		int q = 0;

		bool hasIntersectionFloat(const SDL_FRect* a, const SDL_FRect* b);
	public:
		engine();
		int s();
};