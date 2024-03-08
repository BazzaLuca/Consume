#include "../../Headers/Engine/Engine.h"

Engine::Engine()
{	
	this->m_Window.create(sf::VideoMode(800, 600), "Consume");	
}

void Engine::run()
{
	sf::Clock clock;

	while (this->m_Window.isOpen())
	{
		sf::Time dt = clock.restart();

		float dt_AsSeconds = dt.asSeconds();

		input();
		update(dt_AsSeconds);
		draw();
	}
}


void Engine::input()
{
	this->m_ScreenManager.input(this->m_Window);
}

void Engine::update(float dtAsSeconds)
{
	this->m_ScreenManager.update(dtAsSeconds);
}

void Engine::draw()
{
	// Rub out the last frame
	m_Window.clear(sf::Color::Black);

	this->m_ScreenManager.draw(this->m_Window);

	// Show everything we have just drawn
	m_Window.display();
}
