#include <SDL3/SDL.h>
#include <iostream>
#include "engine.h"
#include "player.h"
#include "loader.h"
engine::engine() {
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0) {
		std::cerr << "SDL failed to initialize! SDL_ERROR: " << SDL_GetError() << "\n";
	}
	w = SDL_CreateWindow("xxx", 640, 480, SDL_WINDOW_RESIZABLE);
	r = SDL_CreateRenderer(w, nullptr);
	loaderInstance.load(r, -1);
	pT = playerInstance.load(r);
}

int engine::s() {
	while (q == 0) {
		input();
		update();
		draw();
	}

	SDL_DestroyRenderer(r);
	SDL_DestroyWindow(w);

	return 0;
}