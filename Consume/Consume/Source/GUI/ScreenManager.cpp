#include "../../Headers/GUI/ScreenManager.h"
#include "../../Headers/GUI/Screens/MainMenuScreen.h"
#include "../../Headers/GUI/Screens/Levels/Level_0.h"

ScreenManager::ScreenManager()
{
	this->m_CurrentScreen = "MainMenuScreen";
	this->m_Screens["MainMenuScreen"] = new MainMenuScreen(this);	
	this->m_Screens["Level_0"] = new Level_0(this);
}

void ScreenManager::switchScreen(std::string screenToSwitchTo)
{
	this->m_CurrentScreen = screenToSwitchTo;
}

void ScreenManager::input(sf::RenderWindow& renderWindow)
{
	this->m_Screens[this->m_CurrentScreen]->input(renderWindow);
}

void ScreenManager::update(float fps)
{
	this->m_Screens[this->m_CurrentScreen]->update(fps);
}

void ScreenManager::draw(sf::RenderWindow& renderWindow)
{
	this->m_Screens[this->m_CurrentScreen]->draw(renderWindow);
}
