#include "../../../../Headers/GUI/Screens/Levels/Level_0.h"

Level_0::Level_0(ScreenManager* screenManagerPointer)
{
	this->m_ScreenManagerPointer = screenManagerPointer;
	this->setBackground("Resources\\Sprites\\MonstersBGLayer0.png");
	this->m_Aberration.setPosition(200, 200);

	this->m_FixedCollision_Top_Boxes.push_back(sf::FloatRect(0, 17*32, 200, 10));

	this->m_FixedCollision_Top_Boxes.push_back(sf::FloatRect(196, 15*32, 184, 10));

	this->m_FixedCollision_Top_Boxes.push_back(sf::FloatRect(380, 17 * 32, 12*32, 10));

	this->m_FixedCollision_Top_Boxes.push_back(sf::FloatRect(0, 384, 128 - 10, 10));
	

	this->m_FixedCollsion_Left_Boxes.push_back(sf::FloatRect(192, 480, 10, 100));

	this->m_FixedCollsion_Right_Boxes.push_back(sf::FloatRect(374, 482, 10, 100));
	this->m_FixedCollsion_Right_Boxes.push_back(sf::FloatRect(128-10, 384, 10, 32));

	this->m_FixedCollsion_Bottom_Boxes.push_back(sf::FloatRect(0, 416-10, 128-10, 10));


	//-----------------------------------------------------------------------------------------------------
	this->m_FixedCollsion_Bottom_Boxes.push_back(sf::FloatRect(6*32+10, 10*32-10, 3*32-20, 10));
	this->m_FixedCollsion_Left_Boxes.push_back(sf::FloatRect(6 * 32, 9*32, 10, 32));
	this->m_FixedCollision_Top_Boxes.push_back(sf::FloatRect(6 * 32+10, 9 * 32, 3 * 32-20, 10));
	//-----------------------------------------------------------------------------------------------------

	this->m_FixedCollsion_Bottom_Boxes.push_back(sf::FloatRect(10, 7 * 32 - 10, 4 * 32 - 20, 10));
	this->m_FixedCollision_Top_Boxes.push_back(sf::FloatRect(10, 6 * 32, 4 * 32 - 20, 10));
	this->m_FixedCollsion_Right_Boxes.push_back(sf::FloatRect(128 - 10, 6*32, 10, 32));
	//--
	this->m_FixedCollsion_Left_Boxes.push_back(sf::FloatRect(8 * 32, 4 * 32, 10, 5*32));
	this->m_FixedCollsion_Bottom_Boxes.push_back(sf::FloatRect(6 * 32 + 10, 4 * 32 - 10, 3 * 32 - 20, 10));
	this->m_FixedCollsion_Left_Boxes.push_back(sf::FloatRect(6 * 32, 3 * 32, 10, 32));
	this->m_FixedCollision_Top_Boxes.push_back(sf::FloatRect(6 * 32 + 10, 3 * 32, 3 * 32 - 20, 10));
	this->m_FixedCollsion_Right_Boxes.push_back(sf::FloatRect(9*32 - 10, 6 * 32, 10, 4*32));
	this->m_FixedCollsion_Right_Boxes.push_back(sf::FloatRect(9 * 32 - 10, 3 * 32, 10, 2 * 32));
	this->m_FixedCollision_Top_Boxes.push_back(sf::FloatRect(9 * 32, 5 * 32, 15*32, 10));
	this->m_FixedCollsion_Bottom_Boxes.push_back(sf::FloatRect(9 * 32, 6 * 32 - 10, 15 * 32, 10));

	//------------------------------------------
	this->m_FixedCollision_Top_Boxes.push_back(sf::FloatRect(15 * 32, 11 * 32, 5 * 32, 10));
	this->m_FixedCollsion_Bottom_Boxes.push_back(sf::FloatRect(15 * 32, 13 * 32 - 10, 5 * 32, 10));
	this->m_FixedCollsion_Left_Boxes.push_back(sf::FloatRect(15 * 32, 11 * 32, 10, 2*32));
	this->m_FixedCollsion_Right_Boxes.push_back(sf::FloatRect(20 * 32 - 10, 11 * 32, 10, 2 * 32));

	//------------------------------------------
	this->m_FixedCollsion_Right_Boxes.push_back(sf::FloatRect(1 * 32 - 10, 1 * 32, 10, 16 * 32));
	this->m_FixedCollsion_Bottom_Boxes.push_back(sf::FloatRect(1 * 32, 1 * 32 - 10, 23 * 32, 10));
	this->m_FixedCollsion_Left_Boxes.push_back(sf::FloatRect(24 * 32, 1 * 32, 10, 16 * 32));

	this->m_BaxkgrounTiles_Texture.loadFromFile("Resources\\Sprites\\brick.png");
	this->m_BackgroundTiles.setPrimitiveType(sf::PrimitiveType::Quads);
	this->m_BackgroundTiles.resize(1000);

	this->m_PoliceMan.setPosition(600, 500);

	// Read highscores
	std::ifstream scoresFile("Resources\\Files\\level_0.txt");

	std::string line;
	if (scoresFile.is_open())
	{
		std::string line;
		int index = 0;
		int lineIndex = 0;

		while (std::getline(scoresFile, line))
		{
			for (int c = 0; c < line.size(); c++)
			{
				if (line[c] == '1')
				{
					this->m_BackgroundTiles[index].position = sf::Vector2f(c*32, lineIndex*32);
					this->m_BackgroundTiles[index+1].position = sf::Vector2f(c*32 + 32, lineIndex * 32);
					this->m_BackgroundTiles[index+2].position = sf::Vector2f(c*32+32, lineIndex * 32 + 32);
					this->m_BackgroundTiles[index+3].position = sf::Vector2f(c * 32, lineIndex * 32 + 32);

					this->m_BackgroundTiles[index].texCoords = sf::Vector2f(0, 0);
					this->m_BackgroundTiles[index+1].texCoords = sf::Vector2f(32, 0);
					this->m_BackgroundTiles[index+2].texCoords = sf::Vector2f(32, 32);
					this->m_BackgroundTiles[index+3].texCoords = sf::Vector2f(0, 32);

					index += 4;
				}
			}

			lineIndex++;
		}

		scoresFile.close();
	}
	else
	{
		//std::cerr << "Could not open file" << std::endl;
	}	

}

