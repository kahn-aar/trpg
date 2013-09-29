#include "Combat.h"

namespace TRPG
{

	Combat::Combat(Team* equipe) : heros(equipe)
	{
		carte = new Map();
		carte->afficheMap();
	}

	void Combat::unCombat()
	{

	}

	
}