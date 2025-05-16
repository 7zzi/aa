#include "Engine.h"

void Engine::input() {
	if (Keyboard::isKeyPressed(Keyboard::Key::Escape)) {
		m_Window.close();
	}

	if (Keyboard::isKeyPressed(Keyboard::Key::A)) {
		Player.moveLeft();
	}
	else {
		Player.stopLeft();
	}

	if (Keyboard::isKeyPressed(Keyboard::Key::W) && isJumpCooldownOver()) {
			Player.jump();
	}

	if (Keyboard::isKeyPressed(Keyboard::Key::D)) {
		Player.moveRight();
	}
	else {
		Player.stopRight();
	}

	/*if (Keyboard::isKeyPressed(Keyboard::Key::O)) {
		ground.hit();
	}*/

}