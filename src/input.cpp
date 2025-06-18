#include "engine.h"
#include <iostream>
void engine::input() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_EVENT_QUIT) {
			// while ( q == 0 )
			//     everything();

			q = 1;
		}

		if (event.type == SDL_EVENT_KEY_DOWN)
		{
			// void move(float x, float y);

			// W

			float a = 5.0f;
			if (event.key.scancode == SDL_SCANCODE_W) {
				playerInstance.move(NULL, -a);
			} 

			// S
			if (event.key.scancode == SDL_SCANCODE_S) {
				playerInstance.move(NULL, a);
			} 

			// A
			if (event.key.scancode == SDL_SCANCODE_A) {
				playerInstance.move(-a, NULL);
			} 

			// D
			if (event.key.scancode == SDL_SCANCODE_D) {
				playerInstance.move(a, NULL);
			}
		}
	}
}