// Consume.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow m_Window;
    m_Window.create(sf::VideoMode(448, 576),
		"Pacman",
		sf::Style::Titlebar | sf::Style::Close);

	while (m_Window.isOpen())
	{
		m_Window.clear(sf::Color::Black);
	}
}