#include "../../Headers/Enemies/Bat.h"

Bat::Bat()
{
	this->m_IsAlive = true;
	this->m_IsDying = false;

	this->m_TextureBat.loadFromFile("Resources\\Sprites\\Bat_Sprite_Sheet.png");

	this->m_Walking_Frames.push_back(sf::IntRect(0, 0, 16, 16));
	this->m_Walking_Frames.push_back(sf::IntRect(16, 0, 16, 16));
	this->m_Walking_Frames.push_back(sf::IntRect(32, 0, 16, 16));
	this->m_Walking_Frames.push_back(sf::IntRect(48, 0, 16, 16));
	this->m_Walking_Frames.push_back(sf::IntRect(64, 0, 16, 16));

	this->m_DyingFrames.push_back(sf::IntRect(0, 16, 16, 16));
	this->m_DyingFrames.push_back(sf::IntRect(16, 16, 16, 16));
	this->m_DyingFrames.push_back(sf::IntRect(32, 16, 16, 16));
	this->m_DyingFrames.push_back(sf::IntRect(48, 16, 16, 16));
	this->m_DyingFrames.push_back(sf::IntRect(64, 16, 16, 16));

	this->m_DeadFrames.push_back(sf::IntRect(64, 16, 16, 16));

	this->m_CurrentFrames = this->m_Walking_Frames;

	this->m_BatSprite = sf::Sprite(this->m_TextureBat, this->m_CurrentFrames[0]);

	this->m_BatSprite.setOrigin(
		this->m_BatSprite.getLocalBounds().width / 2,
		this->m_BatSprite.getLocalBounds().height / 2);

	// TO REMOVE
	this->m_BatSprite.setPosition(600, 400);

	this->m_BatSprite.setScale(3, 3);

	this->m_FrameDuration = 0.1;

	this->m_Position.x = this->m_BatSprite.getGlobalBounds().top;
	this->m_Position.y = this->m_BatSprite.getGlobalBounds().left;

	this->m_CurrentFrame = 0;

	this->m_Speed_X = 170.0f;

	this->m_IsWalking = true;

	this->startPoint = sf::Vector2f(400, 130);
	this->destinationPoint = sf::Vector2f(700, 130);
}

void Bat::update(float dtAsSeconds)
{
	this->m_FrameDuration -= dtAsSeconds;

	if (m_FrameDuration <= 0)
	{
		this->m_FrameDuration = 0.1;
		this->m_CurrentFrame = (this->m_CurrentFrame + 1) % this->m_CurrentFrames.size();		
		this->m_BatSprite.setTextureRect(this->m_CurrentFrames[this->m_CurrentFrame]);

		if (this->m_IsDying && this->m_CurrentFrame == this->m_CurrentFrames.size()-1)
		{
			this->m_IsAlive = false;
			this->m_CurrentFrames = this->m_DeadFrames;
		}
	}

	if (this->m_IsWalking)
	{		
		if (this->m_BatSprite.getGlobalBounds().contains(this->destinationPoint))
		{
			sf::Vector2f copy = destinationPoint;
			this->destinationPoint = this->startPoint;
			this->startPoint = copy;
			this->m_Speed_X = this->m_Speed_X * -1;
			if (this->m_Speed_X > 0)
			{
				this->m_BatSprite.setScale(3, 3);
			}
			else
			{
				this->m_BatSprite.setScale(-3, 3);
			}
		}
		this->m_Position.x = this->m_Position.x + this->m_Speed_X * dtAsSeconds;

		this->m_Hitbox = sf::FloatRect(this->m_BatSprite.getGlobalBounds().left + 10
			, this->m_BatSprite.getGlobalBounds().top + 10
			, 26
			, 26);
	}

	this->m_BatSprite.setPosition(this->m_Position);	
}

void Bat::draw(sf::RenderWindow& renderWindow)
{
	renderWindow.draw(this->m_BatSprite);

	//DEBUG
	/*sf::RectangleShape rs;
	rs.setPosition(this->m_BatSprite.getGlobalBounds().left, this->m_BatSprite.getGlobalBounds().top);
	rs.setSize(sf::Vector2f(this->m_BatSprite.getGlobalBounds().width, this->m_BatSprite.getGlobalBounds().height));
	rs.setFillColor(sf::Color(255, 0, 0, 100));

	sf::RectangleShape rb;
	rb.setPosition(this->destinationPoint.x, this->destinationPoint.y);
	rb.setSize(sf::Vector2f(10, 10));
	rb.setFillColor(sf::Color(0, 255, 0, 100));
	
	renderWindow.draw(rs);
	renderWindow.draw(rb);*/

	sf::RectangleShape cc;
	cc.setPosition(this->m_Hitbox.left, this->m_Hitbox.top);
	cc.setSize(sf::Vector2f(this->m_Hitbox.width, this->m_Hitbox.height));
	cc.setFillColor(sf::Color(255, 0, 0, 100));
	renderWindow.draw(cc);
	// DEBUG
}

void Bat::setPosition(float x, float y)
{
	this->m_Position.x = x;
	this->m_Position.y = y;
}

sf::FloatRect Bat::getHitbox()
{
	return this->m_Hitbox;
}


void Bat::changeFramesToDying()
{
	this->m_IsDying = true;
	this->m_CurrentFrames = this->m_DyingFrames;
	this->m_Speed_X = 0;
	this->m_IsWalking = false;
}

void Bat::resurrect(float speedX)
{
	this->m_CurrentFrames = this->m_Walking_Frames;
	this->m_Speed_X = speedX;
	this->m_IsDying = false;
	this->m_IsAlive = true;
	this->m_IsWalking = true;
	this->startPoint = sf::Vector2f(400, 130);
	this->destinationPoint = sf::Vector2f(700, 130);
}