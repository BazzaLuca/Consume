#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <map>
#include "../../Headers/GUI/Screen.h"


class ScreenManager
{
private:
	std::string m_CurrentScreen;

	std::map<std::string, Screen*> m_Screens;

public:
	ScreenManager();

	void switchScreen(std::string screenToSwitchTo);

	void input(sf::RenderWindow& renderWindow);
	void update(float fps);
	void draw(sf::RenderWindow& renderWindow);
};