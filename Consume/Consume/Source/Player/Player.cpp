#include "../../Headers/Player/Player.h"
#include <iostream>

Player::Player()
{
	this->m_TextureAberration.loadFromFile("Resources\\Sprites\\small_aberration.png");

	this->m_IdleFrames.push_back(sf::IntRect(17, 16, 41, 16));	
	this->m_IdleFrames.push_back(sf::IntRect(99, 16, 41, 16));
	this->m_IdleFrames.push_back(sf::IntRect(260, 16, 41, 16));
	this->m_IdleFrames.push_back(sf::IntRect(99, 16, 41, 16));

	this->m_Walking_Frames.push_back(sf::IntRect(17, 16, 41, 16)); // First walking frame
	this->m_Walking_Frames.push_back(sf::IntRect(99, 16, 41, 16)); // Second walking framw
	this->m_Walking_Frames.push_back(sf::IntRect(183, 16, 41, 16)); // THird frame
	this->m_Walking_Frames.push_back(sf::IntRect(260, 16, 41, 16)); // Fourth frame

	this->m_CurrentFrames = this->m_IdleFrames;

	this->m_AberrationSprite = sf::Sprite(this->m_TextureAberration, this->m_CurrentFrames[0]);

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

	this->m_Speed_X = 170.0f;
	this->m_Speed_Y = 0;

	this->m_Gravity = 1200;

	this->m_IsJumping = false;

	this->m_JumpSpeed = -500;
}

void Player::input(sf::RenderWindow& renderWindow)
{		
	sf::Event event;
	while (renderWindow.pollEvent(event))
	{
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

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
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

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
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

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !this->m_IsJumping)
	{
		this->m_IsJumping = true;
		this->m_Speed_Y = this->m_JumpSpeed;
	}	
}

void Player::update(float dtAsSeconds)
{
	//std::cout << this->m_Speed_Y << std::endl;

	this->m_FrameDuration -= dtAsSeconds;		

	if (this->m_IsGoingLeft)
	{
		this->m_Position.x = this->m_Position.x - this->m_Speed_X * dtAsSeconds;
	}
	else if (this->m_IsGoingRight)
	{	
		this->m_Position.x = this->m_Position.x + this->m_Speed_X * dtAsSeconds;
	}

	this->m_Speed_Y += this->m_Gravity* dtAsSeconds;

	this->m_Position.y = this->m_Position.y + this->m_Speed_Y * dtAsSeconds;

	this->m_AberrationSprite.setPosition(this->m_Position);

	if (m_FrameDuration <= 0)
	{
		this->m_FrameDuration = 0.1;
		this->m_CurrentFrame = (this->m_CurrentFrame + 1) % this->m_CurrentFrames.size();
		this->m_AberrationSprite.setTextureRect(this->m_CurrentFrames[this->m_CurrentFrame]);
	}
	// Da mettere a posto
	this->m_FeetHitbox = sf::FloatRect(
		this->m_AberrationSprite.getGlobalBounds().left,
		this->m_AberrationSprite.getGlobalBounds().top+ this->m_AberrationSprite.getGlobalBounds().height-5,
		this->m_AberrationSprite.getGlobalBounds().width,
		5);

	this->m_HeadHitbox = sf::FloatRect(
		this->m_AberrationSprite.getGlobalBounds().left,
		this->m_AberrationSprite.getGlobalBounds().top,
		this->m_AberrationSprite.getGlobalBounds().width,
		5);

	// Da mettere a posto
	this->m_RightHitBox = sf::FloatRect(
		this->m_AberrationSprite.getGlobalBounds().left+ this->m_AberrationSprite.getGlobalBounds().width - 10,
		this->m_AberrationSprite.getGlobalBounds().top,
		10,
		this->m_AberrationSprite.getGlobalBounds().height);

	this->m_LeftHitbox = sf::FloatRect(
		this->m_AberrationSprite.getGlobalBounds().left,
		this->m_AberrationSprite.getGlobalBounds().top,
		10,
		this->m_AberrationSprite.getGlobalBounds().height);	
}

void Player::draw(sf::RenderWindow& renderWindow)
{
	renderWindow.draw(this->m_AberrationSprite);

	// DEBUG

	/*sf::RectangleShape rs;
	rs.setPosition(this->m_FeetHitbox.left, this->m_FeetHitbox.top);
	rs.setSize(sf::Vector2f(this->m_FeetHitbox.width, this->m_FeetHitbox.height));
	rs.setFillColor(sf::Color::Red);

	sf::RectangleShape rr;
	rs.setPosition(this->m_RightHitBox.left, this->m_RightHitBox.top);
	rs.setSize(sf::Vector2f(this->m_RightHitBox.width, this->m_RightHitBox.height));
	rs.setFillColor(sf::Color::Yellow);

	sf::RectangleShape rl;
	rl.setPosition(this->m_LeftHitbox.left, this->m_LeftHitbox.top);
	rl.setSize(sf::Vector2f(this->m_LeftHitbox.width, this->m_LeftHitbox.height));
	rl.setFillColor(sf::Color::White);

	sf::RectangleShape rh;
	rh.setPosition(this->m_HeadHitbox.left, this->m_HeadHitbox.top);
	rh.setSize(sf::Vector2f(this->m_HeadHitbox.width, this->m_HeadHitbox.height));
	rh.setFillColor(sf::Color::Magenta);

	renderWindow.draw(rs);
	renderWindow.draw(rr);
	renderWindow.draw(rl);
	renderWindow.draw(rh);*/
	// DEBUG
}

void Player::setPosition(float x, float y)
{
	this->m_Position.x = x;
	this->m_Position.y = y;
}

void Player::setSpeedY(float speedY)
{
	this->m_Speed_Y = speedY;
}

void Player::setSpeedX(float speedX)
{
	this->m_Speed_X = speedX;
}

sf::FloatRect Player::getFeetHitbox()
{
	return this->m_FeetHitbox;
}

sf::FloatRect Player::getHeadHitBox()
{
	return this->m_HeadHitbox;
}

sf::Vector2f Player::getOrigin()
{
	return this->m_AberrationSprite.getOrigin();
}

float Player::getHeight()
{
	return this->m_AberrationSprite.getLocalBounds().height;
}

float Player::getWidth()
{
	return this->m_AberrationSprite.getLocalBounds().width;
}

sf::Vector2f Player::getPosition()
{
	return this->m_Position;
}

void Player::setIsJumping(bool isJumping)
{
	this->m_IsJumping = isJumping;
}

sf::FloatRect Player::getRightHitbox()
{
	return this->m_RightHitBox;
}

sf::FloatRect Player::getLeftHitbox()
{
	return this->m_LeftHitbox;
}

bool Player::getIsGoingLeft()
{
	return this->m_IsGoingLeft;
}

void Player::setIsGoingLeft(bool isGoingLeft)
{
	this->m_IsGoingLeft = isGoingLeft;
}

bool Player::getIsGoingRight()
{
	return this->m_IsGoingRight;
}

void Player::setIsGoingRight(bool isGoingRight)
{
	this->m_IsGoingRight = isGoingRight;
}

bool Player::getIsJumping()
{
	return this->m_IsJumping;
}