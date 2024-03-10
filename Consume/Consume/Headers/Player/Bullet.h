#pragma once
#include <SFML/Graphics.hpp>

class Bullet
{
private:
	sf::Texture m_TextureBullet;

	sf::Sprite m_BulletSprite;

	sf::Vector2f m_Position;

	bool m_IsGoingLeft;

	bool m_IsGoingRight;

	float m_SpeedX;

public:
	Bullet();

	void update(float dtAsSeconds);
	void draw(sf::RenderWindow& renderWindow);

	void setIsGoingLeft(bool isGoingLeft);

	void setIsGoingRight(bool isGoignRight);

	void setPosition(sf::Vector2f position);

	sf::FloatRect getHitbox();

};
