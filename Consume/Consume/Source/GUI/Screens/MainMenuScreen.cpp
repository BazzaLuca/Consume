#include "../../../Headers/GUI/Screens/MainMenuScreen.h"
#include <iostream>

MainMenuScreen::MainMenuScreen(ScreenManager* screenManagerPointer)
{
	this->m_ScreenManagerPointer = screenManagerPointer;
	this->setBackground("Resources\\Sprites\\mainmenu_background.png");

	this->m_StartButtonSprite.setPosition(385, 350);
	this->m_StartButtonSprite.setOrigin(105, 32);
	this->m_StartButtonSprite.setTexture(TextureHolder::GetTexture("Resources\\Sprites\\start_button.png"));	

	this->m_LevelsButtonSprite.setPosition(380, 430);
	this->m_LevelsButtonSprite.setOrigin(120, 32);
	this->m_LevelsButtonSprite.setTexture(TextureHolder::GetTexture("Resources\\Sprites\\levels_button.png"));

	this->m_QuitButtonSprite.setPosition(390, 515);
	this->m_QuitButtonSprite.setOrigin(80, 32);
	this->m_QuitButtonSprite.setTexture(TextureHolder::GetTexture("Resources\\Sprites\\quit_button.png"));

	this->m_CursorEvent = CursorEvent::NONE;
	this->m_ElapsedAnimationTime = 0;

	// Read highscores
	std::ifstream scoresFile("Resources\\Files\\scores.txt");

	if (scoresFile.is_open())
	{
		int bestTime;

		// Read last level defeated
		scoresFile >> this->m_LastLevelIndex;
		
		scoresFile >> bestTime;
		LevelManager::UpdateBestTime(bestTime, 0);

		scoresFile >> bestTime;
		LevelManager::UpdateBestTime(bestTime, 1);

		scoresFile >> bestTime;
		LevelManager::UpdateBestTime(bestTime, 2);

		scoresFile.close();
	}
	else
	{
		std::cerr << "Could not open file" << std::endl;
	}
}

void MainMenuScreen::input(sf::RenderWindow& renderWindow)
{
	sf::Event event;

	while (renderWindow.pollEvent(event))
	{
		if (event.type == sf::Event::KeyPressed)
		{
			// Handle the player quitting
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				renderWindow.close();
			}
		}		

		sf::Vector2i mousePosition = sf::Mouse::getPosition(renderWindow);		

		if (this->m_StartButtonSprite.getGlobalBounds().contains(sf::Vector2f(mousePosition)))
		{			
			this->m_CursorEvent = CursorEvent::START_BUTTON_HOVER;			
		}
		else if (this->m_LevelsButtonSprite.getGlobalBounds().contains(sf::Vector2f(mousePosition)))
		{			
			this->m_CursorEvent = CursorEvent::LEVELS_BUTTON_HOVER;			
		}
		else if (this->m_QuitButtonSprite.getGlobalBounds().contains(sf::Vector2f(mousePosition)))
		{			
			this->m_CursorEvent = CursorEvent::QUIT_BUTTON_HOVER;			
		}
		else
		{
			this->m_CursorEvent = CursorEvent::NONE;
		}

		if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
		{
			if (this->m_CursorEvent == CursorEvent::START_BUTTON_HOVER)
			{
				std::cout << "start" << std::endl;
				if (this->m_LastLevelIndex == 0)
				{
					this->m_ScreenManagerPointer->switchScreen("Level_0");
				}
				else if (this->m_LastLevelIndex == 1)
				{
					this->m_ScreenManagerPointer->switchScreen("Level_1");
				}
				else if (this->m_LastLevelIndex == 2)
				{
					this->m_ScreenManagerPointer->switchScreen("Level_2");
				}			
				else
				{
					// Completed all levels
					this->m_ScreenManagerPointer->switchScreen("Level_2");
				}
				
			}
			else if (this->m_CursorEvent == CursorEvent::LEVELS_BUTTON_HOVER)
			{
				std::cout << "levels" << std::endl;
			}
			else if (this->m_CursorEvent == CursorEvent::QUIT_BUTTON_HOVER)
			{
				renderWindow.close();
			}
		}
	}
}

void MainMenuScreen::update(float fps)
{		
	if (this->m_CursorEvent == CursorEvent::START_BUTTON_HOVER)
	{		
		this->m_LevelsButtonSprite.setScale(1, 1);
		this->m_QuitButtonSprite.setScale(1, 1);

		this->m_ElapsedAnimationTime += fps;
		float scalefactor = ( (sin(this->m_ElapsedAnimationTime*2)) / 10.0 + (1.0 / 10.0) + 1);	
		this->m_StartButtonSprite.setScale(scalefactor, scalefactor);
	}
	else if (this->m_CursorEvent == CursorEvent::LEVELS_BUTTON_HOVER)
	{
		this->m_StartButtonSprite.setScale(1, 1);
		this->m_QuitButtonSprite.setScale(1, 1);

		this->m_ElapsedAnimationTime += fps;
		float scalefactor = ((sin(this->m_ElapsedAnimationTime * 2)) / 10.0 + (1.0 / 10.0) + 1);
		this->m_LevelsButtonSprite.setScale(scalefactor, scalefactor);
		
	}
	else if (this->m_CursorEvent == CursorEvent::QUIT_BUTTON_HOVER)
	{
		this->m_StartButtonSprite.setScale(1, 1);
		this->m_LevelsButtonSprite.setScale(1, 1);

		this->m_ElapsedAnimationTime += fps;
		float scalefactor = ((sin(this->m_ElapsedAnimationTime * 2)) / 10.0 + (1.0 / 10.0) + 1);
		this->m_QuitButtonSprite.setScale(scalefactor, scalefactor);		
	}
	else
	{
		this->m_ElapsedAnimationTime = 0;
		this->m_StartButtonSprite.setScale(1, 1);
		this->m_LevelsButtonSprite.setScale(1, 1);
		this->m_QuitButtonSprite.setScale(1, 1);
	}
}

void MainMenuScreen::draw(sf::RenderWindow& renderWindow)
{
	this->drawBackground(renderWindow);
	renderWindow.draw(this->m_StartButtonSprite);
	renderWindow.draw(this->m_LevelsButtonSprite);
	renderWindow.draw(this->m_QuitButtonSprite);
}
