#pragma once
#include "../../../../Headers/GUI/Screen.h"
#include "../../ScreenManager.h"
#include "../../../Player/Player.h"

class Level_0 : public Screen
{
private:
	ScreenManager* m_ScreenManagerPointer;

	Player m_Aberration;

	std::vector<sf::FloatRect> m_FixedCollisionBoxes;

public:
	Level_0(ScreenManager* screenManagerPointer);

	void input(sf::RenderWindow& renderWindow) override;
	void update(float fps) override;
	void draw(sf::RenderWindow& renderWindow) override;
};