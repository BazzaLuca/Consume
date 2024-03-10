#pragma once
#include <SFML/Graphics.hpp>

class Bat
{
private:
	sf::Texture m_TextureBat;

	std::vector<sf::IntRect> m_CurrentFrames;

	std::vector<sf::IntRect> m_IdleFrames;

	std::vector<sf::IntRect> m_Walking_Frames;

	std::vector<sf::IntRect> m_DyingFrames;

	std::vector<sf::IntRect> m_DeadFrames;

	sf::Sprite m_BatSprite;

	sf::Vector2f m_Position;

	float m_FrameDuration;

	int m_CurrentFrame;

	float m_Speed_X;

	sf::Vector2f startPoint;

	sf::Vector2f destinationPoint;

	bool m_IsWalking;

	// If player make contact with datamage hitbox then kill player
	sf::FloatRect m_Hitbox;

	bool m_IsAlive;	

	bool m_IsDying;
	
public:
	Bat();

	void update(float dtAsSeconds);
	void draw(sf::RenderWindow& renderWindow);

	void setPosition(float x, float y);
	sf::FloatRect getHitbox();

	void changeFramesToDying();

	void resurrect(float speedX);
};