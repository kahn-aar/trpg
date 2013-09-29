#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include <iostream>
#include "Personnage.h"

using namespace std;

namespace TRPG
{
	class Combattant;

	class Map
	{
	private:
		int carte[TAILLE_MAX][TAILLE_MAX];
		Combattant* carte_joueurs[TAILLE_MAX][TAILLE_MAX];
	public:
		Map();
		void initializeMap();
		void afficheMap() const;
		bool ajouterCombattant(Combattant* cmb, int x, int y);
		Combattant* getBattler(int i, int j) {return carte_joueurs[i][j];}


	};
}

#endif // MAP_H_INCLUDED