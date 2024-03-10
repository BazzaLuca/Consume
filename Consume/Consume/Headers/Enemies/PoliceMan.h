#pragma once
#include <SFML/Graphics.hpp>

class PoliceMan
{
private:
	sf::Texture m_TexturePoliceMan;

	std::vector<sf::IntRect> m_CurrentFrames;

	std::vector<sf::IntRect> m_IdleFrames;

	std::vector<sf::IntRect> m_Walking_Frames;

	sf::Sprite m_PoliceManSprite;

	sf::Vector2f m_Position;

	float m_FrameDuration;

	int m_CurrentFrame;

	float m_Speed_X;

	sf::Vector2f startPoint;
	
	sf::Vector2f destinationPoint;

	bool m_IsWalking;

public:
	PoliceMan();

	void update(float dtAsSeconds);
	void draw(sf::RenderWindow& renderWindow);

	void setPosition(float x, float y);	
};