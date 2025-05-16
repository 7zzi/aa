#include "Engine.h"

using namespace sf;
Engine::Engine()
{
	Clock jumpclock;

	Vector2f resolution;
	m_Window.create(VideoMode({ 640, 480 }), "xxx", State::Windowed);
};

int Engine::start()
{
	while (m_Window.isOpen())
	{
		jumpCountdownAsSeconds -= jumpclock.getElapsedTime().asSeconds();

		Time dt = jumpclock.restart();
		
		float dtAsSeconds = dt.asSeconds();

		input();
		update(dtAsSeconds);
		draw();
	}

	return 0;
}

bool Engine::isJumpCooldownOver() {
	if (jumpCountdownAsSeconds <= 0.0f) {
		jumpCountdownAsSeconds = 1.5f;
		jumpclock.restart();
		return true;
	}
	else {
		return false;
	}
}