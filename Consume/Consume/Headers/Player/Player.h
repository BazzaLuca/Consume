#pragma once
#include <SFML/Graphics.hpp>
#include "../TextureHolder/TextureHolder.h"

class Player
{
private:
	sf::Texture m_TextureAberration;

	std::vector<sf::IntRect> m_CurrentFrames;

	std::vector<sf::IntRect> m_IdleFrames;

	std::vector<sf::IntRect> m_Walking_Frames;	

	sf::Sprite m_AberrationSprite;

	sf::Vector2f m_Position;

	float m_FrameDuration;

	int m_CurrentFrame;

	bool m_IsGoingLeft;

	bool m_IsGoingRight;

	float m_Speed;

public:
	Player();

	void setPosition(float x, float y);

	void input(sf::RenderWindow& renderWindow);
	void update(float dtAsSeconds);
	void draw(sf::RenderWindow& renderWindow);
};