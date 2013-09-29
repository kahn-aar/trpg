#include "Map.h"

namespace TRPG
{
	Map::Map()
	{
		for(unsigned int i = 0; i<TAILLE_MAX; i++)
			for(unsigned int j = 0; j<TAILLE_MAX; j++)
				carte[i][j] = 0;
	}

	void Map::initializeMap()
	{
		for(unsigned int i = 0; i<TAILLE_MAX; i++)
			for(unsigned int j = 0; j<TAILLE_MAX; j++)
				{
					carte[i][j] = 0;
					carte_joueurs[i][j] = NULL;
			}
	}

	void Map::afficheMap() const
	{
		for(unsigned int i = 0; i<TAILLE_MAX; i++)
		{
			for(unsigned int j = 0; j<TAILLE_MAX; j++)
				cout << carte[i][j] << " ";
			cout << endl;
		}
		cout << endl << endl << endl;

		for(unsigned int i = 0; i<TAILLE_MAX; i++)
		{
			for(unsigned int j = 0; j<TAILLE_MAX; j++)
				{
					if (carte_joueurs[i][j])
						cout << carte_joueurs[i][j]->getName() << " ";
					else
						cout << "0" << " ";
			}
			cout << endl;
		}
		
	}

	bool Map::ajouterCombattant(Combattant* cmb, int x, int y)
	{
		if (carte[x][y] == 0)
		{
			carte[x][y] = 1;
			carte_joueurs[x][y] = cmb;
			return true;
		}
		return false;
	}

}