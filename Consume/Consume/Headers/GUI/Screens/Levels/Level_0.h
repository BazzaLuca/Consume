#pragma once
#include "../../../../Headers/GUI/Screen.h"
#include "../../ScreenManager.h"
#include "../../../Player/Player.h"
#include <fstream>
#include "../../../Enemies/PoliceMan.h"
#include "../../../Enemies/Bat.h"
#include "../../../../Headers/TextureHolder/TextureHolder.h"
#include "../../../../Headers/GUI/Screens/CursorEvent.h"
#include "../../../Player/Bullet.h"

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

	PoliceMan m_PoliceMan;

	Bat m_Bat;

	bool m_IsGamePaused;

	sf::RectangleShape m_RestartPanel;

	sf::Sprite m_RestartButtonSprite;

	sf::Sprite m_QuitButtonSprite;

	CursorEvent m_CursorEvent;

	float m_ElapsedAnimationTime;

	float m_FireRate;

	std::vector<Bullet> m_Bullets;

	bool m_CanShoot;

public:
	Level_0(ScreenManager* screenManagerPointer);

	void input(sf::RenderWindow& renderWindow) override;
	void update(float fps) override;
	void draw(sf::RenderWindow& renderWindow) override;
};