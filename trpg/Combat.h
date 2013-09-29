#ifndef COMBAT_H_INCLUDED
#define COMBAT_H_INCLUDED

#include "Team.h"
#include "Ennemis.h"

namespace TRPG
{
	class Combat
	{
	protected:
		Team* heros;
		list<Combattant*> engages;
		Map* carte;
	public:
		Combat(Team* equipe);
		bool defaite() const {return heros->morts();}
		void unCombat();
		void addEnemis(Ennemis* en){engages.push_back(en);}
		void sort(){engages.sort();}
		void ajoutHeros();
	};
}

#endif // COMBAT_H_INCLUDED