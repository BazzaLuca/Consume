#pragma once

#include <SFML/Graphics.hpp>
#include "../TextureHolder/TextureHolder.h"
#include "../Player/Player.h"
#include "../GUI/ScreenManager.h"
#include "../../Headers/GUI/Screens/LevelManager.h"

class Engine
{
private:
	TextureHolder textureHolder;

	LevelManager levelManager;

	ScreenManager m_ScreenManager;

	sf::RenderWindow m_Window;

	void input();
	void update(float dtAsSeconds);
	void draw();

public:
	Engine();

	void run();
};