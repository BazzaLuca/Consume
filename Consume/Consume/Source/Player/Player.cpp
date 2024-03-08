#include "../../Headers/Player/Player.h"

Player::Player()
{
	this->m_TextureAberration.loadFromFile("Resources\\Sprites\\small_aberration.png");

	this->m_IdleFrames.push_back(sf::IntRect(17, 16, 41, 16));	
	this->m_IdleFrames.push_back(sf::IntRect(99, 16, 38, 16));	
	this->m_IdleFrames.push_back(sf::IntRect(260, 16, 33, 16));	
	this->m_IdleFrames.push_back(sf::IntRect(99, 16, 38, 16));	

	this->m_Walking_Frames.push_back(sf::IntRect(17, 16, 41, 16)); // First walking frame
	this->m_Walking_Frames.push_back(sf::IntRect(99, 16, 38, 16)); // Second walking framw
	this->m_Walking_Frames.push_back(sf::IntRect(183, 16, 28, 16)); // THird frame
	this->m_Walking_Frames.push_back(sf::IntRect(260, 16, 33, 16)); // Fourth frame

	this->m_CurrentFrames = this->m_IdleFrames;

	this->m_AberrationSprite = sf::Sprite(this->m_TextureAberration, this->m_Walking_Frames[0]);

	this->m_AberrationSprite.setOrigin(
		this->m_AberrationSprite.getLocalBounds().width / 2,
		this->m_AberrationSprite.getLocalBounds().height / 2);

	this->m_AberrationSprite.setScale(-2, 2);
	this->m_FrameDuration = 0.1;

	this->m_Position.x = this->m_AberrationSprite.getGlobalBounds().top;
	this->m_Position.y = this->m_AberrationSprite.getGlobalBounds().left;

	this->m_CurrentFrame = 0;

	this->m_IsGoingLeft = false;
	this->m_IsGoingRight = false;

	this->m_Speed = 120.0f;
}

void Player::input(sf::RenderWindow& renderWindow)
{
	sf::Event event;

	while (renderWindow.pollEvent(event))
	{
		if (event.type == sf::Event::KeyPressed)
		{
			// TO DO got left go right jump attack
			// Handle the player quitting
			if (event.key.code == sf::Keyboard::Left)
			{
				if (!m_IsGoingLeft)
				{
					this->m_IsGoingLeft = true;
					this->m_IsGoingRight = false;
					this->m_CurrentFrame = 0;
					this->m_CurrentFrames = this->m_Walking_Frames;

					this->m_AberrationSprite.setOrigin(
						this->m_AberrationSprite.getLocalBounds().width / 2,
						this->m_AberrationSprite.getLocalBounds().height / 2);

					this->m_AberrationSprite.setScale(2, 2);
				}				
			}
			else if (event.key.code == sf::Keyboard::Right)
			{
				if (!m_IsGoingRight)
				{
					this->m_IsGoingRight = true;
					this->m_IsGoingLeft = false;
					this->m_CurrentFrame = 0;
					this->m_CurrentFrames = this->m_Walking_Frames;

					this->m_AberrationSprite.setOrigin(
						this->m_AberrationSprite.getLocalBounds().width / 2,
						this->m_AberrationSprite.getLocalBounds().height / 2);

					this->m_AberrationSprite.setScale(-2, 2);
				}
				
			}			
		}	

		if (event.type == sf::Event::KeyReleased)
		{
			if (event.key.code == sf::Keyboard::Left)
			{
				// Key is released, set the flag to false
				this->m_IsGoingLeft = false;
			}
			
			if (event.key.code == sf::Keyboard::Right)
			{
				// Key is released, set the flag to false
				this->m_IsGoingRight = false;
			}
		}

		if (!this->m_IsGoingLeft && !this->m_IsGoingRight)
		{
			this->m_CurrentFrames = this->m_IdleFrames;
		}
	}
}

void Player::update(float dtAsSeconds)
{
	this->m_FrameDuration -= dtAsSeconds;


	if (this->m_IsGoingLeft)
	{
		this->m_Position.x = this->m_Position.x - this->m_Speed * dtAsSeconds;
	}
	else if (this->m_IsGoingRight)
	{
		this->m_Position.x = this->m_Position.x + this->m_Speed * dtAsSeconds;
	}

	this->m_AberrationSprite.setPosition(this->m_Position);

	if (m_FrameDuration <= 0)
	{
		this->m_FrameDuration = 0.1;
		this->m_CurrentFrame = (this->m_CurrentFrame + 1) % this->m_CurrentFrames.size();
		this->m_AberrationSprite.setTextureRect(this->m_CurrentFrames[this->m_CurrentFrame]);
	}
}

void Player::draw(sf::RenderWindow& renderWindow)
{
	renderWindow.draw(this->m_AberrationSprite);
}

void Player::setPosition(float x, float y)
{
	this->m_Position.x = x;
	this->m_Position.y = y;
}