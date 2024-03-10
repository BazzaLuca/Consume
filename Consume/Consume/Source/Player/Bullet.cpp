#include "../../Headers/Player/Bullet.h"
#include "../../Headers/TextureHolder/TextureHolder.h"

Bullet::Bullet()
{
	//this->m_TextureBullet.loadFromFile("Resources\\Sprites\\bullet.png");
	this->m_BulletSprite.setTexture(TextureHolder::GetTexture("Resources\\Sprites\\bullet.png"));
	this->m_BulletSprite.setPosition(-1, -1);
	this->m_Position = sf::Vector2f(-1, -1);
	this->m_IsGoingRight = false;
	this->m_IsGoingLeft = false;
	this->m_SpeedX = 600;
}

void Bullet::setPosition(sf::Vector2f position)
{
	this->m_Position = position;
}

void Bullet::update(float dtAsSeconds)
{
	if (this->m_IsGoingRight)
	{
		this->m_Position.x = this->m_Position.x + this->m_SpeedX * dtAsSeconds;
	}
	else if (this->m_IsGoingLeft)
	{
		this->m_Position.x = this->m_Position.x - this->m_SpeedX * dtAsSeconds;
	}

	this->m_BulletSprite.setPosition(this->m_Position);
}

void Bullet::draw(sf::RenderWindow& renderWindow)
{
	renderWindow.draw(this->m_BulletSprite);
}

void Bullet::setIsGoingLeft(bool isGoingLeft)
{
	this->m_IsGoingLeft = isGoingLeft;
}

void Bullet::setIsGoingRight(bool isGoignRight)
{
	this->m_IsGoingRight = isGoignRight;
}

sf::FloatRect Bullet::getHitbox()
{
	return this->m_BulletSprite.getGlobalBounds();
}