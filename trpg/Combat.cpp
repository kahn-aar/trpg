#include "Combat.h"

namespace TRPG
{

	Combat::Combat(Team* equipe) : heros(equipe)
	{
		carte = new Map();
		carte->initializeMap();
		carte->afficheMap();
		//ajoutHeros();
		
	}

	/**
	* Ajoute les h�ros aux personnages engag�s
	*
	void Combat::ajoutHeros() {
		for (Team.iterator it = (*heros).begin(); it != (*heros).end(); ++it) {
			engages.push_back(*it);
		}
	}
	*/

	void Combat::unCombat()
	{

	}

	
}