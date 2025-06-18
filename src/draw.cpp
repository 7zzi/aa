#include "engine.h"
#include <iostream>

void engine::draw() {
    // SDL_Texture* engine::pT
    // loaded in engine.cpp  >>  pT = playerInstance.load(r);
    if (pT == NULL) { std::cerr << "player texture load failure!" << "\n"; }
    SDL_SetRenderTarget(r, NULL);
    SDL_SetRenderDrawColor(r, 255, 255, 255, 255);
    SDL_RenderClear(r); // Clear the screen (window)
    loaderInstance.render(r);
    SDL_RenderTexture(r, pT, NULL, &playerInstance.rect);


    SDL_RenderPresent(r);
}