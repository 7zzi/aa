#include "engine.h"
#include <iostream>

void engine::draw() {
    if (pT == NULL) { std::cerr << "player texture load failure!" << "\n"; }
    SDL_SetRenderTarget(r, NULL);
    SDL_SetRenderDrawColor(r, 255, 255, 255, 255);
    SDL_RenderClear(r); // Clear the screen (window)
    loader.render(r);
    SDL_RenderTexture(r, pT, NULL, &player.rect);


    SDL_RenderPresent(r);
}