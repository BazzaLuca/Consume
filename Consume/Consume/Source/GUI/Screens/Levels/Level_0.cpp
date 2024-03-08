#include "../../../../Headers/GUI/Screens/Levels/Level_0.h"

Level_0::Level_0(ScreenManager* screenManagerPointer)
{
	this->m_ScreenManagerPointer = screenManagerPointer;
	this->setBackground("Resources\\Sprites\\mainmenu_background.png");
	this->m_Aberration.setPosition(200, 200);
}

void Level_0::input(sf::RenderWindow& renderWindow)
{
	this->m_Aberration.input(renderWindow);
}

void Level_0::update(float fps)
{
	this->m_Aberration.update(fps);
}

void Level_0::draw(sf::RenderWindow& renderWindow)
{
	this->drawBackground(renderWindow);
	this->m_Aberration.draw(renderWindow);
}