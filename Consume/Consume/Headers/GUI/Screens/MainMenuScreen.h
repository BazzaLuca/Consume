#pragma once
#include "../../../Headers/GUI/Screen.h"
#include "../../../Headers/GUI/ScreenManager.h"
#include "../../../Headers/TextureHolder/TextureHolder.h"
#include "../../../Headers/GUI/Screens/LevelManager.h"
#include "CursorEvent.h"
#include <fstream>

class MainMenuScreen : public Screen
{
private:
	ScreenManager* m_ScreenManagerPointer;

	sf::Sprite m_StartButtonSprite;

	sf::Sprite m_LevelsButtonSprite;

	sf::Sprite m_QuitButtonSprite;

	CursorEvent m_CursorEvent;

	float m_ElapsedAnimationTime;

	int m_LastLevelIndex;	

public:
	MainMenuScreen(ScreenManager* screenManagerPointer);

	void input(sf::RenderWindow& renderWindow) override;
	void update(float fps) override;
	void draw(sf::RenderWindow& renderWindow) override;
};

