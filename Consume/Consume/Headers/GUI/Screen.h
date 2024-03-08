#pragma once
#include <SFML/Graphics.hpp>

class Screen
{
private:
	sf::View m_View;

	sf::Sprite m_Background;

protected:
	void setBackground(std::string texturePath);
	void drawBackground(sf::RenderWindow& renderWindow);

public:
	Screen();

	void virtual input(sf::RenderWindow& renderWindow) = 0;
	void virtual update(float fps) = 0;
	void virtual draw(sf::RenderWindow& renderWindow) = 0;
};