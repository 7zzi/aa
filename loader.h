#pragma once

#define LOADER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>
#include "SDL3/SDL.h"
class loader {
private:
	int array[8][40];
	int value;
	int count = 0;
	int b = 0;
	int row = count / 40;
	int col = count % 40;

	std::ifstream file;

	const int MAP_WIDTH = 40;
	const int MAP_HEIGHT = 8;
	const int TILE_SIZE = 16;

	// 0 - air , 1 - ground	, 2 -- lucky block!

	std::unordered_set<int> collidableTiles = { 1, 2 };
	std::vector<std::vector<int>> groundMap;

	int tileID;
	
	int renderArrayRow;
	int renderArrayCol;
public:
	loader();
	void load(SDL_Renderer* ren, int l);
	void render(SDL_Renderer* ren);
	std::vector<SDL_FRect> collisionRects;
	const SDL_FRect srcRect;
	const SDL_FRect dstRect;

	SDL_Texture* tex;
};