#pragma once
#ifndef LEVEL_MANAGER_H
#define LEVEL_MANAGER_H

#include <SFML/Graphics.hpp>

class LevelManager
{
private:	
	// Hold a score for every level
	float m_BestTimes[3];	

	// A pointer of the same type as the class itself
	// the one and only instance
	static LevelManager* m_s_Instance;
public:
	LevelManager();
	
	static float* GetBestTimes();
	static void UpdateBestTime(float bestTime, int position);
};

#endif