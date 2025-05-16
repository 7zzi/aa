#include "Engine.h"

using namespace sf;

void Engine::update(float dtAsSeconds)
{
	Player.update(dtAsSeconds);
}