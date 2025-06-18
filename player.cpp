#include "player.h"
#include <SDL3/SDL.h>
#include <iostream>

player::player() {
}

 SDL_Texture* player::load(SDL_Renderer* ren) {
	SDL_Surface* bmp = SDL_LoadBMP("player");
    if (!bmp) {
        std::cerr << "Failed to load BMP file: blocks.bmp\n";
        return;
    }
	 SDL_Texture* pTex = SDL_CreateTextureFromSurface(ren, bmp);
	 if (!pTex) { std::cout << "failed to create texture! sdl_error: " << SDL_GetError() << std::endl; }
	 SDL_DestroySurface(bmp);
	 return pTex;
 }

 void player::move(float x, float y) {
	 rect.x += x;
	 rect.y += y;
 }

 void player::setsize(float w, float h) {
	 rect.w = w;
	 rect.h = h;
 }

 void player::setpos(float x, float y) {
	 rect.x = x;
	 rect.y = y;
 }

 void player::update(int COLLISION_OUTPUT) {
	 if (COLLISION_OUTPUT == 0) {
		 //velocityY += 2;
	 }

	 /*velocityX += accelerationX;
	 velocityY += accelerationY;
	 rect.x += velocityX;
	 rect.y += velocityY;
	 */
	 if (rect.y >= 240) {
		 //rect.y = 240;
	 }

	 std::cout << rect.x << " " << rect.y << std::endl;
 }