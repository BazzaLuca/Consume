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

	float m_Speed_X;

	float m_Speed_Y;

	float m_Gravity;

	sf::FloatRect m_HeadHitbox;

	sf::FloatRect m_FeetHitbox;

	sf::FloatRect m_RightHitBox;

	sf::FloatRect m_LeftHitbox;

	bool m_IsJumping;

	float m_JumpSpeed = -100;

public:
	Player();

	void setPosition(float x, float y);
	sf::Vector2f getPosition();

	void input(sf::RenderWindow& renderWindow);
	void update(float dtAsSeconds);
	void draw(sf::RenderWindow& renderWindow);

	void setSpeedY(float speedY);
	void setSpeedX(float speedX);

	sf::FloatRect getFeetHitbox();
	sf::FloatRect getRightHitbox();
	sf::FloatRect getLeftHitbox();
	sf::FloatRect getHeadHitBox();

	sf::Vector2f getOrigin();

	float getHeight();
	float getWidth();

	void setIsJumping(bool isJumping);
	bool getIsJumping();

	bool getIsGoingLeft();
	void setIsGoingLeft(bool isGoingLeft);

	bool getIsGoingRight();
	void setIsGoingRight(bool isGoingRight);	
};