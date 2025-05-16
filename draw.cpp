#include "Engine.h"

void Engine::draw(player Player)
{
	m_Window.clear(Color::Black);
	m_Window.draw(Player.sprite);
	Ground.draw(m_Window);
	m_Window.display();
}