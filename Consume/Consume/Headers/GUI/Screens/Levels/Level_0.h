#pragma once
#include "../../../../Headers/GUI/Screen.h"
#include "../../ScreenManager.h"
#include "../../../Player/Player.h"
#include <fstream>

class Level_0 : public Screen
{
private:
	ScreenManager* m_ScreenManagerPointer;

	Player m_Aberration;

	std::vector<sf::FloatRect> m_FixedCollision_Top_Boxes;

	std::vector<sf::FloatRect> m_FixedCollsion_Left_Boxes;

	std::vector<sf::FloatRect> m_FixedCollsion_Right_Boxes;

	std::vector<sf::FloatRect> m_FixedCollsion_Bottom_Boxes;

	sf::Texture m_BaxkgrounTiles_Texture;

	sf::VertexArray m_BackgroundTiles;

public:
	Level_0(ScreenManager* screenManagerPointer);

	void input(sf::RenderWindow& renderWindow) override;
	void update(float fps) override;
	void draw(sf::RenderWindow& renderWindow) override;
};