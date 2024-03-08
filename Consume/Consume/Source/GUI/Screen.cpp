#include "../../Headers/GUI/Screen.h"
#include "../../Headers/TextureHolder/TextureHolder.h"

Screen::Screen()
{
}

void Screen::input(sf::RenderWindow& renderWindow)
{

}

void Screen::update(float fps)
{

}

void Screen::draw(sf::RenderWindow& renderWindow)
{

}


void Screen::setBackground(std::string texturePath)
{
	this->m_Background.setTexture(TextureHolder::GetTexture(texturePath));
}

void Screen::drawBackground(sf::RenderWindow& renderWindow)
{
	renderWindow.draw(this->m_Background);
}