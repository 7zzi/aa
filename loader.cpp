#include <SDL3/SDL.h>
#include <SDL3/SDL_image.h>
#include <fstream>
#include "loader.h"
loader::loader() :
srcRect(), dstRect()
{
}


void loader::load(SDL_Renderer* ren, int l) {
    tex = IMG_LoadTexture(ren, "blocks");
    if (!tex) {
        std::cerr << "Failed to load texture 'blocks'\n";
        return;
    }
    char mapChoiceFileFinal;
    std::ifstream file;
    if (l == -1) {
        const char* mapChoiceFileFinal = "ln1.lz";
    }

    file.open(mapChoiceFileFinal);
    if (!file) {
        std::cerr << "Error: Could not open map file.\n";
        return;
    }
    else {
        std::cout << "File opened successfully\n";
    }

    std::vector<int> values;
    char ch;

    while (file.get(ch)) {
        std::cout << ch;  // Optional: print each char for debugging
        if (ch >= '0' && ch <= '2') {
            values.push_back(ch - '0');
            if (values.size() >= 320) break;
        }
    }

    if (values.size() < 320) {
        std::cerr << "Error: Not enough valid values in the file (need 320, got "
            << values.size() << ").\n";
        return;
    }

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 40; ++j) {
            array[i][j] = values[static_cast<std::vector<int, std::allocator<int>>::size_type>(i) * 40 + j];
        }
    }

    // Optional: print array for debugging
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 40; ++j) {
            std::cout << array[i][j] << ' ';
        }
        std::cout << '\n';
    }
}


void loader::render(SDL_Renderer* ren) {
    if (!tex) return;

    collisionRects.clear();

    for (int renderArrayRow = 0; renderArrayRow < MAP_HEIGHT; ++renderArrayRow) {
        for (int renderArrayCol = 0; renderArrayCol < MAP_WIDTH; ++renderArrayCol) {
            int tileID = array[renderArrayRow][renderArrayCol];

            SDL_FRect srcRect = {
                static_cast<float>(tileID * TILE_SIZE),
                0.0f,
                static_cast<float>(TILE_SIZE),
                static_cast<float>(TILE_SIZE)
            };

            SDL_FRect dstRect = {
                static_cast<float>(renderArrayCol * TILE_SIZE),               // X = col
                static_cast<float>(renderArrayRow * TILE_SIZE + 240),         // Y = row + offset
                static_cast<float>(TILE_SIZE),
                static_cast<float>(TILE_SIZE)
            };

            SDL_RenderTexture(ren, tex, &srcRect, &dstRect);

            if (collidableTiles.count(tileID)) {
                collisionRects.push_back(dstRect);
            }
        }
    }
}