void Level_0::input(sf::RenderWindow& renderWindow)
{
	this->m_Aberration.input(renderWindow);
}

void Level_0::update(float fps)
{
	this->m_Aberration.update(fps);
	this->m_PoliceMan.update(fps);

	for (int i = 0; i < this->m_FixedCollision_Top_Boxes.size(); i++)
	{
		if (this->m_Aberration.getFeetHitbox().intersects(this->m_FixedCollision_Top_Boxes[i]))
		{
			this->m_Aberration.setPosition(this->m_Aberration.getPosition().x, this->m_FixedCollision_Top_Boxes[i].top - this->m_Aberration.getHeight());
			this->m_Aberration.setSpeedY(0);
			this->m_Aberration.setIsJumping(false);
		}
	}		

	for (int i = 0; i < this->m_FixedCollsion_Left_Boxes.size(); i++)
	{
		if (this->m_Aberration.getIsGoingRight())
		{
			if (this->m_Aberration.getRightHitbox().intersects(this->m_FixedCollsion_Left_Boxes[i]))
			{
				this->m_Aberration.setPosition(this->m_FixedCollsion_Left_Boxes[i].left - this->m_Aberration.getWidth(), this->m_Aberration.getPosition().y);				
				this->m_Aberration.setIsGoingRight(false);
			}
		}		
	}

	for (int i = 0; i < this->m_FixedCollsion_Right_Boxes.size(); i++)
	{
		if (this->m_Aberration.getIsGoingLeft())
		{
			if (this->m_Aberration.getLeftHitbox().intersects(this->m_FixedCollsion_Right_Boxes[i]))
			{
				this->m_Aberration.setPosition(this->m_FixedCollsion_Right_Boxes[i].left+ this->m_FixedCollsion_Right_Boxes[i].width+ this->m_Aberration.getWidth(), this->m_Aberration.getPosition().y);
				this->m_Aberration.setIsGoingLeft(false);
			}
		}
	}

	for (int i = 0; i < this->m_FixedCollsion_Bottom_Boxes.size(); i++)
	{
		if (this->m_Aberration.getIsJumping())
		{
			if (this->m_Aberration.getHeadHitBox().intersects(this->m_FixedCollsion_Bottom_Boxes[i]))
			{
				this->m_Aberration.setPosition(this->m_Aberration.getPosition().x, this->m_FixedCollsion_Bottom_Boxes[i].top + this->m_FixedCollsion_Bottom_Boxes[i].height + this->m_Aberration.getHeight());
				this->m_Aberration.setSpeedY(0);
				//this->m_Aberration.setIsJumping(false);
			}
		}
	}
}

