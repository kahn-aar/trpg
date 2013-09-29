#include "Team.h"

namespace TRPG
{
	void Team::affiche() const
	{
		cout << "equipe" << endl;
		cout << "Lvl total : " << lvlTotal << endl;
		cout << "Lvl moyen : " << avgLvl << endl;
		for (list<Heros*>::const_iterator it = equipe.begin(); it != equipe.end(); it++)
		{
			(*it)->affiche();
		}
	}

	bool Team::morts() const
	{
		bool mort = true;
		for (list<Heros*>::const_iterator it = equipe.begin(); it != equipe.end(); it++)
		{
			if (!(*it)->estMort())
				mort = false;
		}
		return mort;
	}

}