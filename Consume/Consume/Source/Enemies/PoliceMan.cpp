#include "../../Headers/Enemies/PoliceMan.h"
#include <iostream>

PoliceMan::PoliceMan()
{

	this->m_TexturePoliceMan.loadFromFile("Resources\\Sprites\\Officer_sheet_unboxed_0.png");

	this->m_IdleFrames.push_back(sf::IntRect(0, 0, 32, 32));
	this->m_IdleFrames.push_back(sf::IntRect(32, 0, 32, 32));
	this->m_IdleFrames.push_back(sf::IntRect(64, 0, 32, 32));
	this->m_IdleFrames.push_back(sf::IntRect(96, 0, 32, 32));
	this->m_IdleFrames.push_back(sf::IntRect(128, 0, 32, 32));
	this->m_IdleFrames.push_back(sf::IntRect(160, 0, 32, 32));
	this->m_IdleFrames.push_back(sf::IntRect(192, 0, 32, 32));

	this->m_Walking_Frames.push_back(sf::IntRect(0, 32, 32, 32));
	this->m_Walking_Frames.push_back(sf::IntRect(32, 32, 32, 32));
	this->m_Walking_Frames.push_back(sf::IntRect(64, 32, 32, 32));
	this->m_Walking_Frames.push_back(sf::IntRect(96, 32, 32, 32));
	this->m_Walking_Frames.push_back(sf::IntRect(128, 32, 32, 32));
	this->m_Walking_Frames.push_back(sf::IntRect(160, 32, 32, 32));
	this->m_Walking_Frames.push_back(sf::IntRect(192, 32, 32, 32));

	this->m_CurrentFrames = this->m_Walking_Frames;

	this->m_PoliceManSprite = sf::Sprite(this->m_TexturePoliceMan, this->m_CurrentFrames[0]);

	this->m_PoliceManSprite.setOrigin(
		this->m_PoliceManSprite.getLocalBounds().width / 2,
		this->m_PoliceManSprite.getLocalBounds().height / 2);

	// TO REMOVE
	this->m_PoliceManSprite.setPosition(600, 400);

	this->m_PoliceManSprite.setScale(3, 3);

	this->m_FrameDuration = 0.1;

	this->m_Position.x = this->m_PoliceManSprite.getGlobalBounds().top;
	this->m_Position.y = this->m_PoliceManSprite.getGlobalBounds().left;

	this->m_CurrentFrame = 0;

	this->m_Speed_X = 170.0f;

	this->m_IsWalking = true;

	this->startPoint = sf::Vector2f(400, 500);
	this->destinationPoint = sf::Vector2f(700, 500);

}

void PoliceMan::update(float dtAsSeconds)
{
	this->m_FrameDuration -= dtAsSeconds;

	if (m_FrameDuration <= 0)
	{
		this->m_FrameDuration = 0.1;
		this->m_CurrentFrame = (this->m_CurrentFrame + 1) % this->m_CurrentFrames.size();
		this->m_PoliceManSprite.setTextureRect(this->m_CurrentFrames[this->m_CurrentFrame]);
	}

	if (this->m_IsWalking)
	{
		//std::cout << this->m_PoliceManSprite.getGlobalBounds().left << std::endl;

		if (this->m_PoliceManSprite.getGlobalBounds().contains(this->destinationPoint))
		{
			sf::Vector2f copy = destinationPoint;
			this->destinationPoint = this->startPoint;
			this->startPoint = copy;
			this->m_Speed_X = this->m_Speed_X * -1;
			if (this->m_Speed_X > 0)
			{
				this->m_PoliceManSprite.setScale(3, 3);
			}
			else
			{
				this->m_PoliceManSprite.setScale(-3, 3);
			}
		}
		this->m_Position.x = this->m_Position.x + this->m_Speed_X * dtAsSeconds;
	}

	this->m_PoliceManSprite.setPosition(this->m_Position);
}

void PoliceMan::draw(sf::RenderWindow& renderWindow)
{	
	renderWindow.draw(this->m_PoliceManSprite);

	// DEBUG
	/*sf::RectangleShape rs;
	rs.setPosition(this->m_PoliceManSprite.getGlobalBounds().left, this->m_PoliceManSprite.getGlobalBounds().top);
	rs.setSize(sf::Vector2f(this->m_PoliceManSprite.getGlobalBounds().width, this->m_PoliceManSprite.getGlobalBounds().height));
	rs.setFillColor(sf::Color(255, 0, 0, 100));

	sf::RectangleShape rb;
	rb.setPosition(this->destinationPoint.x, this->destinationPoint.y);
	rb.setSize(sf::Vector2f(10, 10));
	rb.setFillColor(sf::Color(0, 255, 0, 100));

	renderWindow.draw(rs);
	renderWindow.draw(rb);*/

	// DEBUG
}

void PoliceMan::setPosition(float x, float y)
{
	this->m_Position.x = x;
	this->m_Position.y = y;
}