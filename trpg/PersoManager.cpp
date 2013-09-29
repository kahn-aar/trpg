#include "PersoManager.h"

namespace TRPG
{
	PersoManager* PersoManager::instance = 0;

	PersoManager* PersoManager::getInstance()
	{
		if (!instance)
			instance = new PersoManager();
		return instance;
	}

	void PersoManager::releaseInstance()
	{

	}
}