void Level_0::draw(sf::RenderWindow& renderWindow)
{
	this->drawBackground(renderWindow);
	renderWindow.draw(this->m_BackgroundTiles, &this->m_BaxkgrounTiles_Texture);

	// Draw collision boxes
	for (int i = 0; i < this->m_FixedCollision_Top_Boxes.size(); i++)
	{
		sf::RectangleShape rs;
		rs.setPosition(this->m_FixedCollision_Top_Boxes[i].left, this->m_FixedCollision_Top_Boxes[i].top);
		rs.setSize(sf::Vector2f(this->m_FixedCollision_Top_Boxes[i].width, this->m_FixedCollision_Top_Boxes[i].height));
		rs.setFillColor(sf::Color(0,0,255, 100));

		renderWindow.draw(rs);
	}

	for (int i = 0; i < this->m_FixedCollsion_Bottom_Boxes.size(); i++)
	{
		sf::RectangleShape rs;
		rs.setPosition(this->m_FixedCollsion_Bottom_Boxes[i].left, this->m_FixedCollsion_Bottom_Boxes[i].top);
		rs.setSize(sf::Vector2f(this->m_FixedCollsion_Bottom_Boxes[i].width, this->m_FixedCollsion_Bottom_Boxes[i].height));
		rs.setFillColor(sf::Color(255, 0, 0, 100));

		renderWindow.draw(rs);
	}

	for (int i = 0; i < this->m_FixedCollsion_Left_Boxes.size(); i++)
	{
		sf::RectangleShape rs;
		rs.setPosition(this->m_FixedCollsion_Left_Boxes[i].left, this->m_FixedCollsion_Left_Boxes[i].top);
		rs.setSize(sf::Vector2f(this->m_FixedCollsion_Left_Boxes[i].width, this->m_FixedCollsion_Left_Boxes[i].height));
		rs.setFillColor(sf::Color(126, 126, 0, 200));

		renderWindow.draw(rs);
	}

	for (int i = 0; i < this->m_FixedCollsion_Right_Boxes.size(); i++)
	{
		sf::RectangleShape rs;
		rs.setPosition(this->m_FixedCollsion_Right_Boxes[i].left, this->m_FixedCollsion_Right_Boxes[i].top);
		rs.setSize(sf::Vector2f(this->m_FixedCollsion_Right_Boxes[i].width, this->m_FixedCollsion_Right_Boxes[i].height));
		rs.setFillColor(sf::Color(0, 255, 0, 100));

		renderWindow.draw(rs);
	}	

	this->m_Aberration.draw(renderWindow);
	this->m_PoliceMan.draw(renderWindow);
}