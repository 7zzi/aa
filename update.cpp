#include "engine.h"
#include "loader.h"

bool engine::hasIntersectionFloat(const SDL_FRect* a, const SDL_FRect* b) {
	return (a->x < b->x + b->w) or
		(a->x + a->w > b->x) or
		(a->y < b->y + b->h) or
		(a->y + a->h > b->y);
}

void engine::update() {
	for (const SDL_FRect& wall : loaderInstance.collisionRects) {
		if (hasIntersectionFloat(&playerInstance.rect, &wall)) {
			std::cout << "1" << std::endl;
			playerInstance.update(1);
		}
		else { 
			playerInstance.update(0);
			std::cout << "FALSE" << std::endl;
		}
	}
}