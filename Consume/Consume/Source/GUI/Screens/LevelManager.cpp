#include "../../../Headers/GUI/Screens/LevelManager.h"
#include <assert.h>

using namespace sf;
using namespace std;

LevelManager* LevelManager::m_s_Instance = nullptr;

LevelManager::LevelManager()
{
	assert(m_s_Instance == nullptr);
	m_s_Instance = this;
}

float* LevelManager::GetBestTimes()
{
	// Get a reference to m_Textures using m_S_Instance
	return m_s_Instance->m_BestTimes;
}

void LevelManager::UpdateBestTime(float bestTime, int position)
{
	m_s_Instance->m_BestTimes[position] = bestTime;